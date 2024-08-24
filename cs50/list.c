#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for(int i = 0; i<argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            // free memory thus far
        }

        n->number = number;
        n->next = list;

        list = n;
    }

    int* pointer = malloc(sizeof(int));
    while(list->next)
    {
        printf("%i ", list->number);
        list = list->next;
    }
    printf("\n");
    return 0;
}
