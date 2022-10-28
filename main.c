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

        /*Kalau udah config peta, tolong disimpen di lokasiPemain*/
        POINT lokasiPemain;
        /*createPoint(&lokasiPemain,x,y)*/

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
                NextMenit(&waktuGame);
                ListMakanan buy = pengelompokanMakanan(listMakanan,Buy);
                printCommand(buy,Buy);
                printf("Enter command: \n");
                STARTWORD();
                while(!isFound(buy,wordToInt(currentWord)-1) && wordToInt(currentWord) != 0){
                    printf("Nomor makanan tidak terdapat, silakan masukan input lagi\n");
                    printCommand(buy,Buy);
                    printf("Enter command: \n");
                    STARTWORD();
                }
                if(isFound(buy,wordToInt(currentWord)-1)){
                    Makanan temp = ELMT(buy,wordToInt(currentWord)-1);
                    printf("dapet");
                    NextMenit(&waktuGame);
                    /* Push ke dalam delivery list (lagi nunggu kelar)*/
                }
                break;
            case 5: 
                Word Fry = {"Fry",3};
                NextMenit(&waktuGame);
                printMakanan(pengelompokanMakanan(listMakanan,Fry));
            case 6 : 
                Word Boil = {"Boil",4};
                printMakanan(pengelompokanMakanan(listMakanan,Boil));
           
        }
    }
    return 0;
}