#include <iostream>
//#include "DynamicArray.h"
//#include "LinkedArray.h"
#include "LinkedList.h"

using namespace std;

#if 0
//动态数组
int main01() {

    Dynamic_Array *mArray = Init_Array();
    for (int i = 0; i < 22; ++i) {
        PushBack_Array(mArray, i);
    }

    Print_Array(mArray);

    RemoveByValue_Array(mArray, 11);
    cout << "---------------------------" << endl;
    Print_Array(mArray);
    return 0;
}
//普通链表
int main() {

    auto *mArray = Init_Linked_Array();
    for (int i = 0; i < 10; ++i) {
        PushBack_Array(mArray, i + 1);
    }

    Print_Array(mArray);

    cout << "------------------" << endl;

    //Insert_Array(mArray, 2, 80);
    //Print_Array(mArray);
    Insert_Array(mArray, 10, 60);
    Print_Array(mArray);
    //int pos = Find_Array(mArray, 60);
    //cout << "60 的位置是 " << pos << endl;
    cout << "------------------" << endl;

    RemoveByValue_Array(mArray, 60);
    Print_Array(mArray);
    cout << "last = " << mArray->mLast->mData << endl;
    cout << "size = " << mArray->size << endl;


    cout << "------------------" << endl;

    cout << "位于第5位的是 " << At_Array(mArray, 11) << endl;

    return 0;
}
#endif

struct Person {
    LinkedNode node;
    string name;
    int age;
};

void myPrint(LinkedNode *item) {
    Person *p = (Person *) (item);
    cout << "name = " << p->name << " , age = " << p->age << endl;
}

// 首地址链表
int main() {

    LinkedList *list = Init_LinkedList();

    Person p1, p2, p3;
    p1.name = "aaa";
    p1.age = 10;

    p2.name = "bbb";
    p2.age = 20;

    p3.name = "ccc";
    p3.age = 30;

    Insert_LinkedList(list, 0, (LinkedNode *) (&p1));
    Insert_LinkedList(list, 1, (LinkedNode *) (&p2));
    Insert_LinkedList(list, 2, (LinkedNode *) (&p3));

    Print_LinkedList(list, myPrint);

    Free_LinkedList(list);
    return 0;
}