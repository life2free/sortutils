#include<stdio.h>
#include<string.h>
#include "../include/utils/sort.h"
#include "../include/utils/utils.h"

void testSelectionSort(int *arr, int len);
void testInsertionSort(int *arr, int len);
void testBubbleSort(int *arr, int len);
void testQuickSort(int *arr, int len);
void testMergeSort(int *arr, int len);
void testHeapSort(int *arr, int len);
void testCountSort(int *arr, int len);
void testShellSort(int *arr, int len);
void sortArray1(int *arr, int len, void (*sortFunc)(int *a,int l));

int main(){
	int arr[]={1, 61, 8, 19, 3, -5, 5, 0, 22, -1, 19,76, 0};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	printfArrayWithMessage(arr, len, "origianl:");
	
	sortArray1(arr, len,testSelectionSort);
	// sortArray1(arr, len,testInsertionSort);
	// sortArray1(arr, len,testBubbleSort);
	// sortArray1(arr, len,testQuickSort);
    // sortArray1(arr, len,testMergeSort);
	// sortArray1(arr, len,testHeapSort);
	// sortArray1(arr, len,testCountSort);
	// sortArray1(arr, len,testShellSort);
	
	return 0;
}

void testSelectionSort(int *arr, int len){	
	
	//printf("selectionSort:\n");
	selectionSort(arr, len);
	printfArrayWithMessage(arr, len, "selectionSort asc:");
	
	selectionSortByOrder(arr, len, 1);
	printfArrayWithMessage(arr, len, "selectionSort desc:");
}


void testInsertionSort(int *arr, int len){	
	
	//printf("insertionSort:\n");
	insertionSort(arr, len);
	printfArrayWithMessage(arr, len, "insertionSort asc:");
	
	insertionSortByOrder(arr, len, 1);
	printfArrayWithMessage(arr, len, "insertionSort desc:");
}


void testBubbleSort(int *arr, int len){

	//printf("bubbleSort:\n");
	bubbleSort(arr, len);
	printfArrayWithMessage(arr, len, "bubbleSort asc:");
	
	bubbleSortByOrder(arr, len, 1);
	printfArrayWithMessage(arr, len, "bubbleSort desc:");
}


void testQuickSort(int *arr, int len){
	//printf("quickSort:\n");
	quickSort(arr, len);
	printfArrayWithMessage(arr, len, "quickSort asc:");
	
	quickSortByOrder(arr, len, 1);
	printfArrayWithMessage(arr, len, "quickSort desc:");
}

void testMergeSort(int *arr, int len){
	mergeSort(arr, len);
	printfArrayWithMessage(arr, len, "mergeSort asc:");
	
	mergeSortByOrder(arr, len, 1);
	printfArrayWithMessage(arr, len, "mergeSort desc:");
}


void testHeapSort(int *arr, int len){
	heapSort(arr, len);
	printfArrayWithMessage(arr, len, "heapSort asc:");
	
	heapSortByOrder(arr, len, 1);
	printfArrayWithMessage(arr, len, "heapSort desc:");
}


void testCountSort(int *arr, int len){
	countSort(arr, len);
	printfArrayWithMessage(arr, len, "countSort asc:");
	
	countSortByOrder(arr, len, 1);
	printfArrayWithMessage(arr, len, "countSort desc:");
}


void testShellSort(int *arr, int len){
	shellSort(arr, len);
	printfArrayWithMessage(arr, len, "shellSort asc:");
	
	shellSortByOrder(arr, len,1);
	printfArrayWithMessage(arr, len, "shellSort desc:");
}

void sortArray1(int *arr, int len, void (*sortFunc)(int *a, int l)){
	sortFunc(arr, len);
}