#include<iostream>
using namespace std;

int main(){

    int A;
    int B;
    int AREA = 0;

    cout << "Ingresa el valor de A: " ;
    cin >> A;

    cout << "Ingresa el valor de B: ";
    cin >> B;

    if(A == 0 || B == 0){
        cout << "ninguno de los valores puede ser 0";
      }
       else {
         AREA = A * B;
    cout << "El Area del Rectangulo es: " << AREA;
}

    return 0;
}
