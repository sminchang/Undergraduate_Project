#include "total.h"

void New_User(FILE* fp, struct Data User[SIZE]) // 회원가입
{
	int k = 0;
	int h = 0;
	i++;
	fopen_s(&fp, "user_data.txt", "a");

	while (1)
	{
		printf("사용하실 ID를 입력해주세요.(10자 이내, 영문):");
		scanf("%s", &User[i].ID);
		for (k = 0; k < i; k++) //아이디 중복 체크
		{
			if (strcmp(User[i].ID, User[k].ID) == 0)
			{
				system("cls");
				printf("이미 존재하는 아이디입니다. 다시 입력해주세요.\n");
				break;
			}
		}
		if (k == i) // for문이 끝까지 돌 경우 k값이 i값까지 증가되는 것에 대한 예외처리
			k -= 1;
		if (strcmp(User[i].ID, User[k].ID) != 0)
			break;
	}
	fprintf(fp, "%s ", User[i].ID);

	printf("사용하실 Password를 입력해주세요. (15자 이내, 영문) :");
	scanf("%s", &User[i].PW);
	fprintf(fp, "%s ", User[i].PW);

	printf("키를 입력해주세요. (cm) :");
	scanf("%d", &User[i].Height);
	fprintf(fp, "%d ", User[i].Height);

	printf("몸무게를 입력해주세요. (kg) :");
	scanf("%d", &User[i].Weight);
	fprintf(fp, "%d ", User[i].Weight);

	printf("성별을 선택해주세요. 1)남성 2)여성");
	scanf("%d", &User[i].Gender);
	fprintf(fp, "%d ", User[i].Gender);


	User[i].Member = i;
	fprintf(fp, "%d\n", User[i].Member + 1); // 인덱스 0부터 시작하기 때문에 회원 수 출력을 위해서는 +1.

	fclose(fp);
}
