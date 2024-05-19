/*
 * Pelicula.h
 *
 *  Created on: 19 may 2024
 *      Author: Usuario
 */

#ifndef PELICULAS_H_
#define PELICULAS_H_

class Peliculas{
private:
	char** peliculas;
	int numPeliculas;

public:
	Peliculas();
	Peliculas(char* peli, int numPeliculas);
	virtual ~Peliculas();

	void setNombre(char* nombre, int orden);
	char* getNombre(int orden);
	void setNumPeliculas(int numPeliculas);
	int getNumPeliculas();
};

#endif /* PELICULAS_H_ */
