#include <iostream>  
#include <string>  
#include "TeacherStudent.h"

using namespace std;

Teacher::Teacher()
{
    director = new char[10];
    strcpy(director, "������");
}
Teacher::~Teacher()
{
    cout << "�ͷŶ���director�ڴ�ռ�1��";
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


