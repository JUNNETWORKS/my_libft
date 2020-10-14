/*
以下のコンパイルコマンドを使うとメモリリークとか教えてくれます.
gcc -Wall -Wextra -Werror -g -fsanitize=address *.c -lbsd

最後の -lbsd はGNU Cライブラリに無くて, BSD Cライブラリにのみある関数を使うためのフラグ (strlcpyとか)

事前に
sudo apt install -y libbsd-dev
でlibbsdをインストールする必要がある.
*/

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

# define SAFE_FREE(ptr) { \
    free(ptr); \
    ptr = NULL; \
} \

void printTitle(char str[]){
	printf("--------%s--------\n", str);
}

void newLine(int n){
	for (int i = 0 ; i < n ; i++)
		printf("\n");
}

void compareInt(int expected, int actual){
	printf("expected:\t%d\n", expected);
	printf("actual:  \t%d\n", actual);
	if (expected != actual)
		printf("\n\nYour implementation is not match with c lib!!\n\n");
}

void compareChar(char expected, char actual){
	printf("expected:\t%c\n", expected);
	printf("actual:  \t%c\n", actual);
	if (expected != actual)
		printf("\n\nYour implementation is not match with c lib!!\n\n");
}

void compareStrAndFree(char* expected, char* actual, bool willFree){
	printf("expected:\t%s\n", expected);
	printf("actual:  \t%s\n", actual);
	if (strcmp(expected, actual) != 0)
		printf("\n\nYour implementation is not match with c lib!!\n\n");
	if (willFree){
		SAFE_FREE(expected);
		SAFE_FREE(actual);
	}
}

void compareStrNBytesAndFree(char* expected, char* actual, int n, bool willFree){
	printf("expected:\t");
	for (int idx = 0; idx < n ; idx++)
		printf("%c", expected[idx]);
	newLine(1);
	
	printf("actual:  \t");
	for (int idx = 0; idx < n ; idx++)
		printf("%c", actual[idx]);
	newLine(1);

	// compare
	for (int idx = 0; idx < n ; idx++)
		if (expected[idx] != actual[idx]){
			printf("\n\nYour implementation is not match with c lib!!\n\n");
			break;
		}
	if (willFree){
		SAFE_FREE(expected);
		SAFE_FREE(actual);
	}
}

int main()
{
	char str1[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str2[50] = "0123456789";

	// memset
	printTitle("memset");
	char* memset_expected 	= strdup(str1);
	char* memset_actual 	= strdup(str1);
	char memset_c = '1';
	memset(memset_expected+1, memset_c, 2);
	ft_memset(memset_actual+1, memset_c, 2);
	compareStrAndFree(memset_expected, memset_actual, true);
	
	// bzero
	printTitle("bzero");
	char* bzero_expected 	= strdup(str1);
	char* bzero_actual 		= strdup(str1);
	bzero(bzero_expected+3, 2);
	ft_bzero(bzero_actual+3, 2);
	compareStrAndFree(bzero_expected, bzero_actual, true);

	// memcpy
	printTitle("memcpy");
	char* memcpy_expected 	= strdup(str1);
	char* memcpy_actual 	= strdup(str1);
	char memcpy_str[] 		= "!!!!!!";
	memcpy(memcpy_expected+3, memcpy_str, 2);
	ft_memcpy(memcpy_actual+3, memcpy_str, 2);
	compareStrAndFree(memcpy_expected, memcpy_actual, true);
	// memcpy_str が空の場合
	char* memcpy_expected2 	= strdup(str1);
	char* memcpy_actual2 	= strdup(str1);
	char memcpy_str2[] 		= "";
	memcpy(memcpy_expected2+3, memcpy_str2, 0);
	ft_memcpy(memcpy_actual2+3, memcpy_str2, 0);
	compareStrAndFree(memcpy_expected2, memcpy_actual2, true);

	// memccpy
	printTitle("memccpy");
	char* memccpy_expected 	= calloc(strlen(str1)+1, sizeof(char));
	char* memccpy_actual 	= calloc(strlen(str1)+1, sizeof(char));
	char memccpy_c 		= 'D';
	memccpy(memccpy_expected, str1, memccpy_c, 10);
	ft_memccpy(memccpy_actual, str1, memccpy_c, 10);
	compareStrNBytesAndFree(memccpy_expected, memccpy_actual, 27, true);

	// memmove
	// http://www.orchid.co.jp/computer/cschool/CREF/memmove.html
	printTitle("memmove");
	char* memmove_expected 	= strdup(str1);
	char* memmove_actual 	= strdup(str1);
	memmove(memmove_expected+1, memmove_expected, 24);
	ft_memmove(memmove_actual+1, memmove_actual, 24);
	compareStrAndFree(memmove_expected, memmove_actual, true);

	// memchr
	printTitle("memchr");
	char memchr_c = 'C';
	char* memchr_expected = memchr(str1, memchr_c, 27);
	char* memchr_actual =ft_memchr(str1, memchr_c, 27);
	printf("expected: %c\t(%p)\n", *memchr_expected, memchr_expected);
	printf("actual:   %c\t(%p)\n", *memchr_actual, memchr_actual);
	// マッチしなかったとき
	char memchr_c2 = '!';
	char* memchr_expected2 = memchr(str1, memchr_c2, 27);
	char* memchr_actual2 =ft_memchr(str1, memchr_c2, 27);
	printf("expected: \t(%p)\n", memchr_expected2);
	printf("actual:   \t(%p)\n", memchr_actual2);

	// memcmp
	printTitle("memcmp");
	int memcmp_expected = memcmp("ABC", "ABD", 3);
	int memcmp_actual = ft_memcmp("ABC", "ABD", 3);
	compareInt(memcmp_expected, memcmp_actual);
	int memcmp_expected2 = memcmp("ABC", "ABC", 3);
	int memcmp_actual2 = ft_memcmp("ABC", "ABC", 3);
	compareInt(memcmp_expected2, memcmp_actual2);

	// strlen
	printTitle("strlen");
	size_t strlen_expected = strlen(str1);
	size_t strlen_actual = ft_strlen(str1);
	compareInt(strlen_expected, strlen_actual);
	size_t strlen_expected2 = strlen("");
	size_t strlen_actual2 = ft_strlen("");
	compareInt(strlen_expected2, strlen_actual2);

	// strlcpy
	printTitle("strlcpy");
	char* strlcpy_expected 	= strdup(str1);
	char* strlcpy_actual 	= strdup(str1);
	printf("%s\n", strlcpy_expected);
	strlcpy(strlcpy_expected, str2, 10);
    ft_strlcpy(strlcpy_actual, str2, 10);
	compareStrAndFree(strlcpy_expected, strlcpy_actual, true);

	// strlcat
	printTitle("strlcat");
	char strlcat_expected[50] 	= "ABCDEFG";
	char strlcat_actual[50] 	= "ABCDEFG";
	strlcat(strlcat_expected, str2, sizeof(strlcat_expected));
    ft_strlcat(strlcat_actual, str2, sizeof(strlcat_actual));
	compareStrAndFree(strlcat_expected, strlcat_actual, false);

	// strchr
	printTitle("strchr");
	char* strchr_str = "ZAAZ";
	char* strchr_expected = strchr(strchr_str, 'Z');
	char* strchr_actual = ft_strchr(strchr_str, 'Z');
	printf("expected:\t%p\n", strchr_expected);
	printf("actual:  \t%p\n", strchr_actual);
	compareStrAndFree(strchr_expected, strchr_actual, false);
	char* strchr_expected2 = strchr(str1, '!');
	char* strchr_actual2 = ft_strchr(str1, '!');
	printf("expected:\t%p\n", strchr_expected2);
	printf("actual:  \t%p\n", strchr_actual2);
	
	// strrchr
	printTitle("strrchr");
	char* strrchr_str = "ZAAZ";
	char* strrchr_expected = strrchr(strrchr_str, 'Z');
	char* strrchr_actual = ft_strrchr(strrchr_str, 'Z');
	printf("expected:\t%p\n", strrchr_expected);
	printf("actual:  \t%p\n", strrchr_actual);
	compareStrAndFree(strrchr_expected, strrchr_actual, false);
	char* strrchr_expected2 = strrchr(str1, '!');
	char* strrchr_actual2 = ft_strrchr(str1, '!');
	printf("expected:\t%p\n", strrchr_expected2);
	printf("actual:  \t%p\n", strrchr_actual2);

	// strnstr
	// https://kaworu.jpn.org/doc/FreeBSD/jman/man3/strstr.3.php
	printTitle("strnstr");
	char* strnstr_expected = strnstr(str1, "EFG", 10);
	char* strnstr_actual = ft_strnstr(str1, "EFG", 10);
	printf("expected:\t%p\n", strnstr_expected);
	printf("actual:  \t%p\n", strnstr_actual);
	char* strnstr_expected2 = strnstr(str1, "ABC", 2);
	char* strnstr_actual2 = ft_strnstr(str1, "ABC", 2);
	printf("expected:\t%p\n", strnstr_expected2);
	printf("actual:  \t%p\n", strnstr_actual2);
	char* strnstr_expected3 = strnstr(str1, "", 2);
	char* strnstr_actual3 = ft_strnstr(str1, "", 2);
	printf("expected:\t%p\n", strnstr_expected3);
	printf("actual:  \t%p\n", strnstr_actual3);

	// strncmp
	int strncmp_expected = strncmp("ABCD", "ABC", 10);
	printTitle("strncmp");
	int strncmp_actual = ft_strncmp("ABCD", "ABC", 10);
	compareInt(strncmp_expected, strncmp_actual);
	int strncmp_expected2 = strncmp("ABC", "ABCCCCCCCCCCCCC", 3);
	int strncmp_actual2 = ft_strncmp("ABC", "ABCCCCCCCCCCCCC", 3);
	compareInt(strncmp_expected2, strncmp_actual2);

	// atoi
	printTitle("atoi");
	char atoi_input0[] = "12345";
	char atoi_input1[] = "500.5abc";
	char atoi_input2[] = "2468";
	char atoi_input3[] = "-1234";
	char atoi_input4[] = "+1234";
	char atoi_input5[] = "abc";
	int atoi_expected0 = atoi(atoi_input0);
	int atoi_actual0 = ft_atoi(atoi_input0);
	compareInt(atoi_expected0, atoi_actual0);
	int atoi_expected1 = atoi(atoi_input1);
	int atoi_actual1 = ft_atoi(atoi_input1);
	compareInt(atoi_expected1, atoi_actual1);
	int atoi_expected2 = atoi(atoi_input2);
	int atoi_actual2 = ft_atoi(atoi_input2);
	compareInt(atoi_expected2, atoi_actual2);
	int atoi_expected3 = atoi(atoi_input3);
	int atoi_actual3 = ft_atoi(atoi_input3);
	compareInt(atoi_expected3, atoi_actual3);
	int atoi_expected4 = atoi(atoi_input4);
	int atoi_actual4 = ft_atoi(atoi_input4);
	compareInt(atoi_expected4, atoi_actual4);
	int atoi_expected5 = atoi(atoi_input5);
	int atoi_actual5 = ft_atoi(atoi_input5);
	compareInt(atoi_expected5, atoi_actual5);

	// isalpha
	printTitle("isalpha");
	int isalpha_expected0 = isalpha('A');
	int isalpha_actual0 = ft_isalpha('A');
	compareInt(isalpha_expected0 != 0 ? 1 : 0, isalpha_actual0 != 0 ? 1 : 0);
	int isalpha_expected1 = isalpha('z');
	int isalpha_actual1 = ft_isalpha('z');
	compareInt(isalpha_expected1 != 0 ? 1 : 0, isalpha_actual1 != 0 ? 1 : 0);
	int isalpha_expected2 = isalpha('^');
	int isalpha_actual2 = ft_isalpha('^');
	compareInt(isalpha_expected2 != 0 ? 1 : 0, isalpha_actual2 != 0 ? 1 : 0);
	int isalpha_expected3 = isalpha('\n');
	int isalpha_actual3 = ft_isalpha('\n');
	compareInt(isalpha_expected3 != 0 ? 1 : 0, isalpha_actual3 != 0 ? 1 : 0);
	
	// isdigit
	printTitle("isdigit");
	int isdigit_expected0 = isdigit('0');
	int isdigit_actual0 = ft_isdigit('0');
	compareInt(isdigit_expected0 != 0 ? 1 : 0, isdigit_actual0 != 0 ? 1 : 0);
	int isdigit_expected1 = isdigit('9');
	int isdigit_actual1 = ft_isdigit('9');
	compareInt(isdigit_expected1 != 0 ? 1 : 0, isdigit_actual1 != 0 ? 1 : 0);
	int isdigit_expected2 = isdigit('A');
	int isdigit_actual2 = ft_isdigit('A');
	compareInt(isdigit_expected2 != 0 ? 1 : 0, isdigit_actual2 != 0 ? 1 : 0);
	int isdigit_expected3 = isdigit('\n');
	int isdigit_actual3 = ft_isdigit('\n');
	compareInt(isdigit_expected3 != 0 ? 1 : 0, isdigit_actual3 != 0 ? 1 : 0);

	// isalnum
	printTitle("isalnum");
	int isalnum_expected0 = isalnum('0');
	int isalnum_actual0 = ft_isalnum('0');
	compareInt(isalnum_expected0 != 0 ? 1 : 0, isalnum_actual0 != 0 ? 1 : 0);
	int isalnum_expected1 = isalnum('9');
	int isalnum_actual1 = ft_isalnum('9');
	compareInt(isalnum_expected1 != 0 ? 1 : 0, isalnum_actual1 != 0 ? 1 : 0);
	int isalnum_expected2 = isalnum('A');
	int isalnum_actual2 = ft_isalnum('A');
	compareInt(isalnum_expected2 != 0 ? 1 : 0, isalnum_actual2 != 0 ? 1 : 0);
	int isalnum_expected3 = isalnum('\n');
	int isalnum_actual3 = ft_isalnum('\n');
	compareInt(isalnum_expected3 != 0 ? 1 : 0, isalnum_actual3 != 0 ? 1 : 0);

	// isascii
	printTitle("isascii");
	int isascii_expected0 = isascii('0');
	int isascii_actual0 = ft_isascii('0');
	compareInt(isascii_expected0 != 0 ? 1 : 0, isascii_actual0 != 0 ? 1 : 0);
	int isascii_expected1 = isascii('9');
	int isascii_actual1 = ft_isascii('9');
	compareInt(isascii_expected1 != 0 ? 1 : 0, isascii_actual1 != 0 ? 1 : 0);
	int isascii_expected2 = isascii('A');
	int isascii_actual2 = ft_isascii('A');
	compareInt(isascii_expected2 != 0 ? 1 : 0, isascii_actual2 != 0 ? 1 : 0);
	int isascii_expected3 = isascii('\n');
	int isascii_actual3 = ft_isascii('\n');
	compareInt(isascii_expected3 != 0 ? 1 : 0, isascii_actual3 != 0 ? 1 : 0);
	int isascii_expected4 = isascii(127);
	int isascii_actual4 = ft_isascii(127);
	compareInt(isascii_expected4 != 0 ? 1 : 0, isascii_actual4 != 0 ? 1 : 0);
	int isascii_expected5 = isascii(128);
	int isascii_actual5 = ft_isascii(128);
	compareInt(isascii_expected5 != 0 ? 1 : 0, isascii_actual5 != 0 ? 1 : 0);
	int isascii_expected6 = isascii(0);
	int isascii_actual6 = ft_isascii(0);
	compareInt(isascii_expected6 != 0 ? 1 : 0, isascii_actual6 != 0 ? 1 : 0);

	// isprint
	printTitle("isprint");
	int isprint_expected0 = isprint('0');
	int isprint_actual0 = ft_isprint('0');
	compareInt(isprint_expected0 != 0 ? 1 : 0, isprint_actual0 != 0 ? 1 : 0);
	int isprint_expected1 = isprint('9');
	int isprint_actual1 = ft_isprint('9');
	compareInt(isprint_expected1 != 0 ? 1 : 0, isprint_actual1 != 0 ? 1 : 0);
	int isprint_expected2 = isprint('A');
	int isprint_actual2 = ft_isprint('A');
	compareInt(isprint_expected2 != 0 ? 1 : 0, isprint_actual2 != 0 ? 1 : 0);
	int isprint_expected3 = isprint('\n');
	int isprint_actual3 = ft_isprint('\n');
	compareInt(isprint_expected3 != 0 ? 1 : 0, isprint_actual3 != 0 ? 1 : 0);
	int isprint_expected4 = isprint('~');
	int isprint_actual4 = ft_isprint('~');
	compareInt(isprint_expected4 != 0 ? 1 : 0, isprint_actual4 != 0 ? 1 : 0);
	int isprint_expected5 = isprint('\0');
	int isprint_actual5 = ft_isprint('\0');
	compareInt(isprint_expected5 != 0 ? 1 : 0, isprint_actual5 != 0 ? 1 : 0);

	// toupper
	printTitle("toupper");
	char toupper_expected0 = toupper('0');
	char toupper_actual0 = ft_toupper('0');
	compareChar(toupper_expected0, toupper_actual0);
	char toupper_expected1 = toupper('a');
	char toupper_actual1 = ft_toupper('a');
	compareChar(toupper_expected1, toupper_actual1);
	char toupper_expected2 = toupper('A');
	char toupper_actual2 = ft_toupper('A');
	compareChar(toupper_expected2, toupper_actual2);
	char toupper_expected3 = toupper('\t');
	char toupper_actual3 = ft_toupper('\t');
	compareChar(toupper_expected3, toupper_actual3);
	char toupper_expected4 = toupper('~');
	char toupper_actual4 = ft_toupper('~');
	compareChar(toupper_expected4, toupper_actual4);
	char toupper_expected5 = toupper('z');
	char toupper_actual5 = ft_toupper('z');
	compareChar(toupper_expected5, toupper_actual5);

	// tolower
	printTitle("tolower");
	char tolower_expected0 = tolower('0');
	char tolower_actual0 = ft_tolower('0');
	compareChar(tolower_expected0, tolower_actual0);
	char tolower_expected1 = tolower('a');
	char tolower_actual1 = ft_tolower('a');
	compareChar(tolower_expected1, tolower_actual1);
	char tolower_expected2 = tolower('A');
	char tolower_actual2 = ft_tolower('A');
	compareChar(tolower_expected2, tolower_actual2);
	char tolower_expected3 = tolower('\t');
	char tolower_actual3 = ft_tolower('\t');
	compareChar(tolower_expected3, tolower_actual3);
	char tolower_expected4 = tolower('~');
	char tolower_actual4 = ft_tolower('~');
	compareChar(tolower_expected4, tolower_actual4);
	char tolower_expected5 = tolower('Z');
	char tolower_actual5 = ft_tolower('Z');
	compareChar(tolower_expected5, tolower_actual5);
	
	return 0;
}