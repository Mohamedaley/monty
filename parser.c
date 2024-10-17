#include "main.h"
/**
 * 
 */
int parser(char *line, unsigned int line_number)
{
    char *opcode = strtok(line, " \n\t");
    if (opcode == NULL) return -1;
    
    if (strcmp(opcode, "push") == 0) {
        char *arg = strtok(NULL, " \n\t");
        if (arg == NULL) {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        
        for (int i = 0; arg[i] != '\0'; i++) {
            if (i == 0 && arg[i] == '-') continue;
            if (!isdigit(arg[i])) {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
        }
        
        return atoi(arg);
    }
    return -1;
}