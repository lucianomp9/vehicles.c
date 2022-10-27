#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED

struct _vehiculos;

typedef struct _vehiculos * vehiculos;

vehiculos crearVehiculo(); ///Constructor

void mostrarVehiculo(vehiculos v); ///Mostrar vehiculo

void addPasajero(vehiculos v); ///Anadir pasajero

int buscarPos(vehiculos v, char n[20]); ///Busca posicion disponible para agregar pasajero

void ordenarPorEdad(vehiculos v);  ///(No utilizada en este ejercicio)

void buscarPasajeroMasJoven(vehiculos v); ///Busca pasajero mas joven y lo muestra

void destruirVehiculo(vehiculos v); ///Destructor

#endif // VEHICULO_H_INCLUDED
