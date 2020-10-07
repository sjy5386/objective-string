/*
 * ostring.h
 *
 *  Created on: Oct 2, 2020
 *      Author: Seokjin Yoon
 */

#ifndef OSTRING_H_
#define OSTRING_H_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct String {
    /* field */
    struct String *this;
    char *str;

    /* method */
    const char *(*get)(struct String *);

    void (*set)(struct String *, const char *);

    size_t (*length)(struct String *);

    bool (*equals)(struct String *, struct String *);

    int (*compareTo)(struct String *, struct String *);

    char (*charAt)(struct String *, int);

    int (*indexOf)(struct String *, char);

    struct String *(*concat)(struct String *, struct String *);

    struct String *(*substring)(struct String *, int, int);

    struct String **(*split)(struct String *, const char *);

    struct String *(*toLowerCase)(struct String *);

    struct String *(*toUpperCase)(struct String *);

    struct String *(*trim)(struct String *);
} String;

String *newString(const char *);

void deleteString(String *);

static const char *String_get(String *);

static void String_set(String *, const char *);

static size_t String_length(String *);

static bool String_equals(String *, String *);

static int String_compareTo(String *, String *);

static char String_charAt(String *, int);

static int String_indexOf(String *, char);

static String *String_concat(String *, String *);

static String *String_substring(String *, int, int);

static String **String_split(String *, const char *);

static String *String_toLowerCase(String *);

static String *String_toUpperCase(String *);

static String *String_trim(String *);

#endif // OSTRING_H_
