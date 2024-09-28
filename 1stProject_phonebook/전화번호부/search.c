#include "functions.h"

void search(PhoneBook* pb) {
    char buf[BUFFER_SIZE]; // �˻��� �̸� �Ǵ� ��ȣ�� ������ ����
    printf("�˻��� �̸� �Ǵ� ��ȭ��ȣ�� �Է��ϼ���: ");
    scanf("%s", buf); // �˻��� �Է� �ޱ�

    if (strlen(buf) == 0) {
        printf("�̸� �Ǵ� ��ȭ��ȣ�� �Է����ּ���.\n");
        return;
    }

    int found = 0; // �˻� ��� ���θ� ������ ����

    for (int i = 0; i < pb->n; i++) {
        // �̸� �Ǵ� ��ȭ��ȣ �� (����ȭ�� ��ȣ ���)
        if (strstr(pb->entries[i].name, buf) != NULL || strstr(pb->entries[i].num, buf) != NULL) {
            printf("%s - %s\n", pb->entries[i].name, pb->entries[i].num);
            found = 1;
        }
    }

    if (!found) {
        printf("'%s'�� ��ġ�ϴ� �׸��� �����ϴ�.\n", buf);
    }
}
