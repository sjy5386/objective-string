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

    this->get = String_get;
    this->set = String_set;
    this->length = String_length;
    this->equals = String_equals;
    this->compareTo = String_compareTo;
    this->charAt = String_charAt;
    this->indexOf = String_indexOf;
    this->concat = String_concat;
    this->substring = String_substring;
    this->split = String_split;
    this->toLowerCase = String_toLowerCase;
    this->toUpperCase = String_toUpperCase;
    this->trim = String_trim;

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

static const char *String_get(String *this) { // getter
    if (!this) {
        return NULL;
    }
    return this->str;
}

static void String_set(String *this, const char *str) { // setter
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

static size_t String_length(String *this) {
    if (!this) {
        return 0;
    }
    return strlen(this->str);
}

static bool String_equals(String *this, String *str) {
    if (!this || !str) {
        return false;
    }
    return strcmp(this->str, str->str) == 0;
}

static int String_compareTo(String *this, String *str) {
    return strcmp(this->str, str->str);
}

static char String_charAt(String *this, int index) {
    if (!this || (index > strlen(this->str))) {
        return '\0';
    }
    return this->str[index];
}

static int String_indexOf(String *this, char c) {
    char str2[2] = {
            c, '\0'
    };
    if (!this) {
        return 0;
    }
    return strcspn(this->str, str2);
}

static String *String_concat(String *this, String *str) {
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

static String *String_substring(String *this, int begin, int end) {
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

static String **String_split(String *this, const char *delim) {
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

static String *String_toLowerCase(String *this) {
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

static String *String_toUpperCase(String *this) {
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

static String *String_trim(String *this) {
    int begin = 0, end = 0;

    if (!this) {
        return NULL;
    }

    begin = strspn(this->str, " ");
    for (end = strlen(this->str); (end - 1 >= 0) && (this->str[end - 1] == ' '); end--);
    return String_substring(this, begin, end);
}
