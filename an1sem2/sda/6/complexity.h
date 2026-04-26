#ifndef ANALIZA_EMPIRICA
#define ANALIZA_EMPIRICA
#include <stdio.h>
void compare(const void* one, const void* two);
int bsearchIter(int* arr, int n, int target);
int bsearchRec(int* arr, int target, int left, int right);
#endif