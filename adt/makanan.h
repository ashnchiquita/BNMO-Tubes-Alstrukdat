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
}Makanan;

typedef struct 
{
    Makanan contents[CAPACITY];
}ListMakanan;

#define id(e) (e).id
#define nama(e) (e).namaMakanan
#define expired(e) (e).expired
#define delivery(e) (e).delivery
#define aksi(e) (e).aksi
#define makanan(m,i) (m).contents[(i)]

Word readMakanan();
/* Berfungsi untuk membaca makanan dari file konfigurasi makanan */
/* I.S. File konfigurasi makanan sudah terdefinisi */
/* F.S List makanan sudah terisi beberapa jenis makanan */

void CreateListMakanan(ListMakanan *l);
/* Berfungsi untuk membuat list makanan */
/* I.S. : l sembarang */
/* Terbentuk ListMakanan l kosong dengan kapasitas CAPACITY*/
/* Inisialisasi semua id MAKANAN dalam ListMakanan dengan nilai -1 */

int panjangListMakanan(ListMakanan l);
/* Mengirimkan banyaknya elemen dalam list makanan l*/

void printMakanan(ListMakanan l);
/* Menampilkan isi list makanan ke terminal */
/* I.S : ListMakanan l terdefinisi */
/* F.S : Isi dari ListMakanan l tercetak ke layar */

void addMakanan(ListMakanan *l, Makanan m);
/* Menambahkan MAKANAN m ke dalam ListMakanan l */
/* I.S : ListMakanan l dan MAKANAN m terdefinisi */
/* F.S : MAKANAN m masuk sebagai elemen terakhir di ListMakanan *l */

ListMakanan pengelompokanMakanan(ListMakanan l,Word w);
/* Mengelompokkan makanan berdasarkan kategori aksi yang dimiliki makanan*/

#endif