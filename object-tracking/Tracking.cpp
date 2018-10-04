#include "OpenCVHeaders.h"

Tracking::Tracking() {}

void Tracking::MotionDetection()
{
	VideoCapture capture(0);
	int frameIndex = 0;
	Mat lastFrame;
	while (capture.isOpened())
	{
		Mat frame;
		if (!capture.read(frame))
			break;

		Mat grayFrame, dilatedFrame, edges, deltaFrame, deltaCopyFrame;

		// Convert to grayscale
		cvtColor(frame, grayFrame, CV_BGR2GRAY);

		// Blur the capture to avoid a lot of circles
		GaussianBlur(grayFrame, grayFrame, Size(5, 5), 0);

		if (frameIndex == 0) {
			frameIndex++;

			// Initialize video parameters
			double fcc = capture.get(CV_CAP_PROP_FOURCC);
			double fps = capture.get(CV_CAP_PROP_FPS);
			Size frameSize(grayFrame.size().width, grayFrame.size().height);

			std::cout << "Frame Size = " << grayFrame.size().width << " x " << grayFrame.size().height << "\n";
			// Initialize the last reference frame
			lastFrame = grayFrame;
			continue;
		}
		else if ((frameIndex % 50) == 0) {
			frameIndex = 0;
		}
		frameIndex++;


		// Find differences between the images
		absdiff(lastFrame, grayFrame, deltaFrame);
		threshold(deltaFrame, deltaFrame, 50, 255, THRESH_BINARY);

		// Dilate to fill-in holes and find contours
		int iterations = 2;
		dilate(deltaFrame, deltaFrame, Mat(), Point(-1, -1), iterations);

		// Approximate contours to polygons + get bounding rects and circles
		vector<vector<Point>> contours;
		vector<Vec4i> hierarchy;
		findContours(deltaFrame, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
		vector<vector<Point> > contours_poly(contours.size());
		vector<Rect> boundRect(contours.size());
		vector<Point2f>center(contours.size());
		vector<float>radius(contours.size());

		for (int i = 0; i < contours.size(); i++)
		{
			approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
			boundRect[i] = boundingRect(Mat(contours_poly[i]));
			minEnclosingCircle((Mat)contours_poly[i], center[i], radius[i]);
		}

		// Draw polygonal contour + bonding rects + circles
		for (int i = 0; i< contours.size(); i++)
		{
			Scalar color = Scalar(0, 255, 0);
			drawContours(frame, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
			rectangle(frame, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
			circle(frame, center[i], (int)radius[i], color, 2, 8, 0);
		}

		imshow("Motion detection Frame", frame);
		imshow("Threshold frame", deltaFrame);

		// Press Escape to exit
		switch (waitKey(1)) {
		case 27:
			capture.release();
			return;
		}
	}
}


