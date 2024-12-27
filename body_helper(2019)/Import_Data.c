#include "total.h"

void Import_Data(FILE* fp, FILE* fpp, struct Record Change[SIZE][SIZE], struct Data User[SIZE], struct Of Number[SIZE][SIZE]) // 파일 데이터 불러오기
{
	int k = 0;
	int x = 0, y = 0;

	fp = fopen("user_data.txt", "r");

	while (!feof(fp))
	{
		fscanf(fp, "%s ", &User[i].ID);
		fscanf(fp, "%s ", &User[i].PW);
		fscanf(fp, "%d ", &User[i].Height);
		fscanf(fp, "%d ", &User[i].Weight);
		fscanf(fp, "%d ", &User[i].Gender);
		fscanf(fp, "%d", &User[i].Member);
		i++;
	}
	i -= 2; // i가 두 번 헛돌아서 예외처리, 이유는 모름, feof 인식 방식을 모르겠음.
	fclose(fp);

	fpp = fopen("weight_data.txt", "r");
	for (y = 0; y < SIZE; y++)
	{
		for (x = 0; x < SIZE - 2; x++)
			fscanf(fpp, "%d ", &Change[y][x].weight);
		fscanf(fpp, "%d", &Number[y][SIZE - 1].times);
	}
	fclose(fpp);
}