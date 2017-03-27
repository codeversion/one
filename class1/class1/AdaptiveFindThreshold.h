#ifndef _ADAPTIVEFINDTHRESHOLD_H_
#define _ADAPTIVEFINDTHRESHOLD_H_

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
using namespace cv;



// 仿照matlab，自适应求高低两个门限                                            
void _AdaptiveFindThreshold(CvMat *dx, CvMat *dy, double *low, double *high);

void AdaptiveFindThreshold(const CvArr* image, double *low, double *high, int aperture_size = 3);


#endif