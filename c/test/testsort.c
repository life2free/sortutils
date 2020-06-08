#include<stdio.h>
#include<string.h>
#include "../include/utils/sort.h"
#include "../include/utils/utils.h"

#define ARRFUNCLENGTH 8
typedef void (*pFunc)(int *arr, int len);
typedef void (*pFuncByOrder)(int *arr, int len, int order);

typedef struct _function_meta {
	char * funcName;
    //func funcArr;
    pFunc func;
    pFuncByOrder funcByOrder;
} function_meta;

void sortArray(int *arr, int len, char *funcName);

function_meta * getFuncMeta(char* funcName);

function_meta arrFunc[ARRFUNCLENGTH] = {
	{"selectionSort",selectionSort,selectionSortByOrder},
	{"insertionSort",insertionSort,insertionSortByOrder},
	{"bubbleSort",bubbleSort,bubbleSortByOrder},
	{"quickSort",quickSort,quickSortByOrder},
	{"mergeSort",mergeSort,mergeSortByOrder},
	{"heapSort",heapSort,heapSortByOrder},
	{"countSort",countSort,countSortByOrder},
	{"shellSort",shellSort,shellSortByOrder}	
	};


int main(){
	int arr[]={1, 61, 8, 19, 3, -5, 5, 0, 22, -1, 19,76, 0};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	printfArrayWithMessage(arr, len, "origianl:");
	
	// sortArray(arr, len,"selectionSort");
	// sortArray(arr, len,"insertionSort");
	// sortArray(arr, len,"bubbleSort");
	// sortArray(arr, len,"quickSort");
	// sortArray(arr, len,"mergeSort");
	// sortArray(arr, len,"heapSort");
	// sortArray(arr, len,"countSort");
	sortArray(arr, len,"shellSort");
	
	return 0;
}

function_meta * getFuncMeta(char* funcName){

	function_meta temp={"Not Found",NULL,NULL};
	function_meta * ret = &temp;
	for(int i=0; i<ARRFUNCLENGTH; i++){
		if(!strcasecmp(funcName,arrFunc[i].funcName)){
			ret = &arrFunc[i];			
		}
	}
	return ret;                                                                                              
}

void sortArray(int *arr, int len, char *funcName){
	function_meta * funcMeta = getFuncMeta(funcName);
	if(strcasecmp(funcMeta->funcName,"Not Found")){
		char * mess = funcMeta->funcName;

		(*funcMeta->func)(arr,len);
		char ascMess[20];
		strcat(strcpy(ascMess,mess), " asc:");
		printfArrayWithMessage(arr, len, ascMess);

		(*funcMeta->funcByOrder)(arr, len, 1);
		char descMess[20];
		strcat(strcpy(descMess,mess), " desc:");
		printfArrayWithMessage(arr, len, descMess);
	}else{
		printf("can't find the sort method: %s\n", funcName);
	}
}


