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
    free(stack);
    return 0;
}

void push(int n )
{
    if (top >= 9) {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top] = n;
    printf("Element Pushed into the stack\n");
}

int pop()
{
    if (top == -1) {
            printf("Stack is empty\n");
            return -1;
        }
        int poppedValue = stack[top];
        top--;
        return poppedValue;
}
