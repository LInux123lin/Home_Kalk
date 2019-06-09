
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <calc.h>


int main()
{
    int ile = 1;
    int i = 0;
    char stop = ' ';

    printf("Podaj ilosc dzialan do wykonania: ");
    scanf("%d", &ile);

    if ( ile > 1 && ile < 2147483647 )
    {
        if (1 == ile)
        {
            printf("Podaj dzialanie: \n\n");
        }
        else if (1 < ile)
        {
            printf("Podaj dzialania: \n\n");
        }
    }
    else
    {
        printf("\nBlednie zdefiniowana liczba wykonan programu !\n");
        return 0;
    }

    ile = ile + 1;

    float* res = (float*)malloc(sizeof(float) * ile);
    float* sum = (float*)malloc(sizeof(float) * ile);

    res[0] = 0.0;
    sum[0] = 0.0;

    for (i; i < ile; i++)
    {
        res[i] = takeOPERATION();
        sum[i] = result;
    }
    i = 1;

    for (i; i < ile; i++)
    {
        if (0 == res[i])
        {
            printf("Wynik dzialania nr: %d = %.2f\n", i, sum[i]);
        }
        else if (1 == res[i])
        {
            printf("\nBlad w dzialaniu nr: %d!\n\n", i);
        }
    }

    free(res);
    free(sum);

    printf("\n Wcisnij dowolny klawisz aby zakonczyc dzialanie kalkulatora");

    scanf("%c", &stop);

    return 0;
}
