#include "wordmachine.h"
#include "charmachine.h"
#include "time.h"
#include <stdio.h>
#include "makanan.h"

// Mengubah Word ke integer
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

    // Mendapatkan banyaknya data makanan yang akan diberikan
    ADVWORD();
    int n = wordToInt(currentWord);
    int i = 0; 
    ADVNEWLINE();

    // Membuat ListMakanan untuk menampung semua makanan yang ada 
    ListMakanan l;
    CreateListMakanan(&l);
    while(!EndWord){
        // Mendapatkan ID makanan
        ADVWORD();
        int id = wordToInt(currentWord);
        ADVNEWLINE();

        // Mendapatkan nama makanan 
        ADVWORD();
        Word nama= readMakanan();
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

        /*Jika sudah berada pada MAKANAN terakhir dalam list, gunakan ADVWORD
        agar MARK terbaca dan EndWord bernilai True*/ 
        if(i == n-1){
            ADVWORD();
        }else{
            /*Jika belum pada MAKANAN terakhir di list, gunakan ADVNEWLINE
            agar MARK tidak terbaca dan EndWord bernilai false*/
            ADVNEWLINE();
        }

        // Simpan data - data di atas dalam variable MAKANAN mTemp
        MAKANAN mTemp = {id,nama,expired,delivery,aksi};
        // Masukkan mTemp ke dalam ListMakanan
        addMakanan(&l,mTemp);
        i++;
    }
    printMakanan(l);
}