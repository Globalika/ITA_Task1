#pragma once
#ifndef MY_STRING_LIST
#define MY_STRING_LIST
#include "stdlib.h"
#include "string.h"

////initialise list
void StringListInit(char*** list);
////destroy list // point to nullptr after destroy
void StringListDestroy(char*** list);
////insert at the end
void StringListPushBack(char*** list, const char* str);
////Remove all occurrences of str int the list
void StringListRemove(char*** list, const char* str);
///* Returns the number of items in the list. */
int StringListSize(char*** list);
///* Returns the index position of the first occurrence of str in the list. return -1 if there is no such str */
int StringListIndexOf(char*** list, const char* str);
//listdisplay
void StringListPrint(char*** list);
///* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char*** list);
///* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char*** list, const char* before,const char* after);
///* Sorts the list of strings in ascending order */
void StringListSort(char*** list);
//pop back
void StringListPopBack(char*** list);
//pop front
void StringListPopFront(char*** list);
//push front
void StringListPushFront(char*** list, const char* str);

#endif MY_STRING_LIST