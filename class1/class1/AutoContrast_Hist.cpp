#include "AutoContrast_Hist.h"

//三通道
long FindMinMaxVal(int nPixelNum, int nArr[], int nArrSize, int &nMin, int &nMax, double dLowCut, double dHighCut)
{
    if (nArrSize < 1)
        return 0;

    int nSum = 0;
    int i = 0;
    for (i = 0; i < 256; i++)
    {
        nSum = nSum + nArr[i];
        if (nSum >= nPixelNum*dLowCut*0.01)
        {
            nMin = i;
            break;
        }
    }

    nSum = 0;
    for (i = 255; i >= 0; i--)
    {
        nSum = nSum + nArr[i];
        if (nSum >= nPixelNum*dHighCut*0.01)
        {
            nMax = i;
            break;
        }
    }

    return 1;
}
long AutoContrast_Hist(IplImage *img, double dLowCut, double dHighCut)
{
    if (NULL == img || img->nChannels != 3)
        return 0;

    //double dLowCut = 0.2;
    //double dHighCut = 0.2;

    int i = 0;
    int j = 0;
    int n = 0;
    int nBands = img->nChannels;
    IplImage **pImgArr = new IplImage *[nBands];
    for (i = 0; i < nBands; ++i)
    {
        pImgArr[i] = cvCreateImage(cvGetSize(img), img->depth, 1);
    }
    cvSplit(img, pImgArr[0], pImgArr[1], pImgArr[2], NULL);

    int nHist[3][256];
    memset(nHist, 0, sizeof(nHist));

    //统计各个像素值对应的像素数量
    for (i = 0; i < img->height; ++i)
    {
        for (j = 0; j < img->width; ++j)
        {
            for (n = 0; n < nBands; ++n)
            {
                nHist[n][CV_IMAGE_ELEM(pImgArr[n], uchar, i, j)]++;
            }
        }
    }

    //寻找各波段最大值和最小值
    vector<int> vcMin;
    vector<int> vcMax;
    int nMin = 0, nMax = 0;
    for (n = 0; n < nBands; ++n)
    {
        nMin = 0, nMax = 0;
        if (FindMinMaxVal(img->height * img->width, nHist[n], 256, nMin, nMax, dLowCut, dHighCut) < 1)
            continue;

        vcMin.push_back(nMin);
        vcMax.push_back(nMax);
    }

    if (vcMin.empty())
        nMin = 0;
    else
    {
        sort(vcMin.begin(), vcMin.end());
        nMin = vcMin.front();
    }
    if (vcMax.empty())
        nMax = 255;
    else
    {
        sort(vcMax.begin(), vcMax.end());
        nMax = vcMax.back();
    }

    if (nMin >= nMax)
        return 1;

    //建立映射表
    int nMap[256];
    for (i = 0; i < 256; ++i)
    {
        if (i <= nMin)
            nMap[i] = 0;
        else if (i > nMax)
            nMap[i] = 255;
        else
            nMap[i] = float(i - nMin) / (nMax - nMin) * 255.0;
    }

    //
    for (i = 0; i < img->height; ++i)
    {
        for (j = 0; j < img->width; ++j)
        {
            for (n = 0; n < nBands; ++n)
            {
                CV_IMAGE_ELEM(pImgArr[n], uchar, i, j) = nMap[CV_IMAGE_ELEM(pImgArr[n], uchar, i, j)];
            }
        }
    }

    cvMerge(pImgArr[0], pImgArr[1], pImgArr[2], NULL, img);

    cvReleaseImage(pImgArr);
}
//单通道
long FindMinMaxVal2(int nPixelNum, int nArr[], int nArrSize, int &nMin, int &nMax, double dLowCut, double dHighCut)
{
    if (nArrSize < 1)
        return 0;

    int nSum = 0;
    int i = 0;
    for (i = 0; i < 256; i++)
    {
        nSum = nSum + nArr[i];
        if (nSum >= nPixelNum*dLowCut*0.01)
        {
            nMin = i;
            break;
        }
    }

    nSum = 0;
    for (i = 255; i >= 0; i--)
    {
        nSum = nSum + nArr[i];
        if (nSum >= nPixelNum*dHighCut*0.01)
        {
            nMax = i;
            break;
        }
    }

    return 1;
}
long AutoContrast_Hist2(IplImage *img, double dLowCut, double dHighCut)
{
    if (NULL == img || img->nChannels != 1)
        return 0;

    int i = 0;
    int j = 0;
    int n = 0;

    int nHist[256];
    memset(nHist, 0, sizeof(nHist));

    for (i = 0; i < img->height; ++i)
    {
        for (j = 0; j < img->width; ++j)
        {

            nHist[CV_IMAGE_ELEM(img, uchar, i, j)]++;

        }
    }

    int nMin = 0, nMax = 0;
    FindMinMaxVal(img->height * img->width, nHist, 256, nMin, nMax, dLowCut, dHighCut);
    if (nMin >= nMax)
        return 1;

    int nMap[256];
    for (i = 0; i < 256; ++i)
    {
        if (i <= nMin)
            nMap[i] = 0;
        else if (i > nMax)
            nMap[i] = 255;
        else
            nMap[i] = float(i - nMin) / (nMax - nMin) * 255.0;
    }

    for (i = 0; i < img->height; ++i)
    {
        for (j = 0; j < img->width; ++j)
        {
            CV_IMAGE_ELEM(img, uchar, i, j) = nMap[CV_IMAGE_ELEM(img, uchar, i, j)];
        }
    }
    return 2;
}