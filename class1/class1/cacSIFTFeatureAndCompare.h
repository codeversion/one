#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <iostream>

using namespace std;



// 计算图像的SIFT特征及匹配
float cacSIFTFeatureAndCompare(cv::Mat srcImage1,
    cv::Mat srcImage2, float paraHessian);