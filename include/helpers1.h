// Declare all helper functions for hw1 in this file


// count total number of lines in file including comments/whitespace;
// if verbose == 1, print all the lines, if verbose == 0, don't print anything
int count_all_lines(int verbose); 

// count number of non-empty and non-comment lines
// if verbose == 1, print the lines, otherwise don't
int count_non_empty_lines(int verbose);

// print maximum line width from input stream (excluding newline)
// leading spaces are included
// if verbose == 1, print the line, otherwise don't
int max_line_width(int verbose);

// count the number of assigments in the input
// if verbose == 1, print all lines containing assignments
int count_assignments(int verbose);

// count the number of loops in the input
// for, while, do; line ends with "{"
int count_loops(int verbose);

// count the number of function definitions in the input;
// no leading spaces, at least one '(' and one ')' ,
// and one '{'
int count_func_defs(int verbose);