#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <iostream>

using namespace std;



// ����ͼ���SIFT������ƥ��
float cacSIFTFeatureAndCompare(cv::Mat srcImage1,
    cv::Mat srcImage2, float paraHessian);