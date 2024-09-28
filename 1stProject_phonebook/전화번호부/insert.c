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
    scanf("%s", buf1); // �̸� �Է� �ޱ�

    // ��ȣ �Է�
    printf("��ȭ��ȣ�� �Է��ϼ��� (���ڸ� �Է��ϰų� '-'�� ������ �� �ֽ��ϴ�): ");
    scanf("%s", buf2); // ��ȭ��ȣ �Է� �ޱ�

    // ��ȭ��ȣ ����ȭ
    formatPhoneNumber(buf2, formattedNum);

    // ������ ����
    strncpy(pb->entries[pb->n].name, buf1, BUFFER_SIZE - 1);
    pb->entries[pb->n].name[BUFFER_SIZE - 1] = '\0';

    strncpy(pb->entries[pb->n].num, formattedNum, BUFFER_SIZE - 1);
    pb->entries[pb->n].num[BUFFER_SIZE - 1] = '\0';

    pb->n++; // �ο� �� ����

    printf("%s ��(��) ��ȭ��ȣ�ο� ����Ǿ����ϴ�.\n", buf1);

    saveload(pb, 1); // ������ ����
}
