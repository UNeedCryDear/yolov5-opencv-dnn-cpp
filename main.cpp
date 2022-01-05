#include "stdafx.h"
#include "yolo.h"
#include <iostream>
#include<opencv2//opencv.hpp>
#include<math.h>

using namespace std;
using namespace cv;
using namespace dnn;

int main()
{
	string img_path = "./image/bus.jpg";
	string model_path = "yolov5s.onnx";
	//int num_devices = cv::cuda::getCudaEnabledDeviceCount();
	//if (num_devices <= 0) {
		//cerr << "There is no cuda." << endl;
		//return -1;
	//}
	//else {
		//cout << num_devices << endl;
	//}

	Yolo test;
	Net net;
	if (test.readModel(net, model_path, false)) {
		cout << "read net ok!" << endl;
	}
	else {
		return -1;
	}

	//生成随机颜色
	vector<Scalar> color;
	srand(time(0));
	for (int i = 0; i < 80; i++) {
		int b = rand() % 256;
		int g = rand() % 256;
		int r = rand() % 256;
		color.push_back(Scalar(b, g, r));
	}
	vector<Output> result;
	Mat img = imread(img_path);

	if (test.Detect(img, net, result)) {
		test.drawPred(img, result, color);

	}
	else {
		cout << "Detect Failed!"<<endl;
	}

	system("pause");
    return 0;
}

