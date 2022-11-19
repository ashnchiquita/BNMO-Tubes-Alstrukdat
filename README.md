# BNMO Cooking Game Simulator

### Tugas Besar IF2110 Algoritma dan Struktur Data 2022/2023
### Created by Group H of K2 IF'21

## About BNMO Cooking Game Simulator
BNMO is a robot game owned by Indra and Doni. Therefore, Indra asked for help from BNMO and Doni to help prepare this special dinner. However, there is a problem. BNMO doesn't know how to cook and Doni can't help with the preparations because of something else. BNMO cannot learn from youcub videos because BNMO is a computer so the easiest thing to do is to make a simulation program for BNMO to emulate. Therefore, Doni asks for your help to develop this simulation program.

BNMO is CLI (Command Line Interface) Game that we made using C language. This game includes a lot of data structure and also Abstract Data Types that we made ourself. Some of them are Stack, Priority Queue, Tree, and many more. The purpose of the game is to food cooking simulation from raw ingredients to dish.

## Setup

- If you use Windows-based OS, you must install GNU Compiler (GCC) and set the PATH.
- If you use UNIX-based OS, you can compile the program directly (see instructions below).

## How To Compile Program?

1. Clone this repository
2. If you want to edit the configuration file, it is inside `config/config.txt`
3. If you want to compile this program, type this inside your terminal `gcc main.c ./adt/source/makanan.c ./adt/source/charmachine.c ./adt/source/wordmachine.c ./adt/source/time.c ./adt/source/config.c ./adt/source/commands.c ./adt/source/simulator.c ./adt/source/point.c ./adt/source/prioqueue.c ./adt/source/tree.c ./adt/source/tree_ext.c ./adt/source/matrix.c ./adt/source/stack.c ./adt/source/notif.c ./adt/source/set.c ./adt/source/kulkas.c  -o driver -lm`

## How To Run Program?
After compiling, you can run the program by running the executable file. Type `./driver` inside your terminal and have fun playing BNMO Cooking Game Simulator!

## Finished Features

- Initiation (splash screen, START and EXIT command, all txt files configuration)
- Simulator
- Food
- Recipe
- Inventory
- Command to order food and Delivery
- Map
- Food Processing
- Time Mechanism
- Others: UNDO, REDO, CATALOG, COOKBOOK, HELP
- Command Parser, Validation, and Error Handling
- Notification
- Bonus: Refrigerator
- Bonus: Food processing time
- Bonus: Food recommendation

## Unfinished Features
- Bonus: Auto BNMO

## Members List:

| Nama                           |   NIM    |                                                   Workload management                                                   |
| ------------------------------ | :------: | :---------------------------------------------------------------------------------------------------------------------: |
| Chiquita Ahsanunnisa       | 13521129 |                                     ADT Queue, Command Parser, Inisiasi (Splash Screen, Command START, Command EXIT), Notifikasi, Kulkas, Laporan                                   |
| Nathania Callista Djuanedi | 13521139 |                                     ADT Sederhana (Time, Point, Makanan, Simulator), Makanan, Mekanisme Waktu, ADT Stack, Fitur UNDO/REDO, Waktu Pengolahan Makanan, Laporan         |
| Hanif Muhammad Zhafran     | 13521157 |                                     ADT Matriks, Peta, Laporan                                                   |
| Ferindya Aulia Berlianty   | 13521161 |                                     ADT List Statik, ADT Mesin Karakter dan Mesin Kata, Laporan                  |
| Zidane Firzatullah         | 13521163 |                                     ADT Tree, Rekomendasi Makanan, Laporan                                       | 

## Program Structure

```
|   README.md
|   main
|   main.c
|
└───.vscode
│       settings.json
│
└───adt
    │   boolean.h
    │   charmachine.h
    |   commands.h
    |   config-r.txt
    |   config.h
    |   configMakanan.txt
    |   configPeta.txt
    |   kulkas.h
    |   liststatik.h
    |   makanan.h
    |   matrix.h
    |   notif.h
    |   objectU.h
    |   point.h
    |   prioqueue.h
    |   set.h
    |   simulator.h
    |   stack.h
    |   time.h
    |   tree.h
    |   wordmachine.h
    │
    ├───driver
    │       configdriver.c
    │       driver.exe
    │       driver_liststatik.c
    │       driverkulkas.c
    │       driverkulkas
    |       main.exe
    |       makanandriver.c
    |       matrixdriver.c
    |       matrixdriver.exe
    |       pointdriver.c
    |       prioqueuedriver.c
    |       simulatordriver.c
    |       stackdriver.c
    |       timedriver.c
    |       timedriver.exe
    |       treedriver.c
    │
    ├───source
            charmachine.c
            commands.c
            config.c
            kulkas.c
            liststatik.c
            makanan.c
            matrix.c
            notif.c
            point.c
            prioqueue.c
            set.c
            simulator.c
            stack.c
            time.c
            tree.c
            tree_ext.c
            wordmachine.c
    ```
