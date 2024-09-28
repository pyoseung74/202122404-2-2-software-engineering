#include "functions.h"

void delEntry(PhoneBook* pb) {
    char buf[BUFFER_SIZE]; // 삭제할 이름을 저장할 버퍼
    printf("삭제할 이름을 입력하세요: ");
    scanf(" %[^\n]", buf); // 이름 입력 받기
    // 입력 버퍼 비우기
    while (getchar() != '\n');

    int index = -1; // 삭제할 인덱스 초기화
    for (int i = 0; i < pb->n; i++) {
        if (strcmp(pb->entries[i].name, buf) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("해당 이름이 전화번호부에 없습니다.\n");
        return;
    }

    // 엔트리 삭제 (뒤의 요소들을 앞으로 이동)
    for (int i = index; i < pb->n - 1; i++) {
        pb->entries[i] = pb->entries[i + 1];
    }

    pb->n--; // 등록된 인원 수 감소

    printf("%s 이(가) 전화번호부에서 삭제되었습니다.\n", buf);

    saveload(pb, 1); // 데이터 저장
}
