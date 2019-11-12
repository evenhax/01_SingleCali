//
// Created by nannan on 2019/11/10.
//

#ifndef SINGLECALI_MYFILEUTILS_H
#define SINGLECALI_MYFILEUTILS_H

#include "MyCommon.h"
#include <string>
#include <boost/filesystem.hpp>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <MacTypes.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <map>
#include <chrono>

class MyFileUtils {
public:
    MyFileUtils();
    /**
     * Set the directory with images to perform the SfM operation on.
     * Image file with extensions "jpg" and "png" will be used.
     * @return true on success.
     */
    ImgNamesVect returnImgNames(const std::string &directoryPath);
    ImgsVect returnImgsVec(ImgNamesVect aImgNamesVect);
    void makeMyDirs();
    cv::Size returnImgSize(ImgsVect aImgsVec);

};


#endif //SINGLECALI_MYFILEUTILS_H
