
## Introduction

This demo provides a camera calibration method based on ***A Flexible New Technique for Camera Calibration*** .

The camera calibration methods can be roughly classified into two catagories: Three-dimensional reference object-based calibration and self calibration.Other techniques exist: vanishing points for orthogonal directions.

However the commonly used method was proposed by Zhang Zhengyou in ***A Flexible New Technique for Camera Calibration*** , more detail can be seen in the PPT under this project. 

The core function is provided by OpenCV3.

## Environment

This demo is created with CLion but it is okay for you to open it with your usual IDE.

OpenCV3 and boost are require. You can adjust it according to your own environment.(More details in CMakeList.txt)

## Usage

Run the main.cpp, and the demo will work out the calibration process. 
The finally output will be saved in 


