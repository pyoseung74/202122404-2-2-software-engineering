#include "functions.h"

void reset(PhoneBook* pb) {
    free(pb->entries); // 동적 메모리 해제
    pb->entries = NULL;
    pb->n = 0;
    pb->capacity = 0;
}
