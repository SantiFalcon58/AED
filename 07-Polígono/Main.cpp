#pragma once
#include <string>
#include "Color.h"
#include "Nodo.h"
#include "Punto.h"
#include "Poligono.h"
#include "Filtro.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Pruebas.h";

using namespace std;

const Color rojo{ 255,0,0 };
const Color verde{ 0,255,0 };
const Color azul{ 0,0,255 };
// Color cyan{0,255,255};
const Color cyan = Sumar(verde, azul);
// Color magenta{255,0,255};
const Color magenta = Sumar(rojo, azul);
//Color amarillo{255,255,0};
const Color amarillo = Sumar(rojo, verde);
// Color negro{0,0,0};
const Color negro = Restar(rojo, rojo);
// Color blanco{255,255,255};
const Color blanco = Sumar(Sumar(rojo, verde), azul);



int main() {
	pruebas();
	CopiarPolígonosConPerímetrosMayoresA(15,"in.poli","out.poli");
}


