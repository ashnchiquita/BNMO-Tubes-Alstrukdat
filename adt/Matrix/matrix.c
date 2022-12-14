/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#include "matrix.h"
#include <stdio.h>
#include <math.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRows, int nCols, Matrix *m) {
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m) {
    return ROW_EFF(m) - 1;
}
IdxType getLastIdxCol(Matrix m) {
    return COL_EFF(m) - 1;
}

void getPosition(Matrix m, POINT *position){
    for(int i =0; i < ROW_EFF(m);i++){
        for(int j = 0; j < COL_EFF(m);j++){
            if(KOOR(m,j,i) == 'S'){
                Absis(*position) = i;
                Ordinat(*position) = j;
            }
        }
    }
}

boolean isMatrixIdxValid(int i, int j) {
    return i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP;
}

boolean isKoorIdxEff(Matrix m, IdxType i, IdxType j) {
    return i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m);
}



/* ********** KELOMPOK BACA/TULIS ********** */

void displayPeta(Matrix m) {
    IdxType i, j;
    for (i = -1; i <= ROW_EFF(m); i++) {
        for (j = -1; j <= COL_EFF(m); j++) {
            if (i == -1 || j == -1 || i == ROW_EFF(m) || j == COL_EFF(m)) {
                printf("*");
            } else if (KOOR(m, i, j) == '#') {
                printf(" ");
            } else {
                printf("%c", KOOR(m, i, j));
            }
            if (j != COL_EFF(m)) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* FUNGSI DAN PROSEDUR PADA PETA */
boolean isLocAdjacent(Matrix m, Simulator S, char loc) {
    int x = Absis(lokasiPemain(S)), y = Ordinat(lokasiPemain(S));
    return KOOR(m, y - 1, x) == loc || KOOR(m, y + 1, x) == loc || KOOR(m, y, x - 1) == loc || KOOR(m, y, x + 1) == loc;
}

void moveNorth(Matrix *m, Simulator *S, boolean *command) {
    int x = Absis(lokasiPemain(*S)), y = Ordinat(lokasiPemain(*S));
    if (y == 0) {
        printf("Simulator tidak bisa bergerak ke tempat tersebut!\n");
    } else if (KOOR(*m, y - 1, x) == 'T' || KOOR(*m, y - 1, x) == 'M' || KOOR(*m, y - 1, x) == 'C' || KOOR(*m, y - 1, x) == 'F' || KOOR(*m, y - 1, x) == 'B' || KOOR(*m, y - 1, x) == 'X') {
        printf("Simulator tidak bisa bergerak ke tempat tersebut!\n");
    } else {
        KOOR(*m, y - 1, x) = 'S';
        KOOR(*m, y, x) = ' ';
        Ordinat(lokasiPemain(*S))--;
        *command = true;
    }
}
void moveEast(Matrix *m, Simulator *S, boolean *command) {
    int x = Absis(lokasiPemain(*S)), y = Ordinat(lokasiPemain(*S));
    if (x == COL_EFF(*m) - 1) {
        printf("Simulator tidak bisa bergerak ke tempat tersebut!\n");
    } else if (KOOR(*m, y, x + 1) == 'T' || KOOR(*m, y, x + 1) == 'M' || KOOR(*m, y, x + 1) == 'C' || KOOR(*m, y, x + 1) == 'F' || KOOR(*m, y, x + 1) == 'B' || KOOR(*m, y, x + 1) == 'X') {
        printf("Simulator tidak bisa bergerak ke tempat tersebut!\n");
    } else {
        KOOR(*m, y, x + 1) = 'S';
        KOOR(*m, y, x) = ' ';
        Absis(lokasiPemain(*S))++;
        *command = true;
    }
}
void moveWest(Matrix *m, Simulator *S, boolean *command) {
    int x = Absis(lokasiPemain(*S)), y = Ordinat(lokasiPemain(*S));
    if (x == 0) {
        printf("Simulator tidak bisa bergerak ke tempat tersebut!\n");
    } else if (KOOR(*m, y, x - 1) == 'T' || KOOR(*m, y, x - 1) == 'M' || KOOR(*m, y, x - 1) == 'C' || KOOR(*m, y, x - 1) == 'F' || KOOR(*m, y, x - 1) == 'B' || KOOR(*m, y, x - 1) == 'X') {
        printf("Simulator tidak bisa bergerak ke tempat tersebut!\n");
    } else {
        KOOR(*m, y, x - 1) = 'S';
        KOOR(*m, y, x) = ' ';
        Absis(lokasiPemain(*S))--;
        *command = true;
    }
}
void moveSouth(Matrix *m, Simulator *S, boolean *command) {
    int x = Absis(lokasiPemain(*S)), y = Ordinat(lokasiPemain(*S));
    if (y == ROW_EFF(*m) - 1) {
        printf("Simulator tidak bisa bergerak ke tempat tersebut!\n");
    } else if (KOOR(*m, y + 1, x) == 'T' || KOOR(*m, y + 1, x) == 'M' || KOOR(*m, y + 1, x) == 'C' || KOOR(*m, y + 1, x) == 'F' || KOOR(*m, y + 1, x) == 'B' || KOOR(*m, y + 1, x) == 'X') {
        printf("Simulator tidak bisa bergerak ke tempat tersebut!\n");
    } else {
        KOOR(*m, y + 1, x) = 'S';
        KOOR(*m, y, x) = ' ';
        Ordinat(lokasiPemain(*S))++;
        *command = true;
    }
}

void fixedDisplay(Matrix *m, Simulator S){
    POINT temp;
    if(KOOR(*m,(S.lokasi.Y),(S.lokasi.X)) != 'S'){
        getPosition(*m,&temp);
        KOOR(*m,(S.lokasi.Y),(S.lokasi.X)) = 'S';
        KOOR(*m,Ordinat(temp),Absis(temp)) = '#';
    }
}