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
#include <windows.h>
#include <winsock2.h>

#include "Peliculas.h"
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
			//break;
	case 2: recuperarContra(s);
			//break;
	case 3:	break;
	default: break;
	}
}

void recuperarContra(SOCKET* s){
	cout << endl;
	cout << endl;
	cout << "RECUPERAR CONTRASEÑA" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "Introducir DNI: ";
	char dni[10];
	cin >> dni;
	cout << endl;
	cout << "Introducir contraseña nueva: ";
	char contrasenha[16];
	cin >> contrasenha;


	//BUSCAR EL DNI DE LA PERSONA EN LA BASE DE DATOS Y ESTABLECER LA CONTRASEÑA INTRODUCIDA
	comandoPassChange(s, dni, contrasenha);

	char q[2];
	cout << "(Q para volver)";
	cin >> q;


	if((strcmp(q, "q") == 0) || (strcmp(q, "Q") == 0)) {
		inicio(s);
	}

}

void inicioSesion(SOCKET* s){
	char usuario[40];
	char contrasenha[16];

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
		Sleep(1000);

		menuPrincipal(s, u);
	} else{
		cout << endl;
		cout<< endl;
		cout << "ERROR INICIANDO SESION, VOLVIENDO A LA PAGINA DE INICIO" << endl;
		inicio(s);

		cout << endl;
	}


}

void menuPrincipal(SOCKET *s, Usuario u){
	cout << endl;
	cout << endl;
	cout << "BIENVENIDO AL MENU PRINCIPAL" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "1. Estadisticas Peliculas" << endl;
	cout << "2. Consultar Puntos y Ofertas" << endl;
	cout << "3. Salir" << endl;
	cout << endl;
	cout << "Introducir opcion: ";
	int opcion = 0;
	cin>>opcion;

	switch(opcion){
	case 1: estatPeliculas(s, u);
			break;
	case 2: menuOfertasPuntos(s, u);
			break;
	case 3: break;
	default: break;;
	}
}

void estatPeliculas(SOCKET *s, Usuario u){
	cout << endl;
	cout << endl;
	cout << "ESTADISTICAS PELICULAS" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "1. Peliculas mas alquiladas" << endl;
	cout << "2. Top por genero" << endl;
	cout << "3. Volver" << endl;
	cout << endl;
	cout << "Introducir opcion: ";
	int opcion;
	cin>>opcion;

	switch(opcion){
	case 1: pelisMasAlquiladas(s, u);
			break;
	case 2: topGeneros(s, u);
			break;
	case 3:	break;
	default: break;
	}
}

void topGeneros(SOCKET *s, Usuario u){
	cout << endl;
	cout << endl;
	cout << "GENEROS" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "1. Accion" << endl << "2. Drama" << endl << "3. Ciencia Ficcion" << endl
			<< "4. Clasicas" << endl << "5. Comedia" << endl << "6. Terror" << endl << "7. Romanticas" << endl << endl;

	int opcion;
	cout << "Introduce una opcion: ";
	cin >> opcion;

	//SACAD LAS PELICULAS DEL FICHERO

	switch(opcion){
	case 1: //SACAR EL TOP DE ACCION
	case 2: //SACAR EL TOP DE DRAMA
	case 3: //SACAR EL TOP DE CIENCIA FICCION
	case 4: //SACAR EL TOP DE CLASICAS
	case 5: //SACAR EL TOP DE COMEDIA
	case 6: //SACAR EL TOP DE TERROR
	case 7: //SACAR EL TOP DE ROMANTICAS
	default: break;
	}
}

void pelisMasAlquiladas(SOCKET *s, Usuario u){
	cout << endl;
	cout << endl;
	cout << "PELICULAS MAS ALQUILADAS" << endl;
	cout << "=======================================" << endl;
	cout << endl;

	//SACAR LAS PELICULAS MAS ALQUILADAS


	//HACER QUE INTRODUZCA EL NOMBRE DE LA PELICULA DE LA QUE SE DESEA VER LOS DATOS
	char nombrePeli[40];
	cout<< "Introduce el titulo de la pelicula: ";
	cin >> nombrePeli;
	datosPelicula(s, nombrePeli, u);
}

void datosPelicula(SOCKET *s, char* nombrePeli, Usuario u){
	cout << endl;
	cout << endl;
	cout << "PELICULA: " << nombrePeli <<  endl;
	cout << "=======================================" << endl;
	cout << endl;
	//SACAR ESTOS DATOS DEL FICHERO DE PELICULAS
	cout << "Duracion: " << endl;
	cout << "Genero: " << endl;
	cout << "Nota: " << endl;
	cout << "Sinopsis: " << endl;
	cout << endl;

	char q[2];
	cout << "(Q para salir)";
	cin >> q;

	if((strcmp(q, "q") == 0) || (strcmp(q, "Q") == 0)) {
		menuPrincipal(s, u);
	}
}

void menuOfertasPuntos(SOCKET *s, Usuario u){
	cout << endl;
	cout << endl;
	cout << "MENU PUNTOS Y OFERTAS " << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "1. Ofertas" << endl;
	cout << "2. Mis puntos" << endl;
	cout << "3. Volver al menu" << endl;
	cout << endl;
	cout << "Introducir opcion: ";

	int opcion = 0;
	cin >> opcion;

	switch(opcion){
	case 1: menuOfertas(s, u);
			break;
	case 2: menuPuntos(s, u);
			break;
	case 3: menuPrincipal(s, u);
			break;
	default: break;
	}
}

void menuPuntos(SOCKET *s, Usuario u){
	cout << endl;
	cout << endl;
	cout << "TUS PELICULAS ALQUILADAS" << endl;
	cout << "=======================================" << endl;

	/*SACAR UNA LISTA DE LAS PELICULAS ALQUILADAS POR EL USUARIO.
		ESA LISTA DEBE DE SACARSE DE LA BASE DE DATOS.
		AL FINAL DE LA LISTA DE ALQUILERES SE DEBE DE PONER EL TOTAL DE PUNTOS DEL USUARIO*/

	Peliculas peliculas = comandoGetAlquileres(s,u);

	for (int i = 0; i < peliculas.getNumPeliculas(); ++i) {
		cout << i << ". " <<  peliculas.getNombre(i) << endl;
	}

	cout << endl;
	cout << "=======================================" << endl;
	cout << "SISTEMA DE PUNTUAJE" << endl;
	cout << "=======================================" << endl;
	cout << "- 3 dias: 3 puntos" << endl;
	cout << "- 5 dias: 5 puntos" << endl;
	cout << "- 7 dias: 7 puntos" << endl;

	char q[2];
	cout << "(Q para volver)";
	cin >> q;

	if((strcmp(q, "q") == 0) || (strcmp(q, "Q") == 0)) {
		menuOfertasPuntos(s, u);
	}
}

void menuOfertas(SOCKET *s, Usuario u){
	cout << endl;
	cout << endl;
	cout << "OFERTAS POR PUNTOS" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "1. Refrescos" << endl;
	cout << "2. Snacks" << endl;
	cout << "3. Volver al menu" << endl;
	cout << endl;
	cout << "Introducir opcion: ";

	int opcion;
	cin >> opcion;

	switch(opcion){
	case 1: ofertasRefrescos(s, u);
			break;
	case 2: ofertasSnacks(s, u);
			break;
	case 3: menuOfertasPuntos(s, u);
			break;
	default: break;
	}
}

void ofertasSnacks(SOCKET *s, Usuario u){
	cout << endl;
	cout << endl;
	cout << "SNACKS" << endl;
	cout << "=======================================" << endl;
	cout << "1. Doritos (30 puntos)" << endl;
	cout << "2. Patatas fritas (25 puntos)" << endl;
	cout << "3. Cheetos Pandilla (32 puntos)" << endl;
	cout << "4. Pelotazos (40 puntos)" << endl;
	cout << "5. Volver a las ofertas" << endl;
	cout << endl;
	cout << "Introducir opcion: ";

	int opcion;
	cin >> opcion;

	/*ACCEDER A LA BASE DE DATOS Y QUITARLE LOS PUNTOS PROPORCIONALES A LA OPCION ELEGIDA AL USUARIO
	 * PRINTEAR POR EJEMPLO "DORITOS CANJEADOS POR 30 PUNTOS" Y DEVOLVERLE AL MENU DE OFERTAS
	 */
	switch(opcion){
	case 1:
	case 2:
	case 3:
	case 4:
	case 5: menuOfertas(s, u);
			break;
	default: break;
	}
}


void ofertasRefrescos(SOCKET *s, Usuario u){
	cout << endl;
	cout << endl;
	cout << "REFRESCOS" << endl;
	cout << "=======================================" << endl;
	cout << "1. Sprite (20 puntos)" << endl;
	cout << "2. Kas (15 puntos)" << endl;
	cout << "3. Coca cola(35 puntos)" << endl;
	cout << "4. Monster (40 puntos)" << endl;
	cout << "5. Volver a las ofertas" << endl;
	cout << endl;
	cout << "Introducir opcion: ";

	int opcion;
	cin >> opcion;

	/*ACCEDER A LA BASE DE DATOS Y QUITARLE LOS PUNTOS PROPORCIONALES A LA OPCION ELEGIDA AL USUARIO
	 * PRINTEAR POR EJEMPLO "SPRITE CANJEADO POR 20 PUNTOS" Y DEVOLVERLE AL MENU DE OFERTAS
	 */
	switch(opcion){
	case 1:
	case 2:
	case 3:
	case 4:
	case 5: menuOfertas(s, u);
			break;
	default: break;
	}
}
