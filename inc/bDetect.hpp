#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
#define PI 3.14159265

#include <opencv2/opencv.hpp>
#include <json/json.h>

extern char state;
extern cv::Scalar mean_color;
extern double x_color, y_color;
extern int colorH, colorS, colorV;
extern int supLimitH, supLimitS, supLimitV, infLimitH, infLimitS, infLimitV;
extern double resize;
extern int selectedCorner;
extern cv::Mat Gframe;
extern cv::Point2f fieldCorners[4];

void on_trackbar(int);
void changeCameraProp(std::string key, std::string value, Json::Value root);
void createTrackBars();
cv::Mat fieldCornersUpdated(cv::Point2f perspectiveIn[], cv::Size size);
void actionPickCorners(cv::VideoCapture &cap, Json::Value &root);
void actionConfigureColors(cv::VideoCapture &cap, Json::Value &root);
void CallBackFunc(int event, int x, int y, int flags, void* userdata);
void colorDetection(cv::Mat src, cv::Mat &mask, cv::Mat &hsv, cv::Mat &tgt, cv::Scalar colors[], int it);
cv::Scalar findPos(cv::Mat &src,cv::Mat &tgt, std::vector<std::vector<cv::Point> > &contours,
              std::vector<cv::Vec4i> &hierarchy, Json::Value &root, float k);
void saveInJson(Json::Value root);
bool detectCircles(cv::Mat &src,cv::Mat &tgt, std::vector<cv::Vec3f> &circles,
              Json::Value &root,float k);
std::vector<cv::Scalar> classifyRobots(cv::Mat &circlemask, int warpSize, std::vector<cv::Vec3f> &circles, cv::Scalar colors[],
			  Json::Value &root, float k);
int matchColorHSV(cv::Scalar color, cv::Scalar colors[], std::vector<int> excludecolors);
