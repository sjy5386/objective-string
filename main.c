#include <stdio.h>
#include "ostring.c"

int main(int argc, char **argv) {
    int i;
    String **arr;

    /* Examples */
    String *str1 = newString("Hello, world!");
    String *str2 = newString("Bye, world?");
    String *str3 = newString("objective-string");
    String *str4;

    printf("str1: %s\n", str1->get(str1));

    str1->set(str1, "Bye, world?");
    printf("str1: %s\n", str1->get(str1));

    printf("Length of str1: %d\n", str1->length(str1));

    printf("Comparing str1 and str2: %s %d\n", str1->equals(str1, str2) ? "true" : "false", str1->compareTo(str1, str2));
    printf("Comparing str1 and str3: %s %d\n", str1->equals(str1, str3) ? "true" : "false", str1->compareTo(str1, str3));

    printf("str1[0]: %c\n", str1->charAt(str1, 0));

    printf("w: %d\n", str1->indexOf(str1, 'w'));

    str4 = str1->concat(str1, str2);
    printf("str1 + str2: %s\n", str4->get(str4));
    deleteString(str4);

    str4 = str1->substring(str1, 5, 10);
    printf("str1[5..10]: %s\n", str4->get(str4));
    deleteString(str4);

    arr = str1->split(str1, ", ");
    for (i = 0; arr[i] != NULL; i++) {
        printf("%s\n", arr[i]->get(arr[i]));
        deleteString(arr[i]);
    }
    free(arr);

    deleteString(str1);
    deleteString(str2);
    deleteString(str3);

    return 0;
}
