#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int colorH = 10, colorS = 229, colorV = 255, rangeH = 10, rangeS = 30, rangeV = 81;
int colorL = 10, colorA = 229, colorB = 255, rangeL = 10, rangeA = 30, rangeB = 81;
int mouse_x, mouse_y;//Posição do mouse

void on_trackbar(int);
void createTrackBars();
void changeCameraProp(string key, string value);
void colorDetection(Mat src, Mat &mask, int it);
void findPos(Mat &src,Mat &tgt, vector<vector<Point> > &contours, vector<Vec4i> &hierarchy);
void CallBackFunc(int event, int x, int y, int flags, void* userdata);

int main(int, char**)
{
	changeCameraProp("exposure_auto","1");
	cout << 1 << endl;
	changeCameraProp("exposure_absolute","80");
	cout << 2 << endl;
	changeCameraProp("focus_auto","0");
	cout << 3 << endl;
	changeCameraProp("white_balance_temperature_auto","0");
	cout << 4 << endl;

	createTrackBars();

	VideoCapture cap(1); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;
		cout << cap.get(CV_CAP_PROP_FRAME_WIDTH) << endl;
		cout << cap.get(CV_CAP_PROP_FRAME_HEIGHT) <<endl;
	for (;;)
	{
		Mat frame, bin;
		cap >> frame; // get a new frame from camera

		colorDetection(frame, bin, 2);

		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;

		findPos(bin, frame, contours, hierarchy);

		//show results
		//namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
		//Create a window
	  namedWindow("Frame", CV_WINDOW_AUTOSIZE);

	  //set the callback function for any mouse event
	  setMouseCallback("Frame", CallBackFunc, NULL);

		imshow("Frame", frame);

		cout << frame << ", " << frame << endl;
		int k = waitKey(30);
		if (k == 27 || k == 'q'){
			break;
		}
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

void createTrackBars(){
	//create the trackbars
	namedWindow("TrackBar", 1);
	cvCreateTrackbar("HUE", "TrackBar", &colorH, 255, on_trackbar);
	cvCreateTrackbar("SATURATION", "TrackBar", &colorS, 255, on_trackbar);
	cvCreateTrackbar("VALUE", "TrackBar", &colorV, 255, on_trackbar);
	cvCreateTrackbar("RANGE_H", "TrackBar", &rangeH, 128, on_trackbar);
	cvCreateTrackbar("RANGE_S", "TrackBar", &rangeS, 128, on_trackbar);
	cvCreateTrackbar("RANGE_V", "TrackBar", &rangeV, 128, on_trackbar);
}

void changeCameraProp(string key, string value){
	if (system(NULL)) puts ("Ok");
    		else exit (EXIT_FAILURE);
  string s ="v4l2-ctl -d /dev/video1 -c " + key + "=" + value;
  system(s.c_str());
}


void colorDetection(Mat src, Mat &mask, int it){
	Mat lab, tgt, thrs;
	//3-channel binary mask
	cvtColor(src, lab, COLOR_BGR2Lab);
	blur(lab, lab, Size(3, 3));
	inRange(lab, Scalar(colorH - rangeH, colorS - rangeS, colorV - rangeV), Scalar(colorH + rangeH + 1 , colorS + rangeS +
	1, colorV + rangeV + 1), mask);

	//image erosion
	Mat element = getStructuringElement( 0,Size( 2,2 ),Point( 0, 0 ) );
  erode( mask, mask, element, Point( 0, 0 ), it	);
	dilate( mask, mask, element, Point( 0, 0 ), 2*it +1);
	erode( mask, mask, element, Point( 0, 0 ), it	);


	//mask aplication
	Mat mask3[] = { mask,mask,mask };
	merge(mask3, 3, thrs);
	bitwise_and(thrs, src, tgt);

	imshow("Bola", tgt);
	imshow("LAB", lab);

}

void findPos(Mat &src,Mat &tgt, vector<vector<Point> > &contours, vector<Vec4i> &hierarchy){
	Mat temp = src.clone();

	if( !temp.empty())
		findContours(temp,contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
		//select best contour
		vector<vector<Point> > contours_poly( contours.size() );
		vector<Point2f> center( contours.size() );
		vector<float> radius( contours.size() );

		int realBallRadius = 21, bestBallRadiusDif = 0, final_radius, bestBall = 0;
		Point ball_center;
		vector<Point> hull;
		double per, cntArea, relation, radiusDif;

		for( int i = 0; i < contours.size(); i++ ){
			approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );//verificar se eh necessario
			minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
			per = arcLength(contours[i], true);
			convexHull(contours[i], hull, true);
			cntArea = contourArea(hull,false) + 0.1;
			relation = (per*radius[i])/2*cntArea;
			radiusDif = abs(realBallRadius - radius[i]);
			if(bestBall == 0 || radiusDif < bestBallRadiusDif){
				final_radius = (int)radius[i];
				ball_center.x = center[i].x;
				ball_center.y = center[i].y;
				bestBall = i;
				bestBallRadiusDif = radiusDif;
			}
		}

		if(bestBall != 0){
			circle( tgt, center[bestBall], (int)radius[bestBall], Scalar(255,0,0), 2, 8, 0 );
		}
}

void on_trackbar(int){};

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
          mouse_x = x;
					mouse_y = y;
     }
}

/*static void on_trackbar2(int, void*)
{
    Mat cnt_img = Mat::zeros(w, w, CV_8UC3);
    int _levels = levels - 3;
    drawContours( cnt_img, contours, _levels <= 0 ? 3 : -1, Scalar(128,255,255),
                  3, LINE_AA, hierarchy, std::abs(_levels) );

    imshow("contours", cnt_img);
}*/
