#pragma once
#include "Poligono.h"

struct NodoPoligono {
	Poligono poligono;
	NodoPoligono* siguiente;
};

struct NodoPunto {
	Punto punto;
	NodoPunto* siguiente;
};