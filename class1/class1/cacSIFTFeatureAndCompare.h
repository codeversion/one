#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <iostream>

using namespace std;



// ����ͼ���SIFT������ƥ��
float cacSIFTFeatureAndCompare(cv::Mat srcImage1,
    cv::Mat srcImage2, float paraHessian)
{
    CV_Assert(srcImage1.data != NULL && srcImage2.data != NULL);//�쳣����������ʽΪfalse �򷵻�һ��������Ϣ ����ֹ����
    // ת��Ϊ�Ҷ�
    cv::Mat grayMat1, grayMat2;
    cv::cvtColor(srcImage1, grayMat1, CV_RGB2GRAY);
    cv::cvtColor(srcImage2, grayMat2, CV_RGB2GRAY);
    // ��ʼ��SURF���������
    cv::SurfFeatureDetector surfDetector(paraHessian);
    cv::SurfDescriptorExtractor surfExtractor;
    // �ؼ��㼰����������������
    vector<cv::KeyPoint> keyPoints1, keyPoints2;
    cv::Mat descriptorMat1, descriptorMat2;
    // ����surf�����ؼ���
    surfDetector.detect(grayMat1, keyPoints1);
    surfDetector.detect(grayMat2, keyPoints2);
    // ����surf������������
    surfExtractor.compute(grayMat1, keyPoints1, descriptorMat1);
    surfExtractor.compute(grayMat2, keyPoints2, descriptorMat2);
    float result = 0;
    // ������ƥ��
    if (keyPoints1.size() > 0 && keyPoints2.size() > 0)
    {
        // ��������ƥ���
        cv::FlannBasedMatcher matcher;
        vector< cv::DMatch > matches;
        std::vector<cv::DMatch> viewMatches;
        matcher.match(descriptorMat1, descriptorMat2, matches);
        // ����ƥ���ж�
        double minDist = 100;
        for (int i = 0; i < matches.size(); i++)
        {
            if (matches[i].distance < minDist)
                minDist = matches[i].distance;
        }
        // ���������������Ҫ���������
        int num = 0;
        std::cout << "minDist: " << minDist << std::endl;
        for (int i = 0; i < matches.size(); i++)
        {
            // ������ƥ������ж�
            if (matches[i].distance <= 2 * minDist)
            {
                result += matches[i].distance * matches[i].distance;
                viewMatches.push_back(matches[i]);
                num++;
            }
        }
        // ƥ��ȼ���
        result /= num;
        // ����������ƥ����
        cv::Mat matchMat;
        cv::drawMatches(srcImage1, keyPoints1,
            srcImage2, keyPoints2, matches, matchMat);
        //cv::imshow("matchMat", matchMat);
        cv::waitKey(0);
    }
    return result;
}