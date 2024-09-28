#include "functions.h"

void saveload(PhoneBook* pb, int mode) {
    if (mode == 0) {
        // 데이터 불러오기 모드
        FILE* fp = fopen(pb->frame, "r"); // 파일 읽기 모드로 열기
        if (fp == NULL) {
            // 파일이 없을 경우 처리
            char choice[BUFFER_SIZE];
            printf("파일을 열 수 없습니다: %s\n", pb->frame);
            printf("새로 만들겠습니까? (Y/N): ");
            scanf("%s", choice); // 사용자 입력 받기
            // 입력 버퍼 비우기
            while (getchar() != '\n');

            if (choice[0] == 'Y' || choice[0] == 'y') {
                fp = fopen(pb->frame, "w"); // 새로운 파일 생성
                fclose(fp);
                printf("새로운 전화번호부 파일이 생성되었습니다.\n");
                return;
            }
            else {
                printf("프로그램을 종료합니다.\n");
                exit(EXIT_FAILURE);
            }
        }

        char line[BUFFER_SIZE * 2]; // 한 줄을 저장할 버퍼
        while (fgets(line, sizeof(line), fp) != NULL) {
            line[strcspn(line, "\n")] = '\0'; // 개행 문자 제거

            // 쉼표로 이름과 번호 분리
            char* token = strtok(line, ",");
            if (token == NULL) continue;

            // 용량 부족 시 확장
            if (pb->n >= pb->capacity) {
                int new_capacity = (pb->capacity == 0) ? 1 : pb->capacity * 2;
                Entry* temp_entries = realloc(pb->entries, new_capacity * sizeof(Entry));
                if (temp_entries == NULL) {
                    fprintf(stderr, "메모리 재할당 실패\n");
                    break;
                }
                pb->entries = temp_entries;
                pb->capacity = new_capacity;
            }

            // 이름 저장
            strcpy(pb->entries[pb->n].name, token);

            // 번호 저장
            token = strtok(NULL, ",");
            if (token == NULL) {
                fprintf(stderr, "파일 형식이 올바르지 않습니다.\n");
                break;
            }
            strcpy(pb->entries[pb->n].num, token);

            pb->n++; // 등록된 인원 수 증가
        }

        fclose(fp); // 파일 닫기

    }
    else if (mode == 1) {
        // 데이터 저장 모드
        FILE* fp = fopen(pb->frame, "w"); // 파일 쓰기 모드로 열기
        if (fp == NULL) {
            fprintf(stderr, "파일을 열 수 없습니다: %s\n", pb->frame);
            return;
        }

        for (int i = 0; i < pb->n; i++) {
            fprintf(fp, "%s,%s\n", pb->entries[i].name, pb->entries[i].num); // 파일에 저장
        }

        fclose(fp); // 파일 닫기
    }
}
