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


//(1/2)Constructed_Destructor.h测试构造函数原理，当在全局中使用对象是，都构造。函数内对象调用构造只有一次
Test m(100);

int main(){
    ////1.Array_max.h最简单类方法示例，类成员函数多线程示例
    //Array_max array1;
    //thread trd1([&array1]{
    //    array1.max_value();
    //});
    //thread trd2(mem_fn(&Array_max::show_test), &array1, 1);//如果没有参数 直接不写
    //trd1.join();
    //trd2.join();

    ////2.TeacherStudent.h构造函数析构函数示例  一个类对象是另外一类的数据成员的情况
    //Student a;
    //a.show();
    //Student b[3];
    //for (int i = 0; i < sizeof(b) / sizeof(Student); i++)
    //{
    //    b[i].show();
    //}
    
    ////3.(2/2)Constructed_Destructor.h测试构造函数原理，当在全局中使用对象是，都构造。函数内对象调用构造只有一次
    //fun_t(20);
    //fun_t(30);//这里只构造一次

    ////4.单链表的18中操作
    //Node *pList = NULL;
    //int length = 0;
    //elemType posElem;
    ////链表初始化
    //initList(&pList);      
    ////遍历链表，打印链表
    //printList(pList);      
    ////创建链表
    //pList = creatList(pList); 
    //printList(pList);
    ////链表的长度
    //sizeList(pList);        
    //printList(pList);
    ////判断链表是否为空链表
    //isEmptyList(pList);     
    ////获取第三个元素，如果元素不足3个，则返回0
    //posElem = getElement(pList, 3); 
    //printf("getElement函数执行，位置 3 中的元素为 %d\n", posElem);
    //printList(pList);
    ////获得元素5的地址
    //getElemAddr(pList, 5);   
    ////将链表中位置4上的元素修改为1
    //modifyElem(pList, 4, 1);  
    //printList(pList);
    ////表头插入元素12
    //insertHeadList(&pList, 5);   
    //printList(pList);
    ////表尾插入元素10
    //insertLastList(&pList, 10);  
    //printList(pList);
    ////清空链表
    //clearList(pList);       

    ////5.自适应边缘检测
    //char buf[256] = { 0 };
    //for (int i = 1; i < 19; i++)
    //{
    //    memset(buf, 0, 256);
    //    //sprintf_s(buf, "F:\\纸管测试图\\1119破损选图\\截图\\%d.bmp", i); 
    //    sprintf_s(buf, "F:\\纸管测试图\\纸管算法1021\\线阵相机抓拍图库（10_17）\\柱面图片库\\%d\\%d.bmp", i, i);
    //    IplImage *src = cvLoadImage(buf);
    //    if (!src)
    //    {
    //        cout << "Can not load image " << i << endl;
    //        continue;
    //    }
    //    IplImage* grayImg = cvCreateImage(cvGetSize(src), 8, 1);
    //    cvCvtColor(src, grayImg, CV_RGB2GRAY);
    //    //输入
    //    IplImage *out = cvCloneImage(grayImg);
    //    double low = 0.0, high = 0.0;
    //    AdaptiveFindThreshold(src, &low, &high);
    //    cvCanny(src, out, low, high);
    //    //清理
    //    cvReleaseImage(&src);
    //    cvReleaseImage(&out);
    //}


    //6.自适应二值化
    for (int i = 1; i < 16; i++)
    {
        char filename[500];
        sprintf(filename, "D:\\工作文件\\1224\\ZM0918\\srcimg%d.bmp", i);
        IplImage*img = cvLoadImage(filename, -1);
        //调用
        AutoContrast_Hist2(img, 0.5, 0.5);
        cvReleaseImage(&img);
    }










    //cin.get();//保留回车在输入流队列中的
    system("pause");
    return 0;
}

