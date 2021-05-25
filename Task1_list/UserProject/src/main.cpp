#include <iostream>
#include "..\..\Task1_list\src\MyList.h"
using namespace std;

int main()
{
	
	char** myList = NULL;
	StringListInit(&myList);
	StringListPushFront(&myList, "22");
	StringListPushFront(&myList, "11");
	StringListPushFront(&myList, "11");
	StringListPushFront(&myList, "22");
	StringListPushFront(&myList, "66");
	StringListPushFront(&myList, "22");
	StringListPushFront(&myList, "22");
	StringListPushFront(&myList, "22");
	StringListPushFront(&myList, "22");
	StringListPushFront(&myList, "33");
	StringListPushFront(&myList, "44");
	StringListPushFront(&myList, "22");
	StringListPushFront(&myList, "33");
	StringListPushFront(&myList, "44");
	StringListPushFront(&myList, "22");
	StringListPushFront(&myList, "33");
	StringListPushFront(&myList, "44");
	StringListPushFront(&myList, "22");
	StringListPushFront(&myList, "22");
	StringListPushFront(&myList, "22");
	StringListPrint(myList); cout << endl; 
	//StringListRemoveDuplicates(myList);
	StringListSort(myList);
	//StringListReplaceInStrings(myList, "22", "00");
	StringListPrint(myList); cout << endl;
	StringListDestroy(&myList);
	return 0;
}