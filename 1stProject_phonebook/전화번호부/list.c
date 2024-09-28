#include "functions.h"

void list(PhoneBook* pb) {
    if (pb->n == 0) {
        char choice[BUFFER_SIZE];

        printf("��ȭ��ȣ�ΰ� ��� �ֽ��ϴ�.\n");
        printf("���ο� ��ȣ�� ����Ͻðڽ��ϱ�? (Y/N): ");
        scanf("%s", choice);
        while (getchar() != '\n');

        if (choice[0] == 'Y' || choice[0] == 'y') {
            insert(pb);
        }
        else {
            return;
        }
    }

    printf("��ȭ��ȣ�� ���:\n");
    for (int i = 0; i < pb->n; i++) {
        printf("%d. �̸�: %s, �й�: %s, ��ȭ��ȣ: %s\n",
            i + 1,
            pb->entries[i].name,
            pb->entries[i].studentNumber,
            pb->entries[i].num);
    }
}