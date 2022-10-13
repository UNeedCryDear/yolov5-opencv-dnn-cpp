# yolov5-opencv-dnn-cpp
使用opencv模块部署yolov5-6.0版本

基于6.0版本的yolov5:https://github.com/ultralytics/yolov5

OpenCV>=4.5.0

导出onnx模型需要将opset设置成12（原来默认的是13，在opencv下面会报错，原因未知）
如果是torch1.12.x的版本,需要在
https://github.com/ultralytics/yolov5/blob/c98128fe71a8676037a0605ab389c7473c743d07/export.py#L155
这里的```do_constant_folding=False```,设置为false才行，否者读取网络会失败，原因未知。
$ python path/to/export.py --weights yolov5s.pt --img [640,640] --opset 12 --include onnx

2022.03.29 更新：  

新增P6模型支持，可以通过yolo.h中定义的YOLO_P6切换  

另外关于换行符，windows下面需要设置为CRLF，上传到github会自动切换成LF，windows下面切换一下即可

以下图片为更新p6模型之后yolov5s6.onnx运行结果：
![zidane](https://user-images.githubusercontent.com/52729998/160559827-45572f7e-54e8-4653-b9be-6d287912b065.jpg)

![bus](https://user-images.githubusercontent.com/52729998/160559831-3ddf926d-b7c3-4687-bd57-26dd4d1cc055.jpg)
