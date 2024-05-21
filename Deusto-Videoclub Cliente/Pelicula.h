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
	char* pelicula;
public:
	Pelicula();
	Pelicula(char* peli);
	virtual ~Pelicula();

	void setNombre(char* nombre);
	char* getNombre();

};

class listaPelis{
public:
	Pelicula* pelis;
	int numPeliculas;

	listaPelis();
	listaPelis(Pelicula* pelis, int numPeliculas);
	~listaPelis();

	void setNumPeliculas(int numPeliculas);
	int getNumPeliculas();
};

#endif /* PELICULA_H_ */
