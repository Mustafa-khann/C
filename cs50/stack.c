#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int* stack = NULL;
int top = -1;

void push(int n);
int pop();

int main()
{
    stack = malloc(sizeof(int) * 10);
    int choice = 0;
    int value = 0;
    bool loop = true;
    while(loop)
    {
        printf("Select an option : 1.Push 2.Pop 3.Exit\n");
        scanf("%i", &choice);
        if(choice == 0)
        {
            printf("please select a choice");
        }
        else if(choice == 1)
        {
            printf("Enter the element to push in the stack: ");
            scanf("%d", &value);
            push(value);
        }
        else if(choice == 2){
            value = pop();
            printf("Popped Value : %i\n", value);
        }
        else {
            loop = false;
        }
    }
    return 0;
}

void push(int n )
{
    stack[++top] = n;
    printf("Element Pushed into the stack\n");
}

int pop()
{
    return stack[--top];
}
