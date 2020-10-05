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

void compareStrAndFree(char* expected, char* actual){
	printf("expected:\t%s\n", expected);
	printf("actual:  \t%s\n", actual);
	if (strcmp(expected, actual) != 0)
		printf("\n\nYour implementation is not match with c lib!!\n\n");
	SAFE_FREE(expected);
	SAFE_FREE(actual);
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
	char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str2[] = "0123456789";

	// memset
	printTitle("memset");
	char* memset_expected 	= strdup(str1);
	char* memset_actual 	= strdup(str1);
	char memset_c = '1';
	memset(memset_expected+1, memset_c, 2);
	ft_memset(memset_actual+1, memset_c, 2);
	compareStrAndFree(memset_expected, memset_actual);
	
	// bzero
	printTitle("bzero");
	char* bzero_expected 	= strdup(str1);
	char* bzero_actual 		= strdup(str1);
	bzero(bzero_expected+3, 2);
	ft_bzero(bzero_actual+3, 2);
	compareStrAndFree(bzero_expected, bzero_actual);

	// memcpy
	printTitle("memcpy");
	char* memcpy_expected 	= strdup(str1);
	char* memcpy_actual 	= strdup(str1);
	char memcpy_str[] 		= "!!!!!!";
	memcpy(memcpy_expected+3, memcpy_str, 2);
	ft_memcpy(memcpy_actual+3, memcpy_str, 2);
	compareStrAndFree(memcpy_expected, memcpy_actual);
	// memcpy_str が空の場合
	char* memcpy_expected2 	= strdup(str1);
	char* memcpy_actual2 	= strdup(str1);
	char memcpy_str2[] 		= "";
	memcpy(memcpy_expected2+3, memcpy_str2, 0);
	ft_memcpy(memcpy_actual2+3, memcpy_str2, 0);
	compareStrAndFree(memcpy_expected2, memcpy_actual2);

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
	compareStrAndFree(memmove_expected, memmove_actual);

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
	compareStrAndFree(strlcpy_expected, strlcpy_actual);

	// strlcat

	// strchr

	return 0;
}
