#ifndef MAKANAN_H
#define MAKANAN_H

#include "../boolean.h"
#include "../Wordmachine/wordmachine.h"
#include "../Charmachine/charmachine.h"
#include "../Time/time.h"

typedef struct{
    int id; 
    Word namaMakanan;
    TIME expired;
    TIME actionTime;
    Word aksi;
    int w;
    int h;
}Makanan;

typedef struct 
{
    Makanan contents[CAPACITY];
}ListMakanan;

#define id(e) (e).id
#define nama(e) (e).namaMakanan
#define expired(e) (e).expired
#define actionTime(e) (e).actionTime
#define aksi(e) (e).aksi
#define w(m) (m).w
#define h(m) (m).h
#define makanan(m,i) (m).contents[(i)]

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

int getIdx(ListMakanan l, int id);
/* Mengembalikan index makanan dengan id tertentu yang berada dalam list makanan */

void printCommand(ListMakanan l, Word command);
/* I.S. : Listmakanan l terdefinisi dan word command terdefinisi */
/* F.S. : Menampilkan semua makanan dari Listmakanan l yang memiliki command yang sama */

boolean isFound(ListMakanan l, int idx);
/* Mengembalikan nilai benar jika index berada dalam range 1 sampai length(l)-1 */

boolean isIdFound(ListMakanan l, int id);
/* Mengembalikan nilai true jika ada makanan dengan id yang diminta, di dalam list makanan */


void setMakanan(ListMakanan *l, Makanan new, int id);
/* I.S. : List makanan terdefinisi, id pasti berada dalam Listmakanan */
/* F.S. : Makanan dengan id dalam Listmakanan terganti menjadi new */

#endif