/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"
#include "simulator.h"
#include "time.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; /* Index baris, kolom */
typedef char KoorType;
typedef struct
{
   KoorType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRows, int nCols, Matrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define KOOR(M, i, j) (M).mem[(i)][(j)]


/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m);
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m);
/* Mengirimkan Index kolom terbesar m */
boolean isMatrixIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
boolean isKoorIdxEff(Matrix m, IdxType i, IdxType j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
void getPosition(Matrix m, POINT *position);
/* I.S. m terdefinisi, position sembarang*/
/* F.S. Nilai absis dan ordinat dari position diisi dengan absis dan ordinat Simulator*/

/* ********** KELOMPOK BACA/TULIS ********** */

void displayPeta(Matrix m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis peta 10x10
* * * * * * * * * * * *
*                     *
*         T S   X     *
*   M           X     *
*               X     *
*         X X X X     *
*   X                 *
*   X             C   *
*   X X X     F       *
*                     *
*             B       *
* * * * * * * * * * * *

*/


/* FUNGSI DAN PROSEDUR PADA PETA */
boolean isLocAdjacent(Matrix m, Simulator S, char loc);
/* Mengirimkan true jika suatu alat/lokasi masak adjacent (berada di samping) dengan Simulator */
void moveNorth(Matrix *m, Simulator *S, boolean *command);
/* I.S. m terdefinisi, S terdefinisi, command sembarang*/
/* F.S. Nilai ordinat dari S berkurang 1 (S bergerak ke arah utara sebanyak satu petak)*/
void moveEast(Matrix *m, Simulator *S, boolean *command);
/* I.S. m terdefinisi, S terdefinisi, command sembarang*/
/* F.S. Nilai absis dari S bertambah 1 (S bergerak ke arah timur sebanyak satu petak)*/
void moveWest(Matrix *m, Simulator *S, boolean *command);
/* I.S. m terdefinisi, S terdefinisi, command sembarang*/
/* F.S. Nilai absis dari S berkurang 1 (S bergerak ke arah barat sebanyak satu petak)*/
void moveSouth(Matrix *m, Simulator *S, boolean *command);
/* I.S. m terdefinisi, S terdefinisi, command sembarang*/
/* F.S. Nilai ordinat dari S bertambah 1 (S bergerak ke arah selatan sebanyak satu petak)*/
void fixedDisplay(Matrix *m, Simulator S);
/* Menyesuaikan display peta saat command undo dan redo */
#endif