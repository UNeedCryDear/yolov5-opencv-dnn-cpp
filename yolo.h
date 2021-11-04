#pragma once
#include<iostream>
#include<opencv2/opencv.hpp>
//#include<string>
//using namespace std;
//using namespace cv;
//using namespace dnn;

struct Output {
	int id;//结果类别id
	float confidence;//结果置信度
	cv::Rect box;//矩形框
};

class Yolo {
public:
	Yolo() {
	}
	~Yolo() {}
	bool readModel(cv::dnn::Net &net,std::string &netPath,bool isCuda);
	bool Detect(cv::Mat &SrcImg,cv::dnn::Net &net, std::vector<Output> &output);
	void drawPred(cv::Mat &img, std::vector<Output> result, std::vector<cv::Scalar> color);

private:
	const float netAnchors[3][6] = { { 10.0, 13.0, 16.0, 30.0, 33.0, 23.0 },{ 30.0, 61.0, 62.0, 45.0, 59.0, 119.0 },{ 116.0, 90.0, 156.0, 198.0, 373.0, 326.0 } };
	const float netStride[3] = { 8, 16.0,32 };
	const int netWidth = 640;
	const int netHeight = 640;
	float nmsThreshold = 0.45;
	float boxThreshold = 0.25;
	float classThreshold = 0.25;
	std::vector<std::string> className = { "person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck", "boat", "traffic light",
		"fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat", "dog", "horse", "sheep", "cow",
		"elephant", "bear", "zebra", "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee",
		"skis", "snowboard", "sports ball", "kite", "baseball bat", "baseball glove", "skateboard", "surfboard",
		"tennis racket", "bottle", "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple",
		"sandwich", "orange", "broccoli", "carrot", "hot dog", "pizza", "donut", "cake", "chair", "couch",
		"potted plant", "bed", "dining table", "toilet", "tv", "laptop", "mouse", "remote", "keyboard", "cell phone",
		"microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors", "teddy bear",
		"hair drier", "toothbrush" };

};
