#include <iostream>  
#include <thread>
#include "Array_max.h"
#include "TeacherStudent.h"
#include "Constructed_Destructor.h"
using namespace std;


//(1/2)���Թ��캯��ԭ������ȫ����ʹ�ö����ǣ������졣�����ڶ�����ù���ֻ��һ��
Test m(100);

int main2(){


    //����෽��ʾ�������߳�ʾ��
    //Array_max array1;
    //thread trd1([&array1]{
    //    array1.max_value();
    //});
    //thread trd2(mem_fn(&Array_max::show_test), &array1, 1);//���û�в��� ֱ�Ӳ�д
    //trd1.join();
    //trd2.join();


    //���캯����������ʾ��  һ�������������һ������ݳ�Ա�����
    Student a;
    a.show();
    Student b[3];
    for (int i = 0; i < sizeof(b) / sizeof(Student); i++)
    {
        b[i].show();
    }
    

    //(2/2)���Թ��캯��ԭ������ȫ����ʹ�ö����ǣ������졣�����ڶ�����ù���ֻ��һ��
    fun_t(20);
    fun_t(30);//����ֻ����һ��


    cin.get();//�����س��������������е�

    //system("pause");
    return 0;
}


