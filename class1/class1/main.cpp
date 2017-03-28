#include <iostream>  
#include <thread>
#include "Array_max.h"
#include "TeacherStudent.h"
#include "Constructed_Destructor.h"
#include "List.h"
#include "AdaptiveFindThreshold.h"
#include "AutoContrast_Hist.h"
#include "Histogram.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;


//(1/2)Constructed_Destructor.h���Թ��캯��ԭ������ȫ����ʹ�ö����ǣ������졣�����ڶ�����ù���ֻ��һ��
//Test m(100);

int main(){
    ////1.Array_max.h����෽��ʾ�������Ա�������߳�ʾ��
    //Array_max array1;
    //thread trd1([&array1]{
    //    array1.max_value();
    //});
    //thread trd2(mem_fn(&Array_max::show_test), &array1, 1);//���û�в��� ֱ�Ӳ�д
    //trd1.join();
    //trd2.join();

    ////2.TeacherStudent.h���캯����������ʾ��  һ�������������һ������ݳ�Ա�����
    //Student a;
    //a.show();
    //Student b[3];
    //for (int i = 0; i < sizeof(b) / sizeof(Student); i++)
    //{
    //    b[i].show();
    //}
    
    ////3.(2/2)Constructed_Destructor.h���Թ��캯��ԭ������ȫ����ʹ�ö����ǣ������졣�����ڶ�����ù���ֻ��һ��
    //fun_t(20);
    //fun_t(30);//����ֻ����һ��

    ////4.List.h�������18�в���
    //Node *pList = NULL;
    //int length = 0;
    //elemType posElem;
    ////�����ʼ��
    //initList(&pList);      
    ////����������ӡ����
    //printList(pList);      
    ////��������
    //pList = creatList(pList); 
    //printList(pList);
    ////����ĳ���
    //sizeList(pList);        
    //printList(pList);
    ////�ж������Ƿ�Ϊ������
    //isEmptyList(pList);     
    ////��ȡ������Ԫ�أ����Ԫ�ز���3�����򷵻�0
    //posElem = getElement(pList, 3); 
    //printf("getElement����ִ�У�λ�� 3 �е�Ԫ��Ϊ %d\n", posElem);
    //printList(pList);
    ////���Ԫ��5�ĵ�ַ
    //getElemAddr(pList, 5);   
    ////��������λ��4�ϵ�Ԫ���޸�Ϊ1
    //modifyElem(pList, 4, 1);  
    //printList(pList);
    ////��ͷ����Ԫ��12
    //insertHeadList(&pList, 5);   
    //printList(pList);
    ////��β����Ԫ��10
    //insertLastList(&pList, 10);  
    //printList(pList);
    ////�������
    //clearList(pList);       

    ////5.AdaptiveFindThreshold.h����Ӧ��Ե���
    //char buf[256] = { 0 };
    //for (int i = 1; i < 19; i++)
    //{
    //    memset(buf, 0, 256);
    //    //sprintf_s(buf, "F:\\ֽ�ܲ���ͼ\\1119����ѡͼ\\��ͼ\\%d.bmp", i); 
    //    sprintf_s(buf, "F:\\ֽ�ܲ���ͼ\\ֽ���㷨1021\\�������ץ��ͼ�⣨10_17��\\����ͼƬ��\\%d\\%d.bmp", i, i);
    //    IplImage *src = cvLoadImage(buf);
    //    if (!src)
    //    {
    //        cout << "Can not load image " << i << endl;
    //        continue;
    //    }
    //    IplImage* grayImg = cvCreateImage(cvGetSize(src), 8, 1);
    //    cvCvtColor(src, grayImg, CV_RGB2GRAY);
    //    //����
    //    IplImage *out = cvCloneImage(grayImg);
    //    double low = 0.0, high = 0.0;
    //    AdaptiveFindThreshold(src, &low, &high);
    //    cvCanny(src, out, low, high);
    //    //����
    //    cvReleaseImage(&src);
    //    cvReleaseImage(&out);
    //}


    ////6.AutoContrast_Hist.h����Ӧ��ֵ��
    //for (int i = 1; i < 16; i++)
    //{
    //    char filename[500];
    //    sprintf(filename, "D:\\�����ļ�\\1224\\ZM0918\\srcimg%d.bmp", i);
    //    IplImage*img = cvLoadImage(filename, -1);
    //    //����
    //    AutoContrast_Hist2(img, 0.5, 0.5);
    //    cvReleaseImage(&img);
    //}

    ////7.ֱ��ͼƥ��  û��д�ɵ����ļ�
    //IplImage * image = cvLoadImage("G:\\screen1.bmp");
    //IplImage * templateImg = cvLoadImage("F:\\save\\MuCurImage1.bmp");
    ////
    //int hist_size = 256;
    //float range[] = { 0, 255 };
    //float* ranges[] = { range };
    ////
    //IplImage* gray_plane = cvCreateImage(cvGetSize(image), 8, 1);
    //cvCvtColor(image, gray_plane, CV_BGR2GRAY);
    //CvHistogram* gray_hist = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, ranges, 1);
    //cvCalcHist(&gray_plane, gray_hist, 0, 0);
    ////
    //IplImage* gray_plane2 = cvCreateImage(cvGetSize(templateImg), 8, 1);
    //cvCvtColor(templateImg, gray_plane2, CV_BGR2GRAY);
    ////
    //double r = 0;
    //int row = 0;
    //int col = 0;
    //for (int i = 0; i < templateImg->height; i++)//for (int i = 0; i < templateImg->height; i++)
    //{
    //    for (int j = 3300; j < 3800; j++)//for (int j = 3300; j < 3800; j++)
    //    {
    //        CvRect tplRect = cvRect(j, i, image->width, image->height);
    //        cvSetImageROI(gray_plane2, tplRect);
    //        //
    //        CvHistogram* gray_hist2 = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, ranges, 1);
    //        cvCalcHist(&gray_plane2, gray_hist2, 0, 0);
    //        //
    //        //��أ�CV_COMP_CORREL    
    //        //������CV_COMP_CHISQR
    //        //ֱ��ͼ�ཻ��CV_COMP_INTERSECT
    //        //Bhattacharyya���룺CV_COMP_BHATTACHARYYA
    //        double com = cvCompareHist(gray_hist, gray_hist2, CV_COMP_CORREL);
    //        //
    //        if (com > r)
    //        {
    //            row = i;
    //            col = j;
    //            r = com;
    //        }
    //        if (com == 1)
    //        {
    //            cout << 2 << endl;
    //        }
    //    }
    //}
    //CvPoint pt1;
    //CvPoint pt2;
    //pt1 = cvPoint(col, row);
    //pt2 = cvPoint(col + image->width, row + image->height);
    //cvRectangle(templateImg, pt1, pt2, cvScalar(0, 0, 255), 1, 8, 0);
    //cout << 1 << endl;

    //����ֱ��ͼ
    IplImage * src = cvLoadImage("E:\\ֽ������\\1516ֽ�ܲ���ͼƬ\\2015ֽ�ܲ���ͼ��\\2015threeweeks\\1218ͼ��\\1\\MBImg\\MBLImage1.bmp");
    IplImage* gray_plane = cvCreateImage(cvGetSize(src), 8, 1);
    cvCvtColor(src, gray_plane, CV_BGR2GRAY);

    //����һ
    int h[256] = { 0 };
    GetHistogram(gray_plane, h);
    ShowHistogram(h);
    //������
    //DrawHistogram(gray_plane);
    




    //cin.get();//�����س��������������е�
    system("pause");
    return 0;
}

