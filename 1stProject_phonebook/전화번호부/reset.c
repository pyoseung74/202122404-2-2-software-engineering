#include "functions.h"

void reset(PhoneBook* pb) {
    free(pb->entries); // ���� �޸� ����
    pb->entries = NULL;
    pb->n = 0;
    pb->capacity = 0;
}
