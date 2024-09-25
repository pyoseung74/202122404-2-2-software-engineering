#include "functions.h"

// *****추가해야할 사항들 1. 02-, 033- 등 지역번호들은 예외처리로 넣어야 할 것인가 (처리완)
//                        2. 전화번호부 저장 파일이 없어졌을 경우에 대한 문제 (saveload.c 에 해결책 추가하기)    (완료?)
//                        3. saveload 완성하기 파일 저장 기능 + 불러오기기능 (기본적인기능) / (추가해볼기능) 파일 생성기능 (완료)
//                        4. saveload 만들때 mode 0은 불러오기 1은 저장모드로 (완료)
//                        5.





int n = 0;                  // 현재 등록된 인원 수
int capacity = 0;           // 배열의 현재 용량
char** name = NULL;         // 이름을 저장할 동적 배열
char** num = NULL;          // 번호를 저장할 동적 배열

const char* frame = "C:\\Users\\pyose\\source\\repos\\전화번호부\\Number.txt"; // 전화번호부 파일의 경로 (실행할 컴퓨터로 경로 수정가능 / \\ )

int main() {
    int usenum;                     // 작업 선택에 필요한 변수 선언하기
    char buffer[BUFFER_SIZE];       // 사용자 입력을 임시로 저장할 버퍼

    saveload(0); // 프로그램 시작 시 파일에서 데이터 불러오기 (mode 0)

    do {
        // 메뉴 출력하기
        printf("전화번호부\n");
        printf("1) 번호 등록\n2) 번호 수정\n3) 번호 삭제\n4) 번호 검색\n5) 전화번호부 출력\n6) 종료\n");
        printf("- 작업을 선택해주세요: ");

        // 사용자 입력 받기
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("입력 오류가 발생했습니다.\n");
            continue;
        }
        usenum = atoi(buffer); // 입력된 문자열을 정수로 변환하기

        switch (usenum) {
        case 1:
            insert();  // 번호 등록 함수 호출하기
            break;
        case 2:
            touch();   // 번호 수정 함수 호출하기
            break;
        case 3:
            delEntry();  // 번호 삭제 함수 호출하기
            break;
        case 4:
            search();  // 전화번호부 검색 함수 호출하기
            break;
        case 5:
            list();    // 전화번호부 출력 함수 호출하기
            break;
        case 6:
            printf("전화번호부를 종료합니다.\n");
            break; // 루프를 종료합니다.
        default:
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            break;
        }
    } while (usenum != 6);  // 입력받은 값이 6이 아닌 동안 반복하기

    reset(); // 프로그램 종료 시 동적 메모리 해제하기
    return 0;
}
