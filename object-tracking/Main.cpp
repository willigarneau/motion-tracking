/*
	Travail Pratique 1
	- William Garneau
	- Isaac Fiset
*/

#include "opencv2\opencv.hpp"
#include <iostream>;
using namespace std;
using namespace cv;

int main() {
	Mat frame = imread("lena.png");
	imshow("template frame", frame);
	waitKey(0);
}