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

    for (i=0;i<n;i++){
        dest[i] = '\0';
    }

    return dest;
}
