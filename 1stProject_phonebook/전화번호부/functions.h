#define strdup _strdup		// visualstudio에서 strdup이 _strdup으로 사용되므로 호환을 위해 사용함
#define _CRT_SECURE_NO_WARNINGS // 경고 제거
#define BUFFER_SIZE 100  // 이름 혹은 전화번호를 임시 저장할 공간 만들기

#include <stdio.h>  // 표준 입출력 함수 사용을 위한 헤더 파일
#include <stdlib.h> // 동적 메모리 할당을 위한 헤더 파일
#include <string.h> // 문자열 처리 함수 사용을 위한 헤더 파일

// 전역 변수 선언
extern int n;                // 현재 등록된 인원 수
extern int capacity;         // 배열의 현재 용량 (추후 realloc 을 사용하여 공간 확장하기) 
extern char** name;          // 이름을 저장할 동적 배열
extern char** num;           // 번호를 저장할 동적 배열
extern const char* frame;    // 전화번호부 파일의 경로

// 함수 원형 선언
void search();               // 전화번호부에서 이름 검색하기
void insert();               // 전화번호부에 신규 등록하기
void delEntry();             // 전화번호부에서 등록된 정보 삭제하기
void list();                 // 전화번호부 전체 목록 출력하기
void touch();                // 전화번호 수정하기
void reset();                // 동적 메모리 해제하기
void saveload(int mode);       // 전화번호부 txt파일에 저장&불러오기 함수 (mode: 0-불러오기, 1-저장하기)
