#include <iostream>  
#include <thread>
#include "Array_max.h"
#include "TeacherStudent.h"
#include "Constructed_Destructor.h"
#include "List.h"
using namespace std;


//(1/2)Constructed_Destructor.h���Թ��캯��ԭ������ȫ����ʹ�ö����ǣ������졣�����ڶ�����ù���ֻ��һ��
Test m(100);

int main(){
    ////Array_max.h����෽��ʾ�������Ա�������߳�ʾ��
    //Array_max array1;
    //thread trd1([&array1]{
    //    array1.max_value();
    //});
    //thread trd2(mem_fn(&Array_max::show_test), &array1, 1);//���û�в��� ֱ�Ӳ�д
    //trd1.join();
    //trd2.join();

    ////TeacherStudent.h���캯����������ʾ��  һ�������������һ������ݳ�Ա�����
    //Student a;
    //a.show();
    //Student b[3];
    //for (int i = 0; i < sizeof(b) / sizeof(Student); i++)
    //{
    //    b[i].show();
    //}
    
    ////(2/2)Constructed_Destructor.h���Թ��캯��ԭ������ȫ����ʹ�ö����ǣ������졣�����ڶ�����ù���ֻ��һ��
    //fun_t(20);
    //fun_t(30);//����ֻ����һ��

    //�������18�в���
    Node *pList = NULL;
    int length = 0;

    elemType posElem;

    initList(&pList);       //�����ʼ��
    printList(pList);       //����������ӡ����

    pList = creatList(pList); //��������
    printList(pList);

    sizeList(pList);        //����ĳ���
    printList(pList);

    isEmptyList(pList);     //�ж������Ƿ�Ϊ������

    posElem = getElement(pList, 3);  //��ȡ������Ԫ�أ����Ԫ�ز���3�����򷵻�0
    printf("getElement����ִ�У�λ�� 3 �е�Ԫ��Ϊ %d\n", posElem);
    printList(pList);

    getElemAddr(pList, 5);   //���Ԫ��5�ĵ�ַ
     
    modifyElem(pList, 4, 1);  //��������λ��4�ϵ�Ԫ���޸�Ϊ1
    printList(pList);

    insertHeadList(&pList, 5);   //��ͷ����Ԫ��12
    printList(pList);

    insertLastList(&pList, 10);  //��β����Ԫ��10
    printList(pList);

    clearList(pList);       //�������



    //cin.get();//�����س��������������е�
    system("pause");
    return 0;
}

