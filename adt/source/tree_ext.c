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

    for (int i = 0;i < childrenCount - 1; ++i) {
        traverseTree_Makanan(*(treeNode.children[i]));
    }

    printf("%d ", treeNode.value.makananV.id);

    if (childrenCount != 0) {
        traverseTree_Makanan(*(treeNode.children[childrenCount-1]));

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

    int childC, childId;
    Tree *cTree = NULL;

    for (int i = 0; i < listTree->sizeEff; ++i) {
        childC = listTree->list[i].childrenCount;
        for (int j = 0; j < childC; ++j) {
            childId = listTree->list[i].children[j]->value.makananV.id;
            cTree = searchRecipeById(listTree, childId);
            if (cTree != NULL) {
                listTree->list[i].children[j] = cTree;
            }
        }
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
}

void displayCookBook(ListTree listTree) {
    int listTreeLen = listTree.sizeEff, treeCLen;
    Tree currentTree;
    Makanan cMakanan;
    printf("List Resep\n"
           "(aksi yang diperlukan - bahan...)\n");

    for (int i = 0; i < listTreeLen; ++i) {
        currentTree = listTree.list[i]; treeCLen = currentTree.childrenCount;
        cMakanan = currentTree.value.makananV;
        printf("%d. ", i+1);
        printWord(cMakanan.aksi);
        printf("\n");
        printWord(cMakanan.namaMakanan);

        for (int j = 0; j < treeCLen; ++j) {
            cMakanan = currentTree.children[j]->value.makananV;
            printf(" - ");
            printWord(cMakanan.namaMakanan);
        }
        printf("\n");

    }
}

boolean searchInventory(PrioQueue inventory, int id) {
    int len = CountElmt(inventory);

    for (int i = 0; i < len; ++i) {
        if (inventory.T[i].id == id)
            return true;
    }

    return false;
}

ListMakanan checkNonExisting(Tree resep, PrioQueue inventory) {
    int itemC = resep.childrenCount;
    ListMakanan listMakanan;
    CreateListMakanan(&listMakanan);

    for (int i = 0; i < itemC; ++i) {
        if (searchInventory(inventory, resep.children[i]->value.makananV.id) == false)
            addMakanan(&listMakanan, resep.children[i]->value.makananV);
    }
    return listMakanan;
}


ListMakanan getRecommendation(ListTree listTree, PrioQueue inventory) {
    int lenListM = listTree.sizeEff, lenListNa, lenLa = 0;
    ListMakanan listNa, listRekomendasi;
    Tree treeTemp, treeToC, *treeNaU, **listAll = malloc(sizeof(Tree*) * listTree.sizeEff);

    CreateListMakanan(&listRekomendasi);

    for (int i = 0; i < lenListM; ++i) {
        // 1. check subset direct children from tree,
        treeToC = listTree.list[i];
        Object obj;
        obj.makananV = treeToC.value.makananV;
        int lenNaC;
        boolean expandedFc = true;

        while (expandedFc) {
            listNa = checkNonExisting(treeToC, inventory);
            lenListNa = panjangListMakanan(listNa);

            if (lenListNa == 0) {
                addMakanan(&listRekomendasi, obj.makananV);
                break;
            }

            // add non existing makanan to tree temp
            listAll[lenLa] = createTreeNode(NULL, obj);
            treeTemp = *listAll[lenLa];
            ++lenLa;
            expandedFc = false;

            for (int j = 0; j < lenListNa; ++j) {
                treeNaU = searchRecipeById(&listTree, listNa.contents[j].id);

                if (treeNaU == NULL) {
                    expandedFc = false;
                    continue;
                }

                lenNaC = treeNaU->childrenCount;
                for (int k = 0; k < lenNaC; ++k) {
                    Object childTemp;
                    childTemp.makananV = treeNaU->children[k]->value.makananV;
                    addChildren(&treeTemp, childTemp);
                    expandedFc = true;
                }

            }

            treeToC = treeTemp;

        }

    }

    // free the heap
    for (int i = 0; i < lenLa; ++i) {
        free(listAll[i]);
    }

    free(listAll);

    return listRekomendasi;
}
