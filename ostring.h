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
    const char * (*get)(struct String *);
    void (*set)(struct String *, const char *);
    size_t (*length)(struct String *);
    bool (*equals)(struct String *, struct String *);
    int (*compareTo)(struct String *, struct String *);
    char (*charAt)(struct String *, int);
    int (*indexOf)(struct String *, char);
    struct String * (*concat)(struct String *, struct String *);
    struct String * (*substring)(struct String *, int, int);
    struct String ** (*split)(struct String *, const char *);
    struct String * (*toLowerCase)(struct String *);
    struct String * (*toUpperCase)(struct String *);
} String;

String * newString(const char *);
void deleteString(String *);

static const char * getString(String *);
static void setString(String *, const char *);
static size_t lengthString(String *);
static bool equalsString(String *, String *);
static int compareToString(String *, String *);
static char charAtString(String *, int);
static int indexOfString(String *, char);
static String * concatString(String *, String *);
static String * substringString(String *, int, int);
static String ** splitString(String *, const char *);
static String * toLowerCaseString(String *);
static String * toUpperCaseString(String *);

#endif // OSTRING_H_
