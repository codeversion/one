#include "cacSIFTFeatureAndCompare.h"


// 计算图像的SIFT特征及匹配
float cacSIFTFeatureAndCompare(cv::Mat srcImage1,
    cv::Mat srcImage2, float paraHessian)
{
    CV_Assert(srcImage1.data != NULL && srcImage2.data != NULL);//异常处理：如果表达式为false 则返回一个错误信息 并终止程序
    // 转换为灰度
    cv::Mat grayMat1, grayMat2;
    cv::cvtColor(srcImage1, grayMat1, CV_RGB2GRAY);
    cv::cvtColor(srcImage2, grayMat2, CV_RGB2GRAY);
    // 初始化SURF检测描述子
    cv::SurfFeatureDetector surfDetector(paraHessian);
    cv::SurfDescriptorExtractor surfExtractor;
    // 关键点及特征描述矩阵声明
    vector<cv::KeyPoint> keyPoints1, keyPoints2;
    cv::Mat descriptorMat1, descriptorMat2;
    // 计算surf特征关键点
    surfDetector.detect(grayMat1, keyPoints1);
    surfDetector.detect(grayMat2, keyPoints2);
    // 计算surf特征描述矩阵
    surfExtractor.compute(grayMat1, keyPoints1, descriptorMat1);
    surfExtractor.compute(grayMat2, keyPoints2, descriptorMat2);
    float result = 0;
    // 特征点匹配
    if (keyPoints1.size() > 0 && keyPoints2.size() > 0)
    {
        // 计算特征匹配点
        cv::FlannBasedMatcher matcher;
        vector< cv::DMatch > matches;
        std::vector<cv::DMatch> viewMatches;
        matcher.match(descriptorMat1, descriptorMat2, matches);
        // 最优匹配判断
        double minDist = 100;
        for (int i = 0; i < matches.size(); i++)
        {
            if (matches[i].distance < minDist)
                minDist = matches[i].distance;
        }
        // 计算距离特征符合要求的特征点
        int num = 0;
        std::cout << "minDist: " << minDist << std::endl;
        for (int i = 0; i < matches.size(); i++)
        {
            // 特征点匹配距离判断
            if (matches[i].distance <= 2 * minDist)
            {
                result += matches[i].distance * matches[i].distance;
                viewMatches.push_back(matches[i]);
                num++;
            }
        }
        // 匹配度计算
        result /= num;
        // 绘制特征点匹配结果
        cv::Mat matchMat;
        cv::drawMatches(srcImage1, keyPoints1,
            srcImage2, keyPoints2, matches, matchMat);
        //cv::imshow("matchMat", matchMat);
        cv::waitKey(0);
    }
    return result;
}