#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    int* array = (int*)malloc(sizeof(int) * 100);
    int target;

    int left = 0, right = 100;
    int mid = (left + right)/2;

    printf("Enter target value between the range of 0 - 100 : ");
    scanf("%i", &target);

    for(int i = 0; i<100; i++){
        array[i] = i;
    }

    if(target < 0 || target > 100)
    {
        printf("Target out of bounds!\n");
    }
    else
    {    bool found = false;

        while(left <= right)
        {
            mid = (right + left ) / 2;

            if(target < mid)
            {
                right = mid - 1;
            }
            else if (target > mid)
            {
                left = mid + 1;
            }
            else if(array[mid] == target)
            {
                printf("Target found at index %d\n", mid);
                break;
            }
        }
    }
}
