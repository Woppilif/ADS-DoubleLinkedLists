#include <stdio.h>
int COUNT = 0;

struct Items
{
	int num;
	struct Items* prev;
	struct Items* next;
};

struct Items* pFirst;


int main(void)
{
	pFirst = malloc(sizeof(struct Items));
	pFirst->num = 5;
	printf("%p x", &pFirst);
	return 0;
}