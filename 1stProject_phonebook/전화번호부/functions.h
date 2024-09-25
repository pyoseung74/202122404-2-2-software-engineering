#define strdup _strdup		// visualstudio���� strdup�� _strdup���� ���ǹǷ� ȣȯ�� ���� �����
#define _CRT_SECURE_NO_WARNINGS // ��� ����
#define BUFFER_SIZE 100  // �̸� Ȥ�� ��ȭ��ȣ�� �ӽ� ������ ���� �����

#include <stdio.h>  // ǥ�� ����� �Լ� ����� ���� ��� ����
#include <stdlib.h> // ���� �޸� �Ҵ��� ���� ��� ����
#include <string.h> // ���ڿ� ó�� �Լ� ����� ���� ��� ����

// ���� ���� ����
extern int n;                // ���� ��ϵ� �ο� ��
extern int capacity;         // �迭�� ���� �뷮 (���� realloc �� ����Ͽ� ���� Ȯ���ϱ�) 
extern char** name;          // �̸��� ������ ���� �迭
extern char** num;           // ��ȣ�� ������ ���� �迭
extern const char* frame;    // ��ȭ��ȣ�� ������ ���

// �Լ� ���� ����
void search();               // ��ȭ��ȣ�ο��� �̸� �˻��ϱ�
void insert();               // ��ȭ��ȣ�ο� �ű� ����ϱ�
void delEntry();             // ��ȭ��ȣ�ο��� ��ϵ� ���� �����ϱ�
void list();                 // ��ȭ��ȣ�� ��ü ��� ����ϱ�
void touch();                // ��ȭ��ȣ �����ϱ�
void reset();                // ���� �޸� �����ϱ�
void saveload(int mode);       // ��ȭ��ȣ�� txt���Ͽ� ����&�ҷ����� �Լ� (mode: 0-�ҷ�����, 1-�����ϱ�)
