#include "StringList.h"

#include "string.h"
#include "stdio.h"

void StringListInit(char*** list)
{
	if (*list != NULL) {
		return;
	}
	else {
		*list = (char**)calloc(sizeof(char**), 2);
		if (NULL == *list) {
			return;
		}
	}
}

void StringListDestroy(char*** list)
{
	if (NULL == (*list)) {
		return;
	}
	else {
		while ((*list)[1] != NULL)
		{
			StringListPopFront(list);
		}
		free(*list);
		*list = NULL;
	}
}

void StringListPushFront(char*** list, const char* str)
{
	if (NULL == str || NULL == (*list)) {
		return;
	}
	else if (NULL == (*list)[1]) {
		(*list)[1] = (char*)calloc((strlen(str) + 1) * sizeof(char), 1);
		if ((*list)[1] != NULL) {
			strcpy_s((*list)[1], strlen(str) + 1, str);
		}
		else { return; }
	}
	else {
		char** oldHead = *list;
		char** newHead = NULL;
		newHead = (char**)calloc(sizeof(char**), 2);
		if (newHead != NULL) {
			newHead[0] = (char*)oldHead;
			newHead[1] = (char*)calloc((strlen(str) + 1) * sizeof(char), 1);
		}
		else { return; }
		if (newHead[1] != NULL) {
			strcpy_s(newHead[1], strlen(str) + 1, str);
			*list = newHead;
			return;
		}
	}
}

void StringListPopFront(char*** list)
{
	if (NULL == (*list) || NULL == ((*list)[1])) {
		return;
	}
	else if (NULL == ((*list)[0])) {
		free((*list)[1]);
		(*list)[1] = NULL;
		return;
	}
	else {
		char** newHead = *list;
		char** oldHead = newHead;
		newHead = (char**)newHead[0];
		free(oldHead[1]);
		free(oldHead);
		*list = newHead;
	}
}

void StringListPushBack(char** list, const char* str)
{
	if (NULL == str || NULL == list) {
		return;
	}
	else {
		if (NULL == list[1]) {
			list[1] = (char*)calloc((strlen(str) + 1) * sizeof(char), 1);
			if (list[1] != NULL) {
				strcpy_s(list[1], strlen(str) + 1, str);
			}
		}
		else {
			char** curr = list;
			while (curr[0] != NULL) {
				curr = (char**)curr[0];
			}
			char** node = (char**)calloc(sizeof(char*), 2);
			if (node != NULL) {
				node[1] = (char*)calloc((strlen(str) + 1) * sizeof(char), 1);
			}
			else { return; }
			if (node[1] != NULL) {
				strcpy_s(node[1], strlen(str) + 1, str);
				curr[0] = (char*)node;
			}
		}
	}
}

void StringListPopBack(char** list)
{
	if (NULL == list || NULL == list[1]) {
		return;
	}
	else if (list[0] == NULL) {
		free(list[1]);
		list[1] = NULL;
		return;
	}
	else
	{
		char** curr = list;
		char** prev = NULL;
		while (curr[0] != NULL)
		{
			prev = curr;
			curr = (char**)curr[0];
		}
		free(curr[1]);
		free(curr);
		prev[0] = NULL;
	}
}

void StringListPrint(char** list)
{
	if (NULL == list || NULL == list[1]) {
		return;
	}
	else {
		char** curr = list;
		char** prev = NULL;
		while (curr[0] != NULL)
		{
			printf("%s", curr[1]);
			printf(",");
			prev = curr;
			curr = (char**)curr[0];
		}
		printf("%s", curr[1]);
	}
}

int StringListSize(char** list)
{
	if (NULL == list || NULL == list[1]) {
		return 0;
	}
	else {
		int count = 1;
		char** curr = list;
		char** prev = NULL;
		while (curr[0] != nullptr) {
			prev = curr;
			curr = (char**)curr[0];
			count++;
		}
		return count;
	}
}

int StringListIndexOf(char** list, const char* str)
{
	if (NULL == list || NULL == list[1]) {
		return -1;
	}
	else {
		char** next = list;
		char** curr = NULL;
		int pos = 0;
		do {
			curr = next;
			next = (char**)next[0];
			if (strcmp(curr[1], str) == 0) {
				return pos;
			}
			pos++;
		} while (next != NULL);
		return -1;
	}
}

void StringListRemove(char*** list, const char* str)
{
	if (NULL == str || NULL == (*list) || NULL == ((*list)[1])) {
		return;
	}
	else {
		char** curr = *list;
		char** prev = NULL;
		while (0 == strcmp(curr[1], str)) {
			*list = (char**)curr[0];
			free(curr[1]);
			free(curr);
			curr = *list;
			if (NULL == curr) {
				return;
			}
		}
		prev = curr;
		curr = (char**)curr[0];
		while (curr != NULL)
		{
			if (0 == strcmp(curr[1], str)) {
				prev[0] = curr[0];
				free(curr[1]);
				free(curr);
				curr = (char**)prev[0];
			}
			else {
				prev = curr;
				curr = (char**)curr[0];
			}
		}
	}
}

void StringListRemoveDuplicates(char*** list)
{
	if (NULL == *list || NULL == (*list)[1] || NULL == (*list)[0]) {
		return;
	}
	else
	{
		StringListQuickSort(list);
		char** current = *list;
		char** next = (char**)current[0];
		while (current[0] != NULL)
		{
			if (0 == strcmp(current[1], next[1]))
			{
				current[0] = next[0];
				free(next[1]);
				free(next);
				next = (char**)current[0];
			}
			else
			{
				current = (char**)current[0];
				next = (char**)next[0];
			}
		}
	}
}

void StringListReplaceInStrings(char** list, const char* before, const char* after)
{
	if (NULL == list || NULL == list[1] || NULL == before || NULL == after) {
		return;
	}
	char** curr = NULL;
	char** next = list;
	int stringAfterLength = strlen(after) + 1;
	do
	{
		curr = next;
		next = (char**)next[0];
		if (0 == strcmp(before, curr[1])) {
				free(curr[1]);
				curr[1] = (char*)calloc(stringAfterLength * sizeof(char), 1);
			if (curr[1] != NULL) {
				strcpy_s(curr[1], stringAfterLength, after);
			}
		}
	} while (next != NULL);
}

void StringListBubbleSort(char** list)
{
	if (NULL == list || NULL == list[1] || NULL == list[0]) {
		return;
	}
	else
	{
		char** iterable = list;
		char** target = NULL;
		target = iterable;
		while (target[0] != NULL)
		{
			target = iterable;
			iterable = (char**)iterable[0];
			while (iterable != NULL)
			{
				if (0 < strcmp(target[1], iterable[1])) {
					char* buff = target[1];
					target[1] = iterable[1];
					iterable[1] = buff;
				}
				iterable = (char**)iterable[0];
			}
			iterable = (char**)target[0];
		}
	}
}

void StringListQuickSort(char*** list, const char* end)
{
	if (NULL == *list || NULL == (*list)[1] || NULL == (*list)[0]) {
		return;
	}
	else
	{
		char** current = *list;
		char** comparable = (char**)current[0];
		char** equal = *list;
		char** left = *list;
		char** right = NULL;
		while ((end == NULL) ? (comparable != NULL) : (0 != strcmp(comparable[1], end)))
		{
			int cmpCurrentComparable = strcmp(current[1], comparable[1]);
			if (cmpCurrentComparable < 0)
			{
				if (right == NULL)
				{
					right = comparable;
				}
			}
			else if (cmpCurrentComparable == 0)
			{
				current = (char**)current[0];

				char* buff = comparable[1];
				comparable[1] = current[1];
				current[1] = buff;
				if (right != NULL)
				{
					right = (char**)right[0];
				}
			}
			else
			{
				char* buff = equal[1];
				equal[1] = ((char**)current[0])[1];
				((char**)current[0])[1] = buff;
				int cmpEqualCurrent = strcmp(equal[1], current[1]);
				if (cmpEqualCurrent == 0)
				{
					if (0 < strcmp(equal[1], ((char**)(equal[0]))[1]))
					{
						char* buff2 = equal[1];
						equal[1] = comparable[1];
						comparable[1] = buff2;
					}
				}
				else if (cmpEqualCurrent > 0)
				{
					char* buff2 = equal[1];
					equal[1] = comparable[1];
					comparable[1] = buff2;
				}
				equal = (char**)equal[0];
				current = (char**)current[0];
				if (right != NULL)
				{
					right = (char**)right[0];
				}
			}
			comparable = (char**)comparable[0];
		}
		if (0 != strcmp(left[1], equal[1])) {
			StringListQuickSort(&left, equal[1]);
		}
		if (right != NULL) {
			StringListQuickSort(&right, end);
		}
	}
}