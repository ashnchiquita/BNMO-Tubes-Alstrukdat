#include "./adt/config.h"
#include "./adt/commands.h"
#include "./adt/simulator.h"
#include "./adt/time.h"
#include "./adt/point.h"

void tampilanLayar(Simulator pemain, TIME waktuMain){
    printWord(namaPemain(pemain));
    printf(" di posisi : ");
    TulisPOINT(lokasiPemain(pemain));
    printf("\n");
    printf("Waktu : %d.%d\n",Jam(waktuMain),Menit(waktuMain));
}

boolean validasiInput(Word input){

}
int main(){
    printf("======== Selamat datang ke game BNMO ==============\n");
    printf("List Command : \n");
    printf("1. START untuk memulai game \n");
    printf("2. EXIT untuk keluar game \n");
    printf("Silakan masukan command yang diinginkan : ");
    STARTWORD();
    while(startCommand(currentWord) != 1 &&startCommand(currentWord) != 2){
        printf("Command tidak valid\n");
        printf("Silakan masukan command yang diinginkan : ");
        STARTWORD();
    }
    if(startCommand(currentWord) == 1){
        Simulator pemain;
        TIME waktuGame;
        ListMakanan listMakanan = configMakanan();
        printf("Masukkan nama pertama anda : \n");
        STARTINPUT();
        createSimulator(&pemain,currentWord);
        CreateTime(&waktuGame,0,1,23);
        printf("Konfigurasi selesai, selamat bermain ");
        printWord(namaPemain(pemain));
        printf("!\n");
        tampilanLayar(pemain,waktuGame);
        printf("Enter Command :");
        
        STARTINPUT();
        Word Catalog = {"Catalog",7};
        if(startCommand(currentWord) == 3){
            printMakanan(listMakanan);
        }

    }
    return 0;
}