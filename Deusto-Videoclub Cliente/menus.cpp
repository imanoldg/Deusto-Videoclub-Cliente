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
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstring>

#include "Pelicula.h"
using namespace std;

void inicio(SOCKET *s) {
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

	switch (opcion) {
	case 1:
		inicioSesion(s);
		break;
	case 2:
		recuperarContra(s);
		break;
	case 3:
		break;
	default:
		break;
	}
}

void recuperarContra(SOCKET *s) {
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

	if ((strcmp(q, "q") == 0) || (strcmp(q, "Q") == 0)) {
		inicio(s);
	}

}

void inicioSesion(SOCKET *s) {
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

	if (correcto == 1) {
		cout << endl;
		cout << endl;

		cout << u.getDNI() << endl;
		cout << u.getNombre() << endl;
		cout << u.getApellido() << endl;
		cout << u.getEmail() << endl;
		cout << u.getTlf() << endl;
		cout << u.getUser() << endl;
		cout << u.getContra() << endl;
		cout << u.getGenero() << endl;
		cout << u.getFechaNcto() << endl;
		cout << u.getNumTarjeta() << endl;
		cout << u.getPuntos() << endl;
		cout << "USUARIO Y CONTRASEÑA CORRECTOS, INICIANDO SESION";

		menuPrincipal(s, u);

	}

	cout << endl;
	cout << endl;
	cout << "VOLVIENDO A LA PAGINA DE INICIO" << endl;
	inicio(s);

}

void menuPrincipal(SOCKET *s, Usuario u) {
	system("cls");
	int opcion;
	cout << "BIENVENIDO AL MENU PRINCIPAL" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "1. Estadisticas Peliculas" << endl;
	cout << "2. Consultar Puntos y Ofertas" << endl;
	cout << "3. Salir" << endl;
	cout << endl;
	cout << "Introducir opcion: ";
	cin >> opcion;

	switch (opcion) {
	case 1:
		estatPeliculas(s, u);
		break;
	case 2:
		menuOfertasPuntos(s, u);
		break;
	case 3:
		break;
	default:
		break;
		;
	}
}

void estatPeliculas(SOCKET *s, Usuario u) {
	cout << endl;
	cout << endl;
	cout << "ESTADISTICAS PELICULAS" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "1. Top por genero" << endl;
	cout << "2. Volver" << endl;
	cout << endl;
	cout << "Introducir opcion: ";
	int opcion;
	cin >> opcion;

	switch (opcion) {
	case 1:
		topGeneros(s, u);
		break;
	case 2:
		menuPrincipal(s, u);
		break;
	default:
		break;
	}
}

vector<PeliculaNota> leerPeliculas() {
    vector<PeliculaNota> peliculas;
    ifstream archivo("peliculas.csv");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de peliculas." << endl;
        return peliculas;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string titulo, duracion_str, nota_str, genero, descripcion;
        if (getline(ss, titulo, ';') &&
            getline(ss, duracion_str, ';') &&
            getline(ss, nota_str, ';') &&
            getline(ss, genero, ';') &&
            getline(ss, descripcion)) {

            int duracion = stoi(duracion_str);
            float nota = stof(nota_str);
            peliculas.emplace_back(titulo.c_str(), duracion, nota, genero.c_str(), descripcion.c_str());
        }
    }

    return peliculas;
}

void topGeneros(SOCKET *s, Usuario u) {
	cout << endl;
	cout << endl;
	cout << "GENEROS" << endl;
	cout << "=======================================" << endl;
	cout << endl;
	cout << "1. Accion" << endl << "2. Drama" << endl << "3. Ciencia Ficcion" << endl << "4. Clasicas" 
		<< endl << "5. Comedia" << endl << "6. Terror" << endl << "7. Romanticas" << endl << endl;

	int opcion;
	cout << "Introduce una opcion: ";
	cin >> opcion;

	vector<PeliculaNota> peliculas = leerPeliculas();
    vector<PeliculaNota> filtradas;
    const char* genero = nullptr;

	switch (opcion) {
	case 1: 
		genero = "Acción"; break;
    case 2: 
		genero = "Drama"; break;
    case 3: 
		genero = "Ciencia Ficción"; break;
    case 4: 
		genero = "Clásicas"; break;
    case 5: 
		genero = "Comedia"; break;
    case 6: 
		genero = "Terror"; break;
    case 7: 
		genero = "Románticas"; break;
	default:
		break;
	}

	for (const auto& pelicula : peliculas) {
        if (strcmp(pelicula.getGenero(), genero) == 0) {
            filtradas.push_back(pelicula);
        }
    }

	sort(filtradas.begin(), filtradas.end(), [](const PeliculaNota& a, const PeliculaNota& b) {
        return a.getNota() > b.getNota();
    });

	cout << "Top peliculas de " << genero << ":" << endl;
	int i = 0;
    for (const auto& pelicula : filtradas) {
		i++;
        cout << i << ". " << pelicula.getTitulo() << " - Nota: " << pelicula.getNota() << endl;
    }

    char opcion2[2];

    cout << "Elije una pelicula para ver sus detalles o pulsa Q para volver atras: " << endl;
    cin >> opcion2;

	
	if ((strcmp(opcion2, "q") == 0) || (strcmp(opcion2, "Q") == 0)) {
		estatPeliculas(s,u);
	} else {
        int opcionI = stoi(opcion2) - 1;
        if (opcionI >= 0 && opcionI < filtradas.size()) {
            datosPelicula(s, filtradas[opcionI].getTitulo(), u);
        }
	}



}

void datosPelicula(SOCKET *s, const char *nombrePeli, Usuario u) {
	vector<PeliculaNota> peliculas = leerPeliculas();
	PeliculaNota* peliculaEncontrada = nullptr;
	
    for (size_t i = 0; i < peliculas.size(); ++i) {
        if (strcmp(peliculas[i].getTitulo(), nombrePeli) == 0) {
            peliculaEncontrada = &peliculas[i];
            break;
        }
    }

	if(peliculaEncontrada != nullptr){
		cout << endl;
		cout << endl;
		cout << "PELICULA: " << peliculaEncontrada->getTitulo() << endl;
		cout << "=======================================" << endl;
		cout << endl;
		cout << "Duracion: " << peliculaEncontrada->getDuracion() << " minutos" << endl;
		cout << "Genero: " << peliculaEncontrada->getGenero() << endl;
		cout << "Nota: " << peliculaEncontrada->getNota() << endl;
		cout << "Sinopsis: " << peliculaEncontrada->getDescripcion() << endl;
		cout << endl;
	}else{
		cout << "No se ha encontrado la pelicula." << endl;
	}

	char q[2];
	cout << "(Q para salir)";
	cin >> q;

	if ((strcmp(q, "q") == 0) || (strcmp(q, "Q") == 0)) {
		menuPrincipal(s, u);
	}
}

void menuOfertasPuntos(SOCKET *s, Usuario u) {
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

	switch (opcion) {
	case 1:
		menuOfertas(s, u);
		break;
	case 2:
		menuPuntos(s, u);
		break;
	case 3:
		menuPrincipal(s, u);
		break;
	default:
		break;
	}
}

void menuPuntos(SOCKET *s, Usuario u) {
	cout << endl;
	cout << endl;
	cout << "TUS PELICULAS ALQUILADAS" << endl;
	cout << "=======================================" << endl;

	/*SACAR UNA LISTA DE LAS PELICULAS ALQUILADAS POR EL USUARIO.
	 ESA LISTA DEBE DE SACARSE DE LA BASE DE DATOS.
	 AL FINAL DE LA LISTA DE ALQUILERES SE DEBE DE PONER EL TOTAL DE PUNTOS DEL USUARIO */

	int numPeliculas = comandoGetNumAlquileres(s, u);
	Pelicula *p = new Pelicula();

	listaPelis peliculas(p, numPeliculas);

	comandoGetAlquileres(s, u, peliculas, numPeliculas);

	for (int i = 0; i < peliculas.getNumPeliculas(); ++i) {
		cout << i << ". " << peliculas.pelis[i].getNombre() << endl;
	}

	cout << endl << endl << "TOTAL PUNTOS: " << u.getPuntos() << endl << endl;

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

	if ((strcmp(q, "q") == 0) || (strcmp(q, "Q") == 0)) {
		menuOfertasPuntos(s, u);
	}
}

void menuOfertas(SOCKET *s, Usuario u) {
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

	switch (opcion) {
	case 1:
		ofertasRefrescos(s, u);
		break;
	case 2:
		ofertasSnacks(s, u);
		break;
	case 3:
		menuOfertasPuntos(s, u);
		break;
	default:
		break;
	}
}

void ofertasSnacks(SOCKET *s, Usuario u) {
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
	switch (opcion) {
	case 1:
		if (u.getPuntos() < 30) {
			cout << "No tienes puntos suficientes" << endl;;
			Sleep(4000);
			system("cls");
			ofertasSnacks(s, u);
			break;
		} else {
			comandoCambiarPuntos(s, u, u.getPuntos() - 30);
			u.setPuntos(u.getPuntos() - 30);
			cout << "Doritos canjeados por 30 puntos" << endl;;
			Sleep(3000);
			menuOfertas(s, u);
			break;
		}
	case 2:
		if (u.getPuntos() < 25) {
			cout << "No tienes puntos suficientes" << endl;;
			Sleep(4000);
			system("cls");
			ofertasSnacks(s, u);
			break;
		} else {
			comandoCambiarPuntos(s, u, u.getPuntos() - 25);
			u.setPuntos(u.getPuntos() - 25);
			cout << "Patatas fritas canjeadas por 25 puntos" << endl;;
			Sleep(3000);
			menuOfertas(s, u);
			break;
		}
	case 3:
		if (u.getPuntos() < 32) {
			cout << "No tienes puntos suficientes" << endl;
			Sleep(4000);
			system("cls");
			ofertasSnacks(s, u);
			break;
		} else {
			comandoCambiarPuntos(s, u, u.getPuntos() - 32);
			u.setPuntos(u.getPuntos() - 32);
			cout << "Cheetos Pandilla canjeados por 32 puntos" << endl;;
			Sleep(3000);
			menuOfertas(s, u);
			break;
		}
	case 4:
		if (u.getPuntos() < 40) {
			cout << "No tienes puntos suficientes" << endl;;
			Sleep(4000);
			system("cls");
			ofertasSnacks(s, u);
			break;
		} else {
			comandoCambiarPuntos(s, u, u.getPuntos() - 40);
			u.setPuntos(u.getPuntos() - 40);
			cout << "Pelotazos canjeados por 40 puntos" << endl;;
			Sleep(3000);
			menuOfertas(s, u);
			break;
		}
	case 5:
		menuOfertas(s, u);
		break;
	default:
		break;
	}
}

void ofertasRefrescos(SOCKET *s, Usuario u) {
	cout << endl;
	cout << endl;
	cout << "REFRESCOS" << endl;
	cout << "=======================================" << endl;
	cout << "1. Sprite (20 puntos)" << endl;
	cout << "2. Kas (15 puntos)" << endl;
	cout << "3. CocaCola(35 puntos)" << endl;
	cout << "4. Monster (40 puntos)" << endl;
	cout << "5. Volver a las ofertas" << endl;
	cout << endl;
	cout << "Introducir opcion: ";

	int opcion;
	cin >> opcion;

	/*ACCEDER A LA BASE DE DATOS Y QUITARLE LOS PUNTOS PROPORCIONALES A LA OPCION ELEGIDA AL USUARIO
	 * PRINTEAR POR EJEMPLO "SPRITE CANJEADO POR 20 PUNTOS" Y DEVOLVERLE AL MENU DE OFERTAS   --------- MIKEL
	 */
	switch (opcion) {
	case 1:
		if (u.getPuntos() < 20) {
			cout << "No tienes puntos suficientes" << endl;;
			Sleep(4000);
			system("cls");
			ofertasSnacks(s, u);
			break;
		} else {
			comandoCambiarPuntos(s, u, u.getPuntos() - 20);
			u.setPuntos(u.getPuntos() - 20);
			cout << "Sprite canjeado por 20 puntos" << endl;;
			Sleep(3000);
			menuOfertas(s, u);
			break;
		}
	case 2:
		if (u.getPuntos() < 15) {
			cout << "No tienes puntos suficientes" << endl;;
			Sleep(4000);
			system("cls");
			ofertasSnacks(s, u);
			break;
		} else {
			comandoCambiarPuntos(s, u, u.getPuntos() - 15);
			u.setPuntos(u.getPuntos() - 15);
			cout << "Kas canjeado por 15 puntos" << endl;;
			Sleep(3000);
			menuOfertas(s, u);
			break;
		}
	case 3:
		if (u.getPuntos() < 35) {
			cout << "No tienes puntos suficientes" << endl;;
			Sleep(4000);
			system("cls");
			ofertasSnacks(s, u);
			break;
		} else {
			comandoCambiarPuntos(s, u, u.getPuntos() - 35);
			u.setPuntos(u.getPuntos() - 35);
			cout << "CocaCola canjeada por 35 puntos" << endl;;
			Sleep(3000);
			menuOfertas(s, u);
			break;
		}
	case 4:
		if (u.getPuntos() < 40) {
			cout << "No tienes puntos suficientes" << endl;;
			Sleep(4000);
			system("cls");
			ofertasSnacks(s, u);
			break;
		} else {
			comandoCambiarPuntos(s, u, u.getPuntos() - 40);
			u.setPuntos(u.getPuntos() - 40);
			cout << "Monster canjeada por 40 puntos" << endl;;
			Sleep(3000);
			menuOfertas(s, u);
			break;
		}
	case 5:
		menuOfertas(s, u);
		break;
	default:
		break;
	}
}
