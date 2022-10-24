#include "../time.h"
#include <stdio.h>

boolean IsTIMEValid (int H, int J, int M){
    return((H >= 0) && (J >= 0 && J <= 23) && (M >= 0 && M<=59));
}

void CreateTime (TIME * T, int HH, int JJ, int MM)
{
    Hari(*T) = HH;
    Jam(*T) = JJ;
    Menit(*T) = MM;
}

void BacaTIME (TIME * T)
{
    int HH;
    int JJ;
    int MM;
    scanf("%d %d %d",&HH,&JJ,&MM);
    while(!(IsTIMEValid(HH,JJ,MM))){
        printf("Jam tidak valid\n");
        scanf("%d %d %d",&HH,&JJ,&MM);
    }
    CreateTime(T,HH,JJ,MM);
}
void TulisTIME (TIME T){
    printf("%d:%d:%d\n",Hari(T),Jam(T),Menit(T));
};
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
int TIMEToMenit(TIME T){
    return(Hari(T) * 24 * 60 + Jam(T) * 60 + Menit(T));
};
TIME MenitToTIME (int menit){
    TIME T;
    Hari(T) = menit/1440;
    Jam(T) = (menit - Hari(T) * 1440)/60;
    Menit(T) = (menit - Hari(T)*1440 - Jam(T) * 60);
    return T;
}; 

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */

/* *** Operator aritmatika TIME *** */
void NextMenit (TIME *T){
    int menit = TIMEToMenit(*T)+1;
    *T = MenitToTIME(menit);
};

/* Mengirim 1 detik setelah T dalam bentuk TIME */
void NextNMenit (TIME *T, int N){
    int menit = TIMEToMenit(*T) +N;
    *T = MenitToTIME(menit);
};
/* Mengirim N detik setelah T dalam bentuk TIME */
void PrevMenit (TIME *T){
    int menit = TIMEToMenit(*T)-1;
    *T = MenitToTIME(menit);;
};
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
void PrevNMenit (TIME *T, int N){
    int menit = TIMEToMenit(*T)-N;
    *T = MenitToTIME(menit);
};
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */

