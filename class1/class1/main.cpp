#include <iostream>  
#include <thread>
#include "Array_max.h"
#include "TeacherStudent.h"

using namespace std;

int main(){


    //����෽��ʾ�������߳�ʾ��
    //Array_max array1;
    //thread trd1([&array1]{
    //    array1.max_value();
    //});
    //thread trd2(mem_fn(&Array_max::show_test), &array1, 1);
    //trd1.join();
    //trd2.join();


    //���캯����������ʾ��
    Student a;
    a.show();
    Student b[3];
    for (int i = 0; i < sizeof(b) / sizeof(Student); i++)
    {
        b[i].show();
    }
    cin.get();



    //system("pause");
    return 0;
}