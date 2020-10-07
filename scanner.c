/*
 * scanner.c
 *
 *  Created on: Aug 7, 2020
 *      Author: Seokjin Yoon
 */

#include "scanner.h"

Scanner *newScanner(FILE *src) {
    Scanner *this = (Scanner *) malloc(sizeof(Scanner));
    this->src = src;
    this->close = deleteScanner;
    return this;
}

void deleteScanner(Scanner *this) {
    if (this) {
        free(this);
        this = NULL;
    }
}
