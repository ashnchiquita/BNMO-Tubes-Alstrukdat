#include "../commands.h"
#include <stdio.h>

int main(){
    TIME T1; 
    TIME T2;
    ListMakanan l;
    Word makanan = {"Ayam",4};
    Word makanan2 = {"Ikan",4};
    Word aksi = {"Fry",3};
    CreateTime(&T1,0,2,3);
    CreateTime(&T2,0,0,15);
    Makanan temp = {1,makanan,T1,T2,aksi,2,3};
    Makanan temp2 = {3,makanan2,T2,T1,aksi,2,4};
    CreateListMakanan(&l);
    addMakanan(&l,temp);
    addMakanan(&l,temp2);
    
    notifikasiPembelian(temp);
    notifikasiGoreng(temp);
    notifikasiGagal(l);
    
}