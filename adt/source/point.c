#include "../point.h"

#include <math.h>
#include <stdio.h>


void CreatePoint(POINT * P,int x, int y)
{
    if(isValid(x,y)){
        Absis(*P) = x;
        Ordinat(*P) = y;
    }else{
        printf("Point tidak valid!");
    }
}

void BacaPOINT(POINT *P){
    int x;
    int y;
    scanf("%d %d",&x,&y);

    while(!isValid(x,y)){
        printf("Point tidak valid!Silakan masukan lagi");
        scanf("%d %d",&x,&y);
    }
    CreatePoint(P,x,y);
}

void TulisPOINT(POINT P){
    printf("(%d,%d)", Absis(P), Ordinat(P));
}

boolean IsOrigin(POINT P){
    return(Absis(P) == 0 && Ordinat(P) == 0);
}
boolean isValid(int x, int y){
    return (x >= Min_X && x <= Max_X && y >= Min_Y && y <= Max_Y);
}

void NextX(POINT *P){
    int x = Absis(*P) + 1;
    int y = Ordinat(*P);
    if(!isValid(x,y)){
        x = Absis(*P); 
        y = Ordinat(*P);
    }
}

void NextY(POINT *P){
    int x = Absis(*P);
    int y = Ordinat(*P) +1;
    if(isValid(x,y)){
        Ordinat(*P) = y; 
        Absis(*P) = x;
    }
}

void PrevX(POINT *P){
    int x = Absis(*P)-1;
    int y = Ordinat(*P);
    if(isValid(x,y)){
        Ordinat(*P) = y; 
        Absis(*P) = x;
    }
}

void PrevY (POINT *P){
    int x =Absis(*P);
    int y = Ordinat(*P)-1;
    if(isValid(x,y)){
        Ordinat(*P) = y; 
        Absis(*P) = x;
    }
}

