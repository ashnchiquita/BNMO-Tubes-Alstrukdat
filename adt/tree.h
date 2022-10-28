#ifndef BNMO_TUBES_ALSTRUKDAT_TREE_H
#define BNMO_TUBES_ALSTRUKDAT_TREE_H

#include <stdlib.h>

#include "objectU.h"

typedef struct nAryNode {
    Object value;
    struct nAryNode **children;
    int childrenCount;
    int childArrSize;
    struct nAryNode *parent;
} TreeNode;

TreeNode *createTreeNode(TreeNode *parent, Object value);
TreeNode **allocateArr(int size);
void addChildren(TreeNode *node, Object size);

#endif
