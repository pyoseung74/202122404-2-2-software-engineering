#include "functions.h"

void reset() {
    for (int i = 0; i < n; i++) {
        free(name[i]);
        free(num[i]);
    }
    free(name);
    free(num);
    name = NULL;
    num = NULL;
    n = 0;
    capacity = 0;
}
