#include "functions.h"

void list(PhoneBook* pb) {
    if (pb->n == 0) {
        char choice[BUFFER_SIZE]; // 사용자 선택을 저장할 버퍼

        printf("전화번호부가 비어 있습니다.\n");
        printf("새로운 번호를 등록하시겠습니까? (Y/N): ");
        scanf("%s", choice); // 사용자 입력 받기

        if (choice[0] == 'Y' || choice[0] == 'y') {
            insert(pb); // 번호 등록 함수 호출
        }
        else {
            return; // 함수 종료
        }
    }

    printf("전화번호부 목록:\n");
    for (int i = 0; i < pb->n; i++) {
        printf("%d. %s - %s\n", i + 1, pb->entries[i].name, pb->entries[i].num); // 엔트리 출력
    }
}
