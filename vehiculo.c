#include <stdio.h>
#include <stdlib.h>
#include "pasajeros.h"
#include "vehiculo.h"
#include <string.h>
#define PASAJEROS 5

struct _vehiculos{
    char marca[30];
    int anio;
    char color[30];
    float promedioEdad; ///Acumulo edad y despues lo divido por pasajeros a bordo
    pasajerosP p[PASAJEROS];
    int pasajerosABordo; ///Pasajeros a bordo, se suma en addPasajero
    int pasajeroMasJoven; ///Guarda el valor del array donde esta el pasajero mas joven.
};


vehiculos crearVehiculo(){
    vehiculos v = malloc(sizeof(struct _vehiculos));

    v->promedioEdad = 0;

    printf("\n- Ingrese la marca del vehiculo\n");
    fflush(stdin);
    gets(v->marca);

    printf("\n- Ingrese el anio del vehiculo\n");
    scanf("%d", &v->anio);

    printf("\n- Ingrese el color del vehiculo\n");
    fflush(stdin);
    gets(v->color);

    v->pasajerosABordo = 0;
    v->promedioEdad = 0;

    for (int i=0; i<PASAJEROS;i++){
        v->p[i] = inicializarPasajero(); ///Inicializamos el vehiculo con los pasajeros vacios.
    }

    return v;
}

void mostrarVehiculo(vehiculos v){
    printf("\n-------VEHICULO-------\n");
    printf("\n- Marca del vehiculo: %s\n", v->marca);
    printf("\n- Anio del vehiculo: %d\n", v->anio);
    printf("\n- Color del vehiculo: %s\n", v->color);
    printf("\n- Pasajeros en el vehiculo: %d\n", v->pasajerosABordo);

    for (int i=0; i<PASAJEROS;i++){
        mostrarPasajero(v->p[i]);
    }

    if (v->pasajerosABordo > 0){ ///Si hay minimo 1 pasajero hacemos el promedio.
    printf("\n- Promedio edad pasajeros: %.2f\n", (v->promedioEdad / v->pasajerosABordo));
    }
}

int buscarPos(vehiculos v, char n[20]){
    int flag=-1; ///Flag en -1, para que si encuentra un lugar cambie a esa direccion del array

    for(int i=0; i<PASAJEROS;i++){
        if (strcmp(getNombre(v->p[i]), n) == 0){ ///Comparamos si encuentra "VACIO" en alguna posicion.
            flag = i; ///Remplazamos con el valor donde hay un slot
            i = PASAJEROS +1; ///Salimos del for
        }
    }

    return flag; ///Retornamos la posicion donde hay slot
}

void ordenarPorEdad(vehiculos v){ ///(No utilizada en este ejercicio)

    pasajerosP aux; ///Creamos un aux con la estructura de pasajeros para hacer el intercambio

    for (int i = 0; i < PASAJEROS; i++){

        for(int j = 0; j < PASAJEROS - 1; j++){

            if( getEdad( v -> p[j] ) > getEdad( v -> p[j+1] )) ///Comparamos si la edad del pasajero J es mayor a la del pasajero J+1
            {
                aux = v->p[j];
                v->p[j] = v->p[j+1];
                v->p[j+1] = aux;
            }
        }
    }
}


void addPasajero(vehiculos v){
    int i;
    i = -1; ///Le damos -1 a I para que si no hay mas lugar no deje agregar un pasajero
    if(v->pasajerosABordo == PASAJEROS){ ///Si los pasajeros a bordo son 5, no hay mas lugar.
        printf("\n-------------------------------------------------\n");
        printf("\nYa no hay mas lugar para agregar otro pasajero!!!\n");
        printf("\n-------------------------------------------------\n");
        i = 1;
    }

    int j = -1; ///Le damos -1 a j, para que si no deje agregar un pasajero.

    j = buscarPos(v, "VACIO"); ///Le damos a J el lugar donde hay SLOT

    if (j != -1 && i == -1){ ///Preguntamos si hay slot o no, o si esta lleno los pasajeros.
        v->p[j] = crearPasajero(); ///Creamos pasajero en el slot
        v->pasajerosABordo++; ///Sumamos un pasajero a bordo.
        v->promedioEdad = v->promedioEdad + getEdad(v->p[j]); ///Sumamos la edad al acumulador para sacar promedio.
    }


}

void buscarPasajeroMasJoven(vehiculos v){

    for (int i=0; i<PASAJEROS;i++)
    {
        if (i==0){
            v->pasajeroMasJoven = i;
        }
        if (getEdad(v->p[i]) != -1){
            if(getEdad(v->p[i]) < getEdad(v -> p[v->pasajeroMasJoven])){
                v->pasajeroMasJoven = i;
            }
        }
    }

    printf("\n--------------------------");
    printf("\n El pasajero mas joven es:\n");
    mostrarPasajero(v->p[v->pasajeroMasJoven]);
    printf("\n--------------------------");


}


/*-----------
 | Destructor
 ------------*/

void destruirVehiculo(vehiculos v)
{
    for(int i = 0; i < PASAJEROS; i++)
    {
        if(v->p[i] != NULL)
        {
            destruirPasajero(v->p[i]);
        }
    }
    free(v);
}
