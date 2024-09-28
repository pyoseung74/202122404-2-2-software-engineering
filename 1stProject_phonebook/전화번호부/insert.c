#include "functions.h"

void insert(PhoneBook* pb) {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE], buf3[BUFFER_SIZE]; // �̸�, �й�, ��ȭ��ȣ�� ������ ����
    char formattedNum[BUFFER_SIZE];            // ����ȭ�� ��ȭ��ȣ�� ������ ����

    // �뷮 ���� �� Ȯ��
    if (pb->n >= pb->capacity) {
        int new_capacity = (pb->capacity == 0) ? 1 : pb->capacity * 2;
        Entry* temp_entries = realloc(pb->entries, new_capacity * sizeof(Entry));
        if (temp_entries == NULL) {
            fprintf(stderr, "�޸� ���Ҵ� ����\n");
            return;
        }
        pb->entries = temp_entries;
        pb->capacity = new_capacity;
    }

    // ������ �Է¹ޱ� (�̸�, �й�, ��ȭ��ȣ)
    printf("�̸��� �Է��ϼ���: ");
    scanf(" %[^\n]", buf1); // ���� �����Ͽ� �Է� �ޱ�
    // �Է� ���� ����
    while (getchar() != '\n');

    if (strlen(buf1) >= BUFFER_SIZE) {
        printf("�̸��� �ʹ� ��ϴ�.\n");
        return;
    }

    // �й� �Է�
    printf("�й��� �Է��ϼ���: ");
    scanf("%s", buf2);
    // �Է� ���� ����
    while (getchar() != '\n');

    if (strlen(buf2) >= BUFFER_SIZE) {
        printf("�й��� �ʹ� ��ϴ�.\n");
        return;
    }

    printf("��ȭ��ȣ�� �Է��ϼ��� (���ڸ� �Է��ϰų� '-'�� ������ �� �ֽ��ϴ�): ");
    scanf("%s", buf3); // ��ȭ��ȣ �Է� �ޱ�
    // �Է� ���� ����
    while (getchar() != '\n');

    if (strlen(buf3) >= BUFFER_SIZE) {
        printf("��ȭ��ȣ�� �ʹ� ��ϴ�.\n");
        return;
    }

    // ��ȭ��ȣ ����ȭ
    formatNum(buf3, formattedNum);

    // ������ ����
    strcpy(pb->entries[pb->n].name, buf1);
    strcpy(pb->entries[pb->n].studentNumber, buf2);
    strcpy(pb->entries[pb->n].num, formattedNum);

    pb->n++; // ��ϵ� �ο� �� ����

    printf("%s ��(��) ��ȭ��ȣ�ο� ����Ǿ����ϴ�.\n", buf1);

    saveload(pb, 1); // ������ ����
}
