/*
	Travail Pratique 1
	- William Garneau
	- Isaac Fiset
*/

#include "OpenCVHeaders.h"

int main() {
	Mat frame = imread("lena.png");
	imshow("template frame", frame);
	waitKey(0);
}