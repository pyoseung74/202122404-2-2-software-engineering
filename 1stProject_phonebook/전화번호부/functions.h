#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS // 보안 경고 제거
#define BUFFER_SIZE 100  // 문자열 저장을 위한 버퍼 크기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 전화번호부 엔트리 구조체 정의
typedef struct {
    char name[BUFFER_SIZE];          // 이름 저장
    char studentNumber[BUFFER_SIZE]; // 학번 저장
    char num[BUFFER_SIZE];           // 전화번호 저장
} Entry;

// 전화번호부 구조체 정의
typedef struct {
    int n;                  // 현재 등록된 인원 수
    int capacity;           // 배열의 현재 용량
    Entry* entries;         // 엔트리 배열
    const char* frame;      // 파일 경로
} PhoneBook;

// 함수 원형 선언
void search(PhoneBook* pb);           // 전화번호부에서 이름 또는 번호 검색하기
void insert(PhoneBook* pb);           // 전화번호부에 신규 등록하기
void delEntry(PhoneBook* pb);         // 전화번호부에서 등록된 정보 삭제하기
void list(PhoneBook* pb);             // 전화번호부 전체 목록 출력하기
void touch(PhoneBook* pb);            // 전화번호 수정하기
void reset(PhoneBook* pb);            // 동적 메모리 해제하기
void saveload(PhoneBook* pb, int mode); // 전화번호부 파일 입출력 함수

// 전화번호 형식화 함수 원형 선언
void formatNum(const char* input, char* output);

#endif // FUNCTIONS_H
