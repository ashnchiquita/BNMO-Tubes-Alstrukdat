#include "../makanan.h"
#include <stdio.h>

Word readMakanan(){
    int i = 1;
    Word tempWord;
    int index = currentWord.Length;
    char temp = currentChar;
    while(currentChar != MARK){
        i++;
        tempWord.TabWord[i-1] = currentChar;
        ADV();
    }
    tempWord.Length = i;
    Word w3 = concatWord(currentWord,tempWord);
    return w3;

}
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
    printf("List Makanan\n");
    printf("nama - durasi kadaluwarsa - aksi yang diperlukan - delivery time\n");
    int length = panjangListMakanan(l);
    for(int i =0 ; i < length;i++){
        printf("%d. ",i+1);
        printWord(nama(l.contents[i]));
        printf(" - ");
        TulisTIME(expired(l.contents[i]));
        printf(" - ");
        printWord(aksi(l.contents[i]));
        printf(" - ");
        TulisTIME(delivery(l.contents[i]));
        printf("\n");
    }
}

void addMakanan(ListMakanan *l,MAKANAN m){
    int length = panjangListMakanan(*l);
    makanan(*l,length) = m;
}


ListMakanan pengelompokanMakanan(ListMakanan l,Word w){
    Word Buy = {"BUY",3};
    Word Chop = {"Chop",4};
    Word Fry = {"Fry",3};
    Word Boil = {"Boil",4};
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
    return lResult;
}
