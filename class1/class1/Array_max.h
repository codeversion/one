#ifndef _ARRAY_MAX_H_
#define _ARRAY_MAX_H_

class Array_max{

private://声明在类的外部不可访问的隐私成员   
    int array[10];
    int max;


public://声明在类的外部可以访问的开放的成员函数   
    void set_value();
    void max_value();
    void show_value();
    void show_test(int a);
};


#endif