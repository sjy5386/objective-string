/*
 * scanner.h
 *
 *  Created on: Aug 7, 2020
 *      Author: Seokjin Yoon
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdio.h>

#define SYSTEM_IN stdin
#define SYSTEM_OUT stdout
#define SYSTEM_ERR stderr

typedef struct Scanner {
    /* field */
    struct Scanner *this;
    FILE *src;
} Scanner;

#endif // SCANNER_H
