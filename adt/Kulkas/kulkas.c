#include "kulkas.h"
#include <stdio.h>

/* Ordered Array */
boolean isFullLK(listKulkas lk) {
    return (lk.length == MAXLK);
}

int max2(int w, int h) {
/* Mencari maksimum dari 2 bilangan */
    return w > h ? w : h;
}

void createLK(listKulkas * lk) {
/* Membuat list kulkas kosong */
    (*lk).length = 0;
}

void insertLK(listKulkas *lk, Makanan x) {
/* Memasukkan makanan x ke dalam list kulkas */
    int i, idxSisip;
    boolean found;
    Makanan currEl;

    /* ALGORITMA */
    found = false;
    for (i = 0; i < (*lk).length  && !found; i++) {
        currEl = (*lk).T[i];
        
        if (max2(w(currEl), h(currEl)) < max2(w(x), h(x))) {
            idxSisip = i;
            found = true;
        }
    }

    if (!found) {
        idxSisip = (*lk).length;
    }

    for (i = (*lk).length; i >= idxSisip + 1; i--) {
        (*lk).T[i] = (*lk).T [i - 1];
    }

    (*lk).length++;
    (*lk).T[idxSisip] = x;
}

void deleteLK(listKulkas *lk, int idx, Makanan *x) {
/* Menghapus elemen ke idx dari list kulkas */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    (*x) = (*lk).T[idx];

    for (i = idx + 1; i < (*lk).length; i++) {
        (*lk).T[i - 1] = (*lk).T[i];
    }
    (*lk).length--;
}

void copyLK(listKulkas * hasil, listKulkas lk) {
/* Mengcopy list kulkas */
    int i;
    
    (*hasil).length = lk.length;

    for (i = 0; i <lk.length; i++) {
        (*hasil).T[i] = lk.T[i];
    }
}

/* Node Desc */
void createND(nodeDesc *nd, int x, int y, int w, int h, int idx) {
/* Membuat/Mengset node desc */
    (*nd).x = x; 
    (*nd).y = y;
    (*nd).w = w;
    (*nd).h = h;
    (*nd).usedByIdx = idx;
}

boolean isNodeUsed(nodeDesc nd) {
/* Mengecek apakah node digunakan */
    return (nd.usedByIdx != -1);
}

boolean isFit(Makanan test, nodeDesc nd) {
/* Mengecek apakah makanan fit ke dalam node */
    return (w(test) <= nd.w) && (h(test) <= nd.h);
}

/* Tree */
void createTA(treeArr * t) {
/* Membuat tree array kosong */
    nodeDesc nd;

    createND(&nd, 0, 0, 20, 10, -1);
    (*t).length = 1;
    (*t).T[0] = nd;
}

boolean isFullTA(treeArr t) {
    return (t.length == MAXTA);
}

void insertTA(treeArr * t, nodeDesc nd, int idx) {
/* Memasukkan nd sebagai elemen ke idx dari list kulkas */
    int i;

    for (i = (*t).length; i >= idx + 1; i--) {
        (*t).T[i] = (*t).T [i - 1];
    }

    (*t).length++;
    (*t).T[idx] = nd;
}

void copyTA(treeArr * hasil, treeArr t) {
/* Mengcopy tree array */
    int i;
    
    (*hasil).length = t.length;

    for (i = 0; i < t.length; i++) {
        (*hasil).T[i] = t.T[i];
    }
}

/* Kulkas Arrangement */
int findNode(treeArr t, Makanan test) {
/* Mencari node yang cukup untuk menyimpan makanan test */
    int i, node;

    node = -1;

    for (i = t.length - 1; i >= 0  && node == -1; i--) {
        if (!isNodeUsed(t.T[i]) && isFit(test, t.T[i])) {
            node = i;
        }
    }

    return node;
}

void splitNode(treeArr * t, int node, listKulkas lk, int lkIdx) {
/* Memecah node menjadi 3 node (1 terisi, 2 kosong)*/
    nodeDesc ndRight, ndDown;
    int wm, hm, temp;

    (*t).T[node].usedByIdx = lkIdx;
    wm = lk.T[lkIdx].w;
    hm = lk.T[lkIdx].h;
    temp = node;

    if (!isFullTA(*t) && (*t).T[node].h - hm != 0) {
        temp++;
        createND(&ndDown, (*t).T[node].x, (*t).T[node].y + hm, (*t).T[node].w, (*t).T[node].h - hm, -1);
        insertTA(t, ndDown, temp);
    }

    if (!isFullTA(*t) && (*t).T[node].w - wm != 0) {
        temp++;
        createND(&ndRight, (*t).T[node].x + wm, (*t).T[node].y, (*t).T[node].w - wm, hm, -1);
        insertTA(t, ndRight, temp);
    }
}

void arrangeKulkas(treeArr * t, listKulkas lk, boolean * success) {
/* Meng-arrange listkulkas menjadi tree kulkas, success jika semua elemen list kulkas fit ke dalam kulkas */
    int i, node;
    *success = true;

    for (i = 0; i < lk.length && *success; i++) {
        node = findNode(*t, lk.T[i]);
        if (node != -1) {
            splitNode(t, node, lk, i);
        } else {
            *success = false;
        }
    }
}

void insertKulkas(treeArr * t, listKulkas * lk, Makanan test, boolean * success) {
/* Menginsert makanan ke dalam kulkas. Insertion mungkin gagal */
    treeArr tempTree;
    listKulkas tempLK;
    boolean fit;

    createTA(&tempTree);
    copyLK(&tempLK, *lk);
    insertLK(&tempLK, test);

    arrangeKulkas(&tempTree, tempLK, &fit);

    if (fit) {
        copyTA(t, tempTree);
        copyLK(lk, tempLK);
    }
    (*success) = fit;
}

void deleteKulkas(treeArr *t, listKulkas *lk, int lkIdx, Makanan *val, boolean * success) {
    boolean fit;
    treeArr tempTree;

    createTA(&tempTree);

    deleteLK(lk,lkIdx, val);
    arrangeKulkas(&tempTree, *lk, &fit);

    if (fit) {
        copyTA(t, tempTree);
    }
    (*success) = fit;
}

/* Matrix Kulkas */
void CreateMatKul(int nRows, int nCols, MatKul *m) {
    int i, j;

    HEIGHT(*m) = nRows;
    WIDTH(*m) = nCols;
    for (i = 0; i < nRows; i++) {
        for(j = 0; j < nCols; j++) {
            EL(*m, i, j) = -1;
        }
    }
}

/* IO */
void matrixKulkas(MatKul * mat, treeArr t, listKulkas lk) {
/* Membuat matriks kulkas */
    int i, j, k;
    CreateMatKul(10, 20, mat);

    for (i = 0; i < t.length; i++) {
        if (isNodeUsed(t.T[i])) {
            for (k = t.T[i].y; k < t.T[i].y + lk.T[t.T[i].usedByIdx].h; k++) {
                for (j = t.T[i].x; j < t.T[i].x + lk.T[t.T[i].usedByIdx].w; j++) {
                    EL(*mat, k, j) = t.T[i].usedByIdx + 1;
                }
            }
        }
    }
}

void printKulkas(MatKul mat, listKulkas lk) {
/* Mendisplay state kulkas */
    int i, j;
    for (i = 0; i < HEIGHT(mat); i++) {
        for (j = 0; j < WIDTH(mat); j++) {
            if (EL(mat, i, j) == -1) {
                printf("* ");
            } else {
                printf("%d ", EL(mat, i, j));
            }
            
        }
        printf("\n");
    }
    printf("\n");

    if (lk.length == 0) {
        printf("Kulkas kosong.\n");
    } else {
        printf("Isi Kulkas (Sorted dari ukuran terbesar):\n");
        printf("(nomor. nama - id - waktu kedaluarsa)\n");
        for (i = 0; i < lk.length; i++) {
            printf("%d. ", i + 1);
            printWord(nama(lk.T[i]));
            printf(" - %d - ", id(lk.T[i]));
            PrintKalimatDurasi(expired(lk.T[i]));
            printf("\n");
        }
    }
}

void printTA(treeArr t) {
    int i;
    for (i = 0; i < t.length; i++) {
        printf("%d ", t.T[i].usedByIdx);
    }
}

void printLK(listKulkas lk) {
    int i;
    for (i = 0; i < lk.length; i++) {
        printWord(nama(lk.T[i]));
        printf(", ");
    }
}