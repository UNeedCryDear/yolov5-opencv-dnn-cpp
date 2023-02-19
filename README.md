# yolov5-opencv-dnn-cpp
使用opencv模块部署yolov5-6.0版本

基于6.0版本的yolov5:https://github.com/ultralytics/yolov5

**OpenCV>=4.5.0**

+ 导出onnx模型需要将opset设置成12（原来默认的是13，在opencv下面会报错，原因未知）</br>
+ 如果是torch1.12.x的版本,需要在
https://github.com/ultralytics/yolov5/blob/c98128fe71a8676037a0605ab389c7473c743d07/export.py#L155
这里的```do_constant_folding=False```,设置为false才行，否者读取网络会失败，原因未知。<br>
```
$ python path/to/export.py --weights yolov5s.pt --img [640,640] --opset 12 --include onnx
```
#### 2023.02.19 更新：
+ 旧代码已经是两年之前的了，之前为了适应yolov5-5.0的版本，后处理部分留下太多繁琐的操作，包括像计算anchors，需要设置对应的stride等等。本次更新将会优化这部分内容，同时加上预处理部分的LetterBox(),与python下的源码保持一致性的预处理方式。

#### 2022.12.13 更新：
+ 如果你的显卡支持FP16推理的话，可以将模型读取代码中的```DNN_TARGET_CUDA```改成```DNN_TARGET_CUDA_FP16```提升推理速度（虽然是蚊子腿，好歹也是肉（： 
#### 2022.03.29 更新：  

+ 新增P6模型支持，可以通过yolo.h中定义的YOLO_P6切换  

+ 另外关于换行符，windows下面需要设置为CRLF，上传到github会自动切换成LF，windows下面切换一下即可

以下图片为更新p6模型之后yolov5s6.onnx运行结果：
![zidane](https://user-images.githubusercontent.com/52729998/160559827-45572f7e-54e8-4653-b9be-6d287912b065.jpg)

![bus](https://user-images.githubusercontent.com/52729998/160559831-3ddf926d-b7c3-4687-bd57-26dd4d1cc055.jpg)
