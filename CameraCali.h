//
// Created by nannan on 2019/11/10.
//

#ifndef SINGLECALI_CAMERACALI_H
#define SINGLECALI_CAMERACALI_H

#include <string>
#include <fstream>
#include <dirent.h>
#include <cstring>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <MacTypes.h>

#include "MyCommon.h"
#include "MyFileUtils.h"
#include "FeatureUtils.h"

using namespace std;
using namespace cv;



class CameraCali {
public:
    void myCaliPipe();
    CameraCali();
private:

    MyFileUtils myFileTool;
    FeatureUtils myFeatureTool;

    ImgNamesVect myImgNames;
    ImgsVect myImgs;

    cv::Size imgSize;
    cv::Size board_size = cv::Size(4,6);    /* The number of angular points per row and column on the calibration board */
    cv::Size square_size = cv::Size(actualWidth, actualHeight); /* The actual measured size of each checkerboard on the calibration plate */
    vector<vector<cv::Point3f>> object_points; /* Save the 3D coordinate of the corners */

    /*Camera intric and extric Mat*/
    Mat cameraMatrix=Mat(3,3,CV_32FC1,Scalar::all(0)); /* Inner Matrix of the camera */
    vector<int> point_counts;  // Number of the corner in each picture
    Mat distCoeffs=Mat(1,5,CV_32FC1,Scalar::all(0)); /* 5 distortion coefficients of the camera：k1,k2,p1,p2,k3 */
    vector<Mat> tvecsMat;  /* the R of each picture */
    vector<Mat> rvecsMat; /* the T of each picture */

    bool myCalibration();
    void caliRecord();
};


#endif //SINGLECALI_CAMERACALI_H
