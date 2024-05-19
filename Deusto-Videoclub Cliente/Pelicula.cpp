/*
 * Pelicula.cpp
 *
 *  Created on: 19 may 2024
 *      Author: Usuario
 */
#include "Pelicula.h"
#include "string.h"
#include <iostream>
using namespace std;

Pelicula::Pelicula(){
	this->peliculas = NULL;
	this->numPeliculas = 0;
}

Pelicula::Pelicula(char* peliculas, int numPeliculas){
	this->peliculas = new char*[numPeliculas];
	this->numPeliculas = numPeliculas;
}

Pelicula::~Pelicula(){
	delete[] this->peliculas;
}

void Pelicula::setNombre(char* nombre, int orden){
	if(orden <= this->numPeliculas){
		this->peliculas[orden -1] = new char[strlen(nombre)];
		this->peliculas[orden - 1] = nombre;
	}
}

char* Pelicula::getNombre(int orden){
	return this->peliculas[orden - 1];
}

void Pelicula::setNumPeliculas(int numPeliculas){
	this->numPeliculas = numPeliculas;
}

int Pelicula::getNumPeliculas(){
	return this->numPeliculas;
}
