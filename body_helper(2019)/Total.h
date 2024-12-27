#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40 // 등록 가능한 회원 수 지정

struct Data {
	char ID[10]; // 회원 아이디
	char PW[15]; // 회원 비밀번호
	int Height; // 회원 신장
	int Weight; // 회원 체중
	int Gender; // 회원 성별
	int Member; // 회원 수
} User;
struct Record { //구조체로 저장하지 않으면 파일 입출력에서 오류가 발생한다.
	int weight; // (변화된)현재 체중
	int number; // 입력받은 현재 체중 횟수
} Change;
struct Of {
	int times; // t를 담을 구조체
}Number;

int i; // 회원 수 인덱스
int j; // 로그인 인덱스
int t; // 현재 체중 횟수 인덱스