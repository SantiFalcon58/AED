all: PoligonosContiguos PoligonosEnlazados

PoligonosContiguos: Color.o Filtro.o Pruebas.o Punto.o PoligonoContiguo.o
	gcc -o PoligonosContiguos Color.o Filtro. Pruebas.o Punto.o PoligonoContiguo.o
	
PoligonosEnlazados: Color.o Filtro.o Pruebas.o Punto.o Poligono.o
	gcc -o PoligonosEnlazados Color.o Filtro.o Pruebas.o Punto.o Poligono.o
	
Color.o: Color.cpp
	gcc -c color.cpp
	
Filtro.o: Filtro.cpp
	gcc -c Filtro.cpp
	
Pruebas.o: Pruebas.cpp
	gcc -c Pruebas.cpp
	
Punto.o: Punto.cpp
	gcc -c Punto.cpp
	
PoligonoContiguo.o: PoligonoContiguo.cpp
	gcc -c PoligonoContiguo.cpp
	
Poligono.o: Poligono.cpp
	gcc -c Poligono.cpp
	
clean:
	rm -rf all *.o