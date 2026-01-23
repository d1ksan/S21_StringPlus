#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
    if (str == S21_NULL) {
        return str;
    }
    unsigned char *ptr = (unsigned char *)str;
    unsigned char value = (unsigned char)c;

    for (s21_size_t i = 0; i < n; i++) {
        ptr[i] = value;
    }
    
    return str;
}