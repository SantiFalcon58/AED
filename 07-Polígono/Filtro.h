#pragma once
#include <fstream>
#include "Poligono.h"
#include <vector>

using namespace std;

void extraerPoligono(ifstream& in, vector<Poligono> &v);

void insertarPoligono(ofstream& out, const vector<Poligono> v);

void CopiarPolígonosConPerímetrosMayoresA(double x, string nombreArchivoIn, string nombreArchivoOut);
