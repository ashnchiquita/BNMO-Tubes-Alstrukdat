#include <stdio.h>
#include "time.h"

int main(){
    TIME T;
    // Test create time
    CreateTime(&T,0,1,59);
    // Tes tulis waktu
    TulisTIME(T);
    // Tes next menit + menitToTIME dan TIMEToMenit
    NextMenit(&T);
    TulisTIME(T);
    // Tes next N menit
    NextNMenit(&T,50);
    TulisTIME(T);
    // Tes prev menit 
    PrevMenit(&T);
    // Tes prev N menit
    PrevNMenit(&T,80);
    return 0;
}