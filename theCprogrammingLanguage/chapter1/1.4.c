#include <stdio.h>

int main()
{
    int celsius, lower = 0, upper = 100, step = 10;

    printf("Celsius to Fahrenheit Table\n");
    printf("---------------------------\n");
    printf("Celsius\t\tFahrenheit\n");

    for(celsius = lower; celsius<=upper; celsius+=step)
        {
            int fehr = (celsius * 5/9) + 32;
            printf("%7d\t%10d\n", celsius, fehr);
        }
    return 0;
}
