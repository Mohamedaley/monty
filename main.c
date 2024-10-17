#include "main.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[EXIT_FAILURE], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[EXIT_FAILURE]);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    int id = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        line_number++;
        if (read == 1)
            continue;
        char *opcode = strtok(line, " \n\t");
        if (strcmp(opcode, "push") == 0) {
            char *arg = strtok(NULL, " \n\t");
            if (arg == NULL || !isdigit(*arg)) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free(line);
                free_stack(stack);
                fclose(file);
                exit(EXIT_FAILURE);
            }
            push(&stack, atoi(arg));
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack, line_number, id); id++;
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free(line);
            free_stack(stack);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    free_stack(stack);
    fclose(file);
    return EXIT_SUCCESS;
}

void free_stack(stack_t *head)
{
    stack_t *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}