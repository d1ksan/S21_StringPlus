#include <check.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "s21_string.h"

#define BUFF_SIZE 512

/* ========== ТЕСТЫ ДЛЯ s21_strlen ========== */

START_TEST(strlen_1) {
    char *str_1 = "LUGANO\0";
    ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_2) {
    char *str_2 = "LUGANO THE \0BEST!!!";
    ck_assert_int_eq(strlen(str_2), s21_strlen(str_2));
}
END_TEST

START_TEST(strlen_3) {
    char *str_3 = "\0";
    ck_assert_int_eq(strlen(str_3), s21_strlen(str_3));
}
END_TEST

START_TEST(strlen_empty) {
    char src[] = "";
    ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_abosal) {
    char src[] = "abosal";
    ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_num) {
    char src[] = "987623456124678";
    ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_string) {
    char src[] = "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_abosal_no_dal) {
    char src[] = "abosal\0no_dal";
    ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_dai_mne_pen) {
    char src[] = "dai_mne_pen(321321)...123...123";
    ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_Floppy_disk) {
    char src[] = "Floppy_disk";
    ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_Russky_kot_Shlepa) {
    char src[] = "Russky_kot_Shlepa";
    ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_kot_Vasily) {
    char src[] = "kot Vasily";
    ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_floppa) {
    char src[] = "floppa";
    ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

/* ========== ТЕСТЫ ДЛЯ s21_strncpy ========== */

START_TEST(strncpy_1) {
    s21_size_t n1 = 3;
    char b1[1024] = "1111111111";
    char b11[1024] = "1111111111";
    char str_1_2[1024] = "123\0";
    ck_assert_pstr_eq(strncpy(b1, str_1_2, n1), s21_strncpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(strncpy_2) {
    s21_size_t n2 = 5;
    char b2[1024] = "1111111111";
    char b22[1024] = "1111111111";
    char str_2_2[1024] = "12345\0006789";
    ck_assert_pstr_eq(strncpy(b2, str_2_2, n2), s21_strncpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncpy_3) {
    s21_size_t n3 = 5;
    char b3[1024] = "11";
    char b33[1024] = "11";
    char str_3_2[1024] = "12345\0006789";
    ck_assert_pstr_eq(strncpy(b3, str_3_2, n3), s21_strncpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(strncpy_empty) {
    char src[] = "";
    char res[] = "";
    char exp[] = "";
    s21_size_t n_byte = 0;
    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);
    ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_zero_byte) {
    char src[] = "123";
    char res[] = "123";
    char exp[] = "123";
    s21_size_t n_byte = 0;
    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);
    ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_empty_src) {
    char src[] = "";
    char res[] = "123";
    char exp[] = "123";
    s21_size_t n_byte = 0;
    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);
    ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_one_byte) {
    char src[] = "123";
    char res[5] = "123";
    char exp[5] = "123";
    s21_size_t n_byte = 1;
    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);
    ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_two_byte) {
    char src[] = "123";
    char res[7] = "123";
    char exp[7] = "123";
    s21_size_t n_byte = 2;
    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);
    ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_string) {
    char src[] = "Str1ng";
    char res[7 + 7] = "Str1ng";
    char exp[7 + 7] = "Str1ng";
    s21_size_t n_byte = 7;
    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);
    ck_assert_str_eq(res, exp);
}
END_TEST

/* ========== ТЕСТЫ ДЛЯ s21_memset ========== */

START_TEST(memset_1) {
    s21_size_t n1 = 6;
    int c1 = '7';
    char b1[1024] = "LUGANO THE BEST!";
    char b11[1024] = "LUGANO THE BEST!";
    ck_assert_pstr_eq(memset(b1, c1, n1), s21_memset(b11, c1, n1));
}
END_TEST

START_TEST(memset_2) {
    s21_size_t n2 = 4;
    int c2 = '4';
    char b2[1024] = " BEST!!";
    char b22[1024] = " BEST!!";
    ck_assert_pstr_eq(memset(b2, c2, n2), s21_memset(b22, c2, n2));
}
END_TEST

START_TEST(memset_3) {
    s21_size_t n3 = 6;
    int c3 = '3';
    char b3[1024] = " LUGANO!";
    char b33[1024] = " LUGANO!";
    ck_assert_pstr_eq(memset(b3, c3, n3), s21_memset(b33, c3, n3));
}
END_TEST

START_TEST(memset_aboba_test) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'g';
    s21_size_t n_byte = 5;
    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);
    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_zero_byte) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'g';
    s21_size_t n_byte = 0;
    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);
    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_empty) {
    char res[] = "";
    char expected[] = "";
    char replace = '\0';
    s21_size_t n_byte = 0;
    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);
    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_replace_on_register_sim) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'A';
    s21_size_t n_byte = 3;
    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);
    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_replace_on_register_num) {
    char res[] = "a1obA";
    char expected[] = "a1obA";
    char replace = '1';
    s21_size_t n_byte = 5;
    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);
    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_long_string) {
    char res[] = "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 hiajhIOUAHSDiouAHSdu1).bA";
    char expected[] = "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 hiajhIOUAHSDiouAHSdu1).bA";
    char replace = '1';
    s21_size_t n_byte = 5;
    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);
    ck_assert_str_eq(res, expected);
}
END_TEST

/* ========== ТЕСТЫ ДЛЯ s21_memcpy ========== */

START_TEST(memcpy_1) {
    s21_size_t n1 = 3;
    char b1[1024] = "";
    char b11[1024] = "";
    char str_1_2[1024] = "LUGANO THE BEST!";
    ck_assert_pstr_eq(memcpy(b1, str_1_2, n1), s21_memcpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(memcpy_2) {
    s21_size_t n2 = 5;
    char b2[1024] = "";
    char b22[1024] = "";
    char str_2_2[1024] = "THE OF \0BEST!!";
    ck_assert_pstr_eq(memcpy(b2, str_2_2, n2), s21_memcpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(memcpy_3) {
    s21_size_t n3 = 4;
    char b3[1024] = "777 ";
    char b33[1024] = "777 ";
    char str_3_2[1024] = "LUGANO!";
    ck_assert_pstr_eq(memcpy(b3, str_3_2, n3), s21_memcpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(memcpy_4) {
    s21_size_t n4 = 4;
    char b4[1024] = "LUGANO! 777 ";
    char b44[1024] = "LUGANO! 777 ";
    ck_assert_pstr_eq(memcpy(b4, b4 + 7, n4), s21_memcpy(b44, b44 + 7, n4));
}
END_TEST

START_TEST(memcpy_hate_test) {
    char src[] = "i hate memcmp";
    s21_size_t kByte = 12;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_string) {
    char src[] = "aboba";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_any_empty) {
    char src[] = "";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_string_with_register) {
    char src[] = "I hate memcmp";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_num) {
    char src[] = "123";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_string) {
    char src[] = "aboba";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_string_with_register) {
    char src[] = "Zboba";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_num) {
    char src[] = "09";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_basic_long_string) {
    char src[] = "abobasdafoijasdofjas asdopij";
    s21_size_t kByte = 28;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register) {
    char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
    s21_size_t kByte = 36;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register_and_num) {
    char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
    s21_size_t kByte = 53;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register_and_num_and_simbol) {
    char src[] = "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
    s21_size_t kByte = 71;
    char res[kByte+8];
    char expected[kByte+8];
    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);
    ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

/* ========== ТЕСТЫ ДЛЯ s21_memchr ========== */

START_TEST(memchr_1) {
    char str[] = "Hello w\0orld\0";
    ck_assert_pstr_eq(memchr(str, 'r', 5), s21_memchr(str, 'r', 5));
}
END_TEST

START_TEST(memchr_2) {
    char str2[] = "john.smith@microsoft.com";
    ck_assert_pstr_eq(memchr(str2, 's', 6), s21_memchr(str2, 's', 6));
}
END_TEST

START_TEST(memchr_3) {
    char str3[] = {'q', 'r', 's', 't', 'w', '\0'};
    ck_assert_pstr_eq(memchr(str3, 's', 5), s21_memchr(str3, 's', 5));
}
END_TEST

START_TEST(memchr_empty_str) {
    s21_size_t n_byte = 0;
    char str[10] = "";
    int find_byte = '\0';
    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_zero_in_string) {
    s21_size_t n_byte = 7;
    char str[10] = "string";
    int find_byte = '\0';
    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_simbol_in_string_in_start) {
    s21_size_t n_byte = 6;
    char str[10] = "Atring";
    int find_byte = 'A';
    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_simbol_in_string_in_end) {
    s21_size_t n_byte = 7;
    char str[10] = "StringA";
    int find_byte = 'A';
    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_num_in_string_in_mid) {
    s21_size_t n_byte = 15;
    char str[16] = "Str55333222ingA";
    int find_byte = '3';
    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_num_in_array_num) {
    int array[] = {1, 2, 3, 666, 5, 99, 100};
    s21_size_t n_byte = sizeof(int) * 7;
    int find_byte = 666;
    ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                     memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_float_in_array) {
    float array[] = {1, 2, 3, 666, 5, 99, 100};
    s21_size_t n_byte = sizeof(float) * 7;
    int find_byte = 666;
    ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                     memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_easy_test_string) {
    s21_size_t n_byte = 5;
    char str[10] = "aboba";
    int find_byte = 'c';
    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
}
END_TEST

/* ========== ТЕСТЫ ДЛЯ s21_memcmp ========== */

START_TEST(memcmp_1) {
    s21_size_t n1 = 3;
    void *str_1_1 = "LUGANO!";
    void *str_1_2 = "LUGANO!";
    ck_assert_int_eq(memcmp(str_1_1, str_1_2, n1), s21_memcmp(str_1_1, str_1_2, n1));
}
END_TEST

START_TEST(memcmp_2) {
    s21_size_t n2 = 3;
    void *str_2_1 = "LUGANO THE BEST!";
    void *str_2_2 = "LU GANO OF THE BEST!!";
    ck_assert_int_eq(memcmp(str_2_1, str_2_2, n2), s21_memcmp(str_2_1, str_2_2, n2));
}
END_TEST

START_TEST(memcmp_3) {
    s21_size_t n3 = 3;
    void *str_3_1 = " LUGANO OF THE BEST!!";
    void *str_3_2 = "LUGANO!";
    ck_assert_int_eq(memcmp(str_3_1, str_3_2, n3), s21_memcmp(str_3_1, str_3_2, n3));
}
END_TEST

START_TEST(memcmp_zero_byte) {
    char str1[] = "aboba";
    char str2[] = "aboba";
    int n = 0;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_first_byte_in_string) {
    char str1[] = "aboba";
    char str2[] = "aboba";
    int n = 3;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_register_test) {
    char str1[] = "aboba";
    char str2[] = "Aboba";
    int n = 1;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_zero_byte_in_num) {
    char str1[] = "1";
    char str2[] = "1";
    int n = 0;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_first_byte_in_num) {
    char str1[] = "1";
    char str2[] = "1234";
    int n = 1;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_in_num) {
    char str1[] = "1234";
    char str2[] = "1234";
    int n = 2;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_long_two_num) {
    char str1[] = "13";
    char str2[] = "1234";
    int n = 2;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_long_first_num) {
    char str1[] = "134567";
    char str2[] = "1234";
    int n = 2;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_eq_long_string) {
    char str1[] = "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
    char str2[] = "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
    int n = 71;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_not_eq_long_string) {
    char str1[] = "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
    char str2[] = "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASd";
    int n = 71;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

/* ========== НАБОР ТЕСТОВ ========== */

Suite *s21_string_test_suite(void) {
    Suite *s = suite_create("s21_string_test");
    TCase *tc = tcase_create("core");

    /* strlen */
    tcase_add_test(tc, strlen_1);
    tcase_add_test(tc, strlen_2);
    tcase_add_test(tc, strlen_3);
    tcase_add_test(tc, strlen_empty);
    tcase_add_test(tc, strlen_abosal);
    tcase_add_test(tc, strlen_num);
    tcase_add_test(tc, strlen_string);
    tcase_add_test(tc, strlen_abosal_no_dal);
    tcase_add_test(tc, strlen_dai_mne_pen);
    tcase_add_test(tc, strlen_Floppy_disk);
    tcase_add_test(tc, strlen_Russky_kot_Shlepa);
    tcase_add_test(tc, strlen_kot_Vasily);
    tcase_add_test(tc, strlen_floppa);

    /* strncpy */
    tcase_add_test(tc, strncpy_1);
    tcase_add_test(tc, strncpy_2);
    tcase_add_test(tc, strncpy_3);
    tcase_add_test(tc, strncpy_empty);
    tcase_add_test(tc, strncpy_zero_byte);
    tcase_add_test(tc, strncpy_empty_src);
    tcase_add_test(tc, strncpy_one_byte);
    tcase_add_test(tc, strncpy_two_byte);
    tcase_add_test(tc, strncpy_string);

    /* memset */
    tcase_add_test(tc, memset_1);
    tcase_add_test(tc, memset_2);
    tcase_add_test(tc, memset_3);
    tcase_add_test(tc, memset_aboba_test);
    tcase_add_test(tc, memset_zero_byte);
    tcase_add_test(tc, memset_empty);
    tcase_add_test(tc, memset_replace_on_register_sim);
    tcase_add_test(tc, memset_replace_on_register_num);
    tcase_add_test(tc, memset_long_string);

    /* memcpy */
    tcase_add_test(tc, memcpy_1);
    tcase_add_test(tc, memcpy_2);
    tcase_add_test(tc, memcpy_3);
    tcase_add_test(tc, memcpy_4);
    tcase_add_test(tc, memcpy_hate_test);
    tcase_add_test(tc, memcpy_zero_test_string);
    tcase_add_test(tc, memcpy_any_empty);
    tcase_add_test(tc, memcpy_zero_test_string_with_register);
    tcase_add_test(tc, memcpy_zero_test_num);
    tcase_add_test(tc, memcpy_one_byte_string);
    tcase_add_test(tc, memcpy_one_byte_string_with_register);
    tcase_add_test(tc, memcpy_one_byte_num);
    tcase_add_test(tc, memcpy_basic_long_string);
    tcase_add_test(tc, memcpy_long_string_with_register);
    tcase_add_test(tc, memcpy_long_string_with_register_and_num);
    tcase_add_test(tc, memcpy_long_string_with_register_and_num_and_simbol);

    /* memchr */
    tcase_add_test(tc, memchr_1);
    tcase_add_test(tc, memchr_2);
    tcase_add_test(tc, memchr_3);
    tcase_add_test(tc, memchr_empty_str);
    tcase_add_test(tc, memchr_find_zero_in_string);
    tcase_add_test(tc, memchr_find_simbol_in_string_in_start);
    tcase_add_test(tc, memchr_find_simbol_in_string_in_end);
    tcase_add_test(tc, memchr_find_num_in_string_in_mid);
    tcase_add_test(tc, memchr_find_num_in_array_num);
    tcase_add_test(tc, memchr_find_float_in_array);
    tcase_add_test(tc, memchr_easy_test_string);

    /* memcmp */
    tcase_add_test(tc, memcmp_1);
    tcase_add_test(tc, memcmp_2);
    tcase_add_test(tc, memcmp_3);
    tcase_add_test(tc, memcmp_zero_byte);
    tcase_add_test(tc, memcmp_first_byte_in_string);
    tcase_add_test(tc, memcmp_register_test);
    tcase_add_test(tc, memcmp_zero_byte_in_num);
    tcase_add_test(tc, memcmp_first_byte_in_num);
    tcase_add_test(tc, memcmp_two_byte_in_num);
    tcase_add_test(tc, memcmp_two_byte_long_two_num);
    tcase_add_test(tc, memcmp_two_byte_long_first_num);
    tcase_add_test(tc, memcmp_eq_long_string);
    tcase_add_test(tc, memcmp_not_eq_long_string);

    suite_add_tcase(s, tc);
    return s;
}

int main(void) {
    setlocale(LC_ALL, "");
    int nf;
    Suite *s = s21_string_test_suite();
    SRunner *sr = srunner_create(s);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_VERBOSE);

    nf = srunner_ntests_failed(sr);
    srunner_free(sr);
    return nf == 0 ? 0 : 1;
}