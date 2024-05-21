/*
 * socket.h
 *
 *  Created on: 16 may 2024
 *      Author: Usuario
 */
#ifndef SOCKET_H_
#define SOCKET_H_

#include <winsock2.h>

#include "Pelicula.h"
#include "Usuario.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int SocketInit(SOCKET* s);
int comandoIniciarSesion(SOCKET* s, char* usuario, char* contrasena, Usuario &u);
void comandoPassChange(SOCKET* s, char* dni, char* contrasenha);
int comandoGetNumAlquileres(SOCKET *s, Usuario &u);
void comandoGetAlquileres(SOCKET* s, Usuario &u, listaPelis &p);
void comandoCambiarPuntos(SOCKET *s, Usuario &u, int numPuntos);
#endif /* SOCKET_H_ */
