/*
 * Usuario.cpp
 *
 *  Created on: 16 may 2024
 *      Author: Usuario
 */
#include "Usuario.h"
#include <iostream>
#include "string.h"
using namespace std;


Usuario::Usuario(char* dni, char* nombre, char* apellido, char* email, int telefono, char* user, char* contra, char genero, char* fechaNcto, int numTarjeta, int puntos){
	strcpy(this->dni, dni);
	strcpy(this->nombre, nombre);
	strcpy(this->apellido, apellido);
	strcpy(this->email, email);
	this->telefono = telefono;
	strcpy(this->user, user);
	strcpy(this->contra, contra);
	this->genero = genero;
	this->fechaNcto = new char(strlen(fechaNcto) + 1);
	strcpy(this->fechaNcto, fechaNcto);
	this->numTarjeta = numTarjeta;
	this->puntos = puntos;
}

Usuario::Usuario(){
	strcpy(this->dni, "");
	strcpy(this->nombre, "");
	strcpy(this->apellido, "");
	strcpy(this->email, "");
	this->telefono = 0;
	strcpy(this->user, "");
	strcpy(this->contra, "");
	this->genero = 'M';
	this->fechaNcto = new char(strlen("") + 1);
	strcpy(this->fechaNcto, "");
	this->numTarjeta = 0;
	this->puntos = 0;
}

Usuario::Usuario(Usuario &otro){
	strcpy(this->dni, otro.dni);
	strcpy(this->nombre, otro.nombre);
	strcpy(this->apellido, otro.apellido);
	strcpy(this->email, otro.email);
	this->telefono = otro.telefono;
	strcpy(this->user, otro.user);
	strcpy(this->contra, otro.contra);
	this->genero = otro.genero;
	this->fechaNcto = new char(strlen(otro.fechaNcto) + 1);
	strcpy(this->fechaNcto, otro.fechaNcto);
	this->numTarjeta = otro.numTarjeta;
	this->puntos = otro.puntos;
}

Usuario::~Usuario(){

}


char* Usuario::getDNI(){
	return this->dni;
}

char* Usuario::getNombre(){
	return this->nombre;
}

char* Usuario::getApellido(){
	return this->apellido;
}

char* Usuario::getEmail(){
	return this->email;
}

char* Usuario::getUser(){
	return this->user;
}

int Usuario::getTlf(){
	return this->telefono;
}

char* Usuario::getContra(){
	return this->contra;
}

char Usuario::getGenero(){
	return this->genero;
}

char* Usuario::getFechaNcto(){
	return this->fechaNcto;
}

int Usuario::getNumTarjeta(){
	return this->numTarjeta;
}

int Usuario::getPuntos(){
	return this->puntos;
}

void Usuario::setPuntos(int puntos){
	this->puntos = puntos;
}

void Usuario::setApellido(char* apellido){
	strcpy(this->apellido, apellido);
}

void Usuario::setContra(char* contra){
	strcpy(this->contra, contra);
}

void Usuario::setDNI(char* dni){
	strcpy(this->dni, dni);
}

void Usuario::setEmail(char* email){
	strcpy(this->email, email);
}

void Usuario::setFechaNcto(char* fecha){
	this->fechaNcto = new char(strlen(fecha) + 1);
	strcpy(this->fechaNcto, fecha);
}

void Usuario::setGenero(char genero){
	this->genero= genero;
}

void Usuario::setNombre(char* nombre){
	strcpy(this->nombre, nombre);
}

void Usuario::setNumTarjeta(int numTarj){
	this->numTarjeta = numTarj;
}

void Usuario::setTlf(int tlf){
	this->telefono = tlf;
}

void Usuario::setUser(char* user){
	strcpy(this->user, user);
}


