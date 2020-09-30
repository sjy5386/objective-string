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
    char (*charAt)(struct String *, int);
} String;

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

static char charAtString(String *this, int index) {
    return this->str[index];
}

String * newString(const char *str) {
    String *this = (String *) malloc(sizeof(String));
    this->this = this;
    this->str = (char *) malloc(sizeof(char) * strlen(str));
    strcpy(this->str, str);
    this->get = getString;
    this->set = setString;
    this->length = lengthString;
    this->equals = equalsString;
    this->charAt = charAtString;
    return this;
}

void deleteString(String *this) {
    free(this->str);
    free(this);
}
