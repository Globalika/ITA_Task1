#pragma once
#ifndef STRING_LIST
#define STRING_LIST

#include "stdlib.h"

/* Initialise list. */
void StringListInit(char*** list);
/* Destroy list. Point to NULL after destroy. */
void StringListDestroy(char*** list);

void StringListPushFront(char*** list, const char* str);

void StringListPopFront(char*** list);

void StringListPushBack(char** list, const char* str);

void StringListPopBack(char** list);
/* Display list */
void StringListPrint(char** list);

int StringListSize(char** list);
/* Returns the index position of the first occurrence of str in the list. 
   Return -1 if there is no such str. */
int StringListIndexOf(char** list, const char* str);
/* Remove all occurrences of str in the list. */
void StringListRemove(char*** list, const char* str);

void StringListRemoveDuplicates(char*** list);
/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, const char* before, const char* after);
/* Sorts the list of strings in ascending order with bubble algoritm. */
void StringListBubbleSort(char** list);
/* Sorts the list of strings in ascending order with quick sort algoritm. */
void StringListQuickSort(char*** list, const char* end = NULL);

#endif STRING_LIST