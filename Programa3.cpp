#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// DECLARACIÓN DE CONSTANTES
const int NINGUNA = 0;
const int CUADRADO = 1;
const int RECTANGULO = 2;
const int CIRCULO = 3;
const int EQUILATERO = 4;
const int ISOSCELES = 5;
const int ESCALENO = 6;

const double PI = 3.14;

// PROTOTIPOS DE FUNCIONES
int determinarFigura(int a, int b, int c);
double calcularArea(int figura, int a, int b, int c);

int main() {
    // DECLARACIÓN DE VARIABLES PRINCIPALES
    int opcion = 0;
    int figuraActual = NINGUNA;
    int A = 0;
    int B = 0;
    int C = 0;
    double areaCalculada = 0.0;

    // MENÚ INTERACTIVO
    do {
        cout << "--- MENÚ ---\n";
        cout << "1. Determine figura.\n";
        cout << "2. Calcule área.\n";
        cout << "3. Salir.\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Entrada de datos
                cout << "Ingresa el valor de A: ";
                cin >> A;
                cout << "Ingresa el valor de B: ";
                cin >> B;
                cout << "Ingresa el valor de C: ";
                cin >> C;

                // Evaluación modular
                figuraActual = determinarFigura(A, B, C);

                switch (figuraActual) {
                    case CUADRADO:
                        cout << "La figura es un cuadrado\n";
                        break;
                    case RECTANGULO:
                        cout << "La figura es un rectángulo\n";
                        break;
                    case CIRCULO:
                        cout << "La figura es un círculo\n";
                        break;
                    case EQUILATERO:
                        cout << "La figura es un triángulo equilátero\n";
                        break;
                    case ISOSCELES:
                        cout << "La figura es un triángulo isósceles\n";
                        break;
                    case ESCALENO:
                        cout << "La figura es un triángulo escaleno\n";
                        break;
                    default:
                        cout << "Los valores no indican figura\n";
                        figuraActual = NINGUNA; // Invalida cualquier figura previa
                        break;
                }
                break;
            }
            case 2: {
                if (figuraActual == NINGUNA) {
                    cout << "Primero deberá determinar la figura en la opción 1\n";
                } else {
                    areaCalculada = calcularArea(figuraActual, A, B, C);
                    cout << fixed << setprecision(2);

                    switch (figuraActual) {
                        case CUADRADO:
                            cout << "El área del CUADRADO es " << areaCalculada << "\n";
                            break;
                        case RECTANGULO:
                            cout << "El área del RECTÁNGULO es " << areaCalculada << "\n";
                            break;
                        case CIRCULO:
                            cout << "El área del CÍRCULO es " << areaCalculada << "\n";
                            break;
                        case EQUILATERO:
                            cout << "El área del TRIÁNGULO EQUILÁTERO es " << areaCalculada << "\n";
                            break;
                        case ISOSCELES:
                            cout << "El área del TRIÁNGULO ISÓSCELES es " << areaCalculada << "\n";
                            break;
                        case ESCALENO:
                            cout << "El área del TRIÁNGULO ESCALENO es " << areaCalculada << "\n";
                            break;
                    }
                }
                break;
            }
            case 3:
                cout << "Hasta la próxima\n";
                break;

            default:
                cout << "Opción no válida\n";
                break;
        }
    } while (opcion != 3);

    return 0;
}

// FUNCIÓN: determinarFigura
int determinarFigura(int a, int b, int c) {
    if (a == 0 && b == 0 && c == 0) {
        return NINGUNA;
    } 
    else if (b == 0 && c == 0) {
        if (a > 0) {
            return CIRCULO;
        } else {
            return NINGUNA;
        }
    } 
    else if (c == 0) {
        if (a <= 0 || b <= 0) {
            return NINGUNA;
        }
        
        if (a == b) {
            return CUADRADO;
        } else {
            return RECTANGULO;
        }
    } 
    else {
        // Validación de lados positivos y desigualdad triangular
        if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
            return NINGUNA;
        } 
        else if (a == b && b == c) {
            return EQUILATERO;
        } 
        else if (a == b || a == c || b == c) {
            return ISOSCELES;
        } 
        else {
            return ESCALENO;
        }
    }
}

// FUNCIÓN: calcularArea
double calcularArea(int figura, int a, int b, int c) {
    double semiperimetro = 0.0;
    double resultadoArea = 0.0;

    switch (figura) {
        case CUADRADO:
            return a * a;

        case RECTANGULO:
            return a * b;

        case CIRCULO:
            return PI * (a * a);

        case EQUILATERO:
        case ISOSCELES:
        case ESCALENO:
            // Fórmula de Herón
            semiperimetro = (a + b + c) / 2.0;
            resultadoArea = sqrt(semiperimetro * (semiperimetro - a) * (semiperimetro - b) * (semiperimetro - c));
            return resultadoArea;

        default:
            return 0.0;
    }
}