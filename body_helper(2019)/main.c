#include "total.h"

extern void Import_Data(FILE* fp, FILE* fpp, struct Record Change[SIZE][SIZE], struct Data User[SIZE], struct Of Number[SIZE]); // �ؽ�Ʈ ���Ͽ��� ������ �ҷ�����
extern void New_User(FILE* fp, struct Data User[SIZE]); // ȸ������
extern int Login(struct Data User[SIZE]); // �α���
extern void Need_Weight(FILE* fpp, struct Record Change[SIZE][SIZE], struct Data User[SIZE]); // �ʿ��� ü������ ����
extern void m_kcal(struct Record Change[SIZE][SIZE], struct Data User[SIZE]); // ���� ���뷮 ����
extern void fm_kcal(struct Record Change[SIZE][SIZE], struct Data User[SIZE]); // ���� ���뷮 ����
extern void Weight_History(struct Record Change[SIZE][SIZE], struct Data User[SIZE]); // ü�� ��ȭ ��ǥ

int main(void)
{
	struct Data User[SIZE];
	struct Record Change[SIZE][SIZE] = { 0, };
	struct Of Number[SIZE][SIZE] = { 0, };
	FILE* fp = NULL;
	FILE* fpp = NULL;

	// ������ �������� ���� ��츦 ����� ����ó��
	fp = fopen("user_data.txt", "a");
	fclose(fp);
	fpp = fopen("Weight_data.txt", "a");
	fclose(fpp);

	Import_Data(fp, fpp, Change, User, Number); // ���� �ҷ�����

	int first_select = 0;
	int k = 0; // while �� Ż���� ���� ����
	int second_select = 0;
	int x = 0, y = 0; // �迭�� �ε����� ����� ����

	while (k != 3)
	{
		printf("�̿��Ͻ� ����� �������ּ���.\n");
		printf("------------------------------\n");
		printf("1)ȸ������ 2)�α���\n");
		scanf("%d", &first_select);
		switch (first_select)
		{
		case 1:
			New_User(fp, User); // ȸ������
			system("cls");
			printf("ȸ�������� �Ǽ̽��ϴ�.\n");
			break;
		case 2:
			if (Login(User) == 3)
			{
				if (Number[j][SIZE - 1].times != 0) // t�� ���� ���� ó��
					t = Number[j][SIZE - 1].times;
				system("cls");
				printf("�α��� �Ǽ̽��ϴ�.\n\n");
				while (1)
				{
					printf("�̿��Ͻ� ����� �������ּ���.\n");
					printf("------------------------------\n");
					printf("1)ü�� ��ȭ ��ǥ\n");
					printf("2)�ʿ��� ����, ���� ü�߰� �ʿ��� �ּ�, �ִ� ���뷮�� �����ص帳�ϴ�.\n");
					scanf("%d", &second_select);

					system("cls");
					switch (second_select)
					{
					case 1:
						Weight_History(Change, User); // ü�� ��ȭ ��ǥ
						break;
					case 2:
						Need_Weight(fpp, Change, User); // �ʿ��� ����, ���� ����
						if (User[j].Gender == 1)
							m_kcal(Change, User); // ������ ��쿡 �ּ�, �ִ� ���뷮 ����
						else if (User[j].Gender == 2)
							fm_kcal(Change, User); // ������ ��쿡 �ּ�, �ִ� ���뷮 ����

						t++;
						Number[j][SIZE - 1].times = t;
						fpp = fopen("weight_data.txt", "w"); // �ش� ȸ���� ������ �ش� �ε����� �����ؾ� �ϱ� ������ ���� ������ ���� ����.
						for (y = 0; y < SIZE; y++)
						{
							for (x = 0; x < SIZE - 2; x++)
								fprintf(fpp, "%d ", Change[y][x].weight);
							if (Number[y][SIZE - 1].times == Number[j][SIZE - 1].times)
								fprintf(fpp, "%d\n", Number[j][SIZE - 1].times);
							else
								fprintf(fpp, "%d\n", Number[y][SIZE - 1].times);
						}
						fclose(fpp);
						break;
					default:
						return 0;
						break;
					}
				}
			}
			else
				printf("�α��ο� �����ϼ̽��ϴ�.\n");
			break;
		default:
			k = 3;
			break;
		}
	}
	return 0;

}