#include "../makanan.h"
#include <stdio.h>

int main(){
    ListMakanan l1;
    TIME T1; 
    TIME T2; 
    Word nama = {"Ayam",4};
    Word aksi = {"chop",4};
    CreateTime(&T1,1,0,0);
    CreateTime(&T1,0,0,15);
    // Testint create list makanan
    CreateListMakanan(&l1);
    Makanan m = {12,nama,T1,T2,aksi};

    // Testing add makanan ke dalam list makanan
    addMakanan(&l1,m);

    // Testing print makanan yang sudah dikelompokan berdasarkan aksinya
    printMakanan(pengelompokanMakanan(l1,aksi));
    return 0;
}