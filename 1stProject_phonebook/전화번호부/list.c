#include "functions.h"

void list(PhoneBook* pb) {
    if (pb->n == 0) {
        char choice[BUFFER_SIZE];

        printf("전화번호부가 비어 있습니다.\n");
        printf("새로운 번호를 등록하시겠습니까? (Y/N): ");
        scanf("%s", choice);
        while (getchar() != '\n');

        if (choice[0] == 'Y' || choice[0] == 'y') {
            insert(pb);
        }
        else {
            return;
        }
    }

    printf("전화번호부 목록:\n");
    for (int i = 0; i < pb->n; i++) {
        printf("%d. 이름: %s, 학번: %s, 전화번호: %s\n",
            i + 1,
            pb->entries[i].name,
            pb->entries[i].studentNumber,
            pb->entries[i].num);
    }
}