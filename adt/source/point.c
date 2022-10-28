#include "../point.h"

#include <math.h>
#include <stdio.h>


void CreatePoint(POINT * P,int x, int y)
{   
    Absis(*P) = x;
    Ordinat(*P) =y;
}

void TulisPOINT(POINT P){
    printf("(%d,%d)", Absis(P), Ordinat(P));
}

boolean IsOrigin(POINT P){
    return(Absis(P) == 0 && Ordinat(P) == 0);
}

void NextX(POINT *P){
    int x = Absis(*P) + 1;
    int y = Ordinat(*P);
}

void NextY(POINT *P){
    int x = Absis(*P);
    int y = Ordinat(*P) +1;
}

void PrevX(POINT *P){
    int x = Absis(*P)-1;
    int y = Ordinat(*P);
}

void PrevY (POINT *P){
    int x =Absis(*P);
    int y = Ordinat(*P)-1;
}

