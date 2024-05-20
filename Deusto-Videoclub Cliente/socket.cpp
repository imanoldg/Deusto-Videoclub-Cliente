/*
 * socket.cpp
 *
 *  Created on: 16 may 2024
 *      Author: Usuario
 */
#include "socket.h"
#include "Usuario.h"
#include <winsock2.h>
#include <iostream>

#include "Peliculas.h"
using namespace std;

int SocketInit(SOCKET* s){
	WSADATA wsaData;
	struct sockaddr_in server;

	cout << "Iniciando libreria socket\n" << endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << " No se ha podido iniciar la libreria socket. Codigo de error: " << WSAGetLastError() << endl;
		return -1;
	}
	cout << "Libreria socket iniciada" << endl;

	//SOCKET creation
	if ((*s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		cout << "No se ha podido crear el socket. Codigo de error: " << WSAGetLastError() << endl;
		WSACleanup();
		return -1;
	}
	cout << "Socket creado correctamente" << endl;

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(*s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR)
	{
		cout << "Error al conectar el socket. Codigo de error: " << WSAGetLastError() << endl;
		closesocket(*s);
		WSACleanup();
		return -1;
	}

	cout << "Conexion establecida con: " << inet_ntoa(server.sin_addr) << " (" << ntohs(server.sin_port) << ")" << endl;
	return 0;
}

int comandoIniciarSesion(SOCKET* s, char* usuario, char* contrasenha, Usuario &u){
	char sendBuff[512], recvBuff[512];

	cout << "Comando enviado" << endl;
	strcpy(sendBuff, "SESION_INIT");
	send(*s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, usuario);
	send(*s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, contrasenha);
	send(*s, sendBuff, sizeof(sendBuff), 0);


	recv(*s, recvBuff, sizeof(recvBuff), 0);
	u.setDNI(recvBuff);
	recv(*s, recvBuff, sizeof(recvBuff), 0);
	u.setNombre(recvBuff);
	recv(*s, recvBuff, sizeof(recvBuff), 0);
	u.setApellido(recvBuff);
	recv(*s, recvBuff, sizeof(recvBuff), 0);
	u.setEmail(recvBuff);
	recv(*s, recvBuff, sizeof(recvBuff), 0);
	u.setUser(recvBuff);
	recv(*s, recvBuff, sizeof(recvBuff), 0);
	u.setContra(recvBuff);
	recv(*s, recvBuff, sizeof(recvBuff), 0);
	u.setGenero(recvBuff);
	recv(*s, recvBuff, sizeof(recvBuff), 0);
	u.setFechaNcto(recvBuff);
	recv(*s, recvBuff, sizeof(recvBuff), 0);
	u.setNumTarjeta(atoi(recvBuff));
	recv(*s, recvBuff, sizeof(recvBuff), 0);
	u.setPuntos(atoi(recvBuff));

	recv(*s, recvBuff, sizeof(recvBuff), 0);


	return atoi(recvBuff);

}

void comandoPassChange(SOCKET* s, char* dni, char* contrasenha){
	char sendBuff[512], recvBuff[512];

	strcpy(sendBuff, "PASS_CHANGE");
	send(*s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, dni);
	send(*s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, contrasenha);
	send(*s, sendBuff, sizeof(sendBuff), 0);


	recv(*s, recvBuff, sizeof(recvBuff), 0);
	cout << recvBuff << endl;
}

Peliculas comandoGetAlquileres(SOCKET* s, Usuario &u){
	char sendBuff[512], recvBuff[512];

	strcpy(sendBuff, "GET_ALQUILERES");
	send(*s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, u.getDNI());
	send(*s, sendBuff, sizeof(sendBuff), 0);

	Peliculas p;

	recv(*s, recvBuff, sizeof(recvBuff), 0);
	p.setNumPeliculas(atoi(recvBuff));

	for (int i = 0; i < p.getNumPeliculas() - 1; ++i) {
		recv(*s, recvBuff, sizeof(recvBuff), 0);
		p.setNombre(recvBuff, i);
	}

	return p;
}

void comandoCambiarPuntos(){

}
