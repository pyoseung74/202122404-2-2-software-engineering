#include "functions.h"

void list() {
    if (n == 0) {   // 등록된 인원이 없을 경우
        char choice[BUFFER_SIZE];  // 사용자 선택을 저장할 버퍼

        printf("전화번호부가 비어 있습니다.\n");
        printf("새로운 번호를 등록하시겠습니까? (Y/N): ");
        fgets(choice, BUFFER_SIZE, stdin);  // 사용자 입력 받기
        choice[strcspn(choice, "\n")] = '\0'; // 개행 문자 제거

        // 사용자 선택 확인
        if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
            insert();  // 번호 등록 함수 호출
        }
        else {
            return;  // 함수 종료하여 이전 메뉴로 돌아감
        }
    }

    // 등록된 인원이 있을 경우 전화번호부 출력
    printf("전화번호부 목록:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, name[i], num[i]);
    }
}
