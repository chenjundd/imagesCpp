#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main() {

	VideoCapture camCapLeft(0);
	int i = 0;

	camCapLeft.set(cv::CAP_PROP_FRAME_WIDTH, 10000);
	camCapLeft.set(cv::CAP_PROP_FRAME_HEIGHT, 10000);
	// int w = (int)mCapture.get(cv::CAP_PROP_FRAME_WIDTH);
	//  int h = (int)mCapture.get(cv::CAP_PROP_FRAME_HEIGHT);

	int w = camCapLeft.get(CV_CAP_PROP_FRAME_WIDTH);
	int h = camCapLeft.get(CV_CAP_PROP_FRAME_HEIGHT);
	printf("cam Resolution%d,%d\n", w, h);
	while (camCapLeft.isOpened()) {
		cv::Mat img1;
		camCapLeft >> img1;
		imshow("L", img1);
		char c = cv::waitKey(1);
		char name[10] = "";
		sprintf(name, "a%d.jpg", i);
		i++;
		//imwrite(name, img1);

	}

	camCapLeft.release();
	return 0;
}

