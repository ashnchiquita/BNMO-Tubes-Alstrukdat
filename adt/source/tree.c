//
// Created by zidane on 10/28/22.
//

#include "../tree.h"

Tree *createTreeNode(Tree *parent, Object value) {
    Tree *node = malloc(sizeof(Tree));

    if (node == NULL) {
        // allocation fails
    }

    node->value = value;
    node->childArrSize = 8;
    node->children = allocateArr(8);
    node->childrenCount = 0;
    node->parent = parent;

    return node;
}

Tree **allocateArr(int size) {
    Tree **arr = malloc(sizeof(Tree*) * size);

    if (arr == NULL) {
        // allocation fails
    }

    return arr;
}

Tree *addChildren(Tree *node, Object value) {
    if (node->childrenCount == node->childArrSize) {
        int newSize = (node->childrenCount) * (1.5) * sizeof(node);

        Tree **newNode = realloc(node->children, newSize);

        if (newNode == NULL) {
            // allocation fails
        }

        node->children = newNode;
        node->childArrSize = newSize;
    }

    Tree *newNode = createTreeNode(node, value);
    node->children[node->childrenCount] = newNode;
    node->childrenCount += 1;

    return newNode;
}

ListTree *createListTree() {
    ListTree *list = malloc(sizeof(ListTree));
    list->sizeEff = 0;

    return list;
}