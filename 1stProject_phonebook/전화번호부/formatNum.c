#include "functions.h"

// ��ȭ��ȣ ����ȭ �Լ� ����
void formatNum(const char* input, char* output) {
    char temp[BUFFER_SIZE];
    int len = 0;
    int idx = 0;

    // �Էµ� ��ȭ��ȣ���� '-' ����
    for (int i = 0; input[i] != '\0' && idx < BUFFER_SIZE - 1; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            temp[idx++] = input[i];
        }
    }
    temp[idx] = '\0'; // ���ڿ� ����
    len = idx;        // ���ڸ� �ִ� ��ȭ��ȣ�� ����

    // ��ȭ��ȣ ���̿� ���� ���� ����
    if (len == 10) {
        // ��: 02-123-4567 �Ǵ� 031-123-4567
        snprintf(output, BUFFER_SIZE, "%c%c-%c%c%c-%c%c%c%c",
            temp[0], temp[1], temp[2], temp[3], temp[4],
            temp[5], temp[6], temp[7], temp[8], temp[9]);
    }
    else if (len == 11) {
        // ��: 010-1234-5678
        snprintf(output, BUFFER_SIZE, "%c%c%c-%c%c%c%c-%c%c%c%c",
            temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6],
            temp[7], temp[8], temp[9], temp[10]);
    }
    else {
        // ������ ������ �� ���� ��� �״�� ��ȯ
        strncpy(output, temp, BUFFER_SIZE - 1);
        output[BUFFER_SIZE - 1] = '\0';
    }
}
