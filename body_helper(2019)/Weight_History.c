#include "total.h"

void Weight_History(struct Record Change[SIZE][SIZE], struct Data User[SIZE]) // 체중 변화 지표
{
	int x = 0;

	printf("초기 체중\t ");
	for (x = 1; x < t + 1; x++)
		printf(" %d차\t\t ", x);
	printf("\n------------------------------------------------------\n");
	printf(" %5d\t\t", User[j].Weight);
	for (x = 0; x < t + 2; x++)
	{
		if (Change[j][x].weight != 0)
			printf(" %5d\t\t", Change[j][x].weight);
	}
	printf("\n------------------------------------------------------\n");
}