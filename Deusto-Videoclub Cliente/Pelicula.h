/*
 * Pelicula.h
 *
 *  Created on: 19 may 2024
 *      Author: Usuario
 */

#ifndef PELICULA_H_
#define PELICULA_H_

class Pelicula{
private:
	char** peliculas;
	int numPeliculas;

public:
	Pelicula();
	Pelicula(char* peli, int numPeliculas);
	virtual ~Pelicula();

	void setNombre(char* nombre, int orden);
	char* getNombre(int orden);
	void setNumPeliculas(int numPeliculas);
	int getNumPeliculas();
};

#endif /* PELICULA_H_ */
