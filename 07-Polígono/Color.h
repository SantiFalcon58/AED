#pragma once
#include <stdint.h>
#include <string>

using namespace std;

struct Color {
    unsigned red;
    unsigned green;
    unsigned blue;
};


Color Sumar(const Color, const Color);
Color Restar(const Color, const Color);
string getHtmlRgb(const Color);
string getHtmlHex(const Color);
bool isColorIgual(const Color, const Color);
Color mezclarColores(const Color, const Color);
Color getComplementario(const Color);
Color colorFromString(string s);
