
#include "../matrix.h"
#include "../config.h"

int main() {

    POINT lokasiPemain;
    Simulator pemain;
    Matrix peta = configPeta(&lokasiPemain);
    Word nama = {"BMNO", 4};
    createSimulator(&pemain, lokasiPemain, nama);

    printf("Apakah index matrix valid (-1, -1): %d\n", isMatrixIdxValid(-1, -1));
    printf("Apakah index matrix valid (1,1): %d\n", isMatrixIdxValid(1,1));

    IdxType lastIdxRow = getLastIdxRow(peta);
    IdxType lastIdxCol = getLastIdxCol(peta);
    printf("Last index row: %d\nLast index col: %d\n", lastIdxRow, lastIdxCol);

    printf("Apakah index matrix efektif (0,0): %d\n", isKoorIdxEff(peta, 0, 0));
    printf("Apakah index matrix efektif (50,50): %d\n", isKoorIdxEff(peta, 50, 50));


    TulisPOINT(lokasiPemain(pemain)); printf("\n");
    displayPeta(peta); printf("\n");
    boolean command = false;
    char c = 'A';
    while (c != 'e') {
        printf("Input arah untuk bergerak (N, W, S, E). Untuk exit, inputkan 'e'.\n");
        scanf(" %c", &c);
        if (c == 'N') {
            moveNorth(&peta, &pemain, &command);
        } else if (c == 'S') {
            moveSouth(&peta, &pemain, &command);
        } else if (c == 'E') {
            moveEast(&peta, &pemain, &command);
        } else if (c == 'W') {
            moveWest(&peta, &pemain, &command);
        }
        TulisPOINT(lokasiPemain(pemain)); printf("\n");
        displayPeta(peta); printf("\n");
        printf("Adjacency list (urutan: T, M, C, F, B, X), jika nilai 0 maka tidak adjacent, jika nilai 1 maka adjacent\n");
        boolean t = isLocAdjacent(peta, pemain, 'T');
        boolean m = isLocAdjacent(peta, pemain, 'M');
        boolean c = isLocAdjacent(peta, pemain, 'C');
        boolean f = isLocAdjacent(peta, pemain, 'F');
        boolean b = isLocAdjacent(peta, pemain, 'B');
        boolean x = isLocAdjacent(peta, pemain, 'X');
        printf("[%d, %d, %d, %d, %d, %d]\n", t, m, c, f, b, x);
    }

    printf("Mendapatkan posisi dari hanya kondisi peta (tidak dari ADT Simulator)\n");
    POINT pos;
    getPosition(peta, &pos);
    printf("Koordinat S: "); TulisPOINT(pos); printf("\n");

}