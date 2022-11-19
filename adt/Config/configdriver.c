#include "config.h"

int main(){
    // ListMakanan l= configMakanan();
    // printMakanan(l);

    POINT lokasiPemain;
    Matrix peta = configPeta(&lokasiPemain);
    TulisPOINT(lokasiPemain); printf("\n");
    displayPeta(peta); printf("\n");
    return 0;
}