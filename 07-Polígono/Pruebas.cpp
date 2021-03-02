#pragma once
#include "Punto.h"
#include "Poligono.h"
#include "Pruebas.h"
#include <iostream>
#include <assert.h>


using namespace std;

void pruebas() {


	Poligono poligono1{ {255,0,0},NULL,NULL,{},0};
	Poligono poligono2{ {0,0,0},NULL,NULL,{},0};
	Poligono poligono3{ {0,255,0},NULL,NULL,{},0};

	Punto punto1{ 1,0 };
	Punto punto2{ 1,1 };
	Punto punto3{ 0,1 };
	Punto punto4{ 0,0 };
	Punto punto5{ -3,0 };
	Punto punto6{ 2,-1 };
	Punto punto7{ 2,3 };
	Punto punto8{ 5,0 };


     const Color rojo{ 255,0,0 };
	 const Color verde{ 0,255,0 };
	 const Color azul{ 0,0,255 };
	 const Color negro{0,0,0};
	 const Color blanco{255,255,255};
	 const Color magenta{255,0,255};

	//PUNTO

	assert(isPuntoIgual({ 1,0 },punto1));
	assert(!isPuntoIgual({ 10,0 }, punto2));

	assert(getDistancia(punto1, punto2) == 1);
	assert(getDistancia(punto4, punto5) == 3);
	

	assert(getDistanciaAlOrigen(punto4) == 0);
	assert(getDistanciaAlOrigen(punto3) == 1);

	int delta[] = { 1,0 };
	mover(punto8, delta);
	assert(isPuntoIgual(punto8, {6,0}));


	assert(getCuadrante(punto2) == Cuadrante::PRIMER);
	assert(getCuadrante(punto6) == Cuadrante::CUARTO);
	assert(getCuadrante(punto7) == Cuadrante::PRIMER);


	//COLOR

	assert(isColorIgual(rojo,{ 255,0,0 }));
	assert(isColorIgual(negro, { 0,0,0 }));

	assert(isColorIgual(Sumar(rojo, azul), magenta));
	assert(isColorIgual(Sumar(Sumar(rojo,verde), azul), blanco));

	assert(isColorIgual(Restar(rojo, rojo), negro));
	assert(isColorIgual(Restar(Restar(blanco,rojo), verde), azul));

	assert(getHtmlRgb(rojo) == "rgb(255,0,0)");
	assert(getHtmlRgb(azul) == "rgb(0,0,255)");

	assert("#0000ff" == getHtmlHex(azul));
	assert("#ff0000" == getHtmlHex(rojo));


	assert(isColorIgual(mezclarColores(negro, blanco), { 127,127,127 }));

	assert(isColorIgual(getComplementario(negro), blanco));


	//POLIGONOS
	addVertice(poligono1, punto1);
	addVertice(poligono1, punto2);
	addVertice(poligono1, punto3); 
	addVertice(poligono1, punto4); 


	assert(getPerimetro(poligono1) ==  4);

	addVertice(poligono2, punto3);
	addVertice(poligono2, punto4);
	addVertice(poligono2, punto5);
	addVertice(poligono2, punto6);
	addVertice(poligono2, punto7);


	assert(getCantidadLados(poligono1) == 4);
	assert(getCantidadLados(poligono2) == 5);
	assert(getCantidadLados(poligono3) == 0);


	removeVertice(poligono1, 2);
	removeVertice(poligono2, 1);


	assert(getCantidadLados(poligono1) == 3);
	assert(getCantidadLados(poligono2) == 4);


	assert(isPuntoIgual({ 1,0 }, getVertice(poligono1, 0)));
	assert(isPuntoIgual({ 0,1 }, getVertice(poligono2, 0)));


	setVertice(poligono1, punto2, 0);
	setVertice(poligono2, punto8, 1);

	assert(isPuntoIgual({1,1}, getVertice(poligono1, 0)));
	assert(isPuntoIgual({6,0}, getVertice(poligono2, 1)));



}