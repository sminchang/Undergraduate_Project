#include "total.h"

void Need_Weight(FILE* fpp, struct Record Change[SIZE][SIZE], struct Data User[SIZE]) // 필요한 증량, 감량 산출
{
	float BMI = 0;
	float mini_nomal = 0;
	float max_nomal = 0;
	float gap = 0;
	float M = 0;

	printf("현재의 체중을 입력하세요:");
	scanf("%d", &Change[j][t].weight);

	M = (User[j].Height * 0.01) * (User[j].Height * 0.01); // cm를 m로 환산, 신장을 제곱하는 식
	BMI = Change[j][t].weight / M;
	printf("BMI 지수: %.1f\n\n", BMI); // BMI 계산

	mini_nomal = M * 20; // 회원의 최소 정상 체중 값
	max_nomal = M * 24; // 회원의 최대 정상 체중 값

	if (BMI < 20.0)
	{
		printf("저체중(underweight)입니다.\n");
		printf("정상체중까지 증량이 필요합니다.");
		gap = mini_nomal - Change[j][t].weight;
		printf("정상 체중을 위하여 %.1fkg 증량이 필요합니다.\n\n", gap);


	}
	else if (BMI >= 20.0 && BMI <= 24.0)
	{
		printf("정상(normal)입니다.\n");
		printf("정확한 측정을 원하신다면, 인바디 측정을 추천드립니다.\n\n");
	}
	else if (BMI >= 23.0 && BMI <= 24.9)
	{
		printf("과체중(overweight)입니다.\n");
		printf("정상체중까지 감량이 필요합니다.");
		gap = Change[j][t].weight - max_nomal;
		printf("정상 체중을 위하여 %.1fkg 감량이 필요합니다.\n\n", gap);
	}
	else
	{
		printf("비만(obese)입니다.\n");
		printf("체중관리가 필요합니다.");
		gap = Change[j][t].weight - max_nomal;
		printf("정상 체중을 위하여 %.1fkg 감량이 필요합니다.\n\n", gap);
	}
}

