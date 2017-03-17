#include <iostream>  
#include <string>  
#include "TeacherStudent.h"

using namespace std;

Teacher::Teacher()
{
    director = new char[10];
    strcpy(director, "王大力");
}
Teacher::~Teacher()
{
    cout << "释放堆区director内存空间1次";
    delete[] director;
    cin.get();
}


char *Teacher::show()
{
    return director;
}


Student::Student()
{
    number = 1;
    score = 100;
}


void Student::show()
{
    cout << number << endl << score << endl << teacher.show() <<endl;
}


