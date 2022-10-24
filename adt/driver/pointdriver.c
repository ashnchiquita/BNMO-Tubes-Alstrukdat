#include "../point.h"
#include <stdio.h>

int main(){
    POINT P;
    int x = 0; 
    int y = 0; 
    // Tes create point
    CreatePoint(&P,x,y);

    // Tes tulis point
    TulisPOINT(P);

    // Tes baca point 
    BacaPOINT(&P);
    
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