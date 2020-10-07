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
} String;

String *newString(const char *);

void deleteString(String *);

static const char *String_get(String *this);

static void String_set(String *this, const char *str);

static size_t String_length(String *this);

static bool String_equals(String *this, String *str);

static int String_compareTo(String *this, String *str);

static char String_charAt(String *this, int index);

static int String_indexOf(String *this, char c);

static String *String_concat(String *this, String *str);

static String *String_substring(String *this, int begin, int end);

static String **String_split(String *this, const char *delim);

static String *String_toLowerCase(String *this);

static String *String_toUpperCase(String *this);

#endif // OSTRING_H_
