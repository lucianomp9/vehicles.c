#ifndef PASAJEROS_H_INCLUDED
#define PASAJEROS_H_INCLUDED

struct _pasajeros;

typedef struct _pasajeros * pasajerosP;

///CONSTRUCTORES
pasajerosP crearPasajero();

pasajerosP inicializarPasajero(); ///Inicializar pasajero ("VACIO", -1, -1)


///Mostrar
void mostrarPasajero(pasajerosP p);


///Getters
int getPos(pasajerosP p);

char * getNombre(pasajerosP p);

int getEdad(pasajerosP p);


///DESTRUCTOR
void destruirPasajero(pasajerosP p);



#endif // PASAJEROS_H_INCLUDED
