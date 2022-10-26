#include "wordmachine.h"
#include "charmachine.h"
#include "time.h"
#include <stdio.h>
#include "makanan.h"

int wordToInt(Word w){
    int jumlah = 0; 
    for(int i = 0; i < w.Length;i++){
        jumlah = jumlah * 10 + (w.TabWord[i]-48);
    }
    return jumlah;
}

int main(){
    Word temp1;
    MAKANAN mTemp;
    int HH,JJ,MM;
    START();

    // Kapasitas maksimal list
    ADVWORD();
    int n = wordToInt(currentWord);
    int i = 0; 
    printf("%d\n",n);
    ADVNEWLINE();
    ListMakanan l;
    CreateListMakanan(&l);
    while(!EndWord){
        // ID dari makanan
        ADVWORD();
        int id = wordToInt(currentWord);
        printf("%d\n",id);
        ADVNEWLINE();


        // Nama makanan 
        ADVWORD();
        Word nama= readMakanan();
        printWord(currentWord);
        ADVNEWLINE();

        // Waktu Expired makanan
        ADVWORD();
        TIME expired;
        HH = wordToInt(currentWord);

        ADVWORD();
        JJ = wordToInt(currentWord);

        ADVWORD();
        MM = wordToInt(currentWord);
        CreateTime(&expired,HH,JJ,MM);
        TulisTIME(expired);
        ADVNEWLINE();
        
        // Waktu Pengiriman 
        ADVWORD();
        TIME delivery;
        HH = wordToInt(currentWord);

        ADVWORD();
        JJ = wordToInt(currentWord);

        ADVWORD();
        MM = wordToInt(currentWord);
        CreateTime(&delivery,HH,JJ,MM);
        TulisTIME(delivery);
        ADVNEWLINE();

        // Aksi 
        ADVWORD();
        Word aksi;
        aksi = CopyPaste(currentWord);
        printWord(aksi);
        if(i == n-1){
            ADVWORD();
        }else{
            ADVNEWLINE();
        }
        MAKANAN mTemp = {id,nama,expired,delivery,aksi};
        addMakanan(&l,mTemp);
        i++;
    }
    printf("%d\n",panjangListMakanan(l));
    printMakanan(l);
}