#include "functions.h"

void touch(PhoneBook* pb) {
    char buf[BUFFER_SIZE];           // ������ �̸��� ������ ����
    char newNum[BUFFER_SIZE];        // ���ο� ��ȭ��ȣ�� ������ ����
    char formattedNum[BUFFER_SIZE];  // ����ȭ�� ��ȭ��ȣ�� ������ ����

    printf("������ �̸��� �Է��ϼ���: ");
    scanf("%s", buf); // �̸� �Է� �ޱ�

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

    // ��ȭ��ȣ ����ȭ
    formatPhoneNumber(newNum, formattedNum);

    // ��ȣ ����
    strncpy(pb->entries[index].num, formattedNum, BUFFER_SIZE - 1);
    pb->entries[index].num[BUFFER_SIZE - 1] = '\0';

    printf("��ȭ��ȣ�� �����Ǿ����ϴ�.\n");

    saveload(pb, 1); // ������ ����
}
