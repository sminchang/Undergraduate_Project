#include "total.h"

void m_kcal(struct Record Change[SIZE][SIZE], struct Data User[SIZE]) // 남성일 경우에 최소, 최대 섭취량 산출
{
	float BMI = 0;
	float M = 0;

	M = (User[j].Height * 0.01) * (User[j].Height * 0.01);
	BMI = Change[j][t].weight / M;

	if (BMI >= 40.0)
	{
		printf("신장 혹은 체중 정보가 잘못 입력되었습니다.\n\n");
	}
	else if (BMI <= 18.5)
	{
		printf("최소섭취량은 %.1fkcal입니다.\n", BMI * 48.5);
		printf("최대섭취량은 %.1fkcal입니다.\n\n", BMI * 60.0);
	}
	else if (BMI > 18.5 && BMI <= 25.0)
	{
		printf("최소섭취량은 %.1fkcal입니다.\n", BMI * 42.0);
		printf("최대섭취량은 %.1fkcal입니다.\n\n", BMI * 58.0);
	}
	else if (BMI > 25.0 && BMI <= 30.0)
	{
		printf("최소섭취량은 %.1fkcal입니다.\n", BMI * 40.0);
		printf("최대섭취량은 %.1fkcal입니다.\n\n", BMI * 56.0);
	}
	else if (BMI > 30.0 && BMI <= 40.0)
	{
		printf("최소섭취량은 %.1fkcal입니다.\n", BMI * 41.0);
		printf("최대섭취량은 %.1fkcal입니다.\n\n", BMI * 50.0);
	}
	else
	{
		printf("회원정보가 잘못 입력되었습니다.\n\n");
	}
}

void fm_kcal(struct Record Change[SIZE][SIZE], struct Data User[SIZE]) // 여성일 경우에 최소, 최대 섭취량 산출
{
	float BMI = 0;
	float M = 0;

	M = (User[j].Height * 0.01) * (User[j].Height * 0.01);
	BMI = Change[j][t].weight / M;

	if (BMI >= 40.0)
	{
		printf("신장 혹은 체중 정보가 잘못 입력되었습니다.\n\n");
	}
	else if (BMI <= 18.5)
	{
		printf("최소섭취량은 %.1fkcal입니다.\n", BMI * 45.0);
		printf("최대섭취량은 %.1fkcal입니다.\n\n", BMI * 59.0);
	}
	else if (BMI > 18.5 && BMI <= 25.0)
	{
		printf("최소섭취량은 %.1fkcal입니다.\n", BMI * 41.0);
		printf("최대섭취량은 %.1fkcal입니다.\n\n", BMI * 57.0);
	}
	else if (BMI > 25.0 && BMI <= 30.0)
	{
		printf("최소섭취량은 %.1fkcal입니다.\n", BMI * 38.0);
		printf("최대섭취량은 %.1fkcal입니다.\n\n", BMI * 52.0);
	}
	else if (BMI > 30.0 && BMI < 40.0)
	{
		printf("최소섭취량은 %.1fkcal입니다.\n", BMI * 38.5);
		printf("최대섭취량은 %.1fkcal입니다.\n\n", BMI * 50.0);
	}
	else
	{
		printf("회원정보가 잘못 입력되었습니다.\n\n");
	}
}