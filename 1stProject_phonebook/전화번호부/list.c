#include "functions.h"

void list(PhoneBook* pb) {
    if (pb->n == 0) {
        char choice[BUFFER_SIZE]; // ����� ������ ������ ����

        printf("��ȭ��ȣ�ΰ� ��� �ֽ��ϴ�.\n");
        printf("���ο� ��ȣ�� ����Ͻðڽ��ϱ�? (Y/N): ");
        scanf("%s", choice); // ����� �Է� �ޱ�

        if (choice[0] == 'Y' || choice[0] == 'y') {
            insert(pb); // ��ȣ ��� �Լ� ȣ��
        }
        else {
            return; // �Լ� ����
        }
    }

    printf("��ȭ��ȣ�� ���:\n");
    for (int i = 0; i < pb->n; i++) {
        printf("%d. %s - %s\n", i + 1, pb->entries[i].name, pb->entries[i].num); // ��Ʈ�� ���
    }
}
