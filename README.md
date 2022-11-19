# BNMO Cooking Game Simulator

### Tugas Besar IF2110 Algoritma dan Struktur Data 2022/2023
### Created by Group H of K2 IF'21

## About BNMO Cooking Game Simulator
BNMO is a robot game owned by Indra and Doni. Therefore, Indra asked for help from BNMO and Doni to help prepare this special dinner. However, there is a problem. BNMO doesn't know how to cook and Doni can't help with the preparations because of something else. BNMO cannot learn from youcub videos because BNMO is a computer so the easiest thing to do is to make a simulation program for BNMO to emulate. Therefore, Doni asks for your help to develop this simulation program.

BNMO is CLI (Command Line Interface) Game that we made using C language. This game includes a lot of data structure and also Abstract Data Types that we made ourself. Some of them are Stack, Priority Queue, Tree, and many more. The purpose of the game is to food cooking simulation from raw ingredients to dish.

## Setup

- If you use Windows-based OS, you must install GNU Compiler (GCC) and set the PATH.
- If you use UNIX-based OS, you can compile the program directly (see instructions below).

## How To Compile This Program?

1. Clone this repository
2. If you want to edit the configuration file, it is inside `adt/Config` folder
3. If you want to compile this program on Linux, type this inside your terminal `gcc main.c ./adt/Wordmachine/wordmachine.c ./adt/Charmachine/charmachine.c ./adt/Time/time.c ./adt/Point/point.c ./adt/Config/config.c ./adt/Prioqueue/prioqueue.c ./adt/Stack/stack.c ./adt/Notifikasi/notif.c ./adt/Commands/commands.c ./adt/Simulator/simulator.c ./adt/Matrix/matrix.c ./adt/Makanan/makanan.c ./adt/Tree/tree.c ./adt/Kulkas/kulkas.c ./adt/Tree/tree_ext.c ./adt/Set/set.c  -o main -lm`

## How To Run This Program?
After compiling, you can run the program by running the executable file. Type `./main` inside your terminal and have fun playing BNMO Cooking Game Simulator!

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

## Members List and Workload Management

| Nama                           |   NIM    |                                                   Workload management                                                   |
| ------------------------------ | :------: | :---------------------------------------------------------------------------------------------------------------------: |
| Chiquita Ahsanunnisa       | 13521129 |                                     ADT Queue, Command Parser, Inisiasi (Splash Screen, Command START, Command EXIT), Notifikasi, Kulkas, Laporan                                   |
| Nathania Callista Djuanedi | 13521139 |                                     ADT Sederhana (Time, Point, Makanan, Simulator), Makanan, Mekanisme Waktu, ADT Stack, Fitur UNDO/REDO, Waktu Pengolahan Makanan, Laporan         |
| Hanif Muhammad Zhafran     | 13521157 |                                     ADT Matriks, Peta, Laporan                                                   |
| Ferindya Aulia Berlianty   | 13521161 |                                     ADT List Statik, ADT Mesin Karakter dan Mesin Kata, Laporan                  |
| Zidane Firzatullah         | 13521163 |                                     ADT Tree, Rekomendasi Makanan, Laporan                                       | 

## Folder Structure

```
|   README.md
|   main
|   main.c
|
└───doc
|       Form_Asistensi.pdf
|       IF2110_TB_02_H.pdf 
|       Notulensi_Rapat.pdf 
|       Progress_Milestone.pdf 
|
└───.vscode
│       settings.json
│
└───adt
    ├───Charmachine 
    |       charmachine.h
    |       charmachine.c
    |       charmachinedriver.c
    |
    |
    ├─── Commands
    |       commands.h
    |        commands.c
    |        commandsdriver.c
    |    
    ├─── Config
    |        config-r.txt
    |        config.c
    |        config.h
    |        configdriver.c
    |        configMakanan.txt
    |        configPeta.txt
    |
    |
    ├─── Kulkas
    |        kulkas.c
    |        kulkas.h
    |        driverkulkas.c
    |
    |
    ├─── Liststatik
    |       liststatik.c
    |       liststatik.h
    |       driver_liststatik.c
    |
    |
    ├─── Makanan
    |       makanan.c
    |       makanan.h
    |       makanandriver.c
    |
    |
    ├─── Matrix
    |        matrix.c
    |        matrix.h
    |        matrixdriver.c
    |        
    |        
    ├─── Notifikasi
    |        notif.c
    |        notif.h
    |        
    |        
    ├─── Point
    |        point.c
    |        point.h
    |        pointdriver.c
    |            
    ├─── Prioqueue
    |        prioqueue.c
    |        prioqueue.h
    |        prioqueuedriver.c
    |        
    |        
    ├─── Set
    |        set.c
    |        set.h
    |        
    |        
    ├─── Simulator
    |        simulator.c
    |        simulator.h
    |        simulatordriver.c
    |        
    |        
    ├─── Stack
    |        stack.c
    |        stack.h
    |        stackdriver.c
    |        
    |        
    ├─── Time 
    |        time.c
    |        time.h
    |        timedriver.c
    |        
    |        
    ├─── Tree
    |        tree_ext.c
    |        tree.c
    |        tree.h
    |        treedriver.c
    |        
    |        
    ├─── Wordmachine
    |        wordmachine.c
    |        wordmachine.h
    |        wordmachinedriver.c
    |        
    |        
    │   boolean.h
    |   objectU.h
    
    ```
