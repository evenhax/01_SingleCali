//
// Created by nannan on 2019/11/10.
//

#ifndef SINGLECALI_MYCOMMON_H
#define SINGLECALI_MYCOMMON_H
#include <vector>
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
# include <string>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <map>

using namespace std;
///0. Used in MyFileUtils
const float mDownscaleFactor=1.0;//used by fileutils

const string totalPath="/Users/nannan/CLionProjects/SingleCali/";
const string imageSourcePath=totalPath+"calibration/";
const string caliOutputPath=totalPath+"cali_out/";
const string featureOutputPath=totalPath+"feature_out/";

typedef std::vector<cv::Mat> ImgsVect;
typedef std::vector<std::string> ImgNamesVect;


///1. Used in Features.h/.cpp


//2. Used for calib

/*3D inforation of the board*/
const int actualWidth=10;
const int actualHeight=10;


#endif //SINGLECALI_MYCOMMON_H
