#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdlib.h>

typedef unsigned long s21_size_t;

#define S21_NULL ((void*)0)
s21_size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

#endif 