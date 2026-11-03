#include<iostream>
using namespace std;

int main(){

int a, b, c;

cout <<"Ingresa el valor de A: ";
cin >> a;

cout <<"Ingresa el valor de B: ";
cin >> b;

cout <<"Ingresa el valor de C: ";
cin >> c;

if(a == 0 && b == 0 && c == 0){
cout << "Los valores no indican la figura";
    }
else if(b == 0 && c == 0){
cout << "La figura es un Circulo";
        }
else if(c == 0){
if(a == b){
cout << "La figura es un Cuadrado";
        }
else{
cout << "La figura es un Rectangulo";
        }
    }

else {
if(a + b <= c || a + c <= b || b + c <= a){
cout << "Los valores no indican la figura";
        }
else if(a == b && b == c){
cout << "La figura es un Triangulo Equilatero";
        }
else if(a == b || a == c || b == c){
cout << "La figura es un Triangulo Isosceles";
        }
else{
cout << "La figura es un Triangulo Escaleno";
        }
    }

return 0;
}