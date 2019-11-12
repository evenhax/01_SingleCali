//
// Created by nannan on 2019/11/10.
//

#include "CameraCali.h"

using namespace cv;
CameraCali::CameraCali() {

}

void CameraCali::myCaliPipe() {
    myImgNames=myFileTool.returnImgNames(imageSourcePath);
    myImgs=myFileTool.returnImgsVec(myImgNames);
    myFileTool.makeMyDirs();
    imgSize=myFileTool.returnImgSize(myImgs);
    myFeatureTool.keyExtraction(myImgs);
    bool success=CameraCali::myCalibration();
    if(success){
        CameraCali::caliRecord();
    }
}

bool CameraCali::myCalibration(){
    cout<<"--------------------------------------\n";
    cout<<"Calibration Starts\n";
    /*3D inforation of the board*/
    cv::Size square_size = cv::Size(actualWidth, actualHeight);  /* The actual measured size of each checkerboard on the calibration plate */

    /* Initialize the 3D coordinates of the corner points on the calibration board */
    int i,j,t;
    for (t=0;t<myImgs.size();t++)
    {
        vector<Point3f> tempPointSet;
        for (i=0;i<board_size.height;i++)
        {
            for (j=0;j<board_size.width;j++)
            {
                Point3f realPoint;
                /* Suppose the calibration plate is placed on a plane with z=0 in the world coordinate system. */
                realPoint.x = i*square_size.width;
                realPoint.y = j*square_size.height;
                realPoint.z = 0;
                tempPointSet.push_back(realPoint);
            }
        }
        object_points.push_back(tempPointSet);
    }

    /* Initialize the number of corner points in each image,
     * assuming that the COMPLETE calibration plate is visible in each image */
    for (i=0;i<myImgs.size();i++)
    {
        point_counts.push_back(board_size.width*board_size.height);
    }
    /* calibration starts */
    calibrateCamera(object_points,myFeatureTool.image_points_seq,imgSize,cameraMatrix,distCoeffs,rvecsMat,tvecsMat,0);
    cout<<"-----------------------------\n";
    cout<<"Calibration ENDS\n";
    return true;
}

void CameraCali::caliRecord(){

    ofstream fout(caliOutputPath+"caliberation_result.txt");  /* the file that save the calibration result */
    //Save the calibration results
    std::cout<<"-------START to save the calibration result--------"<<endl;
    Mat rotation_matrix = Mat(3,3,CV_32FC1, Scalar::all(0)); /* 保存每幅图像的旋转矩阵 */
    fout<<"Camera Intrinsic Matrix："<<endl;
    fout<<cameraMatrix<<endl<<endl;
    fout<<"Distortion coefficient：\n";
    fout<<distCoeffs<<endl<<endl<<endl;
    for (int i=0; i<myImgs.size(); i++)
    {
        fout<<"The R vector of picture "<<i+1<<":"<<endl;
        fout<<tvecsMat[i]<<endl;
        /* Convert the rotation vector to the corresponding rotation matrix */
        Rodrigues(tvecsMat[i],rotation_matrix);
        fout<<"The R matrix of picture "<<i+1<<":"<<endl;
        fout<<rotation_matrix<<endl;
        fout<<"the t of picture "<<i+1<<"："<<endl;
        fout<<rvecsMat[i]<<endl<<endl;
    }
    std::cout<<"----------END of the savement-------"<<endl;
    fout<<endl;

    fout<<endl;
    /************************************************************************
    show the calibration result
    *************************************************************************/
    Mat mapx = Mat(imgSize,CV_32FC1);
    Mat mapy = Mat(imgSize,CV_32FC1);
    Mat R = Mat::eye(3,3,CV_32F);
    std::cout<<"------------Save the calibrated pics---------"<<endl;

    //Save the calibrated pictures
    initUndistortRectifyMap(cameraMatrix,distCoeffs,R,cameraMatrix,imgSize,CV_32FC1,mapx,mapy);
    std::cout<<"---------ALL Have been saved----------"<<endl;
    std::cout<<"---------Whole Process OVER:)---------"<<endl;

}





