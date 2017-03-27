#include <iostream>  
#include <thread>
#include "Array_max.h"
#include "TeacherStudent.h"
#include "Constructed_Destructor.h"
#include "List.h"
#include "AdaptiveFindThreshold.h"
#include "AutoContrast_Hist.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;


//(1/2)Constructed_Destructor.h���Թ��캯��ԭ������ȫ����ʹ�ö����ǣ������졣�����ڶ�����ù���ֻ��һ��
Test m(100);

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

    ////4.�������18�в���
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

    ////5.����Ӧ��Ե���
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


    //6.����Ӧ��ֵ��
    for (int i = 1; i < 16; i++)
    {
        char filename[500];
        sprintf(filename, "D:\\�����ļ�\\1224\\ZM0918\\srcimg%d.bmp", i);
        IplImage*img = cvLoadImage(filename, -1);
        //����
        AutoContrast_Hist2(img, 0.5, 0.5);
        cvReleaseImage(&img);
    }










    //cin.get();//�����س��������������е�
    system("pause");
    return 0;
}

