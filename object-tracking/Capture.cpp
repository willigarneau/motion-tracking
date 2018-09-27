#include "OpenCVHeaders.h"

String fileName = "";

Capture::Capture(String file)
{
	fileName = file;
}

void Capture::Show(String windowName, int flag)
{
	Mat frame = imread(fileName, flag);
	imshow(windowName, frame);
}
