// clang-3.3 `pkg-config --cflags --libs opencv` cam.cpp -o opencv

#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, const char** argv) {
     Mat img = imread("j.png", CV_LOAD_IMAGE_UNCHANGED);

     if (img.empty()) {
          cout << "Error : Image cannot be loaded..!!" << endl;
          return -1;
     }

     namedWindow("App", CV_WINDOW_AUTOSIZE);
     imshow("App", img);

     waitKey(0);

     destroyWindow("MyWindow");
     return 0;
}
