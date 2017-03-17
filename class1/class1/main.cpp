#include <iostream>  
#include <thread>
#include "Array_max.h"

using namespace std;

int main(){


    Array_max array1;
    //array1.set_value();//初始化操作  
    //array1.show_value();//输出最大的数   s

    thread trd1([&array1]{
        array1.max_value();
    });
    thread trd2(mem_fn(&Array_max::show_test), &array1, 1);

    //
    trd1.join();
    trd2.join();


    //system("pause");
    return 0;
}