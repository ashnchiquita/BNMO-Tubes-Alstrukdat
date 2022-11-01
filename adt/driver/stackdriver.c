#include "../stack.h"
#include "../time.h"
#include "../point.h"
#include "../prioqueue.h"

int main(){
    TIME T1; 
    TIME T2; 
    PrioQueue deliveryList;
    PrioQueue inventoryList;
    POINT p1;
    Stack S;
    CreateEmptyStack(&S);
    CreatePoint(&p1,2,2);
    Word nama = {"Ayam",4};
    Word aksi = {"chop",4};
    Word Buy = {"BUY",3};
    CreateTime(&T1,1,0,0);
    CreateTime(&T2,0,2,15);
    Makanan m = {12,nama,T1,T2,aksi};
    Makanan m2 = {20,nama,T1,T2,aksi};

    MakeEmptyQ(&deliveryList,5,true);
    MakeEmptyQ(&inventoryList,5,false);

    Enqueue(&deliveryList,m);
    Enqueue(&inventoryList,m2);

    states temp = {T1,p1,deliveryList,inventoryList};
    PushStack(&S,temp);
    TIME waktu = InfoTopStack(S).waktuMain;
    TulisTIME(waktu);
    states temp2 = {T2,p1,deliveryList,inventoryList};
    PushStack(&S,temp2);
    TulisTIME(InfoTopStack(S).waktuMain);
}