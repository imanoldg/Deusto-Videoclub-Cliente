/*
 * menus.cpp
 *
 *  Created on: 16 may 2024
 *      Author: Usuario
 */
#include "menus.h"
#include "string.h"
#include "socket.h"
#include "Usuario.h"
#include <iostream>
#include <winsock2.h>
using namespace std;

void inicio(SOCKET* s){
	cout << "=======================================" << endl;
	cout << "       ESTADISTICAS VIDEOCLUB" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "Programa de gestión: " << endl;
	cout << "1. Iniciar Sesión" << endl;
	cout << "2. Recuperar Contraseña" << endl;
	cout << "3. Salir" << endl;

	int opcion;
	cout << "Introducir opcion:";

	cin >> opcion;

	switch(opcion){
	case 1: inicioSesion(s);
			break;
	case 2: recuperarContra();
			break;
	case 3: break;
	default: break;
	}
}

void recuperarContra(){
	cout << endl;
	cout << endl;
	cout << "RECUPERAR CONTRASEÑA" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "Introducir DNI: ";
	char* dni;
	cin >> dni;
	cout << endl;
	cout << "Introducir contraseña nueva";
	char* contrasenha;
	cin >> contrasenha;

	//BUSCAR EL DNI DE LA PERSONA EN LA BASE DE DATOS Y COMPARAR CON LA CONTRASEÑA INTRODUCIDA
}

void inicioSesion(SOCKET* s){
	char* usuario;
	char* contrasenha;

	cout << endl;
	cout << endl;
	cout << "Introduce tu usuario: ";
	cin >> usuario;
	cout << endl;
	cout << "Introduce tu contraseña: ";
	cin >> contrasenha;

	//Se crea el usuario con parametros vacios y se pasa como referencia al metodo de socket
	Usuario u;
	int correcto = comandoIniciarSesion(s, usuario, contrasenha, u);

	if(correcto == 1){
		cout << endl;
		cout<< endl;
		cout << "USUARIO Y CONTRASEÑA CORRECTOS, INICIANDO SESION" << endl;

		menuPrincipal();
	} else{
		cout << endl;
		cout<< endl;
		cout << "ERROR INICIANDO SESION, VOLVIENDO A LA PAGINA DE INICIO";
		inicio(s);
	}


}

void menuPrincipal(){
	cout << endl;
	cout << endl;
	cout << "BIENVENIDO AL MENU PRINCIPAL" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "1. Estadisticas Peliculas" << endl;
	cout << "2.Consultar Puntos y Ofertas" << endl;
	cout << "3. Cerrar Sesión" << endl;
	cout << endl;
	cout << "Introducir opcion: ";
	int opcion;
	cin>>opcion;


}
