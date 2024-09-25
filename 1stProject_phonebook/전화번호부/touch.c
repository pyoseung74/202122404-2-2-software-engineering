#include "functions.h"

void touch() {
    char buf[BUFFER_SIZE];  // 수정된 정보를 임시저장할 공간
    printf("수정할 이름을 입력하세요: ");
    fgets(buf, BUFFER_SIZE, stdin);
    buf[strcspn(buf, "\n")] = '\0'; // 개행 문자 제거하기

    int index = -1; // 수정할 항목의 인덱스를 저장할 변수
    for (int i = 0; i < n; i++) {   
        if (strcmp(name[i], buf) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("해당 이름이 전화번호부에 없습니다.\n");
        return;
    }

    printf("새로운 전화번호를 입력하세요: ");
    fgets(buf, BUFFER_SIZE, stdin);
    buf[strcspn(buf, "\n")] = '\0'; // 개행 문자 제거하기

    if (strlen(buf) == 0) {
        printf("전화번호를 입력해주세요.\n");
        return;
    }

    // 기존 번호 메모리 해제하기
    free(num[index]);

    // 새로운 번호 저장하기
    num[index] = strdup(buf);
    if (num[index] == NULL) {    // 메모리가 부족하거나 할당 불가능 크기의 메모리를 사용했을경우 진행됨
        fprintf(stderr, "메모리 할당 실패: 번호를 저장할 수 없습니다.\n");
        return;
    }

    printf("전화번호가 수정되었습니다.\n");

    saveload(1); // 변경된 내용을 파일에 저장하기 (mode 1)
}
