#include <stdio.h>
#include "../queue.h"
#include "../boolean.h"
#include "makanan.h"
#include "config.h"
#include "tree.h"

void copyArr(const char arrS[], char arrD[], int len) {
    for (int i = 0; i < len; ++i) {
        arrD[i] = arrS[i];
    }
}

void path_finding() {
    int map[10][10] = {{'S', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                       {'#', '#', '#', '#', 'T', '#', '#', 'X', '#', '#'},
                       {'#', 'M', '#', '#', '#', '#', '#', 'X', '#', '#'},
                       {'#', '#', '#', '#', '#', '#', '#', 'X', '#', '#'},
                       {'#', '#', '#', '#', 'X', 'X', 'X', 'X', '#', '#'},
                       {'#', 'X', '#', '#', '#', '#', '#', '#', '#', '#'},
                       {'#', 'X', '#', '#', '#', '#', '#', '#', 'C', '#'},
                       {'#', 'X', 'X', 'X', '#', '#', 'F', '#', '#', '#'},
                       {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                       {'#', '#', '#', '#', '#', '#', 'B', '#', '#', '#'}};

    boolean visited[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (map[i][j] == 'X')
                visited[i][j] = true;
            else
                visited[i][j] = false;
        }
    }

    Thing source;
    source.row = 0;
    source.col = 0;
    source.aNum = 0;

    Queue q;
    CreateQueue(&q);
    enqueue(&q, source);
    int i = 0;
    char flow[] = {'F', 'C', 'T'};
    char firstPath[100];

    while (!isEmptyQNP(q)) {
        Thing cur;
        dequeue(&q, &cur);
        if (i == 3)
            break;

        // TODO: csp for scheduling
        if (map[cur.row][cur.col] == flow[i]) {
            printf("path found! path: ");

            if (i == 0) {
                copyArr(cur.acts, firstPath, cur.aNum);
            }

            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (map[i][j] == 'X')
                        visited[i][j] = true;
                    else
                        visited[i][j] = false;
                }
            }

            printf("\n");
            CreateQueue(&q);
            Thing can;
            can.aNum = cur.aNum;
            can.row = can.row;
            can.col = can.col;

            enqueue(&q, can);

            ++i;
        }

        if (cur.row - 1 >= 0 && visited[cur.row - 1][cur.col] == false) {
            Thing new;
            new.row = cur.row - 1;
            new.col = cur.col;
            new.aNum = cur.aNum;
            copyArr(cur.acts, new.acts, cur.aNum);
            new.acts[new.aNum] = 'u';
            new.aNum += 1;
            enqueue(&q, new);
            visited[cur.row - 1][cur.col] = true;
        }

        if (cur.col - 1 >= 0 && visited[cur.row][cur.col - 1] == false) {
            Thing new;
            new.row = cur.row;
            new.col = cur.col - 1;
            new.aNum = cur.aNum;
            copyArr(cur.acts, new.acts, cur.aNum);
            new.acts[new.aNum] = 'l';
            new.aNum += 1;
            enqueue(&q, new);
            visited[cur.row][cur.col - 1] = true;
        }

        if (cur.row + 1 < 10 && visited[cur.row + 1][cur.col] == false) {
            Thing new;
            new.row = cur.row + 1;
            new.col = cur.col;
            new.aNum = cur.aNum;
            copyArr(cur.acts, new.acts, cur.aNum);
            new.acts[new.aNum] = 'd';
            new.aNum += 1;
            enqueue(&q, new);
            visited[cur.row + 1][cur.col] = true;
        }

        if (cur.col + 1 < 10 && visited[cur.row][cur.col + 1] == false) {
            Thing new;
            new.row = cur.row;
            new.col = cur.col + 1;
            new.aNum = cur.aNum;
            copyArr(cur.acts, new.acts, cur.aNum);
            new.acts[new.aNum] = 'r';
            new.aNum += 1;
            enqueue(&q, new);
            visited[cur.row][cur.col + 1] = true;
        }
    }
}

void populateTest() {
    printf("---populate from file testing---\n");
    ListMakanan listMakanan = *configMakananP();
    char fileL[] = "/home/zidane/kuliah/Semester 3/IF2110 - Algoritma & Struktur Data/BNMO-Tubes-Alstrukdat/adt/config-r.txt";
    ListTree listTree = *populateResepFromFile(listMakanan, fileL);

    for (int i = 0; i < listTree.sizeEff; ++i) {
        printf("root id: %d; ", listTree.list[i].value.makananV.id);
        traverseTree_Makanan(listTree.list[i]);
        printf("\n");
    }

    printf("---end---\n");
}

void searchTest() {
    printf("---searching testing---\n");

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

    Makanan *mk = searchMakananById(*tree, 28);

    if (mk != NULL)
        printf("s: %d", mk->id);

    printf("\n---end---\n");
}

void cookbookTest() {
    printf("\n--- Test CookBook ---\n");
    ListMakanan listMakanan = *configMakananP();
    char fileL[] = "/home/zidane/kuliah/Semester 3/IF2110 - Algoritma & Struktur Data/BNMO-Tubes-Alstrukdat/adt/config-r.txt";
    ListTree listTree = *populateResepFromFile(listMakanan, fileL);

    displayCookBook(listTree);

    printf("\n---end---\n");
}

void recommTest() {
    printf("---recomm testing---\n");

    TIME T1;
    TIME T2;
    Word nama = {"Ayam",4};
    Word aksi = {"chop",4};
    CreateTime(&T1,1,0,0);
    CreateTime(&T2,0,2,15);

    ListMakanan listMakanan = *configMakananP();
    char fileL[] = "/home/zidane/kuliah/Semester 3/IF2110 - Algoritma & Struktur Data/BNMO-Tubes-Alstrukdat/adt/config-r.txt";

    PrioQueue inventory;
    MakeEmptyQ(&inventory, 12, false);
    ListTree listTree = *populateResepFromFile(listMakanan, fileL);

    Makanan mi1 = {10,nama,T1,T2,aksi};
    Makanan mi2 = {17,nama,T1,T2,aksi};
    Makanan mi3 = {11,nama,T1,T2,aksi};
    Makanan mi4 = {15,nama,T1,T2,aksi};
    Makanan mi5 = {99,nama,T1,T2,aksi};

    Enqueue(&inventory, mi1);
    Enqueue(&inventory, mi2);
    Enqueue(&inventory, mi3);
    Enqueue(&inventory, mi4);
    Enqueue(&inventory, mi5);
    Enqueue(&inventory, mi4);

    ListMakanan rekomendasi = getRecommendation(listTree, inventory);

    for (int i = 0; i < panjangListMakanan(rekomendasi); ++i) {
        printf("%d. id makanan: %d nama makanan: ", i+1, rekomendasi.contents[i].id);
        printWord(rekomendasi.contents[i].namaMakanan);
        printf("\n");
    }

    printf("\n---end---\n");

}

int main() {

    populateTest();
    searchTest();
    cookbookTest();
    recommTest();

}