#ifndef _RESEARCH_H_
#define _RESEARCH_H_

#include <regex.h>

int research(const char *regularExpression, char *string)
{
    regex_t reg;
    if(regcomp(&reg, regularExpression, REG_EXTENDED|REG_NOSUB) != 0)
    {
        fprintf(
            stderr,
            "%s: %s %s.\n",
            "research.h",
            "Couldn't compile",
            regularExpression
        );
        return -1; // error, cannot compile
    }
    
    if(regexec(&reg, string, 0, NULL, 0) == REG_NOMATCH)
        return 1; // miss
    else
        return 0; // match
}

#endif // _RESEARCH_H_
