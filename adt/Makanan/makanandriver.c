#include "makanan.h"
#include <stdio.h>

int main(){
    ListMakanan l1;
    TIME T1; 
    TIME T2; 
    Word nama = {"Ayam",4};
    Word aksi = {"chop",4};
    Word Buy = {"BUY",3};
    CreateTime(&T1,1,0,0);
    CreateTime(&T2,0,2,15);

    // Testint create list makanan
    CreateListMakanan(&l1);
    Makanan m = {12,nama,T1,T2,aksi};
    Makanan m2 = {20,nama,T1,T2,aksi};
    // Testing add makanan ke dalam list makanan
    addMakanan(&l1,m);
    addMakanan(&l1,m2);
    // Testing print makanan yang sudah dikelompokan berdasarkan aksinya
    ListMakanan lresult = (pengelompokanMakanan(l1,aksi));
    printMakanan(lresult);
    printCommand(lresult,Buy);
    // printf("%d\n",getIdx(l1,20));
    return 0;
}