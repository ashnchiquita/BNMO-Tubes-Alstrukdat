#include "../point.h"
#include <stdio.h>

int main(){
    POINT P;
    // Nanti diganti setelah baca map dari file (tunggu ADT Map)
    int maxB = 10;
    int maxK = 10;
    // Tes create point
    CreatePoint(&P,maxK,maxB);
    
    // Tes tulis point
    TulisPOINT(P);

    // Tes baca point 
    
    // Tes move left (PrevX)
    NextX(&P);
    TulisPOINT(P);
    // TulisPOINT(P);

    // Tes move right (NextX)
    PrevX(&P);
    TulisPOINT(P);

    // Tes move up 
    NextY(&P);
    TulisPOINT(P);

    // Tes move down
    PrevY(&P);
    TulisPOINT(P);

    // Tes kalau point over dari batas yang ada
    PrevX(&P);
    TulisPOINT(P);
    PrevX(&P);
    TulisPOINT(P);
    PrevX(&P);
    TulisPOINT(P);

    return 0;
}