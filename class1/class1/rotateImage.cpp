#include "rotateImage.h"

//��ʱ����תͼ��degree�Ƕȣ�ԭ�ߴ磩
void rotateImage(IplImage* img, IplImage *img_rotate, int degree)
{
    //��ת����Ϊͼ������
    CvPoint2D32f center;
    center.x = float(img->width / 2.0 + 0.5);
    center.y = float(img->height / 2.0 + 0.5);
    //�����ά��ת�ķ���任����
    float m[6];
    CvMat M = cvMat(2, 3, CV_32F, m);
    cv2DRotationMatrix(center, degree, 1, &M);
    //�任ͼ�񣬲��ú�ɫ�������ֵ
    cvWarpAffine(img, img_rotate, &M, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll(0));
}



//��תͼ�����ݲ��䣬�ߴ���Ӧ���
IplImage* rotateImage1(IplImage* img, int degree){
    double angle = degree  * CV_PI / 180.; // ����  
    double a = sin(angle), b = cos(angle);
    int width = img->width;
    int height = img->height;
    int width_rotate = int(height * fabs(a) + width * fabs(b));
    int height_rotate = int(width * fabs(a) + height * fabs(b));
    //��ת����map
    // [ m0  m1  m2 ] ===>  [ A11  A12   b1 ]
    // [ m3  m4  m5 ] ===>  [ A21  A22   b2 ]
    float map[6];
    CvMat map_matrix = cvMat(2, 3, CV_32F, map);
    // ��ת����
    CvPoint2D32f center = cvPoint2D32f(width / 2, height / 2);
    cv2DRotationMatrix(center, degree, 1.0, &map_matrix);
    map[2] += (width_rotate - width) / 2;
    map[5] += (height_rotate - height) / 2;
    IplImage* img_rotate = cvCreateImage(cvSize(width_rotate, height_rotate), 8, 3);
    //��ͼ��������任
    //CV_WARP_FILL_OUTLIERS - ����������ͼ������ء�
    //�������������������ͼ��ı߽��⣬��ô���ǵ�ֵ�趨Ϊ fillval.
    //CV_WARP_INVERSE_MAP - ָ�� map_matrix �����ͼ������ͼ��ķ��任��
    cvWarpAffine(img, img_rotate, &map_matrix, CV_INTER_LINEAR | CV_WARP_FILL_OUTLIERS, cvScalarAll(0));
    return img_rotate;
}



//��תͼ�����ݲ��䣬�ߴ���Ӧ���
IplImage* rotateImage2(IplImage* img, int degree)
{
    double angle = degree  * CV_PI / 180.;
    double a = sin(angle), b = cos(angle);
    int width = img->width, height = img->height;
    //��ת�����ͼ�ߴ�
    int width_rotate = int(height * fabs(a) + width * fabs(b));
    int height_rotate = int(width * fabs(a) + height * fabs(b));
    //IplImage* img_rotate = cvCreateImage(cvSize(width_rotate, height_rotate), img->depth, img->nChannels);

    IplImage* img_rotate = cvCreateImage(cvGetSize(img), img->depth, img->nChannels);

    cvZero(img_rotate);
    //��֤ԭͼ��������Ƕ���ת����С�ߴ�
    int tempLength = sqrt((double)width * width + (double)height *height) + 10;
    int tempX = (tempLength + 1) / 2 - width / 2;
    int tempY = (tempLength + 1) / 2 - height / 2;
    IplImage* temp = cvCreateImage(cvSize(tempLength, tempLength), img->depth, img->nChannels);
    cvZero(temp);
    //��ԭͼ���Ƶ���ʱͼ��tmp����
    cvSetImageROI(temp, cvRect(tempX, tempY, width, height));
    cvCopy(img, temp, NULL);
    cvResetImageROI(temp);
    //��ת����map
    // [ m0  m1  m2 ] ===>  [ A11  A12   b1 ]
    // [ m3  m4  m5 ] ===>  [ A21  A22   b2 ]

    //float m[6];
    //int w = temp->width;
    //int h = temp->height;
    //m[0] = b;
    //m[1] = a;
    //m[3] = -m[1];
    //m[4] = m[0];
    //// ����ת��������ͼ���м�  
    //m[2] = w * 0.5f; 
    //m[5] = h * 0.5f;
    //CvMat M = cvMat(2, 3, CV_32F, m);


    float m[6];

    CvMat M = cvMat(2, 3, CV_32F, m);
    int w = img->width;
    int h = img->height;

    //int w = temp->width;
    //int h = temp->height;

    m[0] = (float)(cos(degree*CV_PI / 180.));
    m[1] = (float)(sin(degree*CV_PI / 180.));
    m[2] = w*0.5f;
    m[3] = -m[1];
    m[4] = m[0];
    m[5] = h*0.5f;



    cvGetQuadrangleSubPix(img, img_rotate, &M);
    cvReleaseImage(&temp);
    return img_rotate;
}


IplImage * FitRotate(IplImage* Img_old, double angle)
{

    IplImage* Img_tmp = NULL;

    double anglerad = (CV_PI* (angle / 180));
    int newheight = int(fabs((sin(anglerad)*Img_old->width)) + fabs((cos(anglerad)*Img_old->height)));
    int newwidth = int(fabs((sin(anglerad)*Img_old->height)) + fabs((cos(anglerad)*Img_old->width)));

    Img_tmp = cvCreateImage(cvSize(newwidth, newheight), IPL_DEPTH_8U, 3);
    cvFillImage(Img_tmp, 0);//Ŀ��ͼ�� ʹ����չ�Ĵ�С

    //IplImage* dst = cvCloneImage(Img_old);//Ŀ��ͼ�� ��ԭͼ��ȴ�  
    IplImage* dst = cvCreateImage(cvGetSize(Img_old), Img_old->depth, Img_old->nChannels);
    cvZero(dst);

    float m[6];
    CvMat M = cvMat(2, 3, CV_32F, m);

    //����һ  ��ȡ�����ı��Σ�ʹ�������ؾ���

    int w = Img_old->width;
    int h = Img_old->height;

    m[0] = (float)(cos(angle*CV_PI / 180.));
    m[1] = (float)(sin(angle*CV_PI / 180.));
    m[2] = w*0.5f;
    m[3] = -m[1];
    m[4] = m[0];
    m[5] = h*0.5f;

    cvGetQuadrangleSubPix(Img_old, dst, &M);//, 1, cvScalarAll(0)

    //cvGetQuadrangleSubPix(Img_old, Img_tmp, &M);//+CV_WARP_FILL_OUTLIERS  , CV_INTER_LINEAR, cvScalarAll(0)

    return dst;
}