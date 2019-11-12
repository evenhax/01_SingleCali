//
// Created by nannan on 2019/11/10.
//
#include <iostream>
#include "MyFileUtils.h"
#include <sys/stat.h>
#include <fstream>
#include <dirent.h>
#include <cstring>

using namespace boost::filesystem;
using namespace std;
using namespace cv;

MyFileUtils::MyFileUtils() {

}
ImgNamesVect MyFileUtils::returnImgNames(const std::string &directoryPath) {

    ImgNamesVect aImgNamesVect;

    //define the path and ensure its existence
    path dirPath(directoryPath);
    if (not exists(dirPath) or not is_directory(dirPath)) {
        cerr << "Cannot open directory: " << directoryPath << endl;

    }

    //fetch all imgs with excepted extension and store their path in mImageFilenames
    for (directory_entry &x : directory_iterator(dirPath)) {
        std::string extension = x.path().extension().string();
        boost::algorithm::to_lower(extension);
        if (extension == ".jpg" or extension == ".png") {
            aImgNamesVect.push_back(x.path().string());
            cout << x.path().string() << " has been written to the aImgNamesVect." << endl;
        }
    }

    if (aImgNamesVect.size() <= 0) {
        cerr << "Unable to find valid files in images directory (\"" << directoryPath << "\")." << endl;

    }


    return aImgNamesVect;
}

ImgsVect MyFileUtils::returnImgsVec(ImgNamesVect aImgNamesVect) {
    ImgsVect aImgsVect;
    for (auto &imageFilename : aImgNamesVect) {
        aImgsVect.push_back(cv::imread(imageFilename));

        if (mDownscaleFactor != 1.0) {
            cv::resize(aImgsVect.back(), aImgsVect.back(), cv::Size(), mDownscaleFactor, mDownscaleFactor);
        }

        if (aImgsVect.back().empty()) {
            cerr << "Unable to read image from file: " << imageFilename << endl;

        }
    }
    int aImgVectSize = aImgsVect.size();
    cout << "The size of aImgsVect is :" << to_string(aImgVectSize) << endl;

    return aImgsVect;

}

void MyFileUtils::makeMyDirs() {
    if (0 != access(caliOutputPath.c_str(), 0)) {
        mkdir(caliOutputPath.c_str(), 0777);
        cout << "The path:" << caliOutputPath.c_str() << " is created successfully" << endl;
    }
    if(0!=access(featureOutputPath.c_str(),0)){
        mkdir(featureOutputPath.c_str(),0777);
        cout<<"The path:"<<featureOutputPath.c_str()<<" is created successfully"<<endl;
    }
//    if(0!=access(matchingOutputPath.c_str(),0)){
//        mkdir(matchingOutputPath.c_str(),0777);
//        cout<<"The path:"<<matchingOutputPath.c_str()<<" is created successfully"<<endl;
//    }

}


cv::Size MyFileUtils::returnImgSize(ImgsVect aImgsVect) {
    cv::Size image_size;
    image_size.width = aImgsVect[0].cols;
    image_size.height = aImgsVect[0].rows;
    cout << "image_size.width = " << image_size.width << endl;
    cout << "image_size.height = " << image_size.height << endl;
    return image_size;

}

