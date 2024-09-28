#include "functions.h"

void delEntry(PhoneBook* pb) {
    char buf[BUFFER_SIZE];
    printf("������ �̸��� �Է��ϼ���: ");
    fgets(buf, BUFFER_SIZE, stdin);
    buf[strcspn(buf, "\n")] = '\0';

    int index = -1;
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

    // ��Ʈ�� ���� (���� ��ҵ��� ������ �̵�)
    for (int i = index; i < pb->n - 1; i++) {
        pb->entries[i] = pb->entries[i + 1];
    }

    pb->n--; // �ο� �� ����

    printf("%s ��(��) ��ȭ��ȣ�ο��� �����Ǿ����ϴ�.\n", buf);

    saveload(pb, 1); // ������ ����
}
