#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANTIDAD 5
struct compu //pdf
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
};
typedef struct compu PC; // quiero usar PC
void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main()
{
    srand(time(NULL)); 
    // formula del rand()
    // rand()% (max - min +1)+min;
    //int tipoVelocidad = rand() % (3 - 1 + 1) + 1; 
    // printf("%d ",tipoVelocidad);
    //int tipoAnio = rand() % (2024 - 2015 + 1) + 2015;
    //int tipoNucleo = rand() % (8 - 1 + 1) + 1;
    char tiposCpu[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
        "Pentium"};

    PC computadoras[CANTIDAD];

    for (int i = 0; i < 5; i++) {
        //accedo a cada arreglo 
        computadoras[i].velocidad = rand() % 3 + 1;
        computadoras[i].anio = rand() % (2024 - 2015 + 1) + 2015;
        computadoras[i].cantidad_nucleos = rand() % 8 + 1;
        computadoras[i].tipo_cpu = tiposCpu[rand() % 6];  //el rand()%6 va desde 0 a 5
    }
        listarPCs(computadoras,CANTIDAD);

    return 0;
}
void listarPCs(struct compu pcs[], int cantidad) {
    //que recorra la cantidad de veces del arreglo(la constante)
    //indexacion
    for (int i = 0; i < cantidad; i++) {
        printf("\nPC nº[%d]\n", i + 1);
        printf("Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("Anio de fabricación: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("Tipo de CPU: %s\n", pcs[i].tipo_cpu);
        printf("======================================\n");//ORDEN
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad){

}
void mostrarMasVeloz(struct compu pcs[], int cantidad){

}