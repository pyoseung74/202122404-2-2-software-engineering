#include "functions.h"

void insert(PhoneBook* pb) {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE]; // 이름과 전화번호를 저장할 버퍼
    char formattedNum[BUFFER_SIZE];            // 형식화된 전화번호를 저장할 버퍼

    // 용량 부족 시 확장
    if (pb->n >= pb->capacity) {
        int new_capacity = (pb->capacity == 0) ? 1 : pb->capacity * 2;
        Entry* temp_entries = realloc(pb->entries, new_capacity * sizeof(Entry));
        if (temp_entries == NULL) {
            fprintf(stderr, "메모리 재할당 실패\n");
            return;
        }
        pb->entries = temp_entries;
        pb->capacity = new_capacity;
    }

    // 이름 입력
    printf("이름을 입력하세요: ");
    scanf("%s", buf1); // 이름 입력 받기

    // 번호 입력
    printf("전화번호를 입력하세요 (숫자만 입력하거나 '-'를 포함할 수 있습니다): ");
    scanf("%s", buf2); // 전화번호 입력 받기

    // 전화번호 형식화
    formatPhoneNumber(buf2, formattedNum);

    // 데이터 저장
    strncpy(pb->entries[pb->n].name, buf1, BUFFER_SIZE - 1);
    pb->entries[pb->n].name[BUFFER_SIZE - 1] = '\0';

    strncpy(pb->entries[pb->n].num, formattedNum, BUFFER_SIZE - 1);
    pb->entries[pb->n].num[BUFFER_SIZE - 1] = '\0';

    pb->n++; // 인원 수 증가

    printf("%s 이(가) 전화번호부에 저장되었습니다.\n", buf1);

    saveload(pb, 1); // 데이터 저장
}
