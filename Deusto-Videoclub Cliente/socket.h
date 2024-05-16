/*
 * socket.h
 *
 *  Created on: 16 may 2024
 *      Author: Usuario
 */
#ifndef SOCKET_H_
#define SOCKET_H_

#include <winsock2.h>
#include "Usuario.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int setUpSocket(SOCKET* s);
int enviarComandoIniciarSesion(SOCKET* s, char* dni, char* contrasena, Usuario& u);

#endif /* SOCKET_H_ */
