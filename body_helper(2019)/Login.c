#include "total.h"

int Login(struct Data User[SIZE]) // 로그인
{
	char id[10];
	char pw[15];
	int k = 0; // 아이디 확인 반복
	int h = 0; // 비밀번호 확인 반복

	for (int k = 0; k < 5; k++)
	{
		printf("ID를 입력하세요:");
		scanf("%s", &id);

		for (j = 0; j < i + 1; j++)
		{
			if (!strcmp(id, User[j].ID))
			{
				for (int h = 0; h < 5; h++)
				{
					printf("Password를 입력하세요:");
					scanf("%s", &pw);
					if (!strcmp(pw, User[j].PW))
					{
						return 3;
					}
					else
					{
						system("cls");
						printf("Password를 잘못 입력하셨습니다.\n");
					}
				}
			}
		}
		if (k != 4)
		{
			system("cls");
			printf("ID를 잘못 입력하셨습니다.\n");
		}
	}
	return 0;
}