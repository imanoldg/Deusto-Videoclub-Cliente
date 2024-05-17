/*
 * menus.h
 *
 *  Created on: 16 may 2024
 *      Author: Usuario
 */

#ifndef MENUS_H_
#define MENUS_H_
#include <winsock2.h>

void inicio(SOCKET* s);
void recuperarContra();
void inicioSesion(SOCKET* s);
void menuPrincipal();
void estatPeliculas();
void topGeneros();
void pelisMasAlquiladas();
void datosPelicula(char* nombrePeli);
void menuOfertasPuntos();
void menuPuntos();
void menuOfertas();
void ofertasRefrescos();
void ofertasSnacks();

#endif /* MENUS_H_ */
