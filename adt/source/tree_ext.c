#include <stdio.h>
#include <math.h>

#include "../boolean.h"
#include "../tree.h"

/**
 * traversing n-ary tree
 * @param treeNode
 */
void traverseTree_Makanan(Tree treeNode) {
    int childrenCount = treeNode.childrenCount;

    printf("%d ", treeNode.value.makananV.id);

    if (childrenCount == 0) {
        return;
    }

    for (int i = 0;i < childrenCount; ++i) {
        traverseTree_Makanan(*(treeNode.children[i]));
    }
}

Makanan *searchMakananByIdIT(Tree *tree, boolean *found, int id) {
    int childrenCount = tree->childrenCount;

    if ((*found) == true) {
        return NULL;
    }

    if ((tree->value.makananV.id) == id) {
        (*found) = true;
        return &(tree->value.makananV);
    }

    if (childrenCount == 0) {
        return NULL;
    }

    Makanan *res;

    for (int i = 0;i < childrenCount; ++i) {
        res = searchMakananByIdIT((tree->children)[i], found, id);
        if (res != NULL)
            return res;
    }

    return NULL;
}

Makanan *searchMakananById(Tree tree, int id) {
    boolean found = false;
    return searchMakananByIdIT(&tree, &found, id);
}

Tree *searchRecipeById(ListTree *tree, int id) {
    for (int i = 0; i < tree->sizeEff; ++i) {
        if (tree->list[i].value.makananV.id == id) {
            return &(tree->list[i]);
        }
    }
    return NULL;
}

int getCharIntValue(char word[], int size) {
    int val = 0;
    for (int i = 1;i <= size; ++i) {
        val += (word[size-i] - 48) * pow(10, i-1);
    }

    return val;
}

Makanan *searchMakananFromList(ListMakanan *listMakanan, int id) {
    int i = 0, cId = listMakanan->contents[i].id;

    while (cId != -1) {
        if (cId == id) {
            return &(listMakanan->contents[i]);
        }
        ++i;
        cId = listMakanan->contents[i].id;
    }

    return NULL;
}

void addToT(ListTree *listTree, ListMakanan *listMakanan, char currentWord[], int *wordCount, int *currentWordSize,
            int currentLine) {

    if (*currentWordSize == 0) {
        return;
    }

    Object nodeVal;

    (*wordCount) += 1;

    int val = getCharIntValue(currentWord, *currentWordSize);
    if (*wordCount == 1) {
        Makanan *makananRootR = searchMakananFromList(listMakanan, val);

        // makanan not found, config is faulty
        if (makananRootR == NULL) {
            printf("makanan not found\n");
            exit(23);
        }

        nodeVal.makananV = *makananRootR;

        Tree rootNode = *createTreeNode(NULL, nodeVal);
        listTree->list[listTree->sizeEff] = rootNode;
        listTree->sizeEff += 1;
    } else if (*wordCount != 2) {
        Makanan *makananRootR = searchMakananFromList(listMakanan, val);

        // makanan not found, config is faulty
        if (makananRootR == NULL) {
            printf("makanan not found");
            exit(23);
        }

        nodeVal.makananV = *makananRootR;
        addChildren(&(listTree->list[currentLine-1]), nodeVal);
    }

    *currentWordSize = 0;

}

/**
 * populate from file for resep. this function assumes config file is not faulty, hence validations r'nt provided
 *
 * @return
 */
ListTree *populateResepFromFile(ListMakanan listMakanan, char fileL[]) {
    FILE *file;
    file = fopen(fileL, "r");

    if (file == NULL) {
        return NULL;
    }

    char currentChar, currentWord[25];
    int currentWordSize = 0, val = 0, currentLine = 0, wordCount = 0;
    ListTree *listTree = createListTree();
    boolean stopFCL = false;
    Object nodeVal;

    while(currentChar != -1) {
        currentChar = fgetc(file);

        if (currentChar == '\n') {
            if (currentLine != 0)
                addToT(listTree, &listMakanan, currentWord, &wordCount, &currentWordSize, currentLine);
            currentLine += 1;
            wordCount = 0;
            stopFCL = false;

            continue;
        }

        if (currentChar == '#') {
            stopFCL = true;
            continue;
        }

        // after detecting #, stop parsing for numbers
        if (stopFCL) {
            continue;
        }

        if (currentLine == 0 || (!(currentChar >= 48 && currentChar <= 57) && currentChar != 32 && currentChar != -1)) {
            continue;
        }

        if (currentChar == 32 || currentChar == -1) {
            addToT(listTree, &listMakanan, currentWord, &wordCount, &currentWordSize, currentLine);
            continue;
        }

        currentWord[currentWordSize] = currentChar;
        ++currentWordSize;
    }

    return listTree;
}

/**
 * use getMakananNa.
 */
void check(Tree *tree, PrioQueue *inventory, ListMakanan *listNa, int depth, int currentDepth) {
    // search if value exists in the value arr (recipe fulfilled)
    // should be faster and simpler using hashtable (but making such DA surely would be a little complex)
    if (depth == currentDepth) {
        boolean notFound = true;
        int i = 0;
        while (notFound && inventory->TAIL >= i) {
            if (tree->value.makananV.id == inventory->T[i].id) {
                notFound = false;
            }
            ++i;
        }


        if (notFound) {
            addMakanan(listNa, tree->value.makananV);
        }

        return;
    }

    if (depth > currentDepth) {
        int childrenCount = tree->childrenCount;
        for (int i = 0; i < childrenCount; i++) {
            check(tree->children[i], inventory, listNa, depth, currentDepth + 1);
        }
    }

}

void haveFood(Tree *tree, PrioQueue *inventory, ListMakanan *listNa, int depth, int currentDepth) {
    // search if value exists in the value arr (recipe fulfilled)
    // should be faster and simpler using hashtable (but making such DA surely would be a little complex)
    if (depth == currentDepth) {
        boolean notFound = true;
        int i = 0;
        while (notFound && inventory->TAIL >= i) {
            if (tree->value.makananV.id == inventory->T[i].id) {
                notFound = false;
            }
            ++i;
        }


        if (!notFound) {
            addMakanan(listNa, tree->value.makananV);
        }

        return;
    }

    if (depth > currentDepth) {
        int childrenCount = tree->childrenCount;
        for (int i = 0; i < childrenCount; i++) {
            haveFood(tree->children[i], inventory, listNa, depth, currentDepth + 1);
        }
    }

}


ListMakanan getMakananNa(Tree tree, PrioQueue inventory) {
    ListMakanan listMakanan;
    CreateListMakanan(&listMakanan);
    check(&tree, &inventory, &listMakanan, 1, 0);
    return listMakanan;
}

ListMakanan getMakanan (Tree tree, PrioQueue inventory){
    ListMakanan listMakanan;
    CreateListMakanan(&listMakanan);
    haveFood(&tree,&inventory,&listMakanan,1,0);
    return listMakanan;
};
