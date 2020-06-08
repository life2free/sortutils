#ifndef _UTILS_H

#define _UTILS_H

int getMax(int *arr, int len);
int getMin(int *arr, int len);
void getMinAndMax(int *arr, int len, int *minAndMax);
char * strToLower(char * str);
char * strToUpper(char * str);
void printfArray(int *arr, int len);
void printfArrayWithMessage(int *arr, int len, char *message);

#endif