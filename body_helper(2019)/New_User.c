#include "total.h"

void New_User(FILE* fp, struct Data User[SIZE]) // ȸ������
{
	int k = 0;
	int h = 0;
	i++;
	fopen_s(&fp, "user_data.txt", "a");

	while (1)
	{
		printf("����Ͻ� ID�� �Է����ּ���.(10�� �̳�, ����):");
		scanf("%s", &User[i].ID);
		for (k = 0; k < i; k++) //���̵� �ߺ� üũ
		{
			if (strcmp(User[i].ID, User[k].ID) == 0)
			{
				system("cls");
				printf("�̹� �����ϴ� ���̵��Դϴ�. �ٽ� �Է����ּ���.\n");
				break;
			}
		}
		if (k == i) // for���� ������ �� ��� k���� i������ �����Ǵ� �Ϳ� ���� ����ó��
			k -= 1;
		if (strcmp(User[i].ID, User[k].ID) != 0)
			break;
	}
	fprintf(fp, "%s ", User[i].ID);

	printf("����Ͻ� Password�� �Է����ּ���. (15�� �̳�, ����) :");
	scanf("%s", &User[i].PW);
	fprintf(fp, "%s ", User[i].PW);

	printf("Ű�� �Է����ּ���. (cm) :");
	scanf("%d", &User[i].Height);
	fprintf(fp, "%d ", User[i].Height);

	printf("�����Ը� �Է����ּ���. (kg) :");
	scanf("%d", &User[i].Weight);
	fprintf(fp, "%d ", User[i].Weight);

	printf("������ �������ּ���. 1)���� 2)����");
	scanf("%d", &User[i].Gender);
	fprintf(fp, "%d ", User[i].Gender);


	User[i].Member = i;
	fprintf(fp, "%d\n", User[i].Member + 1); // �ε��� 0���� �����ϱ� ������ ȸ�� �� ����� ���ؼ��� +1.

	fclose(fp);
}
