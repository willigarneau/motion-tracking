// OpenCV dependency file

// OPENCV INCLUDES
#include "opencv2\core\utility.hpp"
#include "opencv2\videoio.hpp"
#include "opencv2\core\core.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\highgui.hpp"
#include <iostream>
#include <cstring>


// PERSONNAL INCLUDES
#include "VideoCamera.h"
#include "Capture.h"

// NAMESPACES
using namespace std;
using namespace cv;

// STRUCTS
struct Resolution {
	int Width;
	int Height;
};