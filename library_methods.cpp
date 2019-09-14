//
// Created by Dan Orel on 2019-09-10.
//
#include "library_methods.h"

Mat greyscale(std::string filename){
    Mat image = imread(filename);
    Mat greyscaledImage;
    if (image.empty()) {
        std::cerr << "Could not open or find the image" << std::endl;
    }
    cvtColor(image, greyscaledImage, COLOR_BGR2GRAY);
    return greyscaledImage;
}

Mat resize(Mat image){
    Mat resizedImage;
    float OX_scale = 0.5, OY_scale = 0.5;
    resize(image, resizedImage, cv::Size(), OX_scale, OY_scale);
    return resizedImage;
}
