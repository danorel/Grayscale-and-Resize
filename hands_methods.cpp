//
// Created by Dan Orel on 2019-09-10.
//
#include "hands_methods.h"


Mat greyscale(std::string filename){
    Mat RGBImage = imread(filename);
    if (!RGBImage.data){
        std::cerr << "Error! No such image exists by the path " << filename << std::endl;
        exit(-1);
    }
    Mat GrayscaledImage(RGBImage.size(), CV_8UC1);
    int height = RGBImage.rows;
    int width  = RGBImage.cols;
    uchar blue, green, red;
    float BlueCoefficient  = 0.0722,
          GreenCoefficient = 0.7152,
          RedCoefficient   = 0.2126;
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            Vec3b intensity = RGBImage.at<Vec3b>(row, col);
            blue  =intensity.val[0];
            green =intensity.val[1];
            red   =intensity.val[2];
            GrayscaledImage.at<uchar>(row, col) =
                    blue  * BlueCoefficient +
                    green * GreenCoefficient +
                    red   * RedCoefficient;
        }
    }
    return GrayscaledImage;
}


Mat resizeByHalf(std::string filename){
    int scale = 2;
    Mat RGBImage = imread(filename);
    Mat ResizedImage(RGBImage.size() / scale, CV_8UC3);
    int height = round(RGBImage.rows / scale);
    int width  = round(RGBImage.cols / scale) * 3;
    for (int row = 0; row < height; row++){
        for (int column = 0; column < width; column++){
            ResizedImage.at<uchar>(row, column) = RGBImage.at<uchar>(scale * row, scale * column);
        }
    }
    return ResizedImage;
}


Mat resizeByTwice(std::string filename){
    int scale = 2;
    Mat RGBImage = imread(filename);
    Mat ResizedImage(RGBImage.size() * scale, CV_8UC3);
    int height = (RGBImage.rows * scale);
    int width  = (RGBImage.cols * scale) * 3;
    for (int row = 0; row < height; row++){
        for (int column = 0; column < width; column++){
            ResizedImage.at<uchar>(row, column) = RGBImage.at<uchar>(round(row / scale), floor(column / scale));
        }
    }
    return ResizedImage;
}