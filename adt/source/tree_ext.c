#include <stdio.h>
#include <math.h>

#include "boolean.h"
#include "tree.h"

/**
 * traversing n-ary tree
 * @param treeNode
 */
void traverseTree(TreeNode *treeNode) {
    int childrenCount = treeNode->childrenCount;

    printf("%d ", treeNode->value);

    if (childrenCount == 0) {
        return;
    }

    for (int i = 0;i < childrenCount; ++i) {
        traverseTree((treeNode->children)[i]);
    }
}

/**
 *
 * @param treeNode
 * @param found
 * @param valTS
 */
void searchMakananInTree(TreeNode *treeNode, boolean *found, Object valTS) {
    int childrenCount = treeNode->childrenCount;

    if ((*found) == true) {
        return;
    }

    if ((treeNode->value.makananV.id) == valTS.makananV.id) {
        (*found) = true;
        return;
    }

    if (childrenCount == 0) {
        return;
    }

    for (int i = 0;i < childrenCount; ++i) {
        searchMakananInTree((treeNode->children)[i], found, valTS);
    }
}

int getCharIntVal(char word[], int size) {
    int val = 0;
    for (int i = 1;i <= size; ++i) {
        val += (word[size-i] - 48) * pow(10, i-1);
    }

    return val;
}

/**
 * not done
 *
 * @return
 */
TreeNode *populateFromF() {
    FILE *file;
    char currentChar, currentW[25], ch;
    int currentWSize = 0, val = 0;
  //  ListDin line;
 //   CreateListDin(&line, 100);

    file = fopen("/home/zidane/kuliah/Semester 3/IF2110 - Algoritma & Struktur Data/praktikum/preparation-tubes/config-r.txt", "r");

    if (file == NULL) {

    }

    int count = 0;
    while(count < 1) {
        currentChar = fgetc(file);

        if (currentChar == -1)
            count = 1;

        if (!(currentChar >= 48 && currentChar <= 57) && currentChar != 32 && currentChar != -1) {
            continue;
        }

        if (currentChar == 32 || count != 0) {
            if (currentWSize == 0) {
                continue;
            }

            val = getCharIntVal(currentW, currentWSize);
           // insertLast(&line, val);
            currentWSize = 0;
            continue;
        }

        currentW[currentWSize] = currentChar;
        ++currentWSize;
    }

   // printList(line);
    return NULL;
}

/**
 * given a list of values values, search which values is not contained in the tree
 *
 * not done. unsatisfied dependency: list dinamik
 *
 * @param node
 */
/*void check(TreeNode *node, ListDin *valueArr, ListDin *nEArr) {
    if (node == NULL)
        return;

    int total = node->childrenCount;

    // search if value exists in the value arr (recipe fulfilled)
    // should be faster and simpler using hashtable (but making such DA surely would be a little complex)
    boolean notFound = true;
    int i = 0;
    while (notFound && i < valueArr->nEff) {
        if (valueArr->buffer[i] == 0) {
            break;
        }

        if (node->value==valueArr->buffer[i]) {
            notFound = false;
        }
        ++i;
    }

    if (notFound) {
        insertLast(nEArr, node->value);
    }

    for (int i = 0; i < total; i++)
        check(node->children[i], valueArr, nEArr);

}*/
