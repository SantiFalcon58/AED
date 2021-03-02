#pragma once
#include <string>

using namespace std;

struct Punto {
    int x;
    int y;
};

enum struct Cuadrante { PRIMER, SEGUNDO, TERCER, CUARTO };


bool isPuntoIgual(Punto, Punto);
float getDistancia(Punto, Punto);
float getDistanciaAlOrigen(Punto);
void mover(Punto& punto, unsigned values[]);
Cuadrante getCuadrante(Punto);
Punto puntoFromString(string s);

