#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40 // ��� ������ ȸ�� �� ����

struct Data {
	char ID[10]; // ȸ�� ���̵�
	char PW[15]; // ȸ�� ��й�ȣ
	int Height; // ȸ�� ����
	int Weight; // ȸ�� ü��
	int Gender; // ȸ�� ����
	int Member; // ȸ�� ��
} User;
struct Record { //����ü�� �������� ������ ���� ����¿��� ������ �߻��Ѵ�.
	int weight; // (��ȭ��)���� ü��
	int number; // �Է¹��� ���� ü�� Ƚ��
} Change;
struct Of {
	int times; // t�� ���� ����ü
}Number;

int i; // ȸ�� �� �ε���
int j; // �α��� �ε���
int t; // ���� ü�� Ƚ�� �ε���