#include "..\..\StringList\src\StringList.h"

#include "stdio.h"

void ListPushElements(char*** myList)
{
	printf("Push front seven elements :\n");
	StringListPushFront(myList, "22");
	StringListPushFront(myList, "22");
	StringListPushFront(myList, "23");
	StringListPushFront(myList, "44");
	StringListPushFront(myList, "94");
	StringListPushFront(myList, "54");
	StringListPushFront(myList, "34");
	StringListPrint(*myList); printf("\n");
	printf("Push back seven elements :\n");
	StringListPushBack(*myList, "34");
	StringListPushBack(*myList, "44");
	StringListPushBack(*myList, "22");
	StringListPushBack(*myList, "11");
	StringListPushBack(*myList, "22");
	StringListPushBack(*myList, "31");
	StringListPushBack(*myList, "22");
	StringListPrint(*myList); printf("\n");
}

void ListPopElements(char*** myList)
{
	printf("Pop front two elements :\n");
	StringListPopFront(myList);
	StringListPopFront(myList);
	StringListPrint(*myList); printf("\n");
	printf("Pop back two elements :\n");
	StringListPopBack(*myList);
	StringListPopBack(*myList);
	StringListPrint(*myList); printf("\n");
}

int main()
{
	char** myList = NULL;
	StringListInit(&myList);
	ListPushElements(&myList);
	ListPopElements(&myList);
	printf("List size :\n");
	printf("%d",StringListSize(myList)); printf("\n");
	printf("Index of 22 :\n");
	printf("%d", StringListIndexOf(myList, "22")); printf("\n");
	printf("Index of 100 :\n");
	printf("%d", StringListIndexOf(myList, "100")); printf("\n");
	printf("Remove 34 :\n");
	StringListRemove(&myList, "34");
	StringListPrint(myList); printf("\n");
	printf("Replace 22 with 222 :\n");
	StringListReplaceInStrings(myList, "22", "222");
	StringListPrint(myList); printf("\n");
	printf("Sort list :\n");
	StringListQuickSort(&myList);
	StringListPrint(myList); printf("\n");
	printf("Remove duplicates :\n");
	StringListRemoveDuplicates(&myList);
	StringListPrint(myList); printf("\n");
	StringListDestroy(&myList);
	return 0;
}