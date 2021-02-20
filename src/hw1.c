// Caitlin Hruby
// chruby

#include "hw1.h"
#include <stdio.h>
#include <string.h>
// You may define any helper functions you want. Place them in helpers.c/.h

// Main program
int main(int argc, char *argv[]) {
    // Insert your hw1 code here
    
    int i;

    char valid_options1[7][3] = {"-l", "-c", "-w", "-a", "-L", "-f"};
    
    // if valid = 0, one of the options isn't valid,
    // if valid == 1, the options are valid
    int valid1 = 0; 
    int valid2 = 0;
                   
    int verbose = 0; // 0 if no -v, 1 if -v

    

    for (i = 0; i < 7; i++)
    {
        // if the first input is in the string of valid letters
        if (strcmp(argv[1], valid_options1[i]) == 0) 
        {
            valid1 = 1; // mark valid1 as true
        }
    }


    if (argc == 3) // if there are 3 args (2 flags)
    {
        // input2 = argv[2]; // input2 = second flag argument
        if (strcmp(argv[2], "-v") == 0)   // if the second argument is valid
        {
            valid2 = 1; // valid2 = 1, meaning second argument is valid
            verbose = 1;// if the second arg is valid, that means verbose is true
        }
    }


    if (valid1 == 0 || (valid2 == 0 && argc == 3) || argc > 3) // if either of the inputs are invalid
    {
        fprintf(stderr, USAGE_MSG);
        return 1;
    }
    else // if the inputs are valid
    {
        if (strcmp(argv[1], "-l") == 0)
        {
            int result = (count_all_lines(verbose));

            if (result > 0)
            {
                printf("%s %d\n", TOTAL_LINES_OPTION, result);
            }
            else
            {
                return 2;
            }
        }

        else if (strcmp(argv[1], "-c") == 0)
        {
            int result = count_non_empty_lines(verbose);

            if (result > 0)
            {
                printf("%s %d\n", NON_EMPTY_LINES_OPTION, result);
            }
            else
            {
                return 2;
            }
        }

        else if (strcmp(argv[1], "-w") == 0)
        {
            int result = max_line_width(verbose);
            if (result > 0)
            {
                printf("%s %d\n", MAX_LINE_WIDTH_OPTION, result);
            }
            else
            {
                return 2;
            }
        }

        else if (strcmp(argv[1], "-a") == 0)
        {
            int result = count_assignments(verbose);
            if (result > 0)
            {
                printf("%s %d\n", ASSIGNMENT_COUNT_OPTION, result);
            }
            else
            {
                return 2;
            }
        }

        else if (strcmp(argv[1], "-L") == 0)
        {
            // call a func called count_loops()
            int result = count_loops(verbose);
            if (result > 0)
            {
                printf("%s %d\n", LOOP_COUNT_OPTION, result);
            }
            else
            {
                return 2;
            }
        }

        else if (strcmp(argv[1], "-f") == 0)
        {
            int result = count_func_defs(verbose);
            if (result > 0)
            {
                printf("%s %d\n", FUNC_DEF_COUNT_OPTION, result);
            }
            else
            {
                return 2;
            }
        }
    }
    
    return 0;
}