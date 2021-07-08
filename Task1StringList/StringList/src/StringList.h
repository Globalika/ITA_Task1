#pragma once
#ifndef STRING_LIST
#define STRING_LIST

#include "stdlib.h"

/* Initialise list. */
int StringListInit(char*** list);
/* Destroy list. Point to NULL after destroy. */
int StringListDestroy(char*** list);

int StringListPushFront(char*** list, const char* str);

int StringListPopFront(char*** list);

int StringListPushBack(char** list, const char* str);

int StringListPopBack(char** list);
/* Display list */
int StringListPrint(char** list);

int StringListSize(char** list);
/* Returns the index position of the first occurrence of str in the list. 
   Return -1 if there is no such str. */
int StringListIndexOf(char** list, const char* str);
/* Remove all occurrences of str in the list. */
int StringListRemove(char*** list, const char* str);

int StringListRemoveDuplicates(char*** list);
/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
int StringListReplaceInStrings(char** list, const char* before, const char* after);
/* Sorts the list of strings in ascending order with bubble algoritm. */
int StringListBubbleSort(char** list);
/* Sorts the list of strings in ascending order with quick sort algoritm. */
int StringListQuickSort(char*** list, const char* end = NULL);

#endif // STRING_LIST