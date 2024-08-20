#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int* array = (int*)malloc(sizeof(int)*10);
    int target = 0;
    bool found = false;

    for(int i = 0; i<10; i++)
        {
            array[i] = i;
        }

    printf("Enter the target value between 0 - 10 : ");
    scanf("%d", &target);

    for(int i = 0; i<10; i++)
        {
            if(array[i] == target)
                {
                    printf("target found at index %d\n", i);
                    found = true;
                    break;
                }
        }
    if(!found)
        {
            printf("Target out of bounds\n");
        }
    return 0;
}
