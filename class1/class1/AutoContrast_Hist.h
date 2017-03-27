#include <opencv2/opencv.hpp>  
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/legacy/legacy.hpp"
#include "stdio.h"
#include <time.h>
#include <vector>

using namespace std;

//三通道
long FindMinMaxVal(int nPixelNum, int nArr[], int nArrSize, int &nMin, int &nMax, double dLowCut, double dHighCut);
long AutoContrast_Hist(IplImage *img, double dLowCut, double dHighCut);
//单通道
long FindMinMaxVal2(int nPixelNum, int nArr[], int nArrSize, int &nMin, int &nMax, double dLowCut, double dHighCut);
long AutoContrast_Hist2(IplImage *img, double dLowCut, double dHighCut);