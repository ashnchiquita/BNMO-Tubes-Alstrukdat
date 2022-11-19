#include "kulkas.h"

#include <stdio.h>

int main() {
    Makanan food;
    int command, hari, jam, menit, N, idx;
    boolean working, success;
    listKulkas lk;
    treeArr t;
    MatKul mat;

    working = true;
    createLK(&lk);
    createTA(&t);

    while (working) {
        printf("List command:\n");
        printf("1. Masukkan makanan ke kulkas\n");
        printf("2. Ambil makanan dari kulkas\n");
        printf("3. Selesai\n");

        printf("\nPilih command: ");
        STARTWORD();
        command = wordToInt(currentWord);

        if (command == 1) {
            if (isFullLK(lk)) {
                printf("Kulkas penuh.\n");
            } else {
                printf("\nMasukkan data makanan: \n");
                printf("ID : "); 
                STARTWORD();
                id(food) = wordToInt(currentWord);

                printf("Nama : "); 
                STARTWORD();
                nama(food) = CopyPaste(currentWord);

                printf("Waktu expired (<hari> <jam> <menit>) : ");
                STARTWORD();
                hari = wordToInt(currentWord);
                ADVWORD();
                jam = wordToInt(currentWord);
                ADVWORD();
                menit = wordToInt(currentWord);
                CreateTime(&expired(food), hari, jam, menit);

                printf("Waktu aksi (<hari> <jam> <menit>): ");
                STARTWORD();
                hari = wordToInt(currentWord);
                ADVWORD();
                jam = wordToInt(currentWord);
                ADVWORD();
                menit = wordToInt(currentWord);
                CreateTime(&actionTime(food), hari, jam, menit);

                printf("Aksi : "); 
                STARTWORD();
                aksi(food) = CopyPaste(currentWord);

                printf("Width makanan: ");
                STARTWORD();
                w(food) = wordToInt(currentWord);

                printf("Height makanan: ");
                STARTWORD();
                h(food) = wordToInt(currentWord);
                
                insertKulkas(&t,&lk,food,&success);
                
                if (success) {
                    printf("Makanan berhasil dimasukkan ke dalam kulkas.\n");
                } else {
                    printf("Makanan gagal dimasukkan ke dalam kulkas karena kulkas penuh.\n");
                }
            }


        } else if (command == 2) {           
            if (lk.length == 0) {
                printf("Kulkas kosong.\n");
            } else {
                printf("\nNomor makanan di kulkas: "); 
                STARTWORD();
                idx = wordToInt(currentWord) - 1;
                
                deleteKulkas(&t, &lk, idx, &food, &success);
                
                if (success) {
                    printf("Makanan berhasil dihapus dari kulkas.\n");
                } else {
                    printf("Makanan gagal dihapus dari kulkas.\n");
                }
                
                printf("\n\nData makanan yang diambil: \n");
                printf("ID : %d\n", id(food)); 

                printf("Nama : "); 
                printWord(nama(food));
                printf("\n");

                printf("Waktu expired : ");
                TulisTIME(expired(food));
                printf("\n");
            
                printf("Waktu aksi : ");
                TulisTIME(actionTime(food));
                printf("\n");
            
                printf("Aksi : "); 
                printWord(aksi(food));
                printf("\n");

                printf("Width, Height makanan: %d, %d\n", w(food), h(food));
            }

        } else {
            working = false;
        }

        printf("\nSTATE KULKAS:\n");
        matrixKulkas(&mat, t, lk);
        printKulkas(mat, lk);
        printf("\n");
    }
}