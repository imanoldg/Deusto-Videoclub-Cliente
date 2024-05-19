/*
 * Pelicula.cpp
 *
 *  Created on: 19 may 2024
 *      Author: Usuario
 */
#include "Peliculas.h"

#include "string.h"
#include <iostream>
using namespace std;

Peliculas::Peliculas(){
	this->peliculas = NULL;
	this->numPeliculas = 0;
}

Peliculas::Peliculas(char* peliculas, int numPeliculas){
	this->peliculas = new char*[numPeliculas];
	this->numPeliculas = numPeliculas;
}

Peliculas::~Peliculas(){
	delete[] this->peliculas;
}

void Peliculas::setNombre(char* nombre, int orden){
	if(orden <= this->numPeliculas){
		this->peliculas[orden -1] = new char[strlen(nombre)];
		this->peliculas[orden - 1] = nombre;
	}
}

char* Peliculas::getNombre(int orden){
	return this->peliculas[orden - 1];
}

void Peliculas::setNumPeliculas(int numPeliculas){
	this->numPeliculas = numPeliculas;
}

int Peliculas::getNumPeliculas(){
	return this->numPeliculas;
}
