#include "./adt/config.h"
#include "./adt/commands.h"
#include "./adt/simulator.h"
#include "./adt/time.h"
#include "./adt/point.h"
#include "./adt/iohandling.h"

void tampilanLayar(Simulator pemain, TIME waktuMain){
    printWord(namaPemain(pemain));
    printf(" di posisi : ");
    TulisPOINT(lokasiPemain(pemain));
    printf("\n");
    printf("Waktu : %d.%d\n",Jam(waktuMain),Menit(waktuMain));
}

int main() {
    /* KAMUS */
    boolean started;
    Sentence command;
    int waitX, waitY;
    Word moveDirection, nama, pilihan;
    Simulator pemain;
    TIME waktuGame;
    ListMakanan listMakanan, buy;
    POINT lokasiPemain;
    Makanan temp;

    /* ALGORITMA */
    createSentence(&command);

    /* splash screen nyusul */

    printf("Silakan masukkan command (START/EXIT): ");
    command = takeInput();
    while (!(isSentenceEq(command, strToSentence("START")) || isSentenceEq(command, strToSentence("EXIT")))) {
        printf("Silakan masukkan command yang valid.\n");
        command = takeInput();
    }

    if (isSentenceEq(command, strToSentence("START"))) {
        started = true;
        
        /*Kalau udah config peta, tolong disimpen di lokasiPemain*/
        /*createPoint(&lokasiPemain,x,y)*/

        listMakanan = configMakanan();
        printf("Masukkan nama pertama anda : \n");
        /* validasi nama dulu harusnya */
        nama = (takeInput()).T[0];
        createSimulator(&pemain, lokasiPemain, nama);
        CreateTime(&waktuGame,0,0,0);
        printf("Konfigurasi selesai, selamat bermain ");
        printWord(namaPemain(pemain));
        printf("!\n");
    } else if (isSentenceEq(command, strToSentence("EXIT"))) {
        started = false;
    }

    while (started) {
        tampilanLayar(pemain,waktuGame);

        /* tampilkan peta kalo udah ada */

        printf("Enter Command: ");
        command = takeInput();
        if (!isEmptySentence(command)) {
            /* Handling input normal */
            if (isSentenceEq(command, strToSentence("MIX"))) {
                NextMenit(&waktuGame);

                /* CODE MIX */

            } else if (isSentenceEq(command, strToSentence("CHOP"))) {
                NextMenit(&waktuGame);

                /* CODE CHOP */

            } else if (isSentenceEq(command, strToSentence("FRY"))) {
                NextMenit(&waktuGame);

                /* CODE FRY */

                printMakanan(pengelompokanMakanan(listMakanan, strToWord("Fry")));
            } else if (isSentenceEq(command, strToSentence("BOIL"))) {
                NextMenit(&waktuGame);

                /* CODE BOIL */

                printMakanan(pengelompokanMakanan(listMakanan, strToWord("Boil")));
            } else if (isSentenceEq(command, strToSentence("UNDO"))) {
                
                /* CODE UNDO */
            
            } else if (isSentenceEq(command, strToSentence("REDO"))) {

                /* CODE REDO */
            
            } else if (isSentenceEq(command, strToSentence("CATALOG"))) {

                /* CODE CATALOG */
            
            } else if (isSentenceEq(command, strToSentence("COOKBOOK"))) {

                /* CODE COOKBOOK */
            
            } else if (isSentenceEq(command, strToSentence("BUY"))) {
                NextMenit(&waktuGame);

                /* CODE BUY */

                buy = pengelompokanMakanan(listMakanan, strToWord("Buy"));
                printCommand(buy, strToWord("Buy"));
                printf("Enter command: \n");
                pilihan = (takeInput()).T[0];

                while(!isFound(buy, wordToInt(pilihan) - 1) && wordToInt(pilihan) != 0){
                    printf("Nomor makanan tidak terdapat, silakan masukan input lagi\n");
                    printCommand(buy, strToWord("Buy"));
                    printf("Enter command: \n");
                    pilihan = (takeInput()).T[0];
                }

                if (isFound(buy, wordToInt(pilihan) - 1)){
                    temp = ELMT(buy, wordToInt(pilihan) - 1);
                    printf("dapet");
                    NextMenit(&waktuGame);

                    /* Push ke dalam delivery list (lagi nunggu kelar) */

                }
                
            } else if (isSentenceEq(command, strToSentence("DELIVERY"))) {
                NextMenit(&waktuGame);

                /* CODE DELIVERY */

            
            /* Handling input berargumen */
            } else if (isSentenceEq(command, strToSentence("MOVE NORTH")) || isSentenceEq(command, strToSentence("MOVE WEST")) || isSentenceEq(command, strToSentence("MOVE EAST")) || isSentenceEq(command, strToSentence("MOVE SOUTH"))) {
                moveDirection = command.T[1];
                NextMenit(&waktuGame);

                /* CODE MOVE */

                if (isWordEq(moveDirection, strToWord("NORTH"))) {
                    
                    /* MOVE NORTH */

                } else if (isWordEq(moveDirection, strToWord("WEST"))) {
                    
                    /* MOVE WEST */
                    
                } else if (isWordEq(moveDirection, strToWord("EAST"))) {
                    
                    /* MOVE EAST */
                    
                } else if (isWordEq(moveDirection, strToWord("SOUTH"))) {
                    
                    /* MOVE SOUTH */
                    
                }
                
            } else if (isWordEq(command.T[0], strToWord("WAIT")) && command.Length == 3) {
                if (isWordInt(command.T[1]) && isWordInt(command.T[2])) {
                    waitX = wordToInt(command.T[1]);
                    waitY = wordToInt(command.T[2]);

                    /* CODE WAIT */

                } else {
                    printf("Silakan masukkan command yang valid.\nUntuk melihat list command dan keterangannya, silakan masukkan command 'HELP'.");
                }
            } else {
                printf("Silakan masukkan command yang valid.\nUntuk melihat list command dan keterangannya, silakan masukkan command 'HELP'.");
            }
        } else {
            printf("Silakan masukkan command yang valid.\nUntuk melihat list command dan keterangannya, silakan masukkan command 'HELP'.");
        }
    }
    return 0;
}