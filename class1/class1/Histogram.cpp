#include "Histogram.h"

//����һ  δʹ��OpenCVֱ��ͼ����
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
//������  ����OpenCV����
void DrawHistogram(IplImage* gray_plane)
{
    int hist_size = 256;    //ֱ��ͼ�ߴ�  
    int hist_height = 256;
    float range[] = { 0, 255 };  //�Ҷȼ��ķ�Χ  
    float* ranges[] = { range };
    //����һάֱ��ͼ��ͳ��ͼ����[0 255]���صľ��ȷֲ�    CV_HIST_ARRAY ��ζ��ֱ��ͼ���ݱ�ʾΪ��ά�ܼ����� CvMatND
    CvHistogram* gray_hist = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, ranges, 1);
    //����Ҷ�ͼ���һάֱ��ͼ  
    cvCalcHist(&gray_plane, gray_hist, 0, 0);
    //��һ��  ʹ�����п�֮�͵���factor
    cvNormalizeHist(gray_hist, 1.0);

    double scale = 5;
    //����һ��һάֱ��ͼ�ġ�ͼ����������Ϊ�Ҷȼ���������Ϊ���ظ�����*scale��  
    IplImage* hist_image = cvCreateImage(cvSize(hist_size*scale, hist_height), 8, 3);

    cvZero(hist_image);

    //��ȡֱ��ͼ���ֵ
    float max_value = 0;
    cvGetMinMaxHistValue(gray_hist, 0, &max_value, 0, 0);

    //����
    for (int i = 0; i < hist_size; i++)
    {
        float bin_val = cvQueryHistValue_1D(gray_hist, i);  //��ѯֱ�����ֵ
        int intensity = cvRound(bin_val*hist_height / max_value);  //��������ֵ�ĸ߶�
        if (intensity != 0)
        {
            cvRectangle(hist_image,
                cvPoint(i*scale, hist_height - 1),
                cvPoint((i + 1)*scale - 1, hist_height - intensity),

                cvScalar(255, 255, 255),
                -1,//�������  �����߶δ�ϸ 
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