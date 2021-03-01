# Enunciados del Problema

- Desarrollar el tipo Color basado en el modelo RGB (compuestos por 3 componentes de intensidad) y dado 2 colores, se deben poder mezclar generando uno nuevo.
- Desarrollar el tipo Punto, el cual tenga dos componentes que representen los valores en el plano de dicho Punto.
- Desarrollar el tipo Polígono con color, el cual tenga una cantidad dinámica de vértices y debe incluir las operaciones para agregar, remover, acceder y modificar esos vértices
- Dado un archivo con polígonos, copiar a un nuevo archivos los polígonos que tienen un perímetro menor a un valor x.


# Análisis

Para el desarrollo del tipo color crearé un struct que contenga 3 variables de números naturales que irán desde el 0 al 255, para indicar la intensidad del color.

Para el tipo Punto, usaré un struct con 2 variables enteras que representen los valores de X e Y del plano real de dicho punto.

En el caso del Polígono, se desarrollarán 2 versiones, una contigua y otra enlazada. 
En la primera versión se utilizará un arreglo de puntos para representar los vértices del Polígono, por lo cual no será 100% dinámico, ya que tendrá un límite inicial que determinará el máximo de vértices a ingresar. También utilizaré una variable entera para determinar la cantidad de lados que contenga el polígono, con un valor inicial de 0 y que aumentará cuando se añada un nuevo vértice, y disminuirá cuando se remueva. Debido a esto, solo seremos capaces de eliminar el último vértice que fue ingresado al polígono.
En la versión enlazada, tendremos 2 NodoPunto, que indicarán el primer vértice y el último. Un NodoPunto es una estructura que contiene un polígono y la referencia a otro NodoPunto, creando una especie de lista. Esto nos permitirá poder manipular la cantidad de vértices de forma dinámica, pudiendo eliminar cualquiera de los vértices que se encuentren en el polígono en cualquier momento. También nos permitirá incrementar o disminuir el espacio en memoria que ocupe nuestro polígono, ya que a diferencia de la versión contigua, en la que tenía un tamaño estático, la versión enlazada dependerá de la cantidad de vértices que tenga el mismo.

Para el cuarto enunciado crearé un flujo de entrada y salida de datos utilizando <ifstream> y <ofstream>, que dado un archivo llamado "in.poli", cargue los polígonos en un vector de polígonos auxiliar, para posteriormente pegarlos en un archivo "out.poli" cuando el perímetro del polígono sea mayor que un valor X.

# Hipótesis

- Los componentes R, G y B del Color deben estar dentro del intérvalo [0,255]
- Se desarrollarán 2 versiones del tipo Polígono, una contigua y otra enlazada.
- En la versión contigua de Punto será posible únicamente añadir hasta 100 puntos
- En la versión contigua de Punto, solo se podrá remover el último elemento de los puntos
- El valor x de perímetro será 15 por defecto.
- El formato para guardar los polígonos en un archivo será el siguiente:

		R,G,B (Color)
		X1,Y1 (Punto 1)
		Xn,Yn (Punto n)
		       (Espacio para determinar fin de polígono)

# Prototipos

Color Sumar(const Color, const Color);
Color Restar(const Color, const Color);
string getHtmlRgb(const Color);
string getHtmlHex(const Color);
bool isColorIgual(const Color, const Color);
Color mezclarColores(const Color, const Color);
Color getComplementario(const Color);
Color colorFromString(string s);

void extraerPoligono(ifstream& in, vector<Poligono> &v);
void insertarPoligono(ofstream& out, const vector<Poligono> v);
void CopiarPolígonosConPerímetrosMayoresA(double x, string nombreArchivoIn, string nombreArchivoOut);

float getPerimetro(const Poligono poligono);
int getCantidadLados(const Poligono poligono);
void addVertice(Poligono& poligono, const Punto punto);
void setVertice(Poligono& poligono, Punto& punto, const unsigned index);
Punto getVertice(const Poligono poligono, const unsigned);
void removeVertice(Poligono& poligono, const unsigned);
void imprimir(const Poligono poligono);

bool isPuntoIgual(Punto, Punto);
float getDistancia(Punto, Punto);
float getDistanciaAlOrigen(Punto);
void mover(Punto& punto, unsigned values[]);
Cuadrante getCuadrante(Punto);
Punto puntoFromString(string s);
