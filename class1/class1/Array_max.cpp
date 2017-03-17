#include"Array_max.h"

#include<iostream>

using namespace std;


void Array_max::set_value(){
    int i;
    cout << "请输入10个整数" << endl;
    for (i = 0; i < 10; i++){
        cin >> array[i];
    }
};
void Array_max::max_value(){
    set_value();
    int i;
    max = array[0];
    for (i = 1; i < 10; i++){
        if (array[i] > max)
            max = array[i];
    }
    show_value();
};
void Array_max::show_value(){
    cout << "max is :" << max << endl;
};