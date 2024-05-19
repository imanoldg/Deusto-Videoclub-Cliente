/*
 * main.cpp
 *
 *  Created on: 16 may 2024
 *      Author: Usuario
 */
#include "menus.h"
#include "string.h"
#include "socket.h"
#include "Usuario.h"
#include <iostream>
#include <winsock2.h>
using namespace std;

int main(void){
	SOCKET s;
	SocketInit(&s);

	inicio(&s);
	return 1;
}
