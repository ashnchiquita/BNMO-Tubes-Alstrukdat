#include "../tree.h"

#include <stdio.h>

#include "../prioqueue.h"
#include "../config.h"

/**
 * driver's main function. caution: machine dependent.
 *
 */
int main() {
    TIME T1;
    TIME T2;
    Word nama = {"Ayam",4};
    Word aksi = {"chop",4};
    Word Buy = {"BUY",3};
    CreateTime(&T1,1,0,0);
    CreateTime(&T2,0,2,15);

    Makanan m = {12,nama,T1,T2,aksi};
    Makanan m1 = {20,nama,T1,T2,aksi};
    Makanan m2 = {21,nama,T1,T2,aksi};
    Makanan m3 = {22,nama,T1,T2,aksi};
    Makanan m4 = {23,nama,T1,T2,aksi};
    Makanan m5 = {24,nama,T1,T2,aksi};
    Makanan m6 = {25,nama,T1,T2,aksi};
    Makanan m7 = {26,nama,T1,T2,aksi};
    Makanan m8 = {27,nama,T1,T2,aksi};
    Makanan m9 = {28,nama,T1,T2,aksi};
    Makanan m10 = {29,nama,T1,T2,aksi};

    ListMakanan listMakanan, listMakanan1, listMakanan2;
    CreateListMakanan(&listMakanan); CreateListMakanan(&listMakanan1); CreateListMakanan(&listMakanan2);
    addMakanan(&listMakanan, m); addMakanan(&listMakanan, m1); addMakanan(&listMakanan, m2);
    addMakanan(&listMakanan, m3); addMakanan(&listMakanan, m4); addMakanan(&listMakanan, m5);
    addMakanan(&listMakanan, m6); addMakanan(&listMakanan, m7); addMakanan(&listMakanan, m8);
    addMakanan(&listMakanan, m9); addMakanan(&listMakanan, m10);
    addMakanan(&listMakanan1, m2);
    addMakanan(&listMakanan1, m1);
    addMakanan(&listMakanan1, m3);
    addMakanan(&listMakanan1, m4);

    printf("---populate from file testing---\n");
    listMakanan = *configMakananP();
    char fileL[] = "/home/zidane/kuliah/Semester 3/IF2110 - Algoritma & Struktur Data/BNMO-Tubes-Alstrukdat/adt/config-r.txt";
    ListTree listTree = *populateResepFromFile(listMakanan, fileL);

    for (int i = 0; i < listTree.sizeEff; ++i) {
        printf("root id: %d; ", listTree.list[i].value.makananV.id);
        traverseTree_Makanan(listTree.list[i]);
        printf("\n");
    }

    printf("---end---\n");
    printf("---searching testing---\n");

    Object o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11;
    o1.makananV = m; o2.makananV = m1; o3.makananV = m2;
    o4.makananV = m3; o5.makananV = m4; o6.makananV = m5;
    o7.makananV = m6; o8.makananV = m7; o9.makananV = m8;
    o10.makananV = m9; o11.makananV = m10;

    Tree *tree;
    tree = createTreeNode(NULL, o1);
    Tree *child1 = addChildren(tree, o2), *c2 = addChildren(tree, o3),
    *c3 = addChildren(tree, o4), *c4 = addChildren(tree, o5),
    *c5 = addChildren(c2, o6), *c6 = addChildren(c2, o7),
    *c7 = addChildren(c3, o8), *c8 = addChildren(c3, o9),
    *c9 = addChildren(c5, o10), *c10 = addChildren(c8, o11);

    traverseTree_Makanan(*tree);
    Makanan *mk = searchMakananById(*tree, 28);

    if (mk != NULL)
        printf("s: %d", mk->id);

    printf("\n---end---\n");

    printf("---check---\n");
    PrioQueue queue;
    MakeEmptyQ(&queue, 100, false);
    Enqueue(&queue, m2);
    Enqueue(&queue, m3);

    listMakanan2 = getMakananNa(*tree, queue);
    for (int i = 0; i < panjangListMakanan(listMakanan2); ++i) {
        printf("%d ", listMakanan2.contents[i].id);
    }
    printf("\n---end---\n");


}