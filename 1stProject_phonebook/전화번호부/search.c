#include "functions.h"

void search() {
    char buf[BUFFER_SIZE];
    printf("�˻��� �̸��� �Է��ϼ���: ");
    fgets(buf, BUFFER_SIZE, stdin);
    buf[strcspn(buf, "\n")] = '\0'; // ���� ���� �����ϱ�

    int found = 0; // �˻� ��� ���θ� ������ ����
    for (int i = 0; i < n; i++) {
        if (strstr(name[i], buf) != NULL) {
            printf("%s - %s\n", name[i], num[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("�ش� �̸��� ���� ����� ��ȭ��ȣ�ο� �����ϴ�.\n");
    }
}
