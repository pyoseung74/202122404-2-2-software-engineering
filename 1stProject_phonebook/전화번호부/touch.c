#include "functions.h"

void touch(PhoneBook* pb) {
    char buf[BUFFER_SIZE];           // ������ �̸��� ������ ����
    char newNum[BUFFER_SIZE];        // ���ο� ��ȭ��ȣ�� ������ ����
    char formattedNum[BUFFER_SIZE];  // ����ȭ�� ��ȭ��ȣ�� ������ ����

    printf("������ �̸��� �Է��ϼ���: ");
    scanf(" %[^\n]", buf); // �̸� �Է� �ޱ�
    // �Է� ���� ����
    while (getchar() != '\n');

    int index = -1; // ������ �ε��� �ʱ�ȭ
    for (int i = 0; i < pb->n; i++) {
        if (strcmp(pb->entries[i].name, buf) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("�ش� �̸��� ��ȭ��ȣ�ο� �����ϴ�.\n");
        return;
    }

    printf("���ο� ��ȭ��ȣ�� �Է��ϼ��� (���ڸ� �Է��ϰų� '-'�� ������ �� �ֽ��ϴ�): ");
    scanf("%s", newNum); // ���ο� ��ȣ �Է� �ޱ�
    // �Է� ���� ����
    while (getchar() != '\n');

    if (strlen(newNum) >= BUFFER_SIZE) {
        printf("��ȭ��ȣ�� �ʹ� ��ϴ�.\n");
        return;
    }

    // ��ȭ��ȣ ����ȭ
    formatNum(newNum, formattedNum);

    // ��ȣ ����
    strcpy(pb->entries[index].num, formattedNum);

    printf("��ȭ��ȣ�� �����Ǿ����ϴ�.\n");

    saveload(pb, 1); // ������ ����
}
