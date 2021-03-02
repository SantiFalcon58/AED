#ifndef HEAD_INCLUDED
#define HEAD_INCLUDED
#pragma once
#include "Color.h"
#include "Punto.h"
#include <array>

struct Poligono {
    Color color;
    struct NodoPunto * primerPunto;
    struct NodoPunto * ultimoPunto;
    array<Punto, 100> vertices;
    unsigned lados;
};


float getPerimetro(const Poligono poligono);
int getCantidadLados(const Poligono poligono);
void addVertice(Poligono& poligono, const Punto punto);
void setVertice(Poligono& poligono, Punto& punto, const unsigned index);
Punto getVertice(const Poligono poligono, const unsigned);
void removeVertice(Poligono& poligono, const unsigned);
void imprimir(const Poligono poligono);

#endif