#include "total.h"

void Weight_History(struct Record Change[SIZE][SIZE], struct Data User[SIZE]) // ü�� ��ȭ ��ǥ
{
	int x = 0;

	printf("�ʱ� ü��\t ");
	for (x = 1; x < t + 1; x++)
		printf(" %d��\t\t ", x);
	printf("\n------------------------------------------------------\n");
	printf(" %5d\t\t", User[j].Weight);
	for (x = 0; x < t + 2; x++)
	{
		if (Change[j][x].weight != 0)
			printf(" %5d\t\t", Change[j][x].weight);
	}
	printf("\n------------------------------------------------------\n");
}