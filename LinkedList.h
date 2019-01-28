//
// Created by colin on 2019-01-28.
//

#ifndef DATA01_LINKEDLIST_H
#define DATA01_LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;


//链表小节点
typedef struct LINKEDNODE {
    LINKEDNODE *next;
} LinkedNode;


//链表集合
typedef struct LINKEDLIST {

    LinkedNode *head; //首地址
    int size; //大小

} LinkedList;

typedef void(*PRINTLIST)(LinkedNode*); //回调函数

//初始化链表
LinkedList *Init_LinkedList();


/**
 * 插入元素
 * @param list 链表
 * @param pos  索引
 * @param data 数据
 */

void Insert_LinkedList(LinkedList *list, int pos, LinkedNode *data);


/**
 * 打印函数
 * @param list 链表
 * @param print 回调函数
 */
void Print_LinkedList(LinkedList *list, PRINTLIST print);

/**
 * 释放链表
 * @param list 链表
 */
void Free_LinkedList(LinkedList *list);

#endif //DATA01_LINKEDLIST_H
