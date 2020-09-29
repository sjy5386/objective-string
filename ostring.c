#include <stdlib.h>
#include <string.h>

typedef struct String {
    struct String *this;
    char *str;
} String;

String * newString(const char *str) {
    String *this = (String *) malloc(sizeof(String));
    int length = strlen(str);
    this->this = this;
    this->str = (char *) malloc(sizeof(char) * length);
    strncpy(this->str, str, length);
    return this;
}

void deleteString(String *this) {
    free(this->str);
    free(this);
}
