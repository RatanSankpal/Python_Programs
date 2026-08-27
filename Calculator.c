#include <stdio.h>

int errorflag = 0;

float calculator(float no1, float no2, char opt)
{
    switch (opt)
    {
        case '+':
            return no1 + no2;
        case '-':
            return no1 - no2;
        case '*':
            return no1 * no2;
        case '/':
            if (no2 == 0)
            {
                errorflag = 1;
                return no1;
            }
            return no1 / no2;
        default:
            printf("\nInvalid operator\n");
            return 0;
    }
}

int main()
{
    float no1, no2, res;
    char opt;

    printf("\nEnter first number: ");
    scanf("%f", &no1);

    printf("\nEnter second number: ");
    scanf("%f", &no2);

    printf("\nEnter operator: ");
    scanf(" %c", &opt);

    res = calculator(no1, no2, opt);

    if (errorflag)
        printf("Error: Division by zero is not possible\n");
    else
        printf("Result = %.2f\n", res);

    return 0;
}