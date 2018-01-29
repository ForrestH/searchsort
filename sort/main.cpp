#include <cstdio>
#include <vector>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <functional>

#include "basesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"

using namespace Sorting;
using namespace std::placeholders;

void checkSort(std::vector<int> list, int expectedSize)
{
    bool sorted = true;
    for (int i = 0; i < list.size() - 1; ++i)
    {
        if (list[i] > list[i+1])
        {
            sorted = false;
            break;
        }
    }
    
    if (sorted && list.size() == expectedSize)
        printf("(PASS)");
    else
        printf("(FAIL)");
    printf("\n");
}

double timeAlgorithm(std::function<vector<int>(vector<int>)> alg, vector<int> list, int iterations)
{
    clock_t start, end;
    double elapsed;
    
    start = clock();
    for (int i = 0; i < iterations; ++i)
    {
        alg(list);
    }
    end = clock();
    elapsed = (double) (end - start) / CLOCKS_PER_SEC * 1000.0;
    
    return elapsed / iterations;
}

void printList(std::vector<int> list)
{
    for (int item : list)
    {
        printf("%d ", item);
    }
    printf("\n");
}

void clearReadBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    int size;
    std::vector<int> list;
    
    char repeat = '?';
    do
    {
        
        char choice = '?';
        while (true)
        {
            printf("Do you want to enter your own list? (y/n): ");
            scanf("%c", &choice);
            clearReadBuffer();
            
            if (choice != 'y' && choice != 'n')
                printf("Huh?\n");
            else
                break;
        }
        
        if (choice == 'y')
        {
            printf("Enter desired list size: ");
            scanf("%d", &size);
            clearReadBuffer();
            
            printf("Enter a number for each list index with some delimiter\n");
            list.resize(size);
            for (int i = 0; i < size; ++i)
            {
                int number;
                scanf("%d", &number);
                list[i] = number;
            }
            printf("\n");
        }
        else
        {
            printf("Enter desired length of randomly generated list: ");
            scanf("%d", &size);
            clearReadBuffer();
            list.resize(size);
            srand(time(NULL));
            for (int i = 0; i < size; ++i)
                list[i] = std::rand() % 1000000;

            printf("\n");
        }
        
        printf("Enter desired number of iterations for runtime tests: ");
        int timingIterations;
        scanf("%d", &timingIterations);
        clearReadBuffer();
        
        BaseSort *sorter;
        double avgRuntime;
        
        sorter = new BaseSort();
        vector<int> unsorted = sorter->sort(list);
        printf("\nUnsorted list ");
        checkSort(unsorted, size);
        auto noSortFunction = std::bind(&BaseSort::sort, sorter, _1);
        avgRuntime = timeAlgorithm(noSortFunction, list, timingIterations);
        printf("Average runtime of %d runs was %lf ms\n\n", timingIterations, avgRuntime);
        //printList(unsorted);
        
        printf("\nRun insertion sort? (y/n): ");
        char runInsertionSort = '?';
        scanf("%c", &runInsertionSort);
        clearReadBuffer();
        while (runInsertionSort != 'y' && runInsertionSort != 'n')
        {
            printf("Huh?\n");
            scanf("%c", &runInsertionSort);
            clearReadBuffer();
        }
        if (runInsertionSort == 'y')
        {
            delete sorter;
            sorter = new InsertionSort();
            vector<int> insertionSorted = sorter->sort(list);
            printf("Insertion Sort ");
            checkSort(insertionSorted, size);
            auto insertionSortFunction = std::bind(&BaseSort::sort, sorter, _1);
            avgRuntime = timeAlgorithm(insertionSortFunction, list, timingIterations);
            printf("Average runtime of %d runs was %lf ms\n\n", timingIterations, avgRuntime);
            //printList(insertionSorted);
        }
        
        printf("\nRun merge sort? (y/n): ");
        char runMergeSort = '?';
        scanf("%c", &runMergeSort);
        clearReadBuffer();
        while (runMergeSort != 'y' && runMergeSort != 'n')
        {
            printf("Huh?\n");
            scanf("%c", &runMergeSort);
            clearReadBuffer();
        }
        if (runMergeSort == 'y')
        {
            delete sorter;
            sorter = new MergeSort();
            vector<int> mergeSorted = sorter->sort(list);
            printf("Merge Sort ");
            checkSort(mergeSorted, size);
            auto mergeSortFunction = std::bind(&BaseSort::sort, sorter, _1);
            avgRuntime = timeAlgorithm(mergeSortFunction, list, timingIterations);
            printf("Average runtime of %d runs was %lf ms\n\n", timingIterations, avgRuntime);
            //printList(mergeSorted);
        }
        
        printf("\nRun heap sort? (y/n): ");
        char runHeapSort = 'y';
        scanf("%c", &runHeapSort);
        clearReadBuffer();
        while (runHeapSort != 'y' && runHeapSort != 'n')
        {
            printf("Huh?\n");
            scanf("%c", &runHeapSort);
            clearReadBuffer();
        }
        if (runHeapSort == 'y')
        {
            delete sorter;
            sorter = new HeapSort();
            vector<int> heapSorted = sorter->sort(list);
            printf("Heap Sort ");
            checkSort(heapSorted, size);
            auto heapSortFunction = std::bind(&BaseSort::sort, sorter, _1);
            avgRuntime = timeAlgorithm(heapSortFunction, list, timingIterations);
            printf("Average runtime of %d runs was %lf ms\n\n", timingIterations, avgRuntime);
            //printList(heapSorted);
        }
        
        printf("\nRun quick sort? (y/n): ");
        char runQuickSort = '?';
        scanf("%c", &runQuickSort);
        clearReadBuffer();
        while (runQuickSort != 'y' && runQuickSort != 'n')
        {
            printf("Huh?\n");
            scanf("%c", &runQuickSort);
            clearReadBuffer();
        }
        if (runQuickSort == 'y')
        {
            delete sorter;
            sorter = new QuickSort();
            vector<int> quickSorted = sorter->sort(list);
            printf("Quick Sort ");
            checkSort(quickSorted, size);
            auto quickSortFunction = std::bind(&BaseSort::sort, sorter, _1);
            avgRuntime = timeAlgorithm(quickSortFunction, list, timingIterations);
            printf("Average runtime of %d runs was %lf ms\n\n", timingIterations, avgRuntime);
            //printList(heapSorted);
        }
        
        while (true)
        {
            printf("Run again? (y/n): ");
            scanf("%c", &repeat);
            clearReadBuffer();
            
            if (repeat != 'y' && repeat != 'n')
                printf("Huh?\n");
            else
                break;
        }
        
    }while(repeat == 'y');
    
    printf("\nGoodbye\n");
}