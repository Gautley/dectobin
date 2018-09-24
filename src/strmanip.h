#ifndef STRMANIP_H
#define STRMANIP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *str_rev(char *str)
{
    size_t stringLen = strlen(str);
    size_t i;
    size_t j = stringLen-1;
    char *reversed = (char *)malloc(sizeof(char) * (stringLen+1));

    for(i = 0; i < stringLen; i++, j--)
        reversed[i] = str[j];

    return reversed;
}
#endif
