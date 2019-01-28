//
// Created by colin on 2019-01-25.
//

#ifndef DATA01_LINKEDARRAY_H
#define DATA01_LINKEDARRAY_H

#include <iostream>
#include <exception>

using namespace std;

typedef struct LINKED_ENTITY {
    int mData; //实值
    LINKED_ENTITY *mNext; //下一个元素指针
} Linked_Entity;

typedef struct LINKED_ARRAY {

    Linked_Entity *mHead; //表头
    Linked_Entity *mLast; //表尾
    int size;//大小

} Linked_Array;

//初始化一个容器
Linked_Array *Init_Linked_Array();

//插入一条数据
void PushBack_Array(Linked_Array *array, int value);

/**
 * 在指定位置插入一条数据
 * @param array  链表
 * @param pos 索引
 * @param value 值
 */
void Insert_Array(Linked_Array *array, int pos, int value);

/**
 * 删除一条数据 根据元素
 * @param value 要删除的元素
 * @return 删除成功返回0，删除失败返回-1
 */
int RemoveByValue_Array(Linked_Array *array, int value);

/**
 * 查找数据的位置
 * @param array 容器
 * @param value 要查找的值
 * @return 位置，如果没找到返回-1
 */
int Find_Array(Linked_Array *array, int value);


/**
 * 获取下标处元素
 * @param pos  下标
 * @return 元素
 */
int At_Array(Linked_Array *array, int pos);


//打印容器
void Print_Array(Linked_Array *array);

#endif //DATA01_LINKEDARRAY_H
