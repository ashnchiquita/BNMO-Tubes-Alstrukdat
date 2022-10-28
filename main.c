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
        POINT lokasiPemain;
        ListMakanan listMakanan = configMakanan();
        printf("Masukkan nama pertama anda : \n");
        STARTINPUT();
        createSimulator(&pemain,lokasiPemain,currentWord);
        CreateTime(&waktuGame,0,0,0);
        printf("Konfigurasi selesai, selamat bermain ");
        printWord(namaPemain(pemain));
        printf("!\n");
        tampilanLayar(pemain,waktuGame);
        printf("Enter Command :");
        
        STARTINPUT();
        switch(startCommand(currentWord)){
            case 1 : 
                printf("Game sudah dimulai, masukan input yang lain!");
            case 2 :
            case 3: 
                printMakanan(listMakanan);
            case 4 : 
                Word Buy = {"Buy",3};
                printMakanan(pengelompokanMakanan(listMakanan,Buy));
            case 5: 
            case 6 : 
            case 7: 
        }
    }
    return 0;
}