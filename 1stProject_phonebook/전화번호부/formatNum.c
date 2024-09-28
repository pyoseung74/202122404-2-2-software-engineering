#include "functions.h"

void formatNum(const char* input, char* output) {
    char temp[BUFFER_SIZE]; // ���ڸ� ������ ��ȭ��ȣ�� ������ �ӽ� ����
    int idx = 0;

    // �Էµ� ��ȭ��ȣ���� ���ڸ� ����
    for (int i = 0; input[i] != '\0' && idx < BUFFER_SIZE - 1; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            temp[idx++] = input[i];
        }
    }
    temp[idx] = '\0'; // ���ڿ� ����

    int len = strlen(temp);

    // ��ȭ��ȣ�� �� �� �ڸ� Ȯ��
    if (strncmp(temp, "01", 2) == 0) {
        // 01�� �����ϴ� ��ȣ (��: 010-1234-5678)
        if (len == 11) {
            snprintf(output, BUFFER_SIZE, "%c%c%c-%c%c%c%c-%c%c%c%c",
                temp[0], temp[1], temp[2],
                temp[3], temp[4], temp[5], temp[6],
                temp[7], temp[8], temp[9], temp[10]);
        }
        else {
            // ������ ������ �� ���� ��� ���ڸ� ��ȯ
            strcpy(output, temp);
        }
    }
    else if (strncmp(temp, "02", 2) == 0) {
        // 02�� �����ϴ� ��ȣ (��: 02-1234-5678)
        if (len == 10) {
            snprintf(output, BUFFER_SIZE, "%c%c-%c%c%c%c-%c%c%c%c",
                temp[0], temp[1],
                temp[2], temp[3], temp[4], temp[5],
                temp[6], temp[7], temp[8], temp[9]);
        }
        else {
            // ������ ������ �� ���� ��� ���ڸ� ��ȯ
            strcpy(output, temp);
        }
    }
    else {
        // �� ���� ��� (��: 031-123-1245)
        if (len == 10) {
            // ������ȣ 3�ڸ� - ���� 3�ڸ� - ��ȣ 4�ڸ�
            snprintf(output, BUFFER_SIZE, "%c%c%c-%c%c%c-%c%c%c%c",
                temp[0], temp[1], temp[2],
                temp[3], temp[4], temp[5],
                temp[6], temp[7], temp[8], temp[9]);
        }
        else if (len == 11) {
            // ������ȣ 3�ڸ� - ���� 4�ڸ� - ��ȣ 4�ڸ�
            snprintf(output, BUFFER_SIZE, "%c%c%c-%c%c%c%c-%c%c%c%c",
                temp[0], temp[1], temp[2],
                temp[3], temp[4], temp[5], temp[6],
                temp[7], temp[8], temp[9], temp[10]);
        }
        else {
            // ������ ������ �� ���� ��� ���ڸ� ��ȯ
            strcpy(output, temp);
        }
    }
}
