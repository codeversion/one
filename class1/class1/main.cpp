#include <iostream>  
#include <thread>
#include "Array_max.h"
#include "TeacherStudent.h"
#include "Constructed_Destructor.h"
#include "List.h"
using namespace std;


//(1/2)Constructed_Destructor.h测试构造函数原理，当在全局中使用对象是，都构造。函数内对象调用构造只有一次
Test m(100);

int main(){
    ////Array_max.h最简单类方法示例，类成员函数多线程示例
    //Array_max array1;
    //thread trd1([&array1]{
    //    array1.max_value();
    //});
    //thread trd2(mem_fn(&Array_max::show_test), &array1, 1);//如果没有参数 直接不写
    //trd1.join();
    //trd2.join();

    ////TeacherStudent.h构造函数析构函数示例  一个类对象是另外一类的数据成员的情况
    //Student a;
    //a.show();
    //Student b[3];
    //for (int i = 0; i < sizeof(b) / sizeof(Student); i++)
    //{
    //    b[i].show();
    //}
    
    ////(2/2)Constructed_Destructor.h测试构造函数原理，当在全局中使用对象是，都构造。函数内对象调用构造只有一次
    //fun_t(20);
    //fun_t(30);//这里只构造一次

    //单链表的18中操作
    Node *pList = NULL;
    int length = 0;

    elemType posElem;

    initList(&pList);       //链表初始化
    printList(pList);       //遍历链表，打印链表

    pList = creatList(pList); //创建链表
    printList(pList);

    sizeList(pList);        //链表的长度
    printList(pList);

    isEmptyList(pList);     //判断链表是否为空链表

    posElem = getElement(pList, 3);  //获取第三个元素，如果元素不足3个，则返回0
    printf("getElement函数执行，位置 3 中的元素为 %d\n", posElem);
    printList(pList);

    getElemAddr(pList, 5);   //获得元素5的地址
     
    modifyElem(pList, 4, 1);  //将链表中位置4上的元素修改为1
    printList(pList);

    insertHeadList(&pList, 5);   //表头插入元素12
    printList(pList);

    insertLastList(&pList, 10);  //表尾插入元素10
    printList(pList);

    clearList(pList);       //清空链表



    //cin.get();//保留回车在输入流队列中的
    system("pause");
    return 0;
}

