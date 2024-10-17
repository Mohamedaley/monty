#include "main.h"
/**
 * 
 */
void pall(stack_t **head, int line_num, int id)
{
    stack_t *current = *head;
    int i = 1;

    if (id == 0)
    {
        printf("($Monty$)Processing file/");
        for(int j = 0; j < 10; j++)
            printf(".");
    }
    printf("\nLines: \t\t data: \n----------------------\n");
    while (current != NULL) {
        printf("- Line: %d    -    %d -\n", i, current->n);
        current = current->next;
        i++;
    }
    printf("----------------------\nLines detected : %d\n\
Lines contains data : %d\n", line_num,i);
    if(line_num > i)
        printf("Blank lines : %d\n", line_num - i);
}
