#include "time.h"
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

/* Variasi Print */
void TulisTIME (TIME T){
    printf("%d %d %d",Hari(T),Jam(T),Menit(T));
};
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
void TulisJam (TIME T) {
/* I.S. T terdefinisi */
/* F.S. Nilai T ditulis dengan format JJ.MM */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("%02d.%02d",Jam(T),Menit(T));
}
void PrintKalimatDurasi (TIME T) {
/* I.S. T terdefinisi, T merupakan suatu TIME yang dianggap sebagai durasi, T bukan durasi nol */
/* F.S. Nilai T ditulis dengan format <x> hari <y> jam <z> menit */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (Hari(T) != 0) {
        printf("%d hari", Hari(T));
    }
    if (Hari(T) != 0 && Jam(T) != 0) {
        printf(" ");
    }
    if (Jam(T) != 0) {
        printf("%d jam", Jam(T));
    }
    if (Menit(T) != 0 && Jam(T) != 0) {
        printf(" ");
    }
    if (Hari(T) != 0 && Jam(T) == 0 && Menit(T) != 0) {
        printf(" ");
    }    
    if (Menit(T) != 0) {
        printf("%d menit", Menit(T));
    }
}

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
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2) {
/* Mengirimkan true jika T1=T2, false jika tidak */
    return (Hari(T1) == Hari(T2) && Jam(T1) == Jam(T2) && Menit(T1) == Menit(T2));
}
boolean TNEQ (TIME T1, TIME T2) {
/* Mengirimkan true jika T1 tidak sama dengan T2 */
    return !(TEQ(T1, T2));
}
boolean TLT (TIME T1, TIME T2) {
/* Mengirimkan true jika T1<T2, false jika tidak */
    return TIMEToMenit(T1) < TIMEToMenit(T2);
}
boolean TGT (TIME T1, TIME T2) {
/* Mengirimkan true jika T1>T2, false jika tidak */
    return TIMEToMenit(T1) > TIMEToMenit(T2);
}
boolean isZeroTIME (TIME T) {
/* Mengirimkan true jika T = 00:00:00, false jika tidak */
    return (Hari(T) == 0 && Jam(T) == 0 && Menit(T) == 0);
}

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
void handleWait(TIME *T, int h, int m){
    int temp = TIMEToMenit(*T) + h*60 + m;
    *T = MenitToTIME(temp);
}
