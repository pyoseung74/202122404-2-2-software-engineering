#include "functions.h"

void search(PhoneBook* pb) {
    char buf[BUFFER_SIZE]; // �˻��� �̸� �Ǵ� ��ȣ�� ������ ����
    printf("�˻��� �̸� �Ǵ� ��ȭ��ȣ�� �Է��ϼ���: ");
    scanf(" %[^\n]", buf); // �˻��� �Է� �ޱ�
    // �Է� ���� ����
    while (getchar() != '\n');

    if (strlen(buf) >= BUFFER_SIZE) {
        printf("�˻�� �ʹ� ��ϴ�.\n");
        return;
    }

    int found = 0; // �˻� ��� ���θ� ������ ����

    for (int i = 0; i < pb->n; i++) {
        // �̸� �Ǵ� ��ȭ��ȣ ��
        if (strstr(pb->entries[i].name, buf) != NULL || strstr(pb->entries[i].num, buf) != NULL) {
            printf("%s - %s\n", pb->entries[i].name, pb->entries[i].num);
            found = 1;
        }
    }

    if (!found) {
        printf("'%s'�� ��ġ�ϴ� �׸��� �����ϴ�.\n", buf);
    }
}
