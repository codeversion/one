#ifndef _TEACHERSTUDENT_H_
#define _TEACHERSTUDENT_H_


class Teacher
{
public:
    Teacher();
    ~Teacher();
    char *show();
protected:
    char *director;
    //string *director;  
};

class Student
{
public:
    Student();
    void show();

protected:
    int number;
    int score;
    Teacher teacher;
};

#endif