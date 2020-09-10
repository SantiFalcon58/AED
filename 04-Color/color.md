**Problema** <br />
Diseñar un tipo Color basado en el modelo RGB1
, con tres canales de 8 bits.
Todo color está compuesto por tres componentes: intensidad de red (rojo), de
green (verde), y de blue (azul). Cada intensidad está en el rango [0, 255]. Definir
los valores para rojo, azul, verde, cyan, magenta, amarillo, negro, y blanco. Dos
colores se pueden mezclar, lo cual produce un nuevo color que tiene el promedio
de intensidad para cada componente.

**Hipotesis**<br />
La hipótesis para la función mezclarConProporcoines fue la de utilizar 3 porcentajes entre el 0 y el 100, que afectarían al RGB del primer color

**Lexico**<br />
Color ∈ { {red,green,blue} / {red,green,blue} ∈ [0,255]};

**Definicion**<br />
Sumar: Color,Color > Color (Suma los valores de R G y B de las 2 entradas para generar un color nuevo) <br /> 
Restar: Color,Color > Restar (Resta los valores de R G y B del segundo Color al primero, generando un color nuevo) <br />
getHtmlRgb: Color > String (Devuelve en el valor de un Color como String en HTML: rgb(R,G,B) )<br />
getHtmlHex: Color > String (Devuelve el valor Hexadecimal del color en String) <br />
isIgual: Color, Color > bool(Devuelve true en caso de que todas las componentes R G y B sean iguales, false caso contrario) <br />
mezclarColores: Color,Color > Color (Realiza el promedio entre cada una de los componentes R G y B de ambos colores, generando un color nuevo) <br />
getComplementario: Color> Color (Devuelve el inverso de un Color dado sus componentes R G y B (255-valor) ) <br />
mezclarConProporciones: Color, Color, array<int,3> > Color (Mezcla los componentes R G y B <br />


Sumar: Color -> Color/ Sumar(color1,color2) = {color1red + color2red, color1green+color2green, color1blue+ color2blue} ^ color1.red [0,255]
