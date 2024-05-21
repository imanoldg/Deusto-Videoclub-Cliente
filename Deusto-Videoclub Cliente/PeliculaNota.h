#ifndef PELICULANOTA_H_
#define PELICULANOTA_H_

class PeliculaNota
{
private:
    char titulo[100];
    int duracion;
    float nota;
    char genero[50];
    char descripcion[500];

public:
    PeliculaNota(const char* titulo, int duracion, float nota, const char* genero, const char* descripcion);
    
    const char* getTitulo() const;
    int getDuracion() const;
    float getNota() const;
    const char* getGenero() const;
    const char* getDescripcion() const;
};


#endif