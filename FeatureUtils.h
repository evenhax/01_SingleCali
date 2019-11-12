//
// Created by nannan on 2019/11/10.
//

#ifndef SINGLECALI_FEATUREUTILS_H
#define SINGLECALI_FEATUREUTILS_H


#include "MyCommon.h"
#include <opencv2/features2d.hpp>

class FeatureUtils {

public:
    FeatureUtils();
    void keyExtraction(ImgsVect aImgsVect);


    vector<cv::Point2f> image_points_buf;  /* Save the detected key points  */
    vector<vector<cv::Point2f>> image_points_seq; /* Save all key points */

};


#endif //SINGLECALI_FEATUREUTILS_H
