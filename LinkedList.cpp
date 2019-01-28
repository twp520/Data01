//
// Created by colin on 2019-01-28.
//
#include "LinkedList.h"

//初始化链表
LinkedList *Init_LinkedList() {

    auto *list = static_cast<LinkedList *>(malloc(sizeof(LinkedList)));
    list->head = static_cast<LinkedNode *>(malloc(sizeof(LinkedNode)));
    list->head->next = nullptr;
    return list;
}


/**
 * 插入元素
 * @param list 链表
 * @param pos  索引
 * @param data 数据
 */

void Insert_LinkedList(LinkedList *list, int pos, LinkedNode *data) {

    if (nullptr == list || nullptr == data || pos < 0 || pos > list->size)
        return;

    //查找目标索引的前一个data
    LinkedNode *pCur = list->head;
    for (int i = 0; i < pos; ++i) {
        pCur = pCur->next;
    }

    data->next = pCur->next;
    pCur->next = data;
    list->size++;
}


/**
 * 打印函数
 * @param list 链表
 * @param print 回调函数
 */
void Print_LinkedList(LinkedList *list, PRINTLIST print) {
    if (nullptr == list)
        return;
    LinkedNode *p = list->head->next;
    while (p != nullptr) {
        print(p);
        p = p->next;
    }
}

/**
 * 释放链表
 * @param list 链表
 */
void Free_LinkedList(LinkedList *list) {
    if (nullptr == list)
        return;
    if (nullptr != list->head) {
        free(list->head);
    }
    free(list);
}

