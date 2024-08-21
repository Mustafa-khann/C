#include <stdio.h>
int main()
{
    int array[10] = {3,4,5,8,1,2,9,0,6,7};
    int n = sizeof(array) / sizeof(array[0]);
    int min = array[0];

    for(int i = 0; i<n-1; i++)
        {
            min = i;
            for(int j = i+1; j<n; j++)
            {
                if(array[j] < array[min])
                {
                    min = j;
                }
            }
            if(min != i)
            {
                int temp = array[min];
                array[min] = array[i];
                array[i] = temp;
            }
        }

    printf("Array: ");
    for(int i = 0; i<sizeof(array)/sizeof(int);  i++)
        {
            printf("%d", array[i]);
        }
    printf("\n");
    return 0;
}
