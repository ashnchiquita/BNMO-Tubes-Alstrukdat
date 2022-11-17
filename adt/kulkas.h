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

void tryFit(BinTree * kulkas, listKulkas * lk, Makanan test, boolean * fit) {
    BinTree tempTree, root;
    listKulkas tempLK;
    int i;

    tempTree = copyBinTree(*kulkas);
    root = tempTree;
    tempLK = copyList(*lk);
    insertLK(&tempLK, test);
    *fit = true;

    for (i = 0; i < tempLK.length && *fit; i++) {
        node = findNode(root, tempLK.T[i].w, tempLK.T[i].h);
        if (node != NIL) {
            splitNode(node, tempLK.T[i].w, tempLK.T[i].h);
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
    return (w <= INFO(node).w) && (h <= INFO(node).h)
}

Address findNode(Address root, int w, int h) {
    if (isFit(root,w,h)) {
        return root;
    } else if (ROOT(root).usedByIdx != -1) {
        return findNode(RIGHT(root), w, h) || findNode(DOWN(root), w, h); // benerin nih traversenya
    } else {
        return NIL;
    }
}

void splitNode(Address leaf, int w, int h, int idx) {
    
}
#endif