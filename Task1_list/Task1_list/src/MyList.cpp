#include "MyList.h"
#include "stdio.h"

void StringListInit(char*** list)
{
	if (*list == NULL) {
		return;
	}
	else {
		*list = NULL;
		return;
	}
}
void StringListDestroy(char*** list)
{
	if (*list == NULL) {
		return;
	}
	else {
		while (*list != NULL)
		{
			StringListPopFront(list);
		}
		return;
	}
}
void StringListPrint(char*** list)
{
	if (*list == NULL) {
		return;
	}
	else {
		char** curr = *list, ** prev;
		while (curr[0] != NULL)
		{
			printf(curr[1]); printf(",");
			prev = curr;
			curr = (char**)curr[0];
		}
		printf(curr[1]);
		return;
	}
}
void StringListPushBack(char*** list, const char* str)
{
	if (str == NULL) {
		return;
	}
	else if (*list == NULL) {
		char** head = (char**)malloc(2 * sizeof(char**));
		if (head != NULL) {
			head[0] = NULL;
			head[1] = (char*)malloc((strlen(str) + 1) * sizeof(char));
		}
		else { return; }

		if (head[1] != NULL) {
			strcpy_s(head[1], strlen(str) + 1, str);
			*list = head;
			return;
		}
		else { return; }
	}
	else {
		char** curr = *list;
		while (curr[0] != NULL)	{
			curr = (char**)curr[0];
		}
		char** node = (char**)malloc(2 * sizeof(char*));
		if (node != NULL)
		{
			node[0] = NULL;
			node[1] = (char*)malloc((strlen(str) + 1) * sizeof(char));
		}
		else { return; }

		if (node[1] != NULL) {
			strcpy_s(node[1], strlen(str) + 1, str);
			curr[0] = (char*)node;
			return;
		}
		else { return; }
	}
}	
void StringListPopBack(char*** list)
{
	if (*list == NULL) {
		return;
	}
	else if ((*list)[0] == NULL) {
		free((*list)[1]);
		free(*list);
		*list = NULL;
		return;
	}
	else
	{
		char** curr = *list, ** prev = curr;
		while (curr[0] != NULL)
		{
			prev = curr;
			curr = (char**)curr[0];
		}
		free(curr[1]);
		free(curr);
		prev[0] = NULL;
		return;
	}
}
void StringListPushFront(char*** list, const char* str)
{
	if (str == NULL) {
		return;
	}
	else {
		char** oldHead = *list, ** newHead;
		newHead = (char**)malloc(2 * sizeof(char*));
		if (newHead != NULL)	{
			newHead[0] = (char*)oldHead;
			newHead[1] = (char*)malloc((strlen(str) + 1) * sizeof(char));
		}
		else { return; }
		if (newHead[1] != NULL) {
			strcpy_s(newHead[1], strlen(str) + 1, str);
			*list = newHead;
			return;
		}
		else { return; }
	}
}
void StringListPopFront(char*** list)//
{
	if (*list == NULL) {
		return;
	}
	else if ((*list)[0] == NULL) {
		free((*list)[1]);
		free(*list);
		*list = NULL;
		return;
	}
	else {
		char** newHead = *list, ** oldHead;
		oldHead = newHead;
		newHead = (char**)newHead[0];
		free(oldHead[1]);
		free(oldHead);
		*list = newHead;
		return;
	}
}
int StringListSize(char*** list)
{
	if (*list == NULL) {
		return 0;
	}
	else {
		int count = 1;
		char** curr = *list, ** prev;
		while (curr[0] != nullptr) {
			prev = curr;
			curr = (char**)curr[0];
			count++;
		}
		return count;
	}
}
int StringListIndexOf(char*** list, const char* str)
{
	if (*list == NULL) {
		return -1;
	}
	else {
		char** next = *list, ** curr;
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
	if (*list == NULL || str == NULL) {
		return;
	}
	else {
		char** curr = *list, ** prev = NULL;
		while (0 == strcmp(curr[1], str)) {
			*list = (char**)curr[0];
			free(curr[1]);
			free(curr);
			curr = *list;
			if (curr == NULL) {
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
	if (*list == NULL) {
		return;
	}
	else {
		char** current = NULL, ** previous = NULL, ** compared = *list;
		while (compared[0] != NULL)
		{
			compared = (char**)compared[0];
			previous = compared;
			current = (char**)previous[0];
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
		}
		return;
	}
}
void StringListReplaceInStrings(char*** list, const char* before, const char* after)
{
	if (*list == NULL || before == NULL || after == NULL) {
		return;
	}
	char** curr = *list, ** prev = curr;
	while (prev[0] != NULL)
	{
		prev = curr;
		curr = (char**)curr[0];
		if (0 == strcmp(before, prev[1])) {
			free(prev[1]);
			prev[1] = (char*)malloc((strlen(after) + 1) * sizeof(char));
			if (prev[1] != NULL) {
				strcpy_s(prev[1], strlen(after) + 1, after);
			}
		}
	}
}
void StringListSort(char*** list)
{
	if (*list == NULL) {
		return;
	}
	else
	{
		char** iterable = *list, ** target;
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
		return;
	}
}