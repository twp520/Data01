//
// Created by colin on 2019-01-25.
//

#include "LinkedArray.h"

//初始化一个容器
Linked_Array *Init_Linked_Array() {
    //初始化一个头结点
    auto *head = (Linked_Entity *) malloc(sizeof(Linked_Entity));
    head->mData = 0;
    head->mNext = nullptr;


    auto *list = (Linked_Array *) malloc(sizeof(Linked_Array));
    list->size = 0;
    list->mHead = head;
    list->mLast = head;
    return list;
}

//在表尾插入一条数据
void PushBack_Array(Linked_Array *array, int value) {
    if (nullptr == array) {
        return;
    }
    //构造一个新节点
    auto *newNode = (Linked_Entity *) malloc(sizeof(Linked_Entity));
    newNode->mData = value;
    newNode->mNext = nullptr;
    array->mLast->mNext = newNode;
    array->mLast = newNode;
    array->size++;
}

/**
 * 在指定位置插入一条数据
 * @param array  链表
 * @param pos 索引
 * @param value 值
 */
void Insert_Array(Linked_Array *array, int pos, int value) {

    if (nullptr == array || pos < 0 || pos > array->size) {
        return;
    }

    //找到 pos前一个元素
    Linked_Entity *pre = array->mHead;
    for (int i = 0; i < pos; ++i) {
        pre = pre->mNext;
    }
    if (nullptr != pre) {
        //构造新node
        auto *newNode = (Linked_Entity *) malloc(sizeof(Linked_Entity));
        newNode->mData = value;
        newNode->mNext = pre->mNext;
        pre->mNext = newNode;
        if (pos == array->size) {
            array->mLast = newNode;
        }

        array->size++;
    }
}

/**
 * 删除一条数据 根据元素
 * @param value 要删除的元素
 * @return 删除成功返回0，删除失败返回-1
 */
int RemoveByValue_Array(Linked_Array *array, int value) {
    //找到前一条数据
    if (nullptr == array)
        return -1;
    int index = Find_Array(array, value);
    if (index == -1) return -1;

    Linked_Entity *pre = array->mHead;
    for (int i = 0; i < index; ++i) {
        pre = pre->mNext;
    }
    // pre : 10
    // pre->mNext : 60
    // pre->mNext->mNext : null
    auto *newNext = pre->mNext->mNext;
    free(pre->mNext);
    pre->mNext = newNext;
    //考虑last
    if (index == array->size - 1) {
        array->mLast = pre;
    }
    array->size--;


    return 0;
}

/**
 * 查找数据的位置
 * @param array 容器
 * @param value 要查找的值
 * @return 位置，如果没找到返回-1
 */
int Find_Array(Linked_Array *array, int value) {
    if (nullptr != array) {
        int pos = -1;
        Linked_Entity *curr = array->mHead;
        while (nullptr != curr) {
            curr = curr->mNext;
            pos++;
            if (nullptr != curr && curr->mData == value)
                return pos;
        }
    }
    return -1;
}


/**
 * 获取下标处元素
 * @param pos  下标
 * @return 元素
 */
int At_Array(Linked_Array *array, int pos) {
    if (array == nullptr || pos < 0 || pos >= array->size) {
        throw out_of_range("下标越界");
    }
    auto *pre = array->mHead;
    for (int i = 0; i < pos; ++i) {
        pre = pre->mNext;
    }
    return pre->mNext->mData;
}

//打印容器
void Print_Array(Linked_Array *array) {
    if (nullptr == array)
        return;

    auto mCurr = array->mHead->mNext;
    while (mCurr != nullptr) {
        std::cout << mCurr->mData << " ";
        mCurr = mCurr->mNext;
    }
    std::cout << std::endl;
}
