#include "PeliculaNota.h"
#include <cstring>

PeliculaNota::PeliculaNota(const char* titulo, int duracion, float nota, const char* genero, const char* descripcion) {
    strncpy(this->titulo, titulo, sizeof(this->titulo) - 1);
    this->titulo[sizeof(this->titulo) - 1] = '\0';  // Garantizar que termine en null

    this->duracion = duracion;
    this->nota = nota;

    strncpy(this->genero, genero, sizeof(this->genero) - 1);
    this->genero[sizeof(this->genero) - 1] = '\0';  // Garantizar que termine en null

    strncpy(this->descripcion, descripcion, sizeof(this->descripcion) - 1);
    this->descripcion[sizeof(this->descripcion) - 1] = '\0';  // Garantizar que termine en null
}

const char* PeliculaNota::getTitulo() const {
    return titulo;
}

int PeliculaNota::getDuracion() const {
    return duracion;
}

float PeliculaNota::getNota() const {
    return nota;
}

const char* PeliculaNota::getGenero() const {
    return genero;
}

const char* PeliculaNota::getDescripcion() const {
    return descripcion;
}
