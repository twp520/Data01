//
// Created by colin on 2019-01-30.
//
#include "BinaryTree.h"


/**
 * 遍历二叉树
 * @param root 根节点
 */
void Access(BINARYNODE *root) {

    if (root == nullptr)
        return;

    //访问根节点
    cout << root->data;

    //访问左子树
    Access(root->lchild);

    //访问右子树
    Access(root->rchild);

}

int TreeHeight(BINARYNODE *root) {

    if (root == nullptr)
        return 0;

    int left = TreeHeight(root->lchild);
    int right = TreeHeight(root->rchild);

    return (left > right ? left : right) + 1;
}

