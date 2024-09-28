#include "functions.h"

void saveload(PhoneBook* pb, int mode) {
    if (mode == 0) {
        // ������ �ҷ����� ���
        FILE* fp = fopen(pb->frame, "r"); // ���� �б� ���� ����
        if (fp == NULL) {
            // ������ ���� ��� ó��
            char choice[BUFFER_SIZE];
            printf("������ �� �� �����ϴ�: %s\n", pb->frame);
            printf("���� ����ڽ��ϱ�? (Y/N): ");
            scanf("%s", choice); // ����� �Է� �ޱ�
            // �Է� ���� ����
            while (getchar() != '\n');

            if (choice[0] == 'Y' || choice[0] == 'y') {
                fp = fopen(pb->frame, "w"); // ���ο� ���� ����
                fclose(fp);
                printf("���ο� ��ȭ��ȣ�� ������ �����Ǿ����ϴ�.\n");
                return;
            }
            else {
                printf("���α׷��� �����մϴ�.\n");
                exit(EXIT_FAILURE);
            }
        }

        char line[BUFFER_SIZE * 2]; // �� ���� ������ ����
        while (fgets(line, sizeof(line), fp) != NULL) {
            line[strcspn(line, "\n")] = '\0'; // ���� ���� ����

            // ��ǥ�� �̸��� ��ȣ �и�
            char* token = strtok(line, ",");
            if (token == NULL) continue;

            // �뷮 ���� �� Ȯ��
            if (pb->n >= pb->capacity) {
                int new_capacity = (pb->capacity == 0) ? 1 : pb->capacity * 2;
                Entry* temp_entries = realloc(pb->entries, new_capacity * sizeof(Entry));
                if (temp_entries == NULL) {
                    fprintf(stderr, "�޸� ���Ҵ� ����\n");
                    break;
                }
                pb->entries = temp_entries;
                pb->capacity = new_capacity;
            }

            // �̸� ����
            strcpy(pb->entries[pb->n].name, token);

            // ��ȣ ����
            token = strtok(NULL, ",");
            if (token == NULL) {
                fprintf(stderr, "���� ������ �ùٸ��� �ʽ��ϴ�.\n");
                break;
            }
            strcpy(pb->entries[pb->n].num, token);

            pb->n++; // ��ϵ� �ο� �� ����
        }

        fclose(fp); // ���� �ݱ�

    }
    else if (mode == 1) {
        // ������ ���� ���
        FILE* fp = fopen(pb->frame, "w"); // ���� ���� ���� ����
        if (fp == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�: %s\n", pb->frame);
            return;
        }

        for (int i = 0; i < pb->n; i++) {
            fprintf(fp, "%s,%s\n", pb->entries[i].name, pb->entries[i].num); // ���Ͽ� ����
        }

        fclose(fp); // ���� �ݱ�
    }
}
