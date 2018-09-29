// Video camera management component
#include "OpenCVHeaders.h"
VideoCamera::VideoCamera() {}

bool VideoCamera::Start(char* windowName)
{
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		return false;
	}
	cv::Mat img;

	while (true) {
		if (!cap.read(img)) {
			std::cerr << "Error capturing " << std::endl;
			return false;
		}
		imshow(windowName, img);
	}
	return true;
}
