#include "s21_string.h"
s21_size_t s21_strlen(const char *str){
    s21_size_t len = 0;

    while (str[len] != '\0'){
        len++;
    }
    return len;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n){

    s21_size_t i;
    for (i=0; i<n && src[i] != '\0'; i++){
        dest[i] = src[i];
    }

    for (;i<n;i++){
        dest[i] = '\0';
    }

    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *ptr = (unsigned char *)str;
    unsigned char value = (unsigned char)c;
    
    for (s21_size_t i = 0; i < n; i++) {
        ptr[i] = value;
    }
    
    return str;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n){
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    for(s21_size_t i = 0; i<n; i++){
        d[i] = s[i];
    }
    return dest;
}