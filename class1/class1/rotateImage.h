#include <cv.h>
#include <highgui.h>
#include <math.h>
#include <time.h>

using namespace std;

//��ʱ����תͼ��degree�Ƕȣ�ԭ�ߴ磩
void rotateImage(IplImage* img, IplImage *img_rotate, int degree);

//��תͼ�����ݲ��䣬�ߴ���Ӧ���
IplImage* rotateImage1(IplImage* img, int degree);

//��תͼ�����ݲ��䣬�ߴ���Ӧ���
IplImage* rotateImage2(IplImage* img, int degree);

IplImage * FitRotate(IplImage* Img_old, double angle);