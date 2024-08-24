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

    for(int i = 1; i<argc; i++)
        {
            int number = atoi(argv[i]);

            node *head = malloc(sizeof(node));
            if(head == NULL)
                {
                    // free memory thus far
                }
        }
}
