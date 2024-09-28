#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS // ���� ��� ����
#define BUFFER_SIZE 100  // ���ڿ� ������ ���� ���� ũ��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��ȭ��ȣ�� ��Ʈ�� ����ü ����
typedef struct {
    char name[BUFFER_SIZE];          // �̸� ����
    char studentNumber[BUFFER_SIZE]; // �й� ����
    char num[BUFFER_SIZE];           // ��ȭ��ȣ ����
} Entry;

// ��ȭ��ȣ�� ����ü ����
typedef struct {
    int n;                  // ���� ��ϵ� �ο� ��
    int capacity;           // �迭�� ���� �뷮
    Entry* entries;         // ��Ʈ�� �迭
    const char* frame;      // ���� ���
} PhoneBook;

// �Լ� ���� ����
void search(PhoneBook* pb);           // ��ȭ��ȣ�ο��� �̸� �Ǵ� ��ȣ �˻��ϱ�
void insert(PhoneBook* pb);           // ��ȭ��ȣ�ο� �ű� ����ϱ�
void delEntry(PhoneBook* pb);         // ��ȭ��ȣ�ο��� ��ϵ� ���� �����ϱ�
void list(PhoneBook* pb);             // ��ȭ��ȣ�� ��ü ��� ����ϱ�
void touch(PhoneBook* pb);            // ��ȭ��ȣ �����ϱ�
void reset(PhoneBook* pb);            // ���� �޸� �����ϱ�
void saveload(PhoneBook* pb, int mode); // ��ȭ��ȣ�� ���� ����� �Լ�

// ��ȭ��ȣ ����ȭ �Լ� ���� ����
void formatNum(const char* input, char* output);

#endif // FUNCTIONS_H
