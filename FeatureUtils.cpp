//
// Created by nannan on 2019/11/10.
//

#include <opencv/cv.hpp>
#include "FeatureUtils.h"
using namespace std;
using namespace cv;

FeatureUtils::FeatureUtils() {

}

void FeatureUtils::keyExtraction(ImgsVect aImgsVect){
    cout<<"Start to extract the key points..."<<endl;
    int key_count= -1 ;//Save the number of key opints
    Size board_size = Size(4,6);    /* The number of angular points per row and column on the calibration board */

    for(int i=0;i<aImgsVect.size();i++){

        if (0 == findChessboardCorners(aImgsVect[i],board_size,image_points_buf)){
            cout<<"Can not find chessboard corners!\n";
            exit(1);
        }else{
            Mat view_gray;
            cvtColor(aImgsVect[i],view_gray,COLOR_RGB2GRAY);

            /* Subpixel precision */
            find4QuadCornerSubpix(view_gray,image_points_buf,Size(5,5)); //Refine the corner points of the rough extraction
            //cornerSubPix(view_gray,image_points_buf,Size(5,5),Size(-1,-1),TermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER,30,0.1));
            image_points_seq.push_back(image_points_buf);  //Save sub-pixel corner points
            /* Show corner position on image */
            drawChessboardCorners(view_gray,board_size,image_points_buf,false); //Used to mark key points in the image
//            imshow("Corners",view_gray);//show the pictures
////            waitKey(500);//pause for 0.5S
            imwrite(featureOutputPath+"/feature_"+to_string(i)+".jpg",view_gray);
        }

    }

    int total = image_points_seq.size();
    cout<<"total = "<<total<<endl;
    int CornerNum=board_size.width*board_size.height;  //The total number of points in each picture
    for (int j=0 ; j < total ; j++)
    {
        if (0 == j % CornerNum)// 24(i.e.,inner corner number)
        {
            int i = -1;
            i = j / CornerNum;
            int j=i+1;
            cout<<"The data for image:"<<j<<endl;
        }
        if (0 == j % 3)	// This judgment statement formats the output for easy console viewing
        {
            cout<<endl;
        }
        else
        {
            cout.width(10);
        }
        //Output all corner points
        cout<<" -->"<<image_points_seq[j][0].x;
        cout<<" -->"<<image_points_seq[j][0].y;
    }
    cout<<"Key Point Extraction DONE！\n";

}
