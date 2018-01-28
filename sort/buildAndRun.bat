@echo off
set FILES=main.cpp basesort.h insertionsort.h heapsort.h
set OUT_FILE=libSort
g++ -o %OUT_FILE% %FILES% && %OUT_FILE%.exe
