#include <stdio.h>
#include <stdlib.h>

int enqueue(int n);
int dequeue();

int* queue = NULL;
int front = 0;
int rear = 0;
int size = 10;

int main()
{
    queue = malloc(sizeof(int) * size);
    if(queue == NULL)
    {
        printf("Memory Allocation Failed");
        return 1;
    }

    int value = 0;
    while(1)
    {
        printf("Enter Operation Choice : 1. Enqueue 2. Dequeue : ");
        scanf("%i", &value);
        if(value == 1)
        {
            printf("Enter the element : ");
            scanf("%i", &value);
            if(enqueue(value) == 0)
            {
                printf("Queue is full!\n");
            }
        }
        else if(value == 2)
        {
            value = dequeue();
            if(value == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Value at the front is : %i\n", value);
            }
        }
        else
        {
            break;
        }
    }
    free(queue);
    return 0;
}

int enqueue(int n)
{
    if(rear >= size)
    {
        return 0;
    }
    queue[rear] = n;
    rear = (rear + 1) % size;
    return 1;
}

int dequeue()
{
    if(front == rear)
    {
        return -1;
    }
    int value = queue[front];
    front = (front + 1) % size;
    return value;
}
