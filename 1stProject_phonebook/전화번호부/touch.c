#include "functions.h"

void touch() {
    char buf[BUFFER_SIZE];  // ������ ������ �ӽ������� ����
    printf("������ �̸��� �Է��ϼ���: ");
    fgets(buf, BUFFER_SIZE, stdin);
    buf[strcspn(buf, "\n")] = '\0'; // ���� ���� �����ϱ�

    int index = -1; // ������ �׸��� �ε����� ������ ����
    for (int i = 0; i < n; i++) {   
        if (strcmp(name[i], buf) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("�ش� �̸��� ��ȭ��ȣ�ο� �����ϴ�.\n");
        return;
    }

    printf("���ο� ��ȭ��ȣ�� �Է��ϼ���: ");
    fgets(buf, BUFFER_SIZE, stdin);
    buf[strcspn(buf, "\n")] = '\0'; // ���� ���� �����ϱ�

    if (strlen(buf) == 0) {
        printf("��ȭ��ȣ�� �Է����ּ���.\n");
        return;
    }

    // ���� ��ȣ �޸� �����ϱ�
    free(num[index]);

    // ���ο� ��ȣ �����ϱ�
    num[index] = strdup(buf);
    if (num[index] == NULL) {    // �޸𸮰� �����ϰų� �Ҵ� �Ұ��� ũ���� �޸𸮸� ���������� �����
        fprintf(stderr, "�޸� �Ҵ� ����: ��ȣ�� ������ �� �����ϴ�.\n");
        return;
    }

    printf("��ȭ��ȣ�� �����Ǿ����ϴ�.\n");

    saveload(1); // ����� ������ ���Ͽ� �����ϱ� (mode 1)
}
