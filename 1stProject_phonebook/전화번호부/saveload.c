#include "functions.h"

void saveload(int mode) {
    if (mode == 0) {
        // **전화번호부 불러오기 모드**
        FILE* fp = fopen(frame, "r"); // 파일을 읽기 모드로 열기
        if (fp == NULL) {   // 만약 파일이 없다면
            // 사용자에게 새 파일을 만들지 여부를 묻기
            char choice[BUFFER_SIZE];  // 사용자 선택을 저장할 버퍼
            printf("파일을 열 수 없습니다: %s\n", frame);
            printf("파일이 손상되었거나 삭제된 것 같습니다. 새로 만들겠습니까? (Y/N): ");    
            if (fgets(choice, BUFFER_SIZE, stdin) == NULL) {
                printf("입력 오류가 발생했습니다.\n");
                return;
            }
            choice[strcspn(choice, "\n")] = '\0'; // 개행 문자 제거하기

            if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
                fp = fopen(frame, "w"); // 새로운 파일 생성하기
                if (fp == NULL) {
                    fprintf(stderr, "파일을 생성할 수 없습니다: %s\n", frame);
                    return;
                }
                fclose(fp);
                printf("새로운 전화번호부 파일이 생성되었습니다.\n");
                // 파일이 생성되었으므로 추가 작업 없이 함수 종료 또는 main 메뉴로 돌아감
                return;
            }
            else {
                printf("전화번호부를 불러오지 못했습니다. 프로그램을 종료합니다.\n");
                exit(EXIT_FAILURE);
            }
        }


        // 받은 이름과 전화번호를 ',' 구분해서 txt 파일에 저장하기
        char line[BUFFER_SIZE * 2]; // 한 줄을 저장할 버퍼
        while (fgets(line, sizeof(line), fp) != NULL) {
            line[strcspn(line, "\n")] = '\0'; // 개행 문자 제거하기

            // 쉼표를 기준으로 이름과 번호 분리하기
            char* token = strtok(line, ",");    // 저장양식 = 홍길동,01012345678
            if (token == NULL) continue;

            // 배열의 용량이 부족하면 두 배로 늘리기
            if (n >= capacity) {
                int new_capacity = (capacity == 0) ? 1 : capacity * 2;
                char** temp_name = realloc(name, new_capacity * sizeof(char*)); // 배열
                char** temp_num = realloc(num, new_capacity * sizeof(char*));
                if (temp_name == NULL || temp_num == NULL) {
                    fprintf(stderr, "메모리 재할당 실패\n");
                    break;
                }
                name = temp_name;
                num = temp_num;
                capacity = new_capacity;
            }

            // 이름 저장하기
            name[n] = strdup(token);
            if (name[n] == NULL) {
                fprintf(stderr, "메모리 할당 실패: 이름을 저장할 수 없습니다.\n");
                break;
            }

            // 번호 저장하기
            token = strtok(NULL, ","); // ',' 자를 기준으로 문자열 구분하여 저장
            if (token == NULL) {
                fprintf(stderr, "파일 형식이 올바르지 않습니다.\n");
                free(name[n]);
                break;
            }
            num[n] = strdup(token);
            if (num[n] == NULL) {
                fprintf(stderr, "메모리 할당 실패: 번호를 저장할 수 없습니다.\n");
                free(name[n]);
                break;
            }

            n++; // 등록된 인원 수 증가하기
        }

        fclose(fp); // 파일 닫기

    }
    else if (mode == 1) {
        // **전화번호부 저장하기 모드**
        FILE* fp = fopen(frame, "w"); // 파일을 쓰기 모드로 열기
        if (fp == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다: %s\n", frame);
            return;
        }

        // 현재 메모리에 저장된 모든 전화번호부를 파일에 저장하기
        for (int i = 0; i < n; i++) {
            fprintf(fp, "%s,%s\n", name[i], num[i]); // 이름과 번호를 쉼표로 구분하여 저장하기
        }

        fclose(fp); // 파일 닫기
    }
}
