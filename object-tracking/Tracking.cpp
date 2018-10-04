#include "OpenCVHeaders.h"

Tracking::Tracking() {}

void Tracking::MotionDetection()
{
	VideoCapture capture(0);
	MovementDirection md;
	int frameIndex = 0;
	Mat lastFrame;
	while (capture.isOpened())
	{
		Mat frame;
		if (!capture.read(frame))
			break;

		Mat grayFrame, dilatedFrame, edges, deltaFrame, deltaCopyFrame;

		// Scale up image
		/*resize(frame, frame, Size(0, 0), 2, 2);*/

		// Convert to grayscale
		cvtColor(frame, grayFrame, CV_BGR2GRAY);

		// Blur the capture to avoid a lot of circles
		GaussianBlur(grayFrame, grayFrame, Size(7, 7), 0);

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
		int iterations = 20;
		dilate(deltaFrame, deltaFrame, Mat(), Point(-1, -1), iterations);

		// Approximate contours to polygons + get bounding rects and circles
		vector<vector<Point>> contours;
		vector<Vec4i> hierarchy;
		findContours(deltaFrame, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
		vector<vector<Point>>contours_poly(contours.size());
		vector<Rect> boundRect(contours.size());
		vector<Point2f>center(contours.size());
		vector<float>radius(contours.size());

		Position pos;
		pos.X = 0; pos.Y = 0;
		// Movement direction detection
		if (contours.size() == 0) {
			MovementDirection md = MovementDirection(pos);
		}
		else {
			pos.X = (int)contours[0][0].x;
			pos.Y = (int)contours[0][0].y;
		}

		for (int i = 0; i < contours.size(); i++)
		{
			approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
			boundRect[i] = boundingRect(Mat(contours_poly[i]));
			minEnclosingCircle((Mat)contours_poly[i], center[i], radius[i]);
			md = MovementDirection(pos);
		}

		// Draw polygonal contour + bonding rects + circles
		for (int i = 0; i<contours.size(); i++)
		{
			Scalar color = Scalar(0, 255, 0);
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


