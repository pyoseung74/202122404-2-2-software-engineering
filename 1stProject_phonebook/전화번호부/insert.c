#include "functions.h"

void insert() {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE]; // 이름과 전화번호를 입력받을 임시공간 선언하기

    // 배열의 용량이 부족하면 두 배로 늘리기
    if (n >= capacity) {
        int new_capacity = (capacity == 0) ? 1 : capacity * 2;

        // 이름 배열의 크기 조정하기
        char** temp_name = realloc(name, new_capacity * sizeof(char*)); 
        if (temp_name == NULL) {    // 메모리가 부족하거나 할당 불가능한 크기의 메모리를 사용했을경우 진행됨
            fprintf(stderr, "메모리 재할당 실패: 이름 배열을 확장할 수 없습니다.\n");
            return;
        }
        name = temp_name;

        // 번호 배열의 크기 조정하기
        char** temp_num = realloc(num, new_capacity * sizeof(char*));
        if (temp_num == NULL) {     // 메모리가 부족하거나 할당 불가능한 크기의 메모리를 사용했을경우 진행됨
            fprintf(stderr, "메모리 재할당 실패: 번호 배열을 확장할 수 없습니다.\n");
            return;
        }
        num = temp_num;

        capacity = new_capacity; // 새로운 용량으로 업데이트하기
    }

    // 이름 입력받기
    printf("이름을 입력하세요: ");
    fgets(buf1, BUFFER_SIZE, stdin);
    buf1[strcspn(buf1, "\n")] = '\0'; // 개행 문자 제거하기

    if (strlen(buf1) == 0) {    // 입력을 받지 못했을 경우 (문자열 길이가 0 일때)
        printf("이름을 입력해주세요.\n");
        return;
    }

    // 전화번호 입력받기
    printf("전화번호를 입력하세요: ");
    fgets(buf2, BUFFER_SIZE, stdin);
    buf2[strcspn(buf2, "\n")] = '\0'; // 개행 문자 제거하기

    if (strlen(buf2) == 0) {    // 입력을 받지 못했을 경우 (문자열 길이가 0 일때)
        printf("전화번호를 입력해주세요.\n");
        return;
    }

    // 이름 저장하기
    name[n] = strdup(buf1); // 복사된 이름에 메모리를 추가적으로 할당해줌 (추후 메모리 누수 방지를 위해 free 사용해야함)
    if (name[n] == NULL) {  // 메모리가 부족하거나 할당 불가능한 크기의 메모리를 사용했을경우 진행됨
        fprintf(stderr, "메모리 할당 실패: 이름을 저장할 수 없습니다.\n");
        return;
    }

    // 번호 저장하기
    num[n] = strdup(buf2);  // 추후 메모리 누수 방지를 위해 free 사용해야함
    if (num[n] == NULL) {  // 메모리가 부족하거나 할당 불가능한 크기의 메모리를 사용했을경우 진행됨
        fprintf(stderr, "메모리 할당 실패: 번호를 저장할 수 없습니다.\n");
        free(name[n]); // 이미 할당된 name[n] 메모리 해제하기
        return;
    }

    n++; // 등록된 인원 수 증가하기

    printf("%s 이(가) 전화번호부에 저장되었습니다.\n", buf1);

    saveload(1); // 변경된 내용을 파일에 저장하기 (mode 1)
}
