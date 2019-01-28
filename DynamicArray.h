//
// Created by colin on 2019-01-25.
//

#ifndef DATA01_DYNAMICARRAY_H
#define DATA01_DYNAMICARRAY_H

#include <iostream>

typedef struct DYNAMIC_ARRAY {

    int *mAddress; //数组首地址
    int size; //当前元素个数
    int capacity; //当前容器的容量

} Dynamic_Array;

//初始化一个容器
Dynamic_Array *Init_Array();

//插入一条数据
void PushBack_Array(Dynamic_Array *array, int value);

/**
 * 删除一条数据 根据位置
 * @param value 要删除的元素
 * @return 删除成功返回0，删除失败返回-1
 */
int RemoveByPos_Array(Dynamic_Array *array, int pos);

/**
 * 删除一条数据 根据元素
 * @param value 要删除的元素
 * @return 删除成功返回0，删除失败返回-1
 */
int RemoveByValue_Array(Dynamic_Array *array, int value);

/**
 * 查找数据的位置
 * @param array 容器
 * @param value 要查找的值
 * @return 位置，如果没找到返回-1
 */
int Find_Array(Dynamic_Array *array, int value);


/**
 * 获取下标处元素
 * @param pos  下标
 * @return 元素
 */
int At_Array(Dynamic_Array *array, int pos);

//打印容器
void Print_Array(Dynamic_Array *array);

#endif //DATA01_DYNAMICARRAY_H
