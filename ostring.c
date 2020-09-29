#include <stdlib.h>
#include <string.h>

typedef struct String {
    struct String *this;
    char *str;

    const char * (*get)(struct String *);
    void (*set)(struct String *, const char *);
} String;

static const char * getString(String *this) {
    return this->str;
}

static void setString(String *this, const char *str) {
    int length = strlen(str);
    free(this->str);
    this->str = (char *) malloc(sizeof(char) * length);
    strncpy(this->str, str, length);
}

String * newString(const char *str) {
    String *this = (String *) malloc(sizeof(String));
    int length = strlen(str);
    this->this = this;
    this->str = (char *) malloc(sizeof(char) * length);
    strncpy(this->str, str, length);
    this->get = getString;
    this->set = setString;
    return this;
}

void deleteString(String *this) {
    free(this->str);
    free(this);
}
