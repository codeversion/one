#include <iostream>  
#include <thread>
#include "Array_max.h"
#include "TeacherStudent.h"
#include "Constructed_Destructor.h"
using namespace std;


//(1/2)测试构造函数原理，当在全局中使用对象是，都构造。函数内对象调用构造只有一次
Test m(100);

int main2(){


    //最简单类方法示例，多线程示例
    //Array_max array1;
    //thread trd1([&array1]{
    //    array1.max_value();
    //});
    //thread trd2(mem_fn(&Array_max::show_test), &array1, 1);//如果没有参数 直接不写
    //trd1.join();
    //trd2.join();


    //构造函数析构函数示例  一个类对象是另外一类的数据成员的情况
    Student a;
    a.show();
    Student b[3];
    for (int i = 0; i < sizeof(b) / sizeof(Student); i++)
    {
        b[i].show();
    }
    

    //(2/2)测试构造函数原理，当在全局中使用对象是，都构造。函数内对象调用构造只有一次
    fun_t(20);
    fun_t(30);//这里只构造一次


    cin.get();//保留回车在输入流队列中的

    //system("pause");
    return 0;
}


