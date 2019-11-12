cmake_minimum_required(VERSION 3.15)
project(SingleCali)
find_package(OpenCV 3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system thread REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)
set(Boost_USE_STATIC_LIBS ON)

add_executable(SingleCali main.cpp MyFileUtils.cpp MyFileUtils.h MyCommon.h CameraCali.cpp CameraCali.h FeatureUtils.cpp FeatureUtils.h)
target_link_libraries(SingleCali ${OpenCV_LIBS} )
target_link_libraries(SingleCali ${Boost_LIBRARIES})