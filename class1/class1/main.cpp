#include <iostream>  
#include <thread>
#include "Array_max.h"
#include "TeacherStudent.h"
#include "Constructed_Destructor.h"
#include "List.h"
#include "AdaptiveFindThreshold.h"
#include "AutoContrast_Hist.h"
#include "Histogram.h"
#include "cacSIFTFeatureAndCompare.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;


//(1/2)Constructed_Destructor.h测试构造函数原理，当在全局中使用对象是，都构造。函数内对象调用构造只有一次
//Test m(100);

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

    ////4.List.h单链表的18中操作
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

    ////5.AdaptiveFindThreshold.h自适应边缘检测
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


    ////6.AutoContrast_Hist.h自适应二值化
    //for (int i = 1; i < 16; i++)
    //{
    //    char filename[500];
    //    sprintf(filename, "D:\\工作文件\\1224\\ZM0918\\srcimg%d.bmp", i);
    //    IplImage*img = cvLoadImage(filename, -1);
    //    //调用
    //    AutoContrast_Hist2(img, 0.5, 0.5);
    //    cvReleaseImage(&img);
    //}

    ////7.直方图匹配  没有写成单独文件
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
    //        //相关：CV_COMP_CORREL    
    //        //卡方：CV_COMP_CHISQR
    //        //直方图相交：CV_COMP_INTERSECT
    //        //Bhattacharyya距离：CV_COMP_BHATTACHARYYA
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

    ////8.Histogram.h生成直方图
    //IplImage * src = cvLoadImage("E:\\纸管资料\\1516纸管测试图片\\2015纸管测试图库\\2015threeweeks\\1218图库\\1\\MBImg\\MBLImage1.bmp");
    //IplImage* gray_plane = cvCreateImage(cvGetSize(src), 8, 1);
    //cvCvtColor(src, gray_plane, CV_BGR2GRAY);
    ////方法一
    //int h[256] = { 0 };
    //GetHistogram(gray_plane, h);
    //ShowHistogram(h);
    ////方法二
    ////DrawHistogram(gray_plane);
    
    ////9.将图片序列合成视频//没有写单独文件
    ////显示数字的视频
    //Size s(320, 240);
    //VideoWriter writer = VideoWriter("myvideo.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25, s);
    //Mat frame(s, CV_8UC3);
    //for (int i = 0; i < 100; i++)
    //{
    //	frame = Scalar::all(0);
    //	//char text[128] = "阿德斯防守对方";//不能putText中文
    //	char text[128] = {0};
    //	//printf(text, sizeof(text), "%d", i);//不清楚用意
    //	
    //	sprintf_s(text, "%d", i);   //sprintf(str_i,"%d",(i+1));
    //	
    //	//void putText(Mat& img, const string& text, Point org, int fontFace, double fontScale, Scalar color, int thickness=1, int lineType=8, bool bottomLeftOrigin=false )
    //	putText(frame, text, Point(s.width / 3, s.height / 3), FONT_HERSHEY_SCRIPT_SIMPLEX, 3, Scalar(0, 0, 255),2,1);  //CV_FONT_HERSHEY_COMPLEX  , 3,  8  FONT_HERSHEY_SCRIPT_SIMPLEX
    //	writer << frame;
    //}

    //10.cacSIFTFeatureAndCompare.h计算图像的SIFT特征及匹配
    // 读取源图像及待匹配图像
    cv::Mat srcImage1 =
    cv::imread("F:\\20160427新算法测试\\kernel2.bmp", 1);
    if (srcImage1.empty())
    return -1;
    cv::Mat srcImage2 =
    cv::imread("F:\\20160427新算法测试\\kernel2.bmp", 1);
    if (srcImage2.empty())
    return -1;
    double time = (double)cvGetTickCount();
    float matchRate = cacSIFTFeatureAndCompare(srcImage1, srcImage2, 1000);
    time = ((double)cvGetTickCount() - time) / (cvGetTickFrequency() * 1000);
    cout << "运行时间: " << time << "ms" << endl;
    std::cout << "matchRate: " << matchRate << std::endl;




    //cin.get();//保留回车在输入流队列中的
    system("pause");
    return 0;
}

