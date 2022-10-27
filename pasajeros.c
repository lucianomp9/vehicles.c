#include <stdio.h>
#include <stdlib.h>
#include "pasajeros.h"
#include <string.h>
#define PASAJEROS 5

struct _pasajeros{
    char nombre[30];
    int edad;
    int posicion;
};


pasajerosP crearPasajero(){
    pasajerosP p = malloc(sizeof(struct _pasajeros));
    printf("\n------------------\n\n");
    printf("\n- Ingrese el nombre del pasajero\n");
    fflush(stdin);
    gets(p->nombre);

    printf("\n- Ingrese la edad del pasajero\n");
    scanf("%d", &p->edad);

    printf("\nIngrese la posicion\n");
    printf("\n- 1: Conductor");
    printf("\n- 2: Acompañante");
    printf("\n- (3,4,5): Atras\n");
    scanf("%d", &p->posicion);
    while (p->posicion > 5 || p->posicion < 1){ ///Si no existe la posicion avisamos.
        printf("\nEsa posicion no existe, digite nuevamente...\n");
        printf("\n- 1: Conductor");
        printf("\n- 2: Acompañante");
        printf("\n- (3,4,5): Asiento Trasero\n");
        scanf("%d", &p->posicion);
    }

    return p;

}

pasajerosP inicializarPasajero(){
    pasajerosP p = malloc(sizeof(struct _pasajeros));

    strcpy(p->nombre, "VACIO");
    p->edad = -1;
    p->posicion = -1;

    return p;

}

void mostrarPasajero(pasajerosP p){
    printf("\n-------PASAJERO-------\n");
    printf("\n- Nombre pasajero: %s", p->nombre);
    printf("\n- Edad pasajero: %d", p->edad);
    if (p->posicion == 1){
        printf("\n- Posicion pasajero: Conductor\n");
    }
    if (p->posicion == 2){
        printf("\n- Posicion pasajero: Acompañante\n");
    }
    if (p->posicion == 3 || p->posicion == 4 || p->posicion == 5){
        printf("\n- Posicion pasajero: Asiento Trasero\n");
    }
    if (p->posicion == -1){
        printf("\n- Posicion pasajero: Vacia\n");
    }
}

int getPos(pasajerosP p){
    return p->posicion;
}


char * getNombre(pasajerosP p){
    return p->nombre;
}

int getEdad(pasajerosP p){
    return p->edad;
}

void destruirPasajero(pasajerosP p)
{
    free(p);
}


