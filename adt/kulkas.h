#ifndef KULKAS_H
#define KULKAS_H

#include "boolean.h"
#include "makanan.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi Elemen dan Address */
/* Elemen */
#define NIL NULL

typedef struct matrix matKulkas;

typedef struct {
    Makanan T[10];
    int length;
} listKulkas;

typedef struct {
    Address T[10];
    int length;
} listLeaves;

typedef struct {
    int x;
    int y;
    int w;
    int h;
    int usedByIdx;
} nodeDesc;

typedef nodeDesc ElType;
typedef struct treeNode* Address;
typedef struct treeNode {
    ElType info;
    Address right;
    Address down;
} TreeNode;

/* Definisi PohonBiner */
/* pohon Biner kosong p = NIL */
typedef Address BinTree;

/* Selektor */
#define ROOT(p) (p)->info
#define INFO(p) (p)->info
#define RIGHT(p) (p)->right
#define DOWN(p) (p)->down

void tryFit(BinTree * kulkas, listKulkas * lk, Makanan test, boolean * fit, listLeaves * ll) {
    BinTree tempTree;
    listKulkas tempLK;
    int i;

    tempTree = copyBinTree(*kulkas);

    tempLK = copyList(*lk);
    insertLK(&tempLK, test);
    *fit = true;

    for (i = 0; i < tempLK.length && *fit; i++) {
        node = findNode(tempTree, tempLK.T[i].w, tempLK.T[i].h);
        if (node != NIL) {
            splitNode(node, tempLK.T[i].w, tempLK.T[i].h, ll);
        } else {
            *fit = false;
        }
    }

    if (*fit) {
        *kulkas = tempTree;
        *lk = tempLK;
    }
}


Address newNode(ElType nd) {
    Address p;
    p = (Address) malloc(sizeof(TreeNode));
    if (p != NIL) {
        ROOT(p) = nd;
        DOWN(p) = NIL;
        RIGHT(p) = NIL;
    }
    return p;
}

void setNodeDesc(nodeDesc * nd, int x, int y, int w, int h, int idx) {
    (*nd).x = x; 
    (*nd).y = y;
    (*nd).w = w;
    (*nd).h = h;
    (*nd).usedByIdx = idx;
}

boolean isFit(Address node, int w, int h) {
    return (w <= INFO(node).w) && (h <= INFO(node).h);
}

Address findNode(BinTree tree, int w, int h) {
    if (isOneElmt(tree)) {

    } else {
        findNode(RIGHT(tree));
        findNode(LEFT(tree));
    }
}

void splitNode(Address * leaf, int w, int h, int idx, listLeaves * ll) {
    nodeDesc n1, n2;
    Address p1, p2;

    INFO(*leaf).usedByIdx = idx;

    if (INFO(*leaf).h - h != 0) {
        setNodeDesc(&n1,INFO(*leaf).x, INFO(*leaf).y + h, INFO(*leaf).w,INFO(*leaf).h - h, -1);
        p1 = newNode(n1);
        if (p1 != NULL) {
            RIGHT(*leaf) = p1;
        }
    }
    if (INFO(*leaf).w - w != 0) {
        setNodeDesc(&n2,INFO(*leaf).x + w, INFO(*leaf).y, INFO(*leaf).w - w, h, -1);
        p2 = newNode(n2);
        if (p2 != NULL) {
            DOWN(*leaf) = p2;
        }
    }
}

#endif