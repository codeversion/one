#include <cv.h>
#include <highgui.h>
#include <math.h>
#include <time.h>

using namespace std;

//逆时针旋转图像degree角度（原尺寸）
void rotateImage(IplImage* img, IplImage *img_rotate, int degree);

//旋转图像内容不变，尺寸相应变大
IplImage* rotateImage1(IplImage* img, int degree);

//旋转图像内容不变，尺寸相应变大
IplImage* rotateImage2(IplImage* img, int degree);

IplImage * FitRotate(IplImage* Img_old, double angle);