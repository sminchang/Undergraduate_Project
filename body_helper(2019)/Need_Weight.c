#include "total.h"

void Need_Weight(FILE* fpp, struct Record Change[SIZE][SIZE], struct Data User[SIZE]) // �ʿ��� ����, ���� ����
{
	float BMI = 0;
	float mini_nomal = 0;
	float max_nomal = 0;
	float gap = 0;
	float M = 0;

	printf("������ ü���� �Է��ϼ���:");
	scanf("%d", &Change[j][t].weight);

	M = (User[j].Height * 0.01) * (User[j].Height * 0.01); // cm�� m�� ȯ��, ������ �����ϴ� ��
	BMI = Change[j][t].weight / M;
	printf("BMI ����: %.1f\n\n", BMI); // BMI ���

	mini_nomal = M * 20; // ȸ���� �ּ� ���� ü�� ��
	max_nomal = M * 24; // ȸ���� �ִ� ���� ü�� ��

	if (BMI < 20.0)
	{
		printf("��ü��(underweight)�Դϴ�.\n");
		printf("����ü�߱��� ������ �ʿ��մϴ�.");
		gap = mini_nomal - Change[j][t].weight;
		printf("���� ü���� ���Ͽ� %.1fkg ������ �ʿ��մϴ�.\n\n", gap);


	}
	else if (BMI >= 20.0 && BMI <= 24.0)
	{
		printf("����(normal)�Դϴ�.\n");
		printf("��Ȯ�� ������ ���ϽŴٸ�, �ιٵ� ������ ��õ�帳�ϴ�.\n\n");
	}
	else if (BMI >= 23.0 && BMI <= 24.9)
	{
		printf("��ü��(overweight)�Դϴ�.\n");
		printf("����ü�߱��� ������ �ʿ��մϴ�.");
		gap = Change[j][t].weight - max_nomal;
		printf("���� ü���� ���Ͽ� %.1fkg ������ �ʿ��մϴ�.\n\n", gap);
	}
	else
	{
		printf("��(obese)�Դϴ�.\n");
		printf("ü�߰����� �ʿ��մϴ�.");
		gap = Change[j][t].weight - max_nomal;
		printf("���� ü���� ���Ͽ� %.1fkg ������ �ʿ��մϴ�.\n\n", gap);
	}
}

