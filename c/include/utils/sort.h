#ifndef _SORT_H

#define _SORT_H

void selectionSort(int *arr , int len);
void selectionSortByOrder(int *arr , int len , int order);

void insertionSort(int *arr , int len);
void insertionSortByOrder(int *arr , int len , int order);

void bubbleSort(int *arr , int len);
void bubbleSortByOrder(int *arr , int len , int order);

void quickSort(int *arr , int len);
void quickSortByOrder(int *arr , int len , int order);

void mergeSort(int *arr , int len);
void mergeSortByOrder(int *arr , int len , int order);

void heapSort(int *arr , int len);
void heapSortByOrder(int *arr , int len , int order);

void countSort(int *arr , int len);
void countSortByOrder(int *arr , int len , int order);

void shellSort(int *arr , int len);
void shellSortByOrder(int *arr , int len , int order);

#endif