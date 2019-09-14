#include <iostream>
//#include "library_methods.h"
#include "hands_methods.h"
using namespace std;

int main() {
    string pathToImage = "/Users/danorel/Workspace/World of C/C++/KMA/MMPI/practice1/image.jpg";
    string greyscaledLabel = "Greyscaled image";
    string resizedByHalfLabel = "Resized by half image";
    string resizedByTwiceLabel = "Resized by twice image";

    Mat GreyscaledImage = greyscale(pathToImage);
    namedWindow(greyscaledLabel);
    imshow(greyscaledLabel, GreyscaledImage);

    Mat ResizedByHalfImage = resizeByHalf(pathToImage);
    namedWindow(resizedByHalfLabel);
    imshow(resizedByHalfLabel, ResizedByHalfImage);

    Mat ResizedByTwiceImage = resizeByTwice(pathToImage);
    namedWindow(resizedByTwiceLabel);
    imshow(resizedByTwiceLabel, ResizedByTwiceImage);
    waitKey(0);
    return 0;
}