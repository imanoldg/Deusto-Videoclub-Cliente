/*
 * Usuario.h
 *
 *  Created on: 16 may 2024
 *      Author: Usuario
 */
#ifndef USUARIO_H_
#define USUARIO_H_

class Usuario{
private:
	char dni[10];
	char nombre[40];
	char apellido[60];
	char email[60];
	int telefono;
	char user[40];
	char contra[16];
	char genero;
	char* fechaNcto;
	int numTarjeta;
	int puntos;

public:
	Usuario(char* dni, char* nombre, char* apellido, char* email, int telefono, char* user, char* contra, char genero, char* fechaNcto, int numTarjeta, int puntos);
	Usuario();
	Usuario(Usuario &u);
	~Usuario();

	char* getDNI();
	char* getNombre();
	char* getApellido();
	char* getEmail();
	int getTlf();
	char* getUser();
	char* getContra();
	char getGenero();
	char* getFechaNcto();
	int getNumTarjeta();
	int getPuntos();

	void setPuntos(int puntos);
	void setDNI(char* dni);
	void setNombre(char* nombre);
	void setApellido(char* apellido);
	void setEmail(char* email);
	void setTlf(int tlf);
	void setUser(char* user);
	void setContra(char* contra);
	void setGenero(char genero);
	void setFechaNcto(char* fecha);
	void setNumTarjeta(int numTarj);
};

#endif /* USUARIO_H_ */


