#include "MyList.h"
#include "stdio.h"

void StringListInit(char*** list)
{
	if (*list != NULL) {
		return;
	}
	else {
		*list = (char**)calloc(sizeof(char**), 2);
		if(NULL == *list) {
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
			printf("%s",curr[1]);
			printf(",");
			prev = curr;
			curr = (char**)curr[0];
		}
		printf("%s", curr[1]);
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
		if (newHead != NULL)	{
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
	if (NULL == list || NULL == list[1]){
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
void StringListRemoveDuplicates(char** list)
{
	if (NULL == list || NULL == list[1] || NULL == list[0]) {
		return;
	}
	else {
		char** compared = list;
		char** previous = NULL;
		char** current = NULL;
		while (compared[0] != NULL)
		{
			previous = compared;
			current = (char**)compared[0];
			while (current != NULL)
			{
				if (0 == strcmp(current[1], compared[1])) {
					previous[0] = (char*)current[0];
					free(current[1]);
					free(current);
					current = (char**)previous[0];
					continue;
				}
				previous = current;
				current = (char**)current[0];
			}
			if (NULL == compared[0]) {
				return;
			}
			compared = (char**)compared[0];
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
	do
	{
		curr = next;
		next = (char**)next[0];
		if (0 == strcmp(before, curr[1])) {
			free(curr[1]);
			int stringLength = strlen(after) + 1;
			curr[1] = (char*)calloc(stringLength * sizeof(char),1);
			if (curr[1] != NULL) {
				strcpy_s(curr[1], stringLength, after);
			}
		}
	} while (next != NULL);
}
void StringListSort(char** list)
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