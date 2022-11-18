#ifndef KULKAS_H
#define KULKAS_H

#include "boolean.h"
#include "makanan.h"
#include "wordmachine.h"
#include "time.h"

#define MAXHEIGHT 50
#define MAXWIDTH 50

#define MAXLK 200 /* pilih 200 karena ukuran kulkas yang dipilih 200 satuan luas */
#define MAXTA 256

typedef struct {
    Makanan T[MAXLK];
    int length;
} listKulkas; /* Ordered Array */

typedef struct {
    int x;
    int y;
    int w;
    int h;
    int usedByIdx;
} nodeDesc;

typedef struct {
    nodeDesc T[MAXTA];
    int length;
} treeArr;

typedef struct {
   int mem[MAXHEIGHT][MAXWIDTH];
   int height; /* banyaknya/ukuran baris yg terdefinisi */
   int width; /* banyaknya/ukuran kolom yg terdefinisi */
} MatKul;

#define HEIGHT(M) (M).height
#define WIDTH(M) (M).width
#define EL(M, i, j) (M).mem[(i)][(j)]

/* Ordered Array */
boolean isFullLK(listKulkas lk);

int max2(int w, int h);
/* Mencari maksimum dari 2 bilangan */

void createLK(listKulkas * lk);
/* Membuat list kulkas kosong */

void insertLK(listKulkas *lk, Makanan x);
/* Memasukkan makanan x ke dalam list kulkas */

void deleteLK(listKulkas *lk, int idx, Makanan *x);
/* Menghapus elemen ke idx dari list kulkas */

void copyLK(listKulkas * hasil, listKulkas lk);
/* Mengcopy list kulkas */

/* Node Desc */
void createND(nodeDesc *nd, int x, int y, int w, int h, int idx);
/* Membuat/Mengset node desc */

boolean isNodeUsed(nodeDesc nd);
/* Mengecek apakah node digunakan */

boolean isFit(Makanan test, nodeDesc nd);
/* Mengecek apakah makanan fit ke dalam node */

/* Tree */
void createTA(treeArr * t);
/* Membuat tree array kosong */

void insertTA(treeArr * t, nodeDesc nd, int idx);
/* Memasukkan nd sebagai elemen ke idx dari list kulkas */

void copyTA(treeArr * hasil, treeArr t);
/* Mengcopy tree array */

/* Kulkas Arrangement */
int findNode(treeArr t, Makanan test);
/* Mencari node yang cukup untuk menyimpan makanan test */

void splitNode(treeArr * t, int node, listKulkas lk, int lkIdx);
/* Memecah node menjadi 3 node (1 terisi, 2 kosong)*/

void arrangeKulkas(treeArr * t, listKulkas lk, boolean * success);
/* Meng-arrange listkulkas menjadi tree kulkas, success jika semua elemen list kulkas fit ke dalam kulkas */

void insertKulkas(treeArr * t, listKulkas * lk, Makanan test, boolean * success);
/* Menginsert makanan ke dalam kulkas. Insertion mungkin gagal */

void deleteKulkas(treeArr *t, listKulkas *lk, int lkIdx, Makanan *val, boolean * success);

/* Matrix Kulkas */
void CreateMatKul(int nRows, int nCols, MatKul *m);

/* IO */
void matrixKulkas(MatKul * mat, treeArr t, listKulkas lk);
/* Membuat matriks kulkas */

void printKulkas(MatKul mat, listKulkas lk);
/* Mendisplay state kulkas */

#endif