#include"Array_max.h"

#include<iostream>

using namespace std;


void Array_max::set_value(){
    int i;
    cout << "请输入3个整数" << endl;
    for (i = 0; i < 3; i++){
        cin >> array[i];
    }
};
void Array_max::max_value(){
    for (int i = 0; i < 10000; i++)
    {
        cout << "thread1111111111111111111111111111111111\n" ;
    }
};
void Array_max::show_value(){
    cout << "max is :" << max << endl;
};

void Array_max::show_test(int a)
{
    for (int i = 0; i < 10000; i++)
    {
        cout << "thread2\n";
    }
}


