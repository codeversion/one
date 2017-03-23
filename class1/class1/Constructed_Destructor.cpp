#include "Constructed_Destructor.h"
#include <iostream>

using namespace std;

Test::Test(int a)
{
    kk = a;
    cout << "构造参数a:" << a << endl;
}




void fun_t(int n)
{
    static Test a(n);
    //static Test a=n;//这么写也是对的  
    cout << "函数传入参数n:" << n << endl << "对象a的属性kk的值:" << a.kk << endl;
}