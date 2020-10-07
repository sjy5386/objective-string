/*
 * ostring.c
 *
 *  Created on: Sep 29, 2020
 *      Author: Seokjin Yoon
 */

#include "ostring.h"

String *newString(const char *str) { // constructor
    String *this = (String *) malloc(sizeof(String));
    this->this = this;
    this->str = (char *) malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(this->str, str);

    this->get = getString;
    this->set = setString;
    this->length = lengthString;
    this->equals = equalsString;
    this->compareTo = compareToString;
    this->charAt = charAtString;
    this->indexOf = indexOfString;
    this->concat = concatString;
    this->substring = substringString;
    this->split = splitString;
    this->toLowerCase = toLowerCaseString;
    this->toUpperCase = toUpperCaseString;

    return this;
}

void deleteString(String *this) { // destructor
    if (this->str) {
        free(this->str);
        this->str = NULL;
    }
    if (this) {
        free(this);
        this = NULL;
    }
}

static const char *getString(String *this) { // getter
    if (!this) {
        return NULL;
    }
    return this->str;
}

static void setString(String *this, const char *str) { // setter
    if (!this) {
        return;
    }

    if (this->str) {
        free(this->str);
        this->str = NULL;
    }
    this->str = (char *) malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(this->str, str);
}

static size_t lengthString(String *this) {
    if (!this) {
        return 0;
    }
    return strlen(this->str);
}

static bool equalsString(String *this, String *str) {
    if (!this || !str) {
        return false;
    }
    return strcmp(this->str, str->str) == 0;
}

static int compareToString(String *this, String *str) {
    return strcmp(this->str, str->str);
}

static char charAtString(String *this, int index) {
    if (!this || (index > strlen(this->str))) {
        return '\0';
    }
    return this->str[index];
}

static int indexOfString(String *this, char c) {
    char str2[2] = {
            c, '\0'
    };
    if (!this) {
        return 0;
    }
    return strcspn(this->str, str2);
}

static String *concatString(String *this, String *str) {
    char *buf = NULL;
    String *s = NULL;

    if (!this || !str) {
        return NULL;
    }

    buf = (char *) malloc(sizeof(char) * (strlen(this->str) + strlen(str->str) + 1));
    strcpy(buf, this->str);
    strcat(buf, str->str);
    s = newString(buf);
    free(buf);
    buf = NULL;
    return s;
}

static String *substringString(String *this, int begin, int end) {
    int len = end - begin;
    char *buf = NULL;
    String *str = NULL;

    if (!this || (begin < 0) || (end > strlen(this->str)) || (begin >= end)) {
        return NULL;
    }

    buf = (char *) malloc(sizeof(char) * (len + 1));
    strncpy(buf, &this->str[begin], len);
    buf[len] = '\0';
    str = newString(buf);
    free(buf);
    buf = NULL;
    return str;
}

static String **splitString(String *this, const char *delim) {
    char *buf = NULL, *p = NULL;
    int i = 0;
    String **arr = NULL;

    if (!this) {
        return NULL;
    }

    buf = (char *) malloc(sizeof(char) * (strlen(this->str) + 1));
    strcpy(buf, this->str);
    p = strtok(buf, delim);
    for (i = 0; p; i++) {
        p = strtok(NULL, delim);
    }

    strcpy(buf, this->str);
    arr = (String **) malloc(sizeof(String *) * (i + 1));
    p = strtok(buf, delim);
    for (i = 0; p; i++) {
        arr[i] = newString(p);
        p = strtok(NULL, delim);
    }
    arr[i] = NULL;
    free(buf);
    buf = NULL;
    return arr;
}

static String *toLowerCaseString(String *this) {
    char *buf = NULL, *p = this->str, *q = NULL;
    String *str = NULL;

    if (!this) {
        return NULL;
    }

    buf = (char *) malloc(sizeof(char) * (strlen(this->str) + 1));
    q = buf;
    while (*p) {
        *q = tolower(*p);
        p++;
        q++;
    }
    str = newString(buf);
    free(buf);
    buf = NULL;
    return str;
}

static String *toUpperCaseString(String *this) {
    char *buf = NULL, *p = this->str, *q = NULL;
    String *str = NULL;

    if (!this) {
        return NULL;
    }

    buf = (char *) malloc(sizeof(char) * (strlen(this->str) + 1));
    q = buf;
    while (*p) {
        *q = toupper(*p);
        p++;
        q++;
    }
    str = newString(buf);
    free(buf);
    buf = NULL;
    return str;
}
