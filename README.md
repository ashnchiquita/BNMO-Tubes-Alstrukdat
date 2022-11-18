# BNMO

Tugas Besar Alstrukdat IF2110

BNMO is a robot game owned by Indra and Doni. Therefore, Indra asked for help from BNMO and Doni to help prepare this special dinner. However, there is a problem. BNMO doesn't know how to cook and Doni can't help with the preparations because of something else. BNMO cannot learn from youcub videos because BNMO is a computer so the easiest thing to do is to make a simulation program for BNMO to emulate. Therefore, Doni asks for your help to develop this simulation program.

BNMO is CLI (Command Line Interface) Game that we made using c language. This game includes a lot of data structure and also Abstract Data Types that we made ourself. Some of them are Stack, Queue, Linked list, and many more. The purpose of the game is to food cooking simulation from raw ingredients to dish.

## Setup

- If you're in windows based, install GNU Compiler (GCC) and set the PATH (Because UNIX already have the gcc installed by the first place).
- If you're in UNIX based just follow the Usage instruction.

## Usage

1. Clone this repository
2. If you want to edit the configuration file, it is inside `config/config.txt`
3. Execute `run.bat` if you're in windows
4. If you're in UNIX based OS, Execute `run.sh`

## Features Done

- Main menu
- Initiation
- Simulator
- Food
- Recipe
- Inventory
- Ordering groceries and Delivery
- Food processing
- Time mechanism
- Command includes (UNDO, REDO, CATALOG, COOKBOOK)
- Validation and Error Handling
- Notification
- All the bonus includes refrigerator, food processing time, and food recommendation.

## Member List:

| Nama                           |   NIM    |                                                   Workload management                                                   |
| ------------------------------ | :------: | :---------------------------------------------------------------------------------------------------------------------: |
| Chiquita Ahsanunnisa       | 13521129 |                                     ADT Queue, command parser, inisiasi (splash screen, command START, command EXIT), notification, refrigerator, laporan                                   |
| Nathania Callista Djuanedi | 13521139 |                                     ADT Sederhana (Time, Point, Makanan, Simulator), makanan, time mechanism, ADT Stack, fitur UNDO/REDO, food processing time, laporan         
|
| Hanif Muhammaad Zhafran    | 13521157 | 
ADT Matriks, peta, laporan
|
| Ferindya Aulia Berlianty   | 13521161 |                                     ADT List Statik, ADT Mesin Karakter dan Mesin Kata, laporan                    |
| Zidane Firztullah          | 13521163 |                                     ADT Tree, food recommendation, laporan
| 

## Program Structure

```
|.vscode
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
    │       charmachine.c
    |       commands.c
    |       config.c
    |       kulkas.c
    |       liststatik.c
    |       makanan.c
    |       matrix.c
    |       notif.c
    |       point.c
    |       prioqueue.c
    |       set.c
    |       simulator.c
    |       stack.c
    |       time.c
    |       tree.c
    |       tree_ext.c
    |       wordmachine.c
    │
    ```
