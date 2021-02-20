// Declare all helper functions for hw1 in this file

#include <stdio.h>
#include <string.h>


int count_all_lines(int verbose)
{
    int num_lines = 0;
    char read_line[80]; // where the line getting read will get copied into
    
    
    while(fgets(read_line, 80 , stdin))
    {
        num_lines += 1;
        if (verbose == 1)
        {
            fprintf(stderr, "%s", read_line);
        }
    }

    return num_lines;
}



int count_non_empty_lines(int verbose)
{
    int inside_multi_line = 0; // if 1, then you're currently inside a multiline comment
    int num_lines = 0;
    char read_line[80]; // where the line getting read will get copied to
    

    while(fgets(read_line, 80 , stdin))
    {
        char first_char = read_line[0]; // first character in the line
        
        
        // if multi line comment begins
        if (strstr(read_line, "/*"))
        {
            inside_multi_line = 1;
        }
        // if the end of the line has ending multiline comment
        else if (strstr(read_line, "*/")) 
        {
            inside_multi_line = 0;
        }

        if (first_char != '\n' && first_char != '/' && inside_multi_line == 0)
        {
            num_lines += 1;
            if (verbose == 1)
            {
                fprintf(stderr, "%s", read_line);
            }
        }
    }

    return num_lines;
}



int max_line_width(int verbose)
{
    int max_width = 0;       // length of longest line
    char max_width_line[80]; // actual line with words
    char read_line[80];     
    int i;
    int inside_multi_line = 0; // if 1, then you're currently inside a multiline comment


    while(fgets(read_line, 80 , stdin))
    {
        // if multi line comment begins
        if (strstr(read_line, "/*")) 
        {
            inside_multi_line = 1;
        }
        // if the end of the line has ending multiline comment
        else if (strstr(read_line, "*/"))  
        {
            inside_multi_line = 0;
        }

        // if the line isn't a single-line comment and you're
        // not inside a multiline comment
        if ((read_line[0] != '/' && read_line[1] != '/') && inside_multi_line == 0)
        {
            // if the length of the line is greater than max_width
            int line_length = ((int) strlen(read_line))-1;
            if (strstr(read_line, "//"))
            {
                line_length -= strlen(strstr(read_line, "//"));
            }
            if (line_length > max_width) 
            {
                max_width = line_length;
                // if this is the first time max_width_line is getting updated
                strcpy(max_width_line, read_line); // update it
            }
        }
    }
    if (verbose)
    {
        fprintf(stderr, "%s", max_width_line);
    }

    return max_width;
}



int count_assignments(int verbose)
{
    int num_assigments = 0;
    int inside_multi_line = 0;
    char read_line[80];
    int i;
    int j;
    int count_quotes;
    // list of all assignment operators
    char assign_ops[11][6] = {" = ", " -= ", " += ", " *= ", " /= ", " %= ", 
                              " |= ", " &= ", " >>= ", " <<= ", " ^= "};

    while (fgets(read_line, 80, stdin))
    {
        if (strstr(read_line, "/*"))
        {
            inside_multi_line = 1;
        }
        if (strstr(read_line, "*/"))
        {
            inside_multi_line = 0;
        }
        if ((read_line[0] != '/' && read_line[1] != '/') && inside_multi_line == 0)
        {
            // iterate thru list of assignment operators
            for (i = 0; i < 11; i++)
            {
                char *substring = strstr(read_line, assign_ops[i]);
                
                if (substring)
                {
                    while (substring)
                    {
                        count_quotes = 0; // number of quotes in the substring
                        for (j = 0; j < strlen(substring); j++)
                        {
                            // printf("%c", substring[j]);
                            if (substring[j] == '\"')
                            {
                                count_quotes+=1;
                            }
                        }
                        // checking if the assignment operator is not inside a string;
                        // if the number of quotes is even
                        if (count_quotes % 2 == 0)
                        {
                            num_assigments += 1;
                            if (verbose == 1)
                            {
                                fprintf(stderr, "%s", read_line);
                            }
                        }
                        substring = substring+1; // substring[1:end]
                        substring = (strstr(substring, assign_ops[i])); // reassign substring
                    }
                }
            }
        }
    }
    return num_assigments;
}



int count_loops(int verbose)
{
    int i;
    int num_loops = 0;
    char read_line[80];
    // list of loop keywords that signify a loop
    char loop_keywords[3][9] = {" for (", " while (", " do {"};


    while (fgets(read_line, 80, stdin))
    {
        for (i = 0; i < 3; i++)
        {
            if (strstr(read_line, loop_keywords[i]) && read_line[strlen(read_line)-2] == '{')
            {
                num_loops += 1;
                if (verbose == 1)
                {
                    fprintf(stderr, "%s", read_line);
                }
            }
        }
    }

    return num_loops;
}



int count_func_defs(int verbose)
{
    int num_defs = 0;
    int inside_multi_line = 0;
    char read_line[80];


    while (fgets(read_line, 80, stdin))
    {
        if (strstr(read_line, "/*"))
        {
            inside_multi_line = 1;
        }
        else if (strstr(read_line, "*/"))
        {
            inside_multi_line = 0;
        }
        // if the line doesn't start with a space and it's not a comment
        if (read_line[0] != ' ' && 
            (read_line[0] != '/' && read_line[1] != '/') &&
            inside_multi_line == 0)
        {
            // if it contains all of the indications of a function
            if (strstr(read_line, "{") &&
                strstr(read_line, "(") &&
                strstr(read_line, ")"))
            {
                num_defs += 1;
                if (verbose == 1)
                {
                    fprintf(stderr, "%s", read_line);
                }
            }
        }
    }

    return num_defs;
}