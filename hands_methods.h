//
// Created by Dan Orel on 2019-09-10.
//
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

#ifndef PRACTICE2_HANDS_METHODS_H
#define PRACTICE2_HANDS_METHODS_H
Mat greyscale(std::string);
Mat resizeByHalf(std::string filename);
Mat resizeByTwice(std::string filename);
#endif //PRACTICE2_HANDS_METHODS_H
