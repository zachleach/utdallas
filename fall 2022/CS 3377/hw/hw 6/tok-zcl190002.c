/*
        Written by Zach Leach for CS 3377.004 on 09.29.2022
        NetID: zcl190002
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/**
 * reads a line of input into dst.
 * uses malloc and realloc internally (dst should be freed after use).
 */
void getline2(char **dst) {
        size_t size = 0;
        ssize_t n = getline(dst, &size, stdin);
        if ((*dst)[n - 1] == '\n') {
                (*dst)[n - 1] = '\0';
        }
}

/**
 * count the number of sentences in a string, and the number of tokens in each sentence.
 * terminate when the first token in line is "BYE".
 */
int tok(int argc, char *argv[]) {
        
        while (1) {
                // read a line
                printf("Enter a string: ");
                char *line;
                getline2(&line);
                
                int i, j;
                char *str1, *str2, *token, *subtoken;
                char *saveptr1, *saveptr2; 
                
                // for token ('.' delim) in line: 
                for (i = 0, str1 = line; ; str1 = NULL, i++) {
                        // read token
                        token = strtok_r(str1, ".", &saveptr1);
                        if (token == NULL) {
                                break;
                        }
                        
                        // for subtoken (' ' delim) in token
                        for (j = 0, str2 = token; ; str2 = NULL, j++) {
                                // read subtoken
                                subtoken = strtok_r(str2, " ", &saveptr2);
                                if (subtoken == NULL) {
                                        break;
                                }
                                
                                if (i == 0 && j == 0 && strcmp(token, "BYE") == 0) {
                                        exit(EXIT_SUCCESS);
                                }
                                
                                // increment j
                        }
                        
                        printf("sentence %d: tokens %d\n", i + 1, j);
                        // increment i
                }
                
                // getline calls malloc internally
                free(line);
        }
        
        exit(EXIT_SUCCESS);
}