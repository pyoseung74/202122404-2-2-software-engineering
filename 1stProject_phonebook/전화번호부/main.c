#include "functions.h"

int main() {
    int usenum;                  // �۾� ���ÿ� �ʿ��� ����

    // ��ȭ��ȣ�� �ʱ�ȭ
    PhoneBook* pb = (PhoneBook*)malloc(sizeof(PhoneBook));
    if (pb == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        return 1;
    }
    pb->n = 0;                     // ���� ��ϵ� �ο� �� �ʱ�ȭ
    pb->capacity = 0;              // �뷮 �ʱ�ȭ
    pb->entries = NULL;            // ��Ʈ�� �迭 �ʱ�ȭ
    pb->frame = "Number.txt";      // ���� ��� ����

    saveload(pb, 0); // ������ �ҷ�����

    do {
        // �޴� ���
        printf("��ȭ��ȣ��\n");
        printf("1) ��ȣ ���\n2) ��ȣ ����\n3) ��ȣ ����\n4) ��ȣ �˻�\n5) ��ȭ��ȣ�� ���\n6) ����\n");
        printf("- �۾��� �������ּ���: ");

        // ����� �Է� �ޱ�
        if (scanf("%d", &usenum) != 1) {
            printf("�Է� ������ �߻��߽��ϴ�.\n");
            // �Է� ���� ����
            while (getchar() != '\n');
            continue;
        }
        // �Է� ���� ����
        while (getchar() != '\n');

        switch (usenum) {
        case 1:
            insert(pb);  // ��ȣ ��� �Լ� ȣ��
            break;
        case 2:
            touch(pb);   // ��ȣ ���� �Լ� ȣ��
            break;
        case 3:
            delEntry(pb); // ��ȣ ���� �Լ� ȣ��
            break;
        case 4:
            search(pb);  // ��ȭ��ȣ�� �˻� �Լ� ȣ��
            break;
        case 5:
            list(pb);    // ��ȭ��ȣ�� ��� �Լ� ȣ��
            break;
        case 6:
            printf("��ȭ��ȣ�θ� �����մϴ�.\n");
            break;        // ���� ����
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
            break;
        }
    } while (usenum != 6);

    reset(pb); // �޸� ����
    free(pb);  // PhoneBook ����ü ��ü �޸� ����
    return 0;
}
