#include "functions.h"

void delEntry() {
    char buf[BUFFER_SIZE];
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

    // �޸� �����ϱ�
    free(name[index]);
    free(num[index]);

    // �迭�� ���� ��ҵ��� ������ �̵���Ű��
    for (int i = index; i < n - 1; i++) {
        name[i] = name[i + 1];
        num[i] = num[i + 1];
    }

    n--; // ��ϵ� �ο� �� �����ϱ�

    printf("%s ��(��) ��ȭ��ȣ�ο��� �����Ǿ����ϴ�.\n", buf);

    saveload(1); // ����� ������ ���Ͽ� �����ϱ� (mode 1)
}
