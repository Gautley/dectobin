// gaut.: 27/01/2018
// gaut.: if u don't understand what you did here, read getopt(3).

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "strmanip.h"
#include "research.h"

#define VERSION "0.3b"
#define USAGE "dectobin NUM [-n] [-s SEPN] [--version] [--help]"

struct option const longOptions[] = {
    {"no-newline", no_argument, NULL, 'n'},
    {"splitted", required_argument, NULL, 's'},
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 1},
    {0, 0, 0, 0} // required by getopt
};

char *dec_to_bin(size_t decNum);
void dtbprint_version(void);
void dtbprint_usage(void);
void dtbprint_error(const char str[]);
void dtbprint_help(void);

int main(int argc, char** argv)
{
    char *argNumber;
    char *argSplitted;
    unsigned int optionNoNewLine = 0;
    unsigned int optionVersion = 0;
    unsigned int optionSplitted = 0;
    unsigned int optionHelp = 0;

    opterr = 0;
    char opt = 0;

    while((opt = getopt_long(argc, argv, ":vs:n", longOptions, NULL)) != -1)
    {
        switch(opt)
        {
            case 1:
                optionVersion++;
                break;

            case 'h':
                optionHelp++;
                dtbprint_help();
                return 0;

            case 'n':
                optionNoNewLine++;
                break;

            case 's':
                if(research("^[0-9]{1,2}$", optarg) == 0)
                {
                    optionSplitted++;
                    argSplitted = optarg;
                }
                else
                {
                    dtbprint_error("splitted arg must be a two-digits number!");
                    return 1;
                }
                break;
            
            case '?': // unknown option
                fprintf(
                    stderr,
                    "%s: %s: %s %c.\n",
                    "dectobin",
                    "error",
                    "Unknown option",
                    optopt
                );
                dtbprint_usage();
                return 1;

            case ':': // missing argument for option
                fprintf(
                    stderr,
                    "%s: %s: %s %c %s.\n",
                    "dectobin",
                    "error",
                    "The option",
                    optopt,
                    "requires an argument"
                );
                dtbprint_usage();
                return 1;

            default:
                dtbprint_usage();
                return 1;
        }
    }

    // Checking usage (at least one option given)
    if(
        optionVersion > 1
        || optionNoNewLine > 1
        || optionSplitted > 1
        || optionHelp > 1
    )
    {
        dtbprint_usage();
        return 1;
    }

    if(optionVersion == 1)
        dtbprint_version();

    // Checking Mandatory Argument (NUN) and its integrity.
    // It works 'cause getopt organizes the argv. So the global "optind" stores
    // the next element in argv to be processed. (after the getopt_long)
    {
        size_t nonOptionArguments = 0;

        for(size_t i = optind; i < argc; i++)
        {
            argNumber = argv[i];
            nonOptionArguments++;
        }

        if(nonOptionArguments != 1)
        {
            dtbprint_usage();
            return 1;
        }

        if(research("^[0-9]{1,18}$", argNumber) != 0)
        {
            dtbprint_error(
                "NUM must be a positive number. Max 18 digits."
            );
            return 1;
        }
    }


    if(optionSplitted == 0 || atoi(argSplitted) == 0)
    {
        printf("%s", dec_to_bin(atoi(argNumber)));
    }
    else
    {
        uint8_t j;
        size_t i;
        char *numberConverted = dec_to_bin(atoi(argNumber));

        for(i = 0, j = 1; i < strlen(numberConverted); i++, j++)
        {
            printf("%c", numberConverted[i]);
            if(j == atoi(argSplitted))
            {
                printf(" ");
                j = 0;
            }
        }
    }

    if(optionNoNewLine == 0)
    {
        printf("\n");
    }

	return 0;
}

char *dec_to_bin(size_t decNum)
{
	char *binNum = malloc(sizeof(char)*20);

	if(decNum == 0)
		return (char*)"0";

	while(decNum != 0)
	{
		if(decNum % 2 == 0)
			strcat(binNum, "0");
		else
		    strcat(binNum, "1");

			decNum /= 2;
	}

	return str_rev(binNum);
}

// "dectobin print"
void dtbprint(const char str[])
{
    printf("dectobin: %s\n", str);
}

void dtbprint_usage(void)
{
    dtbprint("Usage: "USAGE);
}

void dtbprint_version(void)
{
    dtbprint("Version: "VERSION);
}

void dtbprint_error(const char str[])
{
    fprintf(stderr, "%s: %s: %s\n", "dectobin", "Error", str);
}

void dtbprint_help(void)
{
    dtbprint_usage();
    dtbprint(
        "Help:\n"
        "NUM:\n"
            "    The integer & positive number to be converted. Max 18 "
            "digits.\n"
        "(-n|--no-newline):\n"
            "    No new line after binary number.\n"
        "(-s|--splitted) SEPN:\n"
            "    Inserts a space each SEPN numbers in output. Max 2 digits."
            "Also, it's an integer & positive number.\n"
        "--version:\n"
            "    Output version. Unlike most commands, you can combine "
            "this with others options.\n"
        "(-h|--help):\n"
            "    Output the usage and help (this message). Can't combine.\n"
    );
}
