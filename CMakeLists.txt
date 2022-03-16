cmake_minimum_required(VERSION 2.8)
project( YOLO5 )
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package( OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "-g")

add_executable( yolo5_detector main.cpp yolo.cpp)
target_link_libraries(yolo5_detector  ${OpenCV_LIBS} )