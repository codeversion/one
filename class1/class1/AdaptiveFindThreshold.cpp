#include "AdaptiveFindThreshold.h"

// ����matlab������Ӧ��ߵ���������                                            
void _AdaptiveFindThreshold(CvMat *dx, CvMat *dy, double *low, double *high)
{
    CvSize size;
    IplImage *imge = 0;
    int i, j;
    CvHistogram *hist;
    int hist_size = 255;
    float range_0[] = { 0, 256 };
    float* ranges[] = { range_0 };
    double PercentOfPixelsNotEdges = 0.7;
    size = cvGetSize(dx);
    imge = cvCreateImage(size, IPL_DEPTH_32F, 1);
    // �����Ե��ǿ��, ������ͼ����                                        
    float maxv = 0;
    for (i = 0; i < size.height; i++)
    {
        const short* _dx = (short*)(dx->data.ptr + dx->step*i);
        const short* _dy = (short*)(dy->data.ptr + dy->step*i);
        float* _image = (float *)(imge->imageData + imge->widthStep*i);
        for (j = 0; j < size.width; j++)
        {
            _image[j] = (float)(abs(_dx[j]) + abs(_dy[j]));
            maxv = maxv < _image[j] ? _image[j] : maxv;

        }
    }
    if (maxv == 0){
        *high = 0;
        *low = 0;
        cvReleaseImage(&imge);
        return;
    }

    // ����ֱ��ͼ                                                          
    range_0[1] = maxv;
    hist_size = (int)(hist_size > maxv ? maxv : hist_size);
    hist = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, ranges, 1);
    cvCalcHist(&imge, hist, 0, NULL);
    int total = (int)(size.height * size.width * PercentOfPixelsNotEdges);
    float sum = 0;
    int icount = hist->mat.dim[0].size;

    float *h = (float*)cvPtr1D(hist->bins, 0);
    for (i = 0; i < icount; i++)
    {
        sum += h[i];
        if (sum > total)
            break;
    }
    // ����ߵ�����                                                        
    *high = (i + 1) * maxv / hist_size;
    *low = *high * 0.4;
    cvReleaseImage(&imge);
    cvReleaseHist(&hist);
}

void AdaptiveFindThreshold(const CvArr* image, double *low, double *high, int aperture_size = 3)
{
    cv::Mat src = cv::cvarrToMat(image);//��cvArrתΪMat����
    const int cn = src.channels();
    cv::Mat dx(src.rows, src.cols, CV_16SC(cn));//16λ�з�������
    cv::Mat dy(src.rows, src.cols, CV_16SC(cn));

    //Sobel(src, dx, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);

    cv::Sobel(src, dx, CV_16S, 1, 0, aperture_size, 1, 0, BORDER_DEFAULT);  //cv::BORDER_REPLIC
    cv::Sobel(src, dy, CV_16S, 0, 1, aperture_size, 1, 0, BORDER_DEFAULT);  //������sobel���Ӽ�����ˮƽ�ʹ�ֱ����������ݶ�ǿ��

    CvMat _dx = dx, _dy = dy;
    _AdaptiveFindThreshold(&_dx, &_dy, low, high);

}