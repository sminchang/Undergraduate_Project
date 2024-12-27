#include "total.h"

extern void Import_Data(FILE* fp, FILE* fpp, struct Record Change[SIZE][SIZE], struct Data User[SIZE], struct Of Number[SIZE]); // 텍스트 파일에서 데이터 불러오기
extern void New_User(FILE* fp, struct Data User[SIZE]); // 회원가입
extern int Login(struct Data User[SIZE]); // 로그인
extern void Need_Weight(FILE* fpp, struct Record Change[SIZE][SIZE], struct Data User[SIZE]); // 필요한 체중정보 산출
extern void m_kcal(struct Record Change[SIZE][SIZE], struct Data User[SIZE]); // 남성 섭취량 산출
extern void fm_kcal(struct Record Change[SIZE][SIZE], struct Data User[SIZE]); // 여성 섭취량 산출
extern void Weight_History(struct Record Change[SIZE][SIZE], struct Data User[SIZE]); // 체중 변화 지표

int main(void)
{
	struct Data User[SIZE];
	struct Record Change[SIZE][SIZE] = { 0, };
	struct Of Number[SIZE][SIZE] = { 0, };
	FILE* fp = NULL;
	FILE* fpp = NULL;

	// 파일이 존재하지 않을 경우를 대비한 예외처리
	fp = fopen("user_data.txt", "a");
	fclose(fp);
	fpp = fopen("Weight_data.txt", "a");
	fclose(fpp);

	Import_Data(fp, fpp, Change, User, Number); // 파일 불러오기

	int first_select = 0;
	int k = 0; // while 문 탈출을 위한 변수
	int second_select = 0;
	int x = 0, y = 0; // 배열의 인덱스에 사용할 변수

	while (k != 3)
	{
		printf("이용하실 기능을 선택해주세요.\n");
		printf("------------------------------\n");
		printf("1)회원가입 2)로그인\n");
		scanf("%d", &first_select);
		switch (first_select)
		{
		case 1:
			New_User(fp, User); // 회원가입
			system("cls");
			printf("회원가입이 되셨습니다.\n");
			break;
		case 2:
			if (Login(User) == 3)
			{
				if (Number[j][SIZE - 1].times != 0) // t에 대한 예외 처리
					t = Number[j][SIZE - 1].times;
				system("cls");
				printf("로그인 되셨습니다.\n\n");
				while (1)
				{
					printf("이용하실 기능을 선택해주세요.\n");
					printf("------------------------------\n");
					printf("1)체중 변화 지표\n");
					printf("2)필요한 증량, 감량 체중과 필요한 최소, 최대 섭취량을 산출해드립니다.\n");
					scanf("%d", &second_select);

					system("cls");
					switch (second_select)
					{
					case 1:
						Weight_History(Change, User); // 체중 변화 지표
						break;
					case 2:
						Need_Weight(fpp, Change, User); // 필요한 증량, 감량 산출
						if (User[j].Gender == 1)
							m_kcal(Change, User); // 남성일 경우에 최소, 최대 섭취량 산출
						else if (User[j].Gender == 2)
							fm_kcal(Change, User); // 여성일 경우에 최소, 최대 섭취량 산출

						t++;
						Number[j][SIZE - 1].times = t;
						fpp = fopen("weight_data.txt", "w"); // 해당 회원의 정보를 해당 인덱스에 저장해야 하기 때문에 파일 내용을 새로 쓴다.
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
				printf("로그인에 실패하셨습니다.\n");
			break;
		default:
			k = 3;
			break;
		}
	}
	return 0;

}