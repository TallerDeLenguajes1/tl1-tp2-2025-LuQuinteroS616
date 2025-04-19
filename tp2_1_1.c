#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main()
{
    int i;
    double vt[N];
    srand(time(NULL));  // Semilla antes del uso de rand()

    for (i = 0; i < N; i++)
    {
        vt[i] = 1 + rand() % 100;

        printf("%f ", vt[i]);
    }
    return 0;
}
