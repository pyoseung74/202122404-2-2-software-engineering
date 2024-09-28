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
    scanf(" %[^\n]", buf1); // 공백 포함하여 입력 받기
    // 입력 버퍼 비우기
    while (getchar() != '\n');

    if (strlen(buf1) >= BUFFER_SIZE) {
        printf("이름이 너무 깁니다.\n");
        return;
    }

    // 번호 입력
    printf("전화번호를 입력하세요 (숫자만 입력하거나 '-'를 포함할 수 있습니다): ");
    scanf("%s", buf2); // 전화번호 입력 받기
    // 입력 버퍼 비우기
    while (getchar() != '\n');

    if (strlen(buf2) >= BUFFER_SIZE) {
        printf("전화번호가 너무 깁니다.\n");
        return;
    }

    // 전화번호 형식화
    formatNum(buf2, formattedNum);

    // 데이터 저장
    strcpy(pb->entries[pb->n].name, buf1);
    strcpy(pb->entries[pb->n].num, formattedNum);

    pb->n++; // 등록된 인원 수 증가

    printf("%s 이(가) 전화번호부에 저장되었습니다.\n", buf1);

    saveload(pb, 1); // 데이터 저장
}
