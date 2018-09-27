/*
	Travail Pratique 1
	- William Garneau
	- Isaac Fiset
*/

#include "OpenCVHeaders.h"

int main() {
	Capture frame("lena.png");
	frame.Show("Titre d'image", 1);
	waitKey(0);
}