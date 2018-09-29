/*
	Motion detection tracking 
	Computer Vision 2018
	Cégep Lévis-Lauzon

	OpenCV 3.42

	*** DOCUMENTATION ***
    https://www.learnopencv.com/object-tracking-using-opencv-cpp-python/
    https://docs.opencv.org/2.4/doc/tutorials/imgproc/shapedescriptors/bounding_rects_circles/bounding_rects_circles.html
	https://docs.opencv.org/2.4/modules/video/doc/motion_analysis_and_object_tracking.html
	https://www.intorobotics.com/how-to-detect-and-track-object-with-opencv/

	Copyright (c) 2018, William Garneau, Isaac Fiset and the respective contributors
	All rights reserved.
*/

#include "OpenCVHeaders.h"

int main() {

	std::cout << "Welcome in the motion detection application \nThe program is starting...\n";

	Tracking tracker;
	tracker.MotionDetection();

	return 0;
}

