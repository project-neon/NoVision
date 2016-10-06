#include "bDetect.hpp"
#include <chrono>

using ms = std::chrono::milliseconds;
using tick = std::chrono::steady_clock;

int main(int argc, char *argv[]){
  //loading and testing json file
  Json::Value root;
  std::ifstream Config("../../../inc/configs.json");
  Config >> root;
  cv::Size fieldSize(root.get("fieldSize", 0)[0].asInt(),
                     root.get("fieldSize", 0)[1].asInt() );
  cv::Size fieldSizeMM(root.get("fieldSizeMM", 0)[0].asInt(),
                              root.get("fieldSizeMM", 0)[1].asInt() );

  // Initialize Static Masks
  // This mask is used to exclude outer area of circles detected in HoughCircles
  cv::circle(circleMask, cv::Point(CircleWarpSize / 2, CircleWarpSize / 2),
            (int)(CircleWarpSize / 2.5), cv::Scalar(255,255,255), -1, 8 , 0 );
  cv::imshow("dkjhgfdksfd", circleMask);

  // Constant that multiplied by a unit in mm get the size in pc
  float FIELD_MM = (float)(fieldSize.width) / (float)(fieldSizeMM.width);

  // Plotting (DEBUG)
  int plotWidth = int(fieldSize.width * 2);
  int plotHeigth = int(fieldSize.height * 2);
  std::vector<int> plots;

  changeCameraProp("focus_auto", "0", root);
  changeCameraProp("exposure_auto_priority", "0", root);
  changeCameraProp("exposure_auto", "1", root);
  changeCameraProp("exposure_absolute", "75", root);
  supLimitH = root.get("ballColorRanges",0)["hue"][0].asInt();
  supLimitS = root.get("ballColorRanges",0)["saturation"][0].asInt();
  supLimitV = root.get("ballColorRanges",0)["value"][0].asInt();
  infLimitH = root.get("ballColorRanges",0)["hue"][1].asInt();
  infLimitS = root.get("ballColorRanges",0)["saturation"][1].asInt();
  infLimitV = root.get("ballColorRanges",0)["value"][1].asInt();
  createTrackBars();

  std::string camera = root.get("camera", 1).asString();
  char capNumber = camera.at(10) - 48;
  cv::VideoCapture cap(capNumber); // open the default camera
  if (!cap.isOpened())  // check if we succeeded
    return -1;

  //Load configuration from Json file
  cap.set(3, root.get("cameraRes",0)[0].asInt());
  cap.set(4, root.get("cameraRes",0)[1].asInt());
  cv::Size frameSize(cap.get(3), cap.get(4) );

  cv::Scalar color_rgb(0,0,0);
  fieldCorners[0] = cv::Point2f(root.get("fieldCorners",0)[0][0].asFloat(),
                                      root.get("fieldCorners",0)[0][1].asFloat() );
  fieldCorners[1] = cv::Point2f(root.get("fieldCorners",0)[1][0].asFloat(),
                                      root.get("fieldCorners",0)[1][1].asFloat() );
  fieldCorners[2] = cv::Point2f(root.get("fieldCorners",0)[2][0].asFloat(),
                                      root.get("fieldCorners",0)[2][1].asFloat() );
  fieldCorners[3] = cv::Point2f(root.get("fieldCorners",0)[3][0].asFloat(),
                                      root.get("fieldCorners",0)[3][1].asFloat() );

  cv::Scalar colors[6] = {cv::Scalar( root.get("colors",0)["blue"][0].asInt() ,
                    root.get("colors",0)["blue"][1].asInt() ,
                    root.get("colors",0)["blue"][2].asInt() ),
       cv::Scalar( root.get("colors",0)["green"][0].asInt() ,
                    root.get("colors",0)["green"][1].asInt() ,
                    root.get("colors",0)["green"][2].asInt() ),
       cv::Scalar( root.get("colors",0)["orange"][0].asInt() ,
                    root.get("colors",0)["orange"][1].asInt() ,
                    root.get("colors",0)["orange"][2].asInt() ),
       cv::Scalar( root.get("colors",0)["purple"][0].asInt() ,
                    root.get("colors",0)["purple"][1].asInt() ,
                    root.get("colors",0)["purple"][2].asInt() ),
       cv::Scalar( root.get("colors",0)["red"][0].asInt() ,
                    root.get("colors",0)["red"][1].asInt() ,
                    root.get("colors",0)["red"][2].asInt() ),
       cv::Scalar( root.get("colors",0)["yellow"][0].asInt() ,
                    root.get("colors",0)["yellow"][1].asInt() ,
                    root.get("colors",0)["yellow"][2].asInt()),
                  };

  cv::Mat warpMatrix =  fieldCornersUpdated(fieldCorners, fieldSize);
  std::vector<double> times(10);
  cv::Mat bin, hsv, tgt;
  //Create a window
  cv::namedWindow("Frame", CV_WINDOW_AUTOSIZE);
  //set the callback function for any mouse event
  cv::setMouseCallback("Frame", CallBackFunc, NULL);

  for(;;){
    auto start_total = tick::now();
    auto start = tick::now();
    cap >> Gframe; // get a new frame from camera
    cv::Mat warpedFrame = Gframe.clone();//trocar pelo tamanho
    cv::warpPerspective(Gframe,warpedFrame,warpMatrix,fieldSize,cv::INTER_NEAREST,
                        cv::BORDER_CONSTANT, cv::Scalar() );

    Gframe = warpedFrame;
    warpedFrame.release();
    auto finish = tick::now();
    auto diff = finish - start;
    times[0] = (double)std::chrono::duration_cast<ms>(diff).count();

    //===============================================================================
    start = tick::now();
    cv::cvtColor(Gframe, GframeHSV, cv::COLOR_BGR2HSV);
    cv::GaussianBlur(GframeHSV, GframeHSV, cv::Size(3, 3),0,0);
    colorDetection(GframeHSV, bin,hsv,tgt, colors , 3);
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    findPos(bin, Gframe, contours, hierarchy, root, FIELD_MM);
    finish = tick::now();
    diff = finish - start;
    times[1] = (double)std::chrono::duration_cast<ms>(diff).count();
    //===============================================================================
    start = tick::now();
    cv::Mat robots_draw;
    std::vector<cv::Vec3f> circles;
    detectCircles(Gframe,robots_draw, circles, root,FIELD_MM);
    for( size_t i = 0; i < circles.size(); i++ ) {
      cv::Vec3i c = circles[i];
      cv::circle( robots_draw, cv::Point(c[0], c[1]), c[2], cv::Scalar(0,0,255), 3, cv::LINE_AA);
      cv::circle( robots_draw, cv::Point(c[0], c[1]), 2, cv::Scalar(0,255,0), 3, cv::LINE_AA);
    }
    std::vector<cv::Scalar> robots = classifyRobots(circles,colors, root, FIELD_MM);
    for( size_t i = 0; i < robots.size(); i++ ) {
      std::stringstream ss;
      ss << robots[i][0] <<" , "<< robots[i][3] << std::endl;
      cv::putText(Gframe, ss.str(), cv::Point(robots[i][1],robots[i][2]), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 0, 0), 2, cv::LINE_8, false);
    }
    finish = tick::now();
    diff = finish - start;
    times[2] = (double)std::chrono::duration_cast<ms>(diff).count();
    //===============================================================================
    start = tick::now();
    int k = cv::waitKey(1);

    if (k == 27 || k == 'q')
      break;
    else if(k == 'f'){
      state = 'f';
      actionPickCorners(cap, root);
      warpMatrix = fieldCornersUpdated(fieldCorners, fieldSize);
    }else if(k == 'c'){
      state = 'c';
      actionConfigureColors(cap,root);
    }else if(k == 's') {
      //função de escrever no json
      root["ballColorRanges"]["hue"][0] = supLimitH;
      root["ballColorRanges"]["hue"][1] = infLimitH;
      root["ballColorRanges"]["saturation"][0] = supLimitS ;
      root["ballColorRanges"]["saturation"][1] = infLimitS ;
      root["ballColorRanges"]["value"][0] = supLimitV;
      root["ballColorRanges"]["value"][1] = infLimitV;
      saveInJson(root);
    }
    cv::imshow("Frame",Gframe);
    cv::imshow("Bola", tgt);
    cv::imshow("HSV", GframeHSV);
    finish = tick::now();
    diff = finish - start;
    times[3] = (double)std::chrono::duration_cast<ms>(diff).count();
    //===============================================================================
    auto finish_total = tick::now();
    diff = finish_total - start_total;
    double time_total = (double)std::chrono::duration_cast<ms>(diff).count();
    //
    // std::cout <<"Tempo total: " << time_total << "\tLendo Frame: " << times[0] << "\tDetectando a bolinha: " <<
    // times[1] << "\tDetectando os robos: " << times[2] << "\tRestante: " <<
    // times[3] << std::endl;

  }
  return 0;
}
