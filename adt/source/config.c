#include "../config.h"
#include <stdio.h>
#include <stdlib.h>

ListMakanan *configMakananP(){
    Word temp1;
    Makanan mTemp;
    boolean finised = false;
    int HH,JJ,MM;
    STARTFILE("./adt/configMakanan.txt");
    // Mendapatkan banyaknya data makanan yang akan diberikan
    ADVWORD();
    int n = wordToInt(currentWord);
    int i = 0;
    ADVNEWLINE();

    // Membuat ListMakanan untuk menampung semua makanan yang ada
    ListMakanan *l = malloc(sizeof(ListMakanan));
    CreateListMakanan(l);
    while(!EndWord && !finised){
        // Mendapatkan ID makanan
        ADVWORD();
        int id = wordToInt(currentWord);
        ADVNEWLINE();

        // Mendapatkan nama makanan
        ADVSPASI();
        Word nama = currentWord;
        ADVNEWLINE();

        // Mendapatkan Waktu Expired makanan
        ADVWORD();
        TIME expired;
        // Mendapatkan hari expired  makanan
        HH = wordToInt(currentWord);
        // Mendapatkan jam expired makanan
        ADVWORD();
        JJ = wordToInt(currentWord);
        // Mendapatkan menit expired makanan
        ADVWORD();
        MM = wordToInt(currentWord);

        // Membuat waktu dengan hari,jam, dan menit yang sudah ada
        CreateTime(&expired,HH,JJ,MM);
        ADVNEWLINE();

        // Mendapatkan Waktu Pengiriman makanan
        ADVWORD();
        TIME delivery;
        // Mendapatkan hari delivery makanan
        HH = wordToInt(currentWord);
        // Mendapatkan jam delivery makanan
        ADVWORD();
        JJ = wordToInt(currentWord);
        // Mendapatkan menit delivery makanan
        ADVWORD();
        MM = wordToInt(currentWord);
        // Membuat waktu delivery dengan hari,jam, dan menit yang ada
        CreateTime(&delivery,HH,JJ,MM);
        ADVNEWLINE();

        // Mendapatkan aksi makanan
        ADVWORD();
        Word aksi;
        aksi = CopyPaste(currentWord);
        ADVNEWLINE();

        // Mendapatkan width makanan 
        ADVWORD();
        int width;
        width = wordToInt(currentWord);
        ADVNEWLINE();

        // Mendapatkan height makanan 
        ADVWORD();
        int height;
        height = wordToInt(currentWord);

        /*Jika sudah berada pada MAKANAN terakhir dalam list, gunakan ADVWORD
        agar MARK terbaca dan EndWord bernilai True*/
        if(i == n-1){
            finised = true;
        }else{
            /*Jika belum pada MAKANAN terakhir di list, gunakan ADVNEWLINE
            agar MARK tidak terbaca dan EndWord bernilai false*/
            ADVNEWLINE();
        }

        // Simpan data - data di atas dalam variable MAKANAN mTemp
        Makanan mTemp = {id,nama,expired,delivery,aksi, width, height};
        if(isIdFound(*l,id)){
            setMakanan(l,mTemp,id);
        }else{
            // Masukkan mTemp ke dalam ListMakanan
            addMakanan(l,mTemp);
        }
        i++;
    }
    return l;
    // printMakanan(l);
}

Matrix configPeta(POINT *lokasiPemain) {
    Matrix peta;
    STARTFILE("./adt/configPeta.txt");
    int ncol, nrow;
    ADVWORD();
    nrow = wordToInt(currentWord);
    ADVWORD();
    ncol = wordToInt(currentWord);
    CreateMatrix(nrow, ncol, &peta);
    ADVNEWLINE();


    int j = 0;
    ADVWORD();
    while(!EndWord) {
        for (int i = 0; i < currentWord.Length; i++) {
            KOOR(peta, j, i) = currentWord.TabWord[i];
            if (KOOR(peta, j, i) == 'S') {
                CreatePoint(lokasiPemain, i, j);
            }
        }

        if (j != nrow - 1) {
            ADVNEWLINE();
            ADVWORD();
        } else {
            ADVWORD();
        }
        j++;
    }
    return peta;
}