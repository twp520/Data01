//
// Created by colin on 2019-01-25.
//
#include "DynamicArray.h"

//初始化一个容器
Dynamic_Array *Init_Array() {
    auto *mArray = (Dynamic_Array *) malloc(sizeof(Dynamic_Array));
    mArray->size = 0;
    mArray->capacity = 20;
    mArray->mAddress = (int *) malloc(sizeof(int) * mArray->capacity);
    return mArray;
}

//插入一条数据
void PushBack_Array(Dynamic_Array *array, int value) {
    if (nullptr == array) {
        return;
    }
    if (array->size == array->capacity - 1) {
        //进行扩容
        array->capacity = array->capacity * 2;
        int *tempAdd = (int *) malloc(sizeof(int) * array->capacity);
        memcpy(tempAdd, array->mAddress, array->size * sizeof(int));
        free(array->mAddress);
        array->mAddress = tempAdd;
    }
    array->mAddress[array->size] = value;
    array->size++;
}

/**
 * 删除一条数据 根据位置
 * @param value 要删除的元素
 * @return 删除成功返回0，删除失败返回-1
 */
int RemoveByPos_Array(Dynamic_Array *array, int pos) {
    if (nullptr == array || pos < 0 || pos >= array->size) {
        return -1;
    }
    for (int i = pos; i < array->size - 1; ++i) {
        array->mAddress[i] = array->mAddress[i + 1];
    }
    return 0;
}

/**
 * 删除一条数据 根据元素
 * @param value 要删除的元素
 * @return 删除成功返回0，删除失败返回-1
 */
int RemoveByValue_Array(Dynamic_Array *array, int value) {
    if (nullptr == array) {
        return -1;
    }
    return RemoveByPos_Array(array, Find_Array(array, value));
}

/**
 * 查找数据的位置
 * @param array 容器
 * @param value 要查找的值
 * @return 位置，如果没找到返回-1
 */
int Find_Array(Dynamic_Array *array, int value) {
    if (nullptr == array) {
        return -1;
    }
    for (int i = 0; i < array->size; ++i) {
        if (value == array->mAddress[i]) {
            return i;
        }
    }
    return -1;
}

/**
 * 获取下标处元素
 * @param pos  下标
 * @return 元素
 */
int At_Array(Dynamic_Array *array, int pos) {
    return array->mAddress[pos];
}

//打印容器
void Print_Array(Dynamic_Array *array) {
    if (nullptr == array) {
        return;
    }
    for (int i = 0; i < array->size; ++i) {
        printf("index = %d , value = %d \n", i, *(array->mAddress + i));
    }
}