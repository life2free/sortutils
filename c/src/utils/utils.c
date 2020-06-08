#include<stdio.h>
#include "../../include/utils/utils.h"

int getMax(int *arr, int len){
	int maxVal = -99999;
	if(len>0){
		if(len == 1) return *arr;
		else if(len == 2) return *arr >= *(arr+1) ? *arr : *(arr+1);
		else{
			maxVal = *arr;
			for(int i=0; i<len; i++){
				if(maxVal < *(arr+i))
					maxVal = *(arr+i);
			}
		}
	}
	return maxVal;
}


int getMin(int *arr, int len){
	int minVal = -99999;
	if(len>0){
		if(len == 1) return *arr;
		else if(len == 2) return *arr <= *(arr+1) ? *arr : *(arr+1);
		else{
			minVal = *arr;
			for(int i=0; i<len; i++){
				if(minVal > *(arr+i))
					minVal = *(arr+i);
			}
		}
	}
	return minVal;
}

void getMinAndMax(int *arr, int len, int *minAndMax){
	int minVal = -99999;
	int maxVal = -99999;
	if(len>0){
		if(len == 1) minVal = maxVal = *arr;
		else if(len == 2){
			minVal = (*arr <= *(arr+1) ? *arr : *(arr+1));
			maxVal = *arr + *(arr+1) - minVal;
		}else{
			minVal = maxVal = *arr;
			for(int i=0; i<len; i++){
				if(maxVal < *(arr+i))
					maxVal = *(arr+i);
				else if(minVal > *(arr+i))
					minVal = *(arr+i);
			}
		}
	}
	*minAndMax = minVal;
	*(minAndMax+1) = maxVal;
}


char * strToLower(char * str){
	char * ret = str;
	for(; *str != '\0'; str++){
		if((*str >= 'A')&&(*str <= 'Z')){
			*str += 32;
		}
	}
	return ret;
}

char * strToUpper(char * str){
	char * ret = str;
	for(; *str != '\0'; str++){
		if((*str >= 'a')&&(*str <= 'z')){
			*str -= 32;
		}
	}
	return ret;
}

void printfArray(int *arr, int len){
	for(int i=0; i<len; i++){
		printf("%d  ", *(arr+i));
	}
}


void printfArrayWithMessage(int *arr, int len, char *message){
	printf("%s\n", message);
	printfArray(arr, len);
	printf("\n");
}