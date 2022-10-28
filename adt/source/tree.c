//
// Created by zidane on 10/28/22.
//

#include "../tree.h"

TreeNode *createTreeNode(TreeNode *parent, Object value) {
    TreeNode *node = malloc(sizeof(TreeNode));
    node->value = value;
    node->childArrSize = 8;
    node->children = allocateArr(8);
    node->childrenCount = 0;
    node->parent = parent;

    return node;
}

TreeNode **allocateArr(int size) {
    TreeNode **arr = malloc(sizeof(TreeNode*) * size);

    if (arr == NULL) {
        // allocation fails
    }

    return arr;
}

void addChildren(TreeNode *node, Object value) {
    if (node->childrenCount == node->childArrSize) {
        int newSize = (node->childrenCount) * (1.5) * sizeof(node);

        TreeNode **newNode = realloc(node->children, newSize);

        if (newNode == NULL) {
            // allocation fails
        }

        node->children = newNode;
        node->childArrSize = newSize;
    }
    TreeNode *newNode = createTreeNode(node, value);
    node->children[node->childrenCount] = newNode;
    node->childrenCount += 1;

}