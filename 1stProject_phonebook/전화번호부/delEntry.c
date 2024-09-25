#include "functions.h"

void delEntry() {
    char buf[BUFFER_SIZE];
    printf("삭제할 이름을 입력하세요: ");
    fgets(buf, BUFFER_SIZE, stdin);
    buf[strcspn(buf, "\n")] = '\0'; // 개행 문자 제거하기

    int index = -1; // 삭제할 항목의 인덱스를 저장할 변수
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

    // 메모리 해제하기
    free(name[index]);
    free(num[index]);

    // 배열의 뒤쪽 요소들을 앞으로 이동시키기
    for (int i = index; i < n - 1; i++) {
        name[i] = name[i + 1];
        num[i] = num[i + 1];
    }

    n--; // 등록된 인원 수 감소하기

    printf("%s 이(가) 전화번호부에서 삭제되었습니다.\n", buf);

    saveload(1); // 변경된 내용을 파일에 저장하기 (mode 1)
}
