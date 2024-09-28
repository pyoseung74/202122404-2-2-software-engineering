#include "functions.h"

void delEntry(PhoneBook* pb) {
    char buf[BUFFER_SIZE];
    printf("삭제할 이름을 입력하세요: ");
    fgets(buf, BUFFER_SIZE, stdin);
    buf[strcspn(buf, "\n")] = '\0';

    int index = -1;
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

    pb->n--; // 인원 수 감소

    printf("%s 이(가) 전화번호부에서 삭제되었습니다.\n", buf);

    saveload(pb, 1); // 데이터 저장
}
