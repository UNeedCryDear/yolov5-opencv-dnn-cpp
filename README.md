# yolov5-opencv-dnn-cpp
使用opencv模块部署yolov5-6.0版本

基于6.0版本的yolov5:https://github.com/ultralytics/yolov5

OpenCV>=4.5.0

导出onnx模型需要将opset设置成12（原来默认的是13，在opencv下面会报错，原因未知）
 
$ python path/to/export.py --weights yolov5s.pt --img [640,640] --opset 12 --include onnx



