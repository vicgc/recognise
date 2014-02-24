#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>

// g++ webcam_recognise.cpp `pkg-config --cflags --libs opencv` -I/usr/include/opencv2/

using namespace std;
using namespace cv;

// Grab the next camera frame. Waits until the next frame is ready, and
// provides direct access to it, so do NOT modify or free the returned image!
// Will automatically initialize the camera on the first frame.
IplImage* getCameraFrame(CvCapture* &camera)
{
	IplImage *frame;
	int w, h;

	// If the camera hasn't been initialized, then open it.
	if (!camera) {
		printf("Acessing the camera ...\n");
		camera = cvCreateCameraCapture( 0 );
		if (!camera) {
			printf("Couldn't access the camera.\n");
			exit(1);
		}
		// Try to set the camera resolution to 320 x 240.
		cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH, 320);
		cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT, 240);
		// Get the first frame, to make sure the camera is initialized.
		frame = cvQueryFrame( camera );
		if (frame) {
			w = frame->width;
			h = frame->height;
			printf("Got the camera at %dx%d resolution.\n", w, h);
		}
		// Wait a little, so that the camera can auto-adjust its brightness.
		sleep(1000);	// (in milliseconds)
	}

	// Wait until the next camera frame is ready, then grab it.
	frame = cvQueryFrame( camera );
	if (!frame) {
		printf("Couldn't grab a camera frame.\n");
		exit(1);
	}
	return frame;
}
