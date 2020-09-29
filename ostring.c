#include <stdlib.h>
#include <string.h>

typedef struct String {
    struct String *this;
    char *str;

    const char * (*get)(struct String *);
    void (*set)(struct String *, const char *);
    size_t (*length)(struct String *);
} String;

static const char * getString(String *this) {
    return this->str;
}

static void setString(String *this, const char *str) {
    size_t length = strlen(str);
    free(this->str);
    this->str = (char *) malloc(sizeof(char) * length);
    strncpy(this->str, str, length);
}

static size_t lengthString(String *this) {
    return strlen(this->str);
}

String * newString(const char *str) {
    String *this = (String *) malloc(sizeof(String));
    size_t length = strlen(str);
    this->this = this;
    this->str = (char *) malloc(sizeof(char) * length);
    strncpy(this->str, str, length);
    this->get = getString;
    this->set = setString;
    this->length = lengthString;
    return this;
}

void deleteString(String *this) {
    free(this->str);
    free(this);
}
