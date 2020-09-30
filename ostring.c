#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct String {
    struct String *this;
    char *str;

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

String * newString(const char *str) {
    String *this = (String *) malloc(sizeof(String));
    this->this = this;
    this->str = (char *) malloc(sizeof(char) * strlen(str));
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
    return this;
}

void deleteString(String *this) {
    free(this->str);
    free(this);
}

static const char * getString(String *this) {
    return this->str;
}

static void setString(String *this, const char *str) {
    free(this->str);
    this->str = (char *) malloc(sizeof(char) * strlen(str));
    strcpy(this->str, str);
}

static size_t lengthString(String *this) {
    return strlen(this->str);
}

static bool equalsString(String *this, String *str) {
    return strcmp(this->str, str->str) == 0;
}

static int compareToString(String *this, String *str) {
    return strcmp(this->str, str->str);
}

static char charAtString(String *this, int index) {
    return this->str[index];
}

static int indexOfString(String *this, char c) {
    char str2[2] = {
        c, NULL
    };
    return strcspn(this->str, str2);
}

static String * concatString(String *this, String *str) {
    int len = strlen(this->str) + strlen(str->str);
    char *buf = (char *) malloc(sizeof(char) * len);
    String *s;
    strcpy(buf, this->str);
    strcpy(strchr(buf, NULL), str->str);
    s = newString(buf);
    free(buf);
    return s;
}

static String * substringString(String *this, int begin, int end) {
    int len = end - begin + 1;
    char *buf;
    String *str;
    if ((end > strlen(this->str)) || (begin >= end)) {
        return NULL;
    }
    buf = (char *) malloc(sizeof(char) * len);
    strncpy(buf, &this->str[begin], len);
    buf[end - begin] = NULL;
    str = newString(buf);
    free(buf);
    return str;
}

static String ** splitString(String *this, const char *delim) {
    char *str = (char *) malloc(sizeof(char) * strlen(this->str));
    int i;
    char *p;
    String **arr;
    strcpy(str, this->str);
    p = strtok(str, delim);
    for (i = 0; p != NULL; i++) {
        p = strtok(NULL, delim);
    }

    strcpy(str, this->str);
    arr = (String **) malloc(sizeof(String *) * (i + 1));
    p = strtok(str, delim);
    for (i = 0; p != NULL; i++) {
        arr[i] = newString(p);
        p = strtok(NULL, delim);
    }
    arr[i] = NULL;
    free(str);
    return arr;
}
