#include "total.h"

int Login(struct Data User[SIZE]) // �α���
{
	char id[10];
	char pw[15];
	int k = 0; // ���̵� Ȯ�� �ݺ�
	int h = 0; // ��й�ȣ Ȯ�� �ݺ�

	for (int k = 0; k < 5; k++)
	{
		printf("ID�� �Է��ϼ���:");
		scanf("%s", &id);

		for (j = 0; j < i + 1; j++)
		{
			if (!strcmp(id, User[j].ID))
			{
				for (int h = 0; h < 5; h++)
				{
					printf("Password�� �Է��ϼ���:");
					scanf("%s", &pw);
					if (!strcmp(pw, User[j].PW))
					{
						return 3;
					}
					else
					{
						system("cls");
						printf("Password�� �߸� �Է��ϼ̽��ϴ�.\n");
					}
				}
			}
		}
		if (k != 4)
		{
			system("cls");
			printf("ID�� �߸� �Է��ϼ̽��ϴ�.\n");
		}
	}
	return 0;
}