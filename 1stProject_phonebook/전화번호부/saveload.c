#include "functions.h"

void saveload(int mode) {
    if (mode == 0) {
        // **��ȭ��ȣ�� �ҷ����� ���**
        FILE* fp = fopen(frame, "r"); // ������ �б� ���� ����
        if (fp == NULL) {   // ���� ������ ���ٸ�
            // ����ڿ��� �� ������ ������ ���θ� ����
            char choice[BUFFER_SIZE];  // ����� ������ ������ ����
            printf("������ �� �� �����ϴ�: %s\n", frame);
            printf("������ �ջ�Ǿ��ų� ������ �� �����ϴ�. ���� ����ڽ��ϱ�? (Y/N): ");    
            if (fgets(choice, BUFFER_SIZE, stdin) == NULL) {
                printf("�Է� ������ �߻��߽��ϴ�.\n");
                return;
            }
            choice[strcspn(choice, "\n")] = '\0'; // ���� ���� �����ϱ�

            if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
                fp = fopen(frame, "w"); // ���ο� ���� �����ϱ�
                if (fp == NULL) {
                    fprintf(stderr, "������ ������ �� �����ϴ�: %s\n", frame);
                    return;
                }
                fclose(fp);
                printf("���ο� ��ȭ��ȣ�� ������ �����Ǿ����ϴ�.\n");
                // ������ �����Ǿ����Ƿ� �߰� �۾� ���� �Լ� ���� �Ǵ� main �޴��� ���ư�
                return;
            }
            else {
                printf("��ȭ��ȣ�θ� �ҷ����� ���߽��ϴ�. ���α׷��� �����մϴ�.\n");
                exit(EXIT_FAILURE);
            }
        }


        // ���� �̸��� ��ȭ��ȣ�� ',' �����ؼ� txt ���Ͽ� �����ϱ�
        char line[BUFFER_SIZE * 2]; // �� ���� ������ ����
        while (fgets(line, sizeof(line), fp) != NULL) {
            line[strcspn(line, "\n")] = '\0'; // ���� ���� �����ϱ�

            // ��ǥ�� �������� �̸��� ��ȣ �и��ϱ�
            char* token = strtok(line, ",");    // ������ = ȫ�浿,01012345678
            if (token == NULL) continue;

            // �迭�� �뷮�� �����ϸ� �� ��� �ø���
            if (n >= capacity) {
                int new_capacity = (capacity == 0) ? 1 : capacity * 2;
                char** temp_name = realloc(name, new_capacity * sizeof(char*)); // �迭
                char** temp_num = realloc(num, new_capacity * sizeof(char*));
                if (temp_name == NULL || temp_num == NULL) {
                    fprintf(stderr, "�޸� ���Ҵ� ����\n");
                    break;
                }
                name = temp_name;
                num = temp_num;
                capacity = new_capacity;
            }

            // �̸� �����ϱ�
            name[n] = strdup(token);
            if (name[n] == NULL) {
                fprintf(stderr, "�޸� �Ҵ� ����: �̸��� ������ �� �����ϴ�.\n");
                break;
            }

            // ��ȣ �����ϱ�
            token = strtok(NULL, ","); // ',' �ڸ� �������� ���ڿ� �����Ͽ� ����
            if (token == NULL) {
                fprintf(stderr, "���� ������ �ùٸ��� �ʽ��ϴ�.\n");
                free(name[n]);
                break;
            }
            num[n] = strdup(token);
            if (num[n] == NULL) {
                fprintf(stderr, "�޸� �Ҵ� ����: ��ȣ�� ������ �� �����ϴ�.\n");
                free(name[n]);
                break;
            }

            n++; // ��ϵ� �ο� �� �����ϱ�
        }

        fclose(fp); // ���� �ݱ�

    }
    else if (mode == 1) {
        // **��ȭ��ȣ�� �����ϱ� ���**
        FILE* fp = fopen(frame, "w"); // ������ ���� ���� ����
        if (fp == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�: %s\n", frame);
            return;
        }

        // ���� �޸𸮿� ����� ��� ��ȭ��ȣ�θ� ���Ͽ� �����ϱ�
        for (int i = 0; i < n; i++) {
            fprintf(fp, "%s,%s\n", name[i], num[i]); // �̸��� ��ȣ�� ��ǥ�� �����Ͽ� �����ϱ�
        }

        fclose(fp); // ���� �ݱ�
    }
}
