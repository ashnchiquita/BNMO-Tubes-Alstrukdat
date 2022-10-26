#ifndef MAKANAN_H
#define MAKANAN_H

#include "liststatik.h"
#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "time.h"

typedef struct{
    int id; 
    Word namaMakanan;
    TIME expired;
    TIME delivery;
    Word aksi;
}MAKANAN;

typedef struct 
{
    MAKANAN contents[CAPACITY];
}ListMakanan;

#define id(e) (e).id
#define nama(e) (e).namaMakanan
#define expired(e) (e).expired
#define delivery(e) (e).delivery
#define aksi(e) (e).aksi
#define makanan(m,i) (m).contents[(i)]

Word readMakanan();
void CreateListMakanan(ListMakanan *l);
int panjangListMakanan(ListMakanan l);
void printMakanan(ListMakanan l);
void addMakanan(ListMakanan *l, MAKANAN m);
ListMakanan pengelompokanMakanan(ListMakanan l,Word w);

#endif