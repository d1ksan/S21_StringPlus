#ifndef S21_STRING_H
#define S21_STRING_H
#include <stddef.h>
#define S21_NULL ((void *)0)

typedef unsigned long s21_size_t;
void *s21_memset(void *str, int c, s21_size_t n);

#endif