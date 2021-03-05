# Face Detector
Face Detection using OpenCV with C++. This program can detect faces from image and webcam live video feed.

* Requirement: C++ compiler (preferably GNU Compiler) & OpenCV needs to be installed in your PC. Webcam or similar device is needed for face detection from live 
video.

![Face Detection](https://github.com/SdAm1n/Face-Detector/blob/main/resources/sample.png?raw=true)

### How to run on Linux
* Using the makefile

1. open terminal in project directory
2. use the following command:

```
$ make
$ ./'Face Detector'
```
3. To clean the object files and build the project again from scratch use command  
```
$ make clean
```

* Without using makefile : can use the following commands to compile the project :
```
$ g++ filename.cpp -o filename `pkg-config --cflags --libs opencv4`
$ ./filename 
```
### How to run on Windows
```
$ g++ filename.cpp -o filename `pkg-config --cflags --libs opencv4`
$ filename or $ filename.exe
```

