#include "Constructed_Destructor.h"
#include <iostream>

using namespace std;

Test::Test(int a)
{
    kk = a;
    cout << "�������a:" << a << endl;
}




void fun_t(int n)
{
    static Test a(n);
    //static Test a=n;//��ôдҲ�ǶԵ�  
    cout << "�����������n:" << n << endl << "����a������kk��ֵ:" << a.kk << endl;
}