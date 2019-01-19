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

char *str_repeat_char(char letter, unsigned int times)
{
    char *charsRepeated = malloc(sizeof(char) * (times + 1));
    memset(charsRepeated, letter, times);
    return charsRepeated;
}

char *strcat_at_begin(char *str, char *strToCat)
{
    char *mergedString = malloc(
        sizeof(char) * (strlen(str) + strlen(strToCat) + 1)
    );
    mergedString[0] = '\0';

    mergedString = strcat(mergedString, strToCat);
    mergedString = strcat(mergedString, str);

    return mergedString;
}

#endif
