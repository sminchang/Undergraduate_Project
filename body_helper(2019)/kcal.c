#include "total.h"

void m_kcal(struct Record Change[SIZE][SIZE], struct Data User[SIZE]) // ������ ��쿡 �ּ�, �ִ� ���뷮 ����
{
	float BMI = 0;
	float M = 0;

	M = (User[j].Height * 0.01) * (User[j].Height * 0.01);
	BMI = Change[j][t].weight / M;

	if (BMI >= 40.0)
	{
		printf("���� Ȥ�� ü�� ������ �߸� �ԷµǾ����ϴ�.\n\n");
	}
	else if (BMI <= 18.5)
	{
		printf("�ּҼ��뷮�� %.1fkcal�Դϴ�.\n", BMI * 48.5);
		printf("�ִ뼷�뷮�� %.1fkcal�Դϴ�.\n\n", BMI * 60.0);
	}
	else if (BMI > 18.5 && BMI <= 25.0)
	{
		printf("�ּҼ��뷮�� %.1fkcal�Դϴ�.\n", BMI * 42.0);
		printf("�ִ뼷�뷮�� %.1fkcal�Դϴ�.\n\n", BMI * 58.0);
	}
	else if (BMI > 25.0 && BMI <= 30.0)
	{
		printf("�ּҼ��뷮�� %.1fkcal�Դϴ�.\n", BMI * 40.0);
		printf("�ִ뼷�뷮�� %.1fkcal�Դϴ�.\n\n", BMI * 56.0);
	}
	else if (BMI > 30.0 && BMI <= 40.0)
	{
		printf("�ּҼ��뷮�� %.1fkcal�Դϴ�.\n", BMI * 41.0);
		printf("�ִ뼷�뷮�� %.1fkcal�Դϴ�.\n\n", BMI * 50.0);
	}
	else
	{
		printf("ȸ�������� �߸� �ԷµǾ����ϴ�.\n\n");
	}
}

void fm_kcal(struct Record Change[SIZE][SIZE], struct Data User[SIZE]) // ������ ��쿡 �ּ�, �ִ� ���뷮 ����
{
	float BMI = 0;
	float M = 0;

	M = (User[j].Height * 0.01) * (User[j].Height * 0.01);
	BMI = Change[j][t].weight / M;

	if (BMI >= 40.0)
	{
		printf("���� Ȥ�� ü�� ������ �߸� �ԷµǾ����ϴ�.\n\n");
	}
	else if (BMI <= 18.5)
	{
		printf("�ּҼ��뷮�� %.1fkcal�Դϴ�.\n", BMI * 45.0);
		printf("�ִ뼷�뷮�� %.1fkcal�Դϴ�.\n\n", BMI * 59.0);
	}
	else if (BMI > 18.5 && BMI <= 25.0)
	{
		printf("�ּҼ��뷮�� %.1fkcal�Դϴ�.\n", BMI * 41.0);
		printf("�ִ뼷�뷮�� %.1fkcal�Դϴ�.\n\n", BMI * 57.0);
	}
	else if (BMI > 25.0 && BMI <= 30.0)
	{
		printf("�ּҼ��뷮�� %.1fkcal�Դϴ�.\n", BMI * 38.0);
		printf("�ִ뼷�뷮�� %.1fkcal�Դϴ�.\n\n", BMI * 52.0);
	}
	else if (BMI > 30.0 && BMI < 40.0)
	{
		printf("�ּҼ��뷮�� %.1fkcal�Դϴ�.\n", BMI * 38.5);
		printf("�ִ뼷�뷮�� %.1fkcal�Դϴ�.\n\n", BMI * 50.0);
	}
	else
	{
		printf("ȸ�������� �߸� �ԷµǾ����ϴ�.\n\n");
	}
}