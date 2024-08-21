#include <stdio.h>
int main()
{
    int array[10] = {5, 1, 4, 8, 3, 6, 7, 9, 2};
    int arraySize = sizeof(array)/sizeof(array[0]);

    for(int i = 0; i<arraySize - 1; i++)
        {
            int swapped = 0;
            for(int j = 0; j<arraySize - 1; j++)
                {
                    if(array[j] > array[j+1])
                        {
                            int temp = array[j];
                            array[j] = array[j+1];
                            array[j+1] = temp;
                            swapped = 1;
                        }
                }
            if(swapped == 0)
                {
                    break;
                }
        }
    for(int i = 0; i<arraySize; i++)
        {
            printf("%d", array[i]);
        }
    printf("\n");
}
