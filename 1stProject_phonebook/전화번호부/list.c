#include "functions.h"

void list() {
    if (n == 0) {   // ��ϵ� �ο��� ���� ���
        char choice[BUFFER_SIZE];  // ����� ������ ������ ����

        printf("��ȭ��ȣ�ΰ� ��� �ֽ��ϴ�.\n");
        printf("���ο� ��ȣ�� ����Ͻðڽ��ϱ�? (Y/N): ");
        fgets(choice, BUFFER_SIZE, stdin);  // ����� �Է� �ޱ�
        choice[strcspn(choice, "\n")] = '\0'; // ���� ���� ����

        // ����� ���� Ȯ��
        if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
            insert();  // ��ȣ ��� �Լ� ȣ��
        }
        else {
            return;  // �Լ� �����Ͽ� ���� �޴��� ���ư�
        }
    }

    // ��ϵ� �ο��� ���� ��� ��ȭ��ȣ�� ���
    printf("��ȭ��ȣ�� ���:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, name[i], num[i]);
    }
}
