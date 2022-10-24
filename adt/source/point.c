#include "../point.h"

#include <math.h>
#include <stdio.h>

boolean isValid(POINT P,int x, int y){
    return (x >= Min_X && x <= MAXK(P) && y >= Min_Y && y <= MAXB(P));
}

void CreatePoint(POINT * P,int maxKanan, int maxBawah)
{   
    Absis(*P) = 0;
    Ordinat(*P) =0;
    MAXK(*P) = maxKanan;
    MAXB(*P) = maxBawah;
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
    if(isValid(*P,x,y)){
        Absis(*P) =x;
        Ordinat(*P) = y;
    }
}

void NextY(POINT *P){
    int x = Absis(*P);
    int y = Ordinat(*P) +1;
    if(isValid(*P,x,y)){
        Ordinat(*P) = y; 
        Absis(*P) = x;
    }
}

void PrevX(POINT *P){
    int x = Absis(*P)-1;
    int y = Ordinat(*P);
    if(isValid(*P,x,y)){
        Ordinat(*P) = y; 
        Absis(*P) = x;
    }
}

void PrevY (POINT *P){
    int x =Absis(*P);
    int y = Ordinat(*P)-1;
    if(isValid(*P,x,y)){
        Ordinat(*P) = y; 
        Absis(*P) = x;
    }
}

