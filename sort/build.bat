@echo off
set FILES=main.cpp basesort.h insertionsort.h heapsort.h quicksort.h
set OUT_FILE=libSort
g++ -o %OUT_FILE% %FILES%