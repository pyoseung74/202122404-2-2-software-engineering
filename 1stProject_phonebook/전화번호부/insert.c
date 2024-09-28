#include "functions.h"

void insert(PhoneBook* pb) {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE]; // �̸��� ��ȭ��ȣ�� ������ ����
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

    // �̸� �Է�
    printf("�̸��� �Է��ϼ���: ");
    scanf(" %[^\n]", buf1); // ���� �����Ͽ� �Է� �ޱ�
    // �Է� ���� ����
    while (getchar() != '\n');

    if (strlen(buf1) >= BUFFER_SIZE) {
        printf("�̸��� �ʹ� ��ϴ�.\n");
        return;
    }

    // ��ȣ �Է�
    printf("��ȭ��ȣ�� �Է��ϼ��� (���ڸ� �Է��ϰų� '-'�� ������ �� �ֽ��ϴ�): ");
    scanf("%s", buf2); // ��ȭ��ȣ �Է� �ޱ�
    // �Է� ���� ����
    while (getchar() != '\n');

    if (strlen(buf2) >= BUFFER_SIZE) {
        printf("��ȭ��ȣ�� �ʹ� ��ϴ�.\n");
        return;
    }

    // ��ȭ��ȣ ����ȭ
    formatNum(buf2, formattedNum);

    // ������ ����
    strcpy(pb->entries[pb->n].name, buf1);
    strcpy(pb->entries[pb->n].num, formattedNum);

    pb->n++; // ��ϵ� �ο� �� ����

    printf("%s ��(��) ��ȭ��ȣ�ο� ����Ǿ����ϴ�.\n", buf1);

    saveload(pb, 1); // ������ ����
}
