#ifndef BNMO_TUBES_ALSTRUKDAT_TREE_H
#define BNMO_TUBES_ALSTRUKDAT_TREE_H

#define TREE_LIST_MAX 100

#include <stdlib.h>

#include "objectU.h"
#include "prioqueue.h"

typedef struct nAryNode {
    Object value;
    struct nAryNode **children;
    int childrenCount;
    int childArrSize;
    struct nAryNode *parent;
} Tree;

typedef struct nAryNodeList {
    int sizeEff;
    Tree list[TREE_LIST_MAX];
} ListTree;

Tree *createTreeNode(Tree *parent, Object value);
Tree **allocateArr(int size);
Tree *addChildren(Tree *node, Object value);

ListTree *createListTree();

/* function declarations: makanan*/

void traverseTree_Makanan(Tree tree);

/*
 * search for makanan with id makanan = id from. returns NULL if not found.
 * */
Makanan *searchMakananById(Tree tree, int id);

/*
 * search recipe tree in the recipe list. returns NULL if not found.
 *
 * */
Tree *searchRecipeById(ListTree *tree, int id);

/*
 * populate resep from config file. returns NULL if it fails to load file.
 *
 * */
ListTree *populateResepFromFile(ListMakanan *listMakanan, char fileL[]);

/**
 * given a resep (in the form of tree) and inventory, search for makanan which r'nt available in the
 * inventory. returns ListMakanan of panjang = 0 if all makanan needed are available in the inventory.
 */
ListMakanan *getMakananNa(Tree tree, PrioQueue inventory);

#endif
