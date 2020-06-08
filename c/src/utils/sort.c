#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include "../../include/utils/sort.h"
#include "../../include/utils/utils.h"

void selectionSort(int *arr, int len);
void selectionSortByOrder(int *arr, int len, int order);
static void swap(int *a, int *b);
static void selectionSortAsc(int *arr, int len);
static void selectionSortDesc(int *arr, int len);

void insertionSort(int *arr, int len);
void insertionSortByOrder(int *arr, int len, int order);
static void insertionSortAsc(int *arr, int len);
static void insertionSortDesc(int *arr, int len);

void bubbleSort(int *arr, int len);
void bubbleSortByOrder(int *arr, int len, int order);
static void bubbleSortAsc(int *arr, int len);
static void bubbleSortDesc(int *arr, int len);

static void quickSortAscPartition(int *arr, int low, int high);
static void quickSortAscPartition1(int *arr, int low, int high);
static void quickSortAscPartition2(int *arr, int low, int high);
static void quickSortDescPartition(int *arr, int low, int high);
static void quickSortDescPartition1(int *arr, int low, int high);
static void quickSortDescPartition2(int *arr, int low, int high);
void quickSort(int *arr, int len);
void quickSortByOrder(int *arr, int len, int order);
static void quickSortAsc(int *arr, int len);
static void quickSortDesc(int *arr, int len);

static void mergeAsc(int *arr, int *tempArr, int startIndex1, int endIndex1, int startIndex2, int endIndex2);
static void mergeSortAscUnit(int *arr, int *tempArr, int startIndex, int endIndex);
static void mergeDesc(int *arr, int *tempArr, int startIndex1, int endIndex1, int startIndex2, int endIndex2);
static void mergeSortDescUnit(int *arr, int *tempArr, int startIndex, int endIndex);
void mergeSort(int *arr, int len);
void mergeSortByOrder(int *arr, int len, int order);
static void mergeSortAsc(int *arr, int len);
static void mergeSortDesc(int *arr, int len);

static void adjustHeapMax(int *arr, int index, int len);
static void adjustHeapMin(int *arr, int index, int len);
static void heapInsertMax(int *arr, int len);
static void heapInsertMin(int *arr, int len);
static void heapInsertMax1(int *arr, int len);
static void heapInsertMin1(int *arr, int len);
void heapSort(int *arr, int len);
void heapSortByOrder(int *arr, int len, int order);
static void heapSortAsc(int *arr, int len);
static void heapSortDesc(int *arr, int len);
static void heapSortAsc1(int *arr, int len);
static void heapSortDesc1(int *arr, int len);

void countSort(int *arr, int len);
void countSortByOrder(int *arr, int len, int order);
static void countSortAsc(int *arr, int len);
static void countSortDesc(int *arr, int len);

void shellSort(int *arr, int len);
void shellSortByOrder(int *arr, int len, int order);
static void shellSortAsc(int *arr, int len);
static void shellSortDesc(int *arr, int len);


static void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void selectionSort(int *arr, int len){
	selectionSortByOrder(arr, len,0);
}

void selectionSortByOrder(int *arr, int len, int order){
	if(!order){
		selectionSortAsc(arr, len);
	}else{
		selectionSortDesc(arr, len);
	}
}

static void selectionSortAsc(int *arr, int len){
	if(len > 1){
		int minIndex = 0;
		for(int i = 0; i<len-1; i++){
			minIndex = i;
			for(int j = i + 1 ; j<len; j++){
				if(*(arr+j) < *(arr+minIndex)){
					minIndex = j;
				}
			}
			if(minIndex != i){
				swap(arr+i, arr+minIndex);
			}
		}
	}
}

static void selectionSortDesc(int *arr, int len){
	if(len > 1){
		int maxIndex = 0;
		for(int i = 0; i<len-1; i++){
			maxIndex = i;
			for(int j = i + 1 ; j<len; j++){
				if(*(arr+j) > *(arr+maxIndex)){
					maxIndex = j;
				}
			}
			if(maxIndex!= i){
				swap(arr+i, arr+maxIndex);
			}
		}
	}
}


void insertionSort(int *arr, int len){
	insertionSortByOrder(arr, len,0);
}

void insertionSortByOrder(int *arr, int len, int order){
	if(!order){
		insertionSortAsc(arr, len);
	}else{
		insertionSortDesc(arr, len);
	}
}

static void insertionSortAsc(int *arr, int len){
	if(len > 1){
		int temp = 0;
		for(int i = 1; i<len; i++){
			temp = *(arr+i);
			int j = i-1;
			while(j >= 0 && *(arr+j)>temp){
				*(arr+j+1) = *(arr+j);
				 j--;
			}
			if(j+1 < i){
				*(arr+j+1) = temp;
			}
		}
	}
}

static void insertionSortDesc(int *arr, int len){
	if(len > 1){
		int temp = 0;
		for(int i = 1; i<len; i++){
			temp = *(arr+i);
			int j = i-1;
			while(j >= 0 && *(arr+j)<temp){
				*(arr+j+1) = *(arr+j);
				j--;
			}
			if(j+1 < i){
				*(arr+j+1) = temp;
			}
		}
	}
}


void bubbleSort(int *arr, int len){
	bubbleSortByOrder(arr, len,0);
}

void bubbleSortByOrder(int *arr, int len, int order){
	if(!order){
		bubbleSortAsc(arr, len);
	}else{
		bubbleSortDesc(arr, len);
	}
}

static void bubbleSortAsc(int *arr, int len){
	if(len > 1){
		bool swapTag = false;
		for(int i = 0; i<len-1; i++){
			swapTag = false;
			for(int j = 0; j<len-1-i; j++){
				if(*(arr+j) > *(arr+j+1)){
					swap(arr+j, arr+j+1);
					swapTag = true;
				}
			}
			if(!swapTag)
				break;
		}
	}
}

static void bubbleSortDesc(int *arr, int len){
	if(len > 1){
		bool swapTag = false;
		for(int i = 0; i<len-1; i++){
			swapTag = false;
			for(int j = 0; j<len-1-i; j++){
				if(*(arr+j) < *(arr+j+1)){
					swap(arr+j, arr+j+1);
					swapTag = true;
				}
			}
			if(!swapTag)
				break;
		}
	}
}


void quickSort(int *arr, int len){
	quickSortByOrder(arr, len,0);
}

void quickSortByOrder(int *arr, int len, int order){
	if(!order){
		quickSortAsc(arr, len);
	}else{
		quickSortDesc(arr, len);
	}
}

static void quickSortAscPartition(int *arr, int low, int high){
	if(low<high){
		int pivot = *(arr+low);
		int i = low;
		int j =high;
		
		while(i<j){
			while(i<j && *(arr+j)>=pivot){
				j--;
			}
			while(i<j && *(arr+i)<=pivot){
				i++;
			}
			if(i<j){
				swap(arr+i, arr+j);
			}
		}
		*(arr+low) = *(arr+i);
		*(arr+i) =pivot;
		quickSortAscPartition(arr, low, i-1);
		quickSortAscPartition(arr, i+1, high);
	}
}

static void quickSortAscPartition1(int *arr, int low, int high){
	if(low<high){
		int pivot = *(arr+low);
		int i = low;
		int j =high;
		
		while(i<j){
			while(i<j && *(arr+j)>=pivot){
				j--;
			}
			if(i<j){
				*(arr+i) = *(arr+j);
				i++;
			}
			while(i<j && *(arr+i)<=pivot){
				i++;
			}
			if(i<j){
				*(arr+j) = *(arr+i);
				j--;
			}
		}
		*(arr+i) =pivot;
		quickSortAscPartition1(arr, low, i-1);
		quickSortAscPartition1(arr, i+1, high);
	}
}

static void quickSortAscPartition2(int *arr, int low, int high){
	if(low<high){
		int pivot = *(arr+high);
		int i = low-1;
		int j = low;
		
		while(j<high){
			if(*(arr+j)<=pivot){
				if(++i<j){
					swap(arr+i, arr+j);
				}
			}
			j++;
		}
		swap(arr+i+1, arr+high);		
		quickSortAscPartition2(arr, low, i);
		quickSortAscPartition2(arr, i+2, high);
	}
}

static void quickSortAsc(int *arr, int len){
	if(len > 1){
		quickSortAscPartition2(arr, 0, len-1);	
	}
}

static void quickSortDescPartition(int *arr, int low, int high){
	if(low<high){
		int pivot = *(arr+low);
		int i = low;
		int j =high;
		
		while(i<j){
			while(i<j && *(arr+j)<=pivot){
				j--;
			}
			while(i<j && *(arr+i)>=pivot){
				i++;
			}
			if(i<j){
				swap(arr+i, arr+j);
			}
		}
		*(arr+low) = *(arr+i);
		*(arr+i) =pivot;
		quickSortDescPartition(arr, low, i-1);
		quickSortDescPartition(arr, i+1, high);
	}
}

static void quickSortDescPartition1(int *arr, int low, int high){
	if(low<high){
		int pivot = *(arr+low);
		int i = low;
		int j =high;
		
		while(i<j){
			while(i<j && *(arr+j)<=pivot){
				j--;
			}
			if(i<j){
				*(arr+i) = *(arr+j);
				i++;
			}
			while(i<j && *(arr+i)>=pivot){
				i++;
			}
			if(i<j){
				*(arr+j) = *(arr+i);
				j--;
			}
		}
		*(arr+i) =pivot;
		quickSortDescPartition1(arr, low, i-1);
		quickSortDescPartition1(arr, i+1, high);
	}
}

static void quickSortDescPartition2(int *arr, int low, int high){
	if(low<high){
		int pivot = *(arr+high);
		int i = low-1;
		int j = low;
		
		while(j<high){
			if(*(arr+j)>=pivot){
				if(++i<j) swap(arr+i, arr+j);
			}
			j++;
		}
		swap(arr+i+1, arr+high);
		quickSortDescPartition2(arr, low, i);
		quickSortDescPartition2(arr, i+2, high);
	}
}

static void quickSortDesc(int *arr, int len){
	if(len > 1){
		quickSortDescPartition2(arr, 0, len-1);	
	}
}


void mergeSort(int *arr, int len){
	mergeSortByOrder(arr, len, 0);
}

void mergeSortByOrder(int *arr, int len, int order){
	if(!order){
		mergeSortAsc(arr, len);
	}else{
		mergeSortDesc(arr, len);
	}
}

static void mergeAsc(int *arr, int *tempArr, int startIndex1, int endIndex1, int startIndex2, int endIndex2){
	
	if(*(arr+endIndex1)>*(arr+startIndex2)){
		int lIndex = startIndex1;
		int rIndex = startIndex2;
		int tempIndex;
		if(*(arr+startIndex1)>= *(arr+endIndex2)){
			while(rIndex <= endIndex2){
				*(tempArr+lIndex++) = *(arr+rIndex++);
			}
			tempIndex = lIndex;
			lIndex = startIndex1;
			while(lIndex <= endIndex1){
				*(tempArr+tempIndex++) = *(arr+lIndex++);
			}
		}else{
			tempIndex = startIndex1;
			while(lIndex <= endIndex1 && rIndex <= endIndex2){
				if(*(arr+lIndex)<= *(arr+rIndex)){
					*(tempArr+tempIndex++) = *(arr+lIndex++);
				}else{
					*(tempArr+tempIndex++) = *(arr+rIndex++);
				}
			}
			while(lIndex <= endIndex1){
				*(tempArr+tempIndex++) = *(arr+lIndex++);
			}
			while(rIndex <= endIndex2){
				*(tempArr+tempIndex++) = *(arr+rIndex++);
			}
		}
		
		tempIndex = startIndex1;
		while(tempIndex <= endIndex1){
			*(arr+tempIndex) = *(tempArr+tempIndex);
			tempIndex ++;
		}
		tempIndex = startIndex2;
		while(tempIndex <= endIndex2){
			*(arr+tempIndex) = *(tempArr+tempIndex);
			tempIndex ++;
		}
	}
}

static void mergeSortAscUnit(int *arr, int *tempArr, int startIndex, int endIndex){
	if(startIndex < endIndex){
		int index_split = (startIndex + endIndex)/2;
		mergeSortAscUnit(arr, tempArr, startIndex, index_split);
		mergeSortAscUnit(arr, tempArr, index_split+1, endIndex);
		mergeAsc(arr, tempArr, startIndex, index_split, index_split+1, endIndex);
	}
}

static void mergeSortAsc(int *arr, int len){
	if(len > 1){
		int tempArr[len];
		memset(tempArr, 0, sizeof(tempArr));
		mergeSortAscUnit(arr, tempArr, 0, len-1);
	}
}

static void mergeDesc(int *arr, int *tempArr, int startIndex1, int endIndex1, int startIndex2, int endIndex2){
	
	if(*(arr+endIndex1)<*(arr+startIndex2)){
		int lIndex = startIndex1;
		int rIndex = startIndex2;
		int tempIndex;
		if(*(arr+startIndex1)<= *(arr+endIndex2)){
			while(rIndex <= endIndex2){
				*(tempArr+lIndex++) = *(arr+rIndex++);
			}
			tempIndex = lIndex;
			lIndex = startIndex1;
			while(lIndex <= endIndex1){
				*(tempArr+tempIndex++) = *(arr+lIndex++);
			}
		}else{
			tempIndex = startIndex1;
			while(lIndex <= endIndex1 && rIndex <= endIndex2){
				if(*(arr+lIndex)>= *(arr+rIndex)){
					*(tempArr+tempIndex++) = *(arr+lIndex++);
				}else{
					*(tempArr+tempIndex++) = *(arr+rIndex++);
				}
			}
			while(lIndex <= endIndex1){
				*(tempArr+tempIndex++) = *(arr+lIndex++);
			}
			while(rIndex <= endIndex2){
				*(tempArr+tempIndex++) = *(arr+rIndex++);
			}
		}
		
		tempIndex = startIndex1;
		while(tempIndex <= endIndex1){
			*(arr+tempIndex) = *(tempArr+tempIndex);
			tempIndex ++;
		}
		tempIndex = startIndex2;
		while(tempIndex <= endIndex2){
			*(arr+tempIndex) = *(tempArr+tempIndex);
			tempIndex ++;
		}
	}
}

static void mergeSortDescUnit(int *arr, int *tempArr, int startIndex, int endIndex){
	if(startIndex < endIndex){
		int index_split = (startIndex + endIndex)/2;
		mergeSortDescUnit(arr, tempArr, startIndex, index_split);
		mergeSortDescUnit(arr, tempArr, index_split+1, endIndex);
		mergeDesc(arr, tempArr, startIndex, index_split, index_split+1, endIndex);
	}
}

static void mergeSortDesc(int *arr, int len){
	if(len > 1){
		int tempArr[len];
		memset(tempArr, 0, sizeof(tempArr));
		mergeSortDescUnit(arr, tempArr, 0, len-1);
	}
}


void heapSort(int *arr, int len){
	heapSortByOrder(arr, len,0);
}

void heapSortByOrder(int *arr, int len, int order){
	if(!order){
		//heapSortAsc(arr, len);
		heapSortAsc1(arr, len);
	}else{
		//heapSortDesc(arr, len);
		heapSortDesc1(arr, len);
	}
}

static void adjustHeapMax(int *arr, int index, int len){
	int temp = *(arr+index);
	int index_leftchildnode = 2 * index + 1;
	int index_max;
	while(index_leftchildnode<len){
		index_max = index_leftchildnode;
		if((index_leftchildnode+1)<len && (*(arr+index_leftchildnode)<*(arr+index_leftchildnode+1))){
			index_max += 1;
		}
		if(*(arr+index_max)>temp){
			*(arr+index) = *(arr+index_max);
			index = index_max;
			index_leftchildnode = 2 * index + 1;
		}else
			break;
	}
	*(arr+index) = temp;
}

static void adjustHeapMin(int *arr, int index, int len){
	int temp = *(arr+index);
	int index_leftchildnode = 2 * index + 1;
	int index_min;
	while(index_leftchildnode<len){
		index_min= index_leftchildnode;
		if((index_leftchildnode+1)<len && (*(arr+index_leftchildnode)>*(arr+index_leftchildnode+1))){
			index_min += 1;
		}
		if(*(arr+index_min)<temp){
			*(arr+index) = *(arr+index_min);
			index = index_min;
			index_leftchildnode = 2 * index + 1;
		}else
			break;
	}
	*(arr+index) = temp;
}

static void heapInsertMax(int *arr, int len){
	int index_current, index_fathernode;
	for(int i=1; i<len; i++){
		index_current = i;
		index_fathernode = (index_current - 1)/2;
		while(index_fathernode>= 0 && *(arr+index_current)>*(arr+index_fathernode)){
			swap(arr+index_current, arr+index_fathernode);
			index_current = index_fathernode;
			if(!index_current)
				break;
			index_fathernode = (index_current - 1)/2;
		}
	}
}

static void heapInsertMax1(int *arr, int len){
	int index_current, index_fathernode, temp;
	for(int i=1; i<len; i++){
		index_current = i;
		index_fathernode = (index_current - 1)/2;
		temp = *(arr+index_current);
		while(index_fathernode>= 0 && temp>*(arr+index_fathernode)){
			*(arr+index_current) = *(arr+index_fathernode);
			index_current = index_fathernode;
			if(!index_current)
				break;
			index_fathernode = (index_current - 1)/2;
		}
		*(arr+index_current) = temp;
	}
}

static void heapInsertMin(int *arr, int len){
	int index_current, index_fathernode;
	for(int i=1; i<len; i++){
		index_current = i;
		index_fathernode = (index_current - 1)/2;
		while(index_fathernode>= 0 && *(arr+index_current)<*(arr+index_fathernode)){
			swap(arr+index_current, arr+index_fathernode);
			index_current = index_fathernode;
			if(!index_current)
				break;
			index_fathernode = (index_current - 1)/2;
		}
	}
}

static void heapInsertMin1(int *arr, int len){
	int index_current, index_fathernode, temp;
	for(int i=1; i<len; i++){
		index_current = i;
		index_fathernode = (index_current - 1)/2;
		temp = *(arr+index_current);
		while(index_fathernode>= 0 && temp<*(arr+index_fathernode)){
			*(arr+index_current) = *(arr+index_fathernode);
			index_current = index_fathernode;
			if(!index_current)
				break;
			index_fathernode = (index_current - 1)/2;
		}
		*(arr+index_current) = temp;
	}
}

static void heapSortAsc(int *arr, int len){
	if(len > 1){
		int index_last_fathernode = len/2-1;
		for(int i = index_last_fathernode; i>= 0; i--){
			adjustHeapMax(arr, i, len);
		}
		
		for(int i = len-1; i>0; i--){
			swap(arr+i, arr);
			adjustHeapMax(arr,0, i);
		}
	}
}

static void heapSortDesc(int *arr, int len){
	if(len > 1){
		int index_last_fathernode = len/2-1;
		for(int i = index_last_fathernode; i>= 0; i--){
			adjustHeapMin(arr, i, len);
		}
		
		for(int i = len-1; i>0; i--){
			swap(arr+i, arr);
			adjustHeapMin(arr,0, i);
		}
	}
}

static void heapSortAsc1(int *arr, int len){
	if(len > 1){
		heapInsertMax(arr, len);
		
		for(int i = len-1; i>0; i--){
			swap(arr+i, arr);
			heapInsertMax(arr, i);
		}
	}
}

static void heapSortDesc1(int *arr, int len){
	if(len > 1){
		heapInsertMin(arr, len);
		
		for(int i = len-1; i>0; i--){
			swap(arr+i, arr);
			heapInsertMin(arr, i);
		}
	}
}


void countSort(int *arr, int len){
	countSortByOrder(arr, len,0);
}
	
void countSortByOrder(int *arr, int len, int order){
	if(!order){
		countSortAsc(arr, len);
	}else{
		countSortDesc(arr, len);
	}
}

static void countSortAsc(int *arr, int len){
	if(len > 1){
		int minAndMax[2]={0},minVal,maxVal;
		getMinAndMax(arr, len,minAndMax);
		minVal=minAndMax[0];
		maxVal=minAndMax[1];
		int countArrLen = maxVal-minVal+1;
		/*
		int resultArr[12]={0};
		int countArr[13]={0};
		*/
		int resultArr[len];
		memset(resultArr, 0, sizeof(resultArr));
		int countArr[countArrLen];
		memset(countArr, 0, sizeof(countArr));
		
		for(int i = 0; i<len; i++){
			countArr[*(arr+i)-minVal] += 1;
		}
		
		for(int i =1; i<countArrLen; i++){
			countArr[i] += countArr[i-1];
		}
		
		int countArrIndex = -1;
		for(int i = len-1; i>= 0; i--){
			countArrIndex = *(arr+i) - minVal;
			resultArr[countArr[countArrIndex]-1] = *(arr+i);
			countArr[countArrIndex] -= 1;
		}
		
		for(int i = 0; i<len; i++){
			*(arr+i) = resultArr[i];
		}
	}
}

static void countSortDesc(int *arr, int len){
	if(len > 1){
		int minAndMax[2]={0},minVal,maxVal;
		getMinAndMax(arr, len,minAndMax);
		minVal=minAndMax[0];
		maxVal=minAndMax[1];
		int countArrLen = maxVal - minVal + 1;
		/*
		int resultArr[12]={0};
		int countArr[13]={0};
		*/
		int resultArr[len];
		memset(resultArr, 0, sizeof(resultArr));
		int countArr[countArrLen];
		memset(countArr, 0, sizeof(countArr));
		
		for(int i = 0; i<len; i++){
			countArr[*(arr+i) - minVal] += 1;
		}
		
		for(int i =countArrLen-2; i>= 0; i--){
			countArr[i] += countArr[i+1];
		}
		
		int countArrIndex =-1;
		for(int i = len-1; i>= 0; i--){
			countArrIndex = *(arr+i) - minVal;
			resultArr[countArr[countArrIndex] - 1] = *(arr+i);
			countArr[countArrIndex] -= 1;
		}
		
		for(int i = 0; i<len; i++){
			*(arr+i) = resultArr[i];
		}
	}
}


void shellSort(int *arr, int len){
	shellSortByOrder(arr, len,0);
}

void shellSortByOrder(int *arr, int len, int order){
	if(!order){
		shellSortAsc(arr, len);
	}else{
		shellSortDesc(arr, len);
	}
}

static void shellSortAsc(int *arr, int len){
	if(len > 1){
		int gap = len/2;
		while(gap>0){
			int temp = 0;
			for(int i =gap; i<len; i++){
				temp = *(arr+i);
				int j = i-gap;
				while(j >= 0 && *(arr+j)>temp){
					*(arr+j+gap) = *(arr+j);
					j -= gap;
				}
				if(j+gap < i){
					*(arr+j+gap) = temp;
				}
			}
			gap = gap/2;
		}
	}
}

static void shellSortDesc(int *arr, int len){
	if(len > 1){
		int gap = len/2;
		while(gap>0){
			int temp = 0;
			for(int i =gap; i<len; i++){
				temp = *(arr+i);
				int j = i-gap;
				while(j >= 0 && *(arr+j)<temp){
					*(arr+j+gap) = *(arr+j);
					j -= gap;
				}
				if(j+gap < i){
					*(arr+j+gap) = temp;
				}
			}
			gap = gap/2;
		}
	}
}