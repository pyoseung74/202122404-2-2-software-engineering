#include "functions.h"

int main() {
    int usenum;                  // 작업 선택에 필요한 변수

    // 전화번호부 초기화
    PhoneBook* pb = (PhoneBook*)malloc(sizeof(PhoneBook));
    if (pb == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1;
    }
    pb->n = 0;                     // 현재 등록된 인원 수 초기화
    pb->capacity = 0;              // 용량 초기화
    pb->entries = NULL;            // 엔트리 배열 초기화
    pb->frame = "Number.txt";      // 파일 경로 설정

    saveload(pb, 0); // 데이터 불러오기

    do {
        // 메뉴 출력
        printf("전화번호부\n");
        printf("1) 번호 등록\n2) 번호 수정\n3) 번호 삭제\n4) 번호 검색\n5) 전화번호부 출력\n6) 종료\n");
        printf("- 작업을 선택해주세요: ");

        // 사용자 입력 받기
        if (scanf("%d", &usenum) != 1) {
            printf("입력 오류가 발생했습니다.\n");
            // 입력 버퍼 비우기
            while (getchar() != '\n');
            continue;
        }
        // 입력 버퍼 비우기
        while (getchar() != '\n');

        switch (usenum) {
        case 1:
            insert(pb);  // 번호 등록 함수 호출
            break;
        case 2:
            touch(pb);   // 번호 수정 함수 호출
            break;
        case 3:
            delEntry(pb); // 번호 삭제 함수 호출
            break;
        case 4:
            search(pb);  // 전화번호부 검색 함수 호출
            break;
        case 5:
            list(pb);    // 전화번호부 출력 함수 호출
            break;
        case 6:
            printf("전화번호부를 종료합니다.\n");
            break;        // 루프 종료
        default:
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            break;
        }
    } while (usenum != 6);

    reset(pb); // 메모리 해제
    free(pb);  // PhoneBook 구조체 자체 메모리 해제
    return 0;
}
