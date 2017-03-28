#include "Histogram.h"

//方法一  未使用OpenCV直方图函数
void GetHistogram(IplImage* A, int *h)
{
    int hei = A->height;
    int wid = A->width;
    //int h[256] = { 0 };
    vector <int> vHighPoint;

    for (int i = 0; i < hei; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            for (int k = 0; k < 256; k++)
            {
                if (((uchar*)(A->imageData + A->widthStep*i))[j] == k)
                {
                    h[k]++;
                }
            }
        }
    }
    //ShowHistogram(h);
}
void ShowHistogram(int iH[])
{
    IplImage *HistogramImg = cvCreateImage(cvSize(256, 100), IPL_DEPTH_8U, 1);
    cvZero(HistogramImg);
    int iMaxValue = 0;
    for (int i = 0; i < 256; i++)
    {
        if (iMaxValue < iH[i])
            iMaxValue = iH[i];
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            int iTmp = 100 - iH[j] * 100 / iMaxValue;
            if (i < iTmp)
                ((uchar*)(HistogramImg->imageData + 256 * i))[j] = 255;
        }
    }
    cvReleaseImage(&HistogramImg);
}
//方法二  采用OpenCV函数
void DrawHistogram(IplImage* gray_plane)
{
    int hist_size = 256;    //直方图尺寸  
    int hist_height = 256;
    float range[] = { 0, 255 };  //灰度级的范围  
    float* ranges[] = { range };
    //创建一维直方图，统计图像在[0 255]像素的均匀分布    CV_HIST_ARRAY 意味着直方图数据表示为多维密集数组 CvMatND
    CvHistogram* gray_hist = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, ranges, 1);
    //计算灰度图像的一维直方图  
    cvCalcHist(&gray_plane, gray_hist, 0, 0);
    //归一化  使得所有块之和等于factor
    cvNormalizeHist(gray_hist, 1.0);

    double scale = 5;
    //创建一张一维直方图的“图”，横坐标为灰度级，纵坐标为像素个数（*scale）  
    IplImage* hist_image = cvCreateImage(cvSize(hist_size*scale, hist_height), 8, 3);

    cvZero(hist_image);

    //获取直方图最大值
    float max_value = 0;
    cvGetMinMaxHistValue(gray_hist, 0, &max_value, 0, 0);

    //绘制
    for (int i = 0; i < hist_size; i++)
    {
        float bin_val = cvQueryHistValue_1D(gray_hist, i);  //查询直方块的值
        int intensity = cvRound(bin_val*hist_height / max_value);  //相对于最大值的高度
        if (intensity != 0)
        {
            cvRectangle(hist_image,
                cvPoint(i*scale, hist_height - 1),
                cvPoint((i + 1)*scale - 1, hist_height - intensity),

                cvScalar(255, 255, 255),
                -1,//负数填充  整数线段粗细 
                8,
                0);
        }
    }
    cvNamedWindow("GraySource", 1);
    cvShowImage("GraySource", gray_plane);
    cvNamedWindow("H-S Histogram", 1);
    cvShowImage("H-S Histogram", hist_image);

    cvWaitKey(0);
}