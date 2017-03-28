#include <opencv2/opencv.hpp>  
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/legacy/legacy.hpp"
#include "stdio.h"
#include <time.h>
#include <vector>


#include <cv.h>
#include <highgui.h>
#include <iostream>
using namespace std;

//方法一  未使用OpenCV直方图函数
void GetHistogram(IplImage* A, int *h);
void ShowHistogram(int iH[]);
//方法二  采用OpenCV函数
void DrawHistogram(IplImage* gray_plane);