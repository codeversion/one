//测试构造函数原理，当在全局中使用对象是，都构造。函数内对象调用构造只有一次

#ifndef _CONSTRUCTED_DESTRUCTOR_H_
#define _CONSTRUCTED_DESTRUCTOR_H_

class Test
{
public:
    Test(int a);
public:
    int kk;
};

void fun_t(int n);

#endif