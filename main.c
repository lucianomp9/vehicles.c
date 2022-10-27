#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PASAJEROS 5
#include "pasajeros.h"
#include "vehiculo.h"

int main()
{
    vehiculos v = crearVehiculo();
    mostrarVehiculo(v);
    addPasajero(v);
    addPasajero(v);
    buscarPasajeroMasJoven(v);
    mostrarVehiculo(v);
    addPasajero(v);
    addPasajero(v);
    addPasajero(v);
    addPasajero(v);
    mostrarVehiculo(v);
    destruirVehiculo(v);
    return 0;
}
