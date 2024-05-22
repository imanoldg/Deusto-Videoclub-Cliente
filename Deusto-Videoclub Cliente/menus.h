/*
 * menus.h
 *
 *  Created on: 16 may 2024
 *      Author: Usuario
 */

#ifndef MENUS_H_
#define MENUS_H_
#include <winsock2.h>
#include "Usuario.h"
#include "PeliculaNota.h"
#include <vector>
using namespace std;

void inicio(SOCKET* s);
void recuperarContra(SOCKET* s);
void inicioSesion(SOCKET* s);
void menuPrincipal(SOCKET* s, Usuario u);
void estatPeliculas(SOCKET *s, Usuario u);
void topGeneros(SOCKET *s, Usuario u);
void pelisMasAlquiladas(SOCKET *s, Usuario u);
void datosPelicula(SOCKET *s, const char* nombrePeli, Usuario u);
void menuOfertasPuntos(SOCKET *s, Usuario u);
void menuPuntos(SOCKET *s, Usuario u);
void menuOfertas(SOCKET *s, Usuario u);
void ofertasRefrescos(SOCKET *s, Usuario u);
void ofertasSnacks(SOCKET *s, Usuario u);
vector<PeliculaNota> leerPeliculas();

#endif /* MENUS_H_ */
