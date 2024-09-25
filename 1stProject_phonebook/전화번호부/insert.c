#include "functions.h"

void insert() {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE]; // �̸��� ��ȭ��ȣ�� �Է¹��� �ӽð��� �����ϱ�

    // �迭�� �뷮�� �����ϸ� �� ��� �ø���
    if (n >= capacity) {
        int new_capacity = (capacity == 0) ? 1 : capacity * 2;

        // �̸� �迭�� ũ�� �����ϱ�
        char** temp_name = realloc(name, new_capacity * sizeof(char*)); 
        if (temp_name == NULL) {    // �޸𸮰� �����ϰų� �Ҵ� �Ұ����� ũ���� �޸𸮸� ���������� �����
            fprintf(stderr, "�޸� ���Ҵ� ����: �̸� �迭�� Ȯ���� �� �����ϴ�.\n");
            return;
        }
        name = temp_name;

        // ��ȣ �迭�� ũ�� �����ϱ�
        char** temp_num = realloc(num, new_capacity * sizeof(char*));
        if (temp_num == NULL) {     // �޸𸮰� �����ϰų� �Ҵ� �Ұ����� ũ���� �޸𸮸� ���������� �����
            fprintf(stderr, "�޸� ���Ҵ� ����: ��ȣ �迭�� Ȯ���� �� �����ϴ�.\n");
            return;
        }
        num = temp_num;

        capacity = new_capacity; // ���ο� �뷮���� ������Ʈ�ϱ�
    }

    // �̸� �Է¹ޱ�
    printf("�̸��� �Է��ϼ���: ");
    fgets(buf1, BUFFER_SIZE, stdin);
    buf1[strcspn(buf1, "\n")] = '\0'; // ���� ���� �����ϱ�

    if (strlen(buf1) == 0) {    // �Է��� ���� ������ ��� (���ڿ� ���̰� 0 �϶�)
        printf("�̸��� �Է����ּ���.\n");
        return;
    }

    // ��ȭ��ȣ �Է¹ޱ�
    printf("��ȭ��ȣ�� �Է��ϼ���: ");
    fgets(buf2, BUFFER_SIZE, stdin);
    buf2[strcspn(buf2, "\n")] = '\0'; // ���� ���� �����ϱ�

    if (strlen(buf2) == 0) {    // �Է��� ���� ������ ��� (���ڿ� ���̰� 0 �϶�)
        printf("��ȭ��ȣ�� �Է����ּ���.\n");
        return;
    }

    // �̸� �����ϱ�
    name[n] = strdup(buf1); // ����� �̸��� �޸𸮸� �߰������� �Ҵ����� (���� �޸� ���� ������ ���� free ����ؾ���)
    if (name[n] == NULL) {  // �޸𸮰� �����ϰų� �Ҵ� �Ұ����� ũ���� �޸𸮸� ���������� �����
        fprintf(stderr, "�޸� �Ҵ� ����: �̸��� ������ �� �����ϴ�.\n");
        return;
    }

    // ��ȣ �����ϱ�
    num[n] = strdup(buf2);  // ���� �޸� ���� ������ ���� free ����ؾ���
    if (num[n] == NULL) {  // �޸𸮰� �����ϰų� �Ҵ� �Ұ����� ũ���� �޸𸮸� ���������� �����
        fprintf(stderr, "�޸� �Ҵ� ����: ��ȣ�� ������ �� �����ϴ�.\n");
        free(name[n]); // �̹� �Ҵ�� name[n] �޸� �����ϱ�
        return;
    }

    n++; // ��ϵ� �ο� �� �����ϱ�

    printf("%s ��(��) ��ȭ��ȣ�ο� ����Ǿ����ϴ�.\n", buf1);

    saveload(1); // ����� ������ ���Ͽ� �����ϱ� (mode 1)
}
