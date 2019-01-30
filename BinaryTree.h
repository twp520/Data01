//
// Created by colin on 2019-01-30.
//

#ifndef DATA01_BINARYTREE_H
#define DATA01_BINARYTREE_H

#include <iostream>

using namespace std;

typedef struct BINARYNODE {
    char data;
    BINARYNODE *lchild;
    BINARYNODE *rchild;

} BinaryNode;


/**
 * 遍历二叉树
 * @param root 根节点
 */
void Access(BINARYNODE *root);


/**
 * 求树的高度
 * @param root 根节点
 */
int TreeHeight(BINARYNODE *root);

#endif //DATA01_BINARYTREE_H
