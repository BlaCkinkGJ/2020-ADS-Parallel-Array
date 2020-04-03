/**
 * @file parallel.h
 * @author 오기준 (kijunking@pusan.ac.kr)
 * @brief PA(Parallel Array)에서 사용되는 모든 함수에 대한 선언이 적혀있다.
 * @date 2020-04-03
 * 
 */

#ifndef PARALLEL_H_
#define PARALLEL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define MAX_CHAR_LEN 64 /**< 레코드에서 값을 받을j수 있는 최대 크기 */
#define MAX_ENTRY_SIZE 100000
#define NR_ITEMS 4
#define MAX_LINE_LEN (MAX_CHAR_LEN * NR_ITEMS)

#define TRIVIAL

#define FAIL_TO_SEARCH -1

/**
 * @brief trivial, improve의 함수를 선택할 수 있는 구조체이다.
 * 
 */
struct op {
	int (*init)(void); /**< 초기화를 수행한다. */
	int (*insert)(char *str, FILE *outp_fp); /**< PA에 insert를 수행한다. */
	int (*search)(char *str,
		      FILE *outp_fp); /**< PA에 search 수행, search도 겸한다. */
	int (*remove)(char *str, FILE *outp_fp); /**< PA에 remove를 수행한다. */
	void (*free)(void);
};

#ifdef TRIVIAL
int trivial_init(void);
int trivial_insert(char *str, FILE *outp_fp);
int trivial_search(char *str, FILE *outp_fp);
int trivial_remove(char *str, FILE *outp_fp);
void trivial_free(void);
#else
int improve_init(void);
int improve_insert(char *str, FILE *outp_fp);
int improve_search(char *str, FILE *outp_fp);
int improve_remove(char *str, FILE *outp_fp);
void improve_free(void);
#endif

static inline char *get_csv_field(char **strptr, const char *delim)
{
	char *ptr = *strptr;

	if (ptr == NULL) {
		return NULL;
	}

	while (**strptr) {
		if (strchr(delim, **strptr) != NULL) {
			**strptr = 0x00;
			(*strptr)++;
			return ptr;
		}
		(*strptr)++;
	}
	*strptr = NULL;

	return ptr;
}

#endif