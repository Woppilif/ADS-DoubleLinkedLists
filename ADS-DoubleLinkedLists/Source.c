#include <stdio.h>
#include <stdbool.h>

int COUNT = 0;

struct Items {
	int val;
	struct Items* next;
	struct Items* prev;
};

struct Items* pHead;

void init()
{
	pHead = malloc(sizeof(struct Items));
	pHead->val = 0;
	pHead->next = pHead;
	pHead->prev = pHead;
	return;
}

bool empty()
{
	if (pHead->next == pHead)
	{
		return true;
	}
	return false;
}

struct Items* Search(int item)
{
	struct Items* pTemp = pHead->prev;
	while (pTemp != pHead)
	{
		if (pTemp->val == item)
		{
			return pTemp;
		}
		else
		{
			pTemp = pTemp->prev;
		}
	}
	return NULL;
}

void OutForw()
{
	struct Items* pTemp = pHead->next;
	while (pTemp != pHead)
	{
		printf("VAL: %d\n", pTemp->val);
		pTemp = pTemp->next;
	}
	return;
}

void OutBack()
{
	struct Items* pTemp = pHead->prev;
	while (pTemp != pHead)
	{
		printf("VAL: %d\n", pTemp->val);
		pTemp = pTemp->prev;
	}
	return;
}

int AddAfter(int item)
{
	struct Items *pNew = malloc(sizeof(struct Items));
	if (empty())
	{
		pNew->val = COUNT++;
		pNew->next = pHead;
		pNew->prev = pHead;
		pHead->next = pNew;
		pHead->prev = pNew;
		return 1;
	}
	struct Items* pSearch = Search(item);
	if (pSearch == NULL)
	{
		printf("NO match\n");
		return 0;
	}
	pNew->val = COUNT++;
	pNew->next = pSearch->next;
	pNew->prev = pSearch;
	pNew->next->prev = pNew;
	pSearch->next = pNew;
	return 1;
}

int AddBefore(int item) 
{
	struct Items* pNew = malloc(sizeof(struct Items));
	if (empty())
	{
		pNew->val = COUNT++;
		pNew->next = pHead;
		pNew->prev = pHead;
		pHead->next = pNew;
		pHead->prev = pNew;
		return 1;
	}
	struct Items* pSearch = Search(item);
	if (pSearch == NULL)
	{
		printf("NO match\n");
		return 0;
	}
	pNew->val = COUNT++;
	pNew->next = pSearch;
	pNew->prev = pSearch->prev;
	pNew->prev->next = pNew;
	pSearch->prev = pNew;
	return 1;
}

int Delete(int item)
{
	struct Items* pSearch = Search(item);
	if (pSearch == NULL)
	{
		printf("NO match\n");
		return 0;
	}
	pSearch->prev->next = pSearch->next;
	pSearch->next->prev = pSearch->prev;
	free(pSearch);
	return 1;
}

void help()
{
	printf("1 - Print all in forward direction\n2 - Print all in back direction\n");
	printf("3 - Add after selected item\n4 - Add before selected item\n");
	printf("5 - Delete selected item\n");
	return;
}

int main(void)
{
	int choice = 0;
	int item = 0;
	init();
	while (choice != -1)
	{
		help();
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			OutForw();
			break;
		case 2:
			OutBack();
			break;
		case 3:
			printf("Add After:");
			scanf_s("%d", &item);
			AddAfter(item);
			break;
		case 4:
			printf("Add before:");
			scanf_s("%d", &item);
			AddBefore(item);
			break;
		case 5:
			printf("Delete:");
			scanf_s("%d", &item);
			Delete(item);
			break;
		default:
			help();
			break;
		}
	}
	return 0;
}


