#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANTIDAD 5
struct compu // pdf
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
};
typedef struct compu PC; // quiero usar PC
// en la declaracion de las funciones, cambie el struct compu por PC por el typedef
void listarPCs(PC pcs[], int cantidad);
void mostrarMasVieja(PC pcs[], int cantidad);
void mostrarMasVeloz(PC pcs[], int cantidad);

int main()
{
    srand(time(NULL));
    // formula del rand()
    // rand()% (max - min +1)+min;
    // int tipoVelocidad = rand() % (3 - 1 + 1) + 1;
    // printf("%d ",tipoVelocidad);
    // int tipoAnio = rand() % (2024 - 2015 + 1) + 2015;
    // int tipoNucleo = rand() % (8 - 1 + 1) + 1;
    char tiposCpu[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
                            "Pentium"};

    PC computadoras[CANTIDAD];//son 5

    for (int i = 0; i < 5; i++)
    {
        // accedo a cada arreglo
        computadoras[i].velocidad = rand() % 3 + 1;
        computadoras[i].anio = rand() % (2024 - 2015 + 1) + 2015;
        computadoras[i].cantidad_nucleos = rand() % 8 + 1;
        //esto funciona debido al puntero que se encuentra en la estructura
        computadoras[i].tipo_cpu = tiposCpu[rand() % 6]; // el rand()%6 va desde 0 a 5
    }
    listarPCs(computadoras, CANTIDAD);
    mostrarMasVieja(computadoras, CANTIDAD);
    mostrarMasVeloz(computadoras,CANTIDAD);

    return 0;
}
void listarPCs(PC pcs[], int cantidad)
{
    // que recorra la cantidad de veces del arreglo(la constante)
    // indexacion
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nPC nº[%d]\n", i + 1);
        printf("Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("Anio de fabricacion: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("Tipo de CPU: %s\n", pcs[i].tipo_cpu);
        printf("======================================\n"); // ORDEN
    }
}

void mostrarMasVieja(PC pcs[], int cantidad)
{
    int indiceDeLaVieja = 0;
    
    for (int i = 1; i < cantidad; i++)
    { 
            //se pone en cero e i en 1 para comparar en el if

        if (pcs[i].anio < pcs[indiceDeLaVieja].anio)
        {
            indiceDeLaVieja = i;
        }
    }

    printf("\nLA PC MAS VIEJA ES LA Nº:[%d]:\n", indiceDeLaVieja + 1);
    printf("Velocidad: %d GHz\n", pcs[indiceDeLaVieja].velocidad);
    printf("Anioo de fabricacion: %d\n", pcs[indiceDeLaVieja].anio);
    printf("Cantidad de nucleos: %d\n", pcs[indiceDeLaVieja].cantidad_nucleos);
    printf("Tipo de CPU: %s\n", pcs[indiceDeLaVieja].tipo_cpu);
}

void mostrarMasVeloz(PC pcs[], int cantidad)
{
    int indiceMasVeloz = 0;
    //se pone en cero e i en 1 para comparar en el if
    //mostrare la primera encontrada solamente
    for (int i = 1; i < cantidad; i++)
    {
        if (pcs[i].velocidad > pcs[indiceMasVeloz].velocidad)
        {
            indiceMasVeloz = i;
        }
    }

    printf("\nLA PC CON MAS VELOCIDAD Nº [%d]\n", indiceMasVeloz+1);
    printf("Velocidad: %d GHz\n", pcs[indiceMasVeloz].velocidad);
    printf("Anioo de fabricacion: %d\n", pcs[indiceMasVeloz].anio);
    printf("Cantidad de nucleos: %d\n", pcs[indiceMasVeloz].cantidad_nucleos);
    printf("Tipo de CPU: %s\n", pcs[indiceMasVeloz].tipo_cpu);
}