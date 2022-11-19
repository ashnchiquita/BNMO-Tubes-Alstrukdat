#include "../makanan.h"
#include "../wordmachine.h"
#include <stdio.h>

void CreateListMakanan(ListMakanan *l){
    for(int i = IDX_MIN; i < CAPACITY;i++){
        id((*l).contents[i]) = -1;
    }
}

int panjangListMakanan(ListMakanan l){
    int i = IDX_MIN;
    int count = 0;
    while(id(l.contents[i]) != -1){
        i++;
        count++;
    }
    return i;
}


void printMakanan(ListMakanan l){
    printf("===================  List Makanan  =======================\n");
    printf("Nama - Durasi Kadaluwarsa - Aksi yang Diperlukan - Action Time\n");
    int length = panjangListMakanan(l);
    for(int i =0 ; i < length;i++){
        printf("%d.",i+1);
        printWord(nama(l.contents[i]));
        printf(" - ");
        TulisTIME(expired(l.contents[i]));
        printf(" - ");
        printWord(aksi(l.contents[i]));
        printf(" - ");
        TulisTIME(actionTime(l.contents[i]));
        printf("\n");
    }
}

void addMakanan(ListMakanan *l,Makanan m){
    int length = panjangListMakanan(*l);
    makanan(*l,length) = m;
}


ListMakanan pengelompokanMakanan(ListMakanan l,Word w){
    Word Buy = {"Buy",3};
    Word Chop = {"Chop",4};
    Word Fry = {"Fry",3};
    Word Boil = {"Boil",4};
    Word Mix = {"Mix",3};
    ListMakanan lResult;
    CreateListMakanan(&lResult);
    if(wordEqual(w,Buy)){
        for(int i =0 ; i < panjangListMakanan(l);i++){
            if(wordEqual(aksi(l.contents[i]),Buy)){
                addMakanan(&lResult,l.contents[i]);
            }
        }
    }else if(wordEqual(w,Chop)){
        for(int i =0 ;i < panjangListMakanan(l);i++){
            if(wordEqual(aksi(l.contents[i]),Chop)){
                addMakanan(&lResult,l.contents[i]);
            }
        }
    }else if(wordEqual(w,Fry)){
        for(int i =0 ; i < panjangListMakanan(l);i++){
            if(wordEqual(aksi(l.contents[i]),Fry)){
                addMakanan(&lResult,l.contents[i]);
            }
        }
    }else if(wordEqual(w,Boil)){
        for(int i =0 ; i < panjangListMakanan(l);i++){
            if(wordEqual(aksi(l.contents[i]),Boil)){
                addMakanan(&lResult,l.contents[i]);
            }
        }
    }
    else if(wordEqual(w,Mix)){
        for(int i =0 ; i < panjangListMakanan(l);i++){
            if(wordEqual(aksi(l.contents[i]),Mix)){
                addMakanan(&lResult,l.contents[i]);
            }
        }
    }
    return lResult;
}
int getIdx(ListMakanan l, int id){
    int i = 0 ;
    while(id(ELMT(l,i)) != id){
        i++;
    }
    return i;
}



void printCommand(ListMakanan l, Word command){
    printf("==================================\n");
    printf("========    ");
    printWord(command); 
    printf("      =============\n");
    printf("==================================\n");
    for(int i =0 ; i < panjangListMakanan(l);i++){
        printf("%d. ",i+1);
        TIME temp = actionTime(ELMT(l,i));
        printWord(nama(ELMT(l,i)));
        if(!isZeroTIME(actionTime(l.contents[i]))){
            printf(" (");
            PrintKalimatDurasi(temp);
            printf(")");
        };
        printf("\n");
    }
    printf("Masukkan 0 untuk kembali ke Menu\n");
}

boolean isFound(ListMakanan l, int idx){
    return(idx >= 0 && idx < panjangListMakanan(l));
}