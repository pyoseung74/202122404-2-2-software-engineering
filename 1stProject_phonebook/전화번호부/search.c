#include "functions.h"

void search() {
    char buf[BUFFER_SIZE];
    printf("검색할 이름을 입력하세요: ");
    fgets(buf, BUFFER_SIZE, stdin);
    buf[strcspn(buf, "\n")] = '\0'; // 개행 문자 제거하기

    int found = 0; // 검색 결과 여부를 저장할 변수
    for (int i = 0; i < n; i++) {
        if (strstr(name[i], buf) != NULL) {
            printf("%s - %s\n", name[i], num[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("해당 이름을 가진 사람이 전화번호부에 없습니다.\n");
    }
}
