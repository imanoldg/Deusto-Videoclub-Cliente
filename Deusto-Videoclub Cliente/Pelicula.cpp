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
	strcpy(this->pelicula, "nombrePeli");
}

Pelicula::Pelicula(char* pelicula){
	strcpy(this->pelicula, pelicula);
}

Pelicula::~Pelicula(){

}

void Pelicula::setNombre(char* nombre){
	strcpy(this->pelicula, nombre);
}

char* Pelicula::getNombre(){
	return this->pelicula;
}



listaPelis::listaPelis(Pelicula* peli, int numPeliculas){
	this->pelis = new Pelicula[numPeliculas];
	this->numPeliculas = numPeliculas;
}

listaPelis::listaPelis(){
	this->pelis = NULL;
	this->numPeliculas = 0;
}

listaPelis::~listaPelis(){
	delete[] this->pelis;
}

void listaPelis::setNumPeliculas(int numPeliculas){
	this->numPeliculas = numPeliculas;
}

int listaPelis::getNumPeliculas(){
	return this->numPeliculas;
}
