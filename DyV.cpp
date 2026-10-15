#include <iostream>
#include <vector>
#include "DyV.h"

int main() {
    vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15};

    int val;

    cout << "Introduce el numero que quieres buscar: ";
    cin >> val;

    int resultado = busquedaBinaria(val, v, 0, v.size() - 1);

    if (resultado == -1) {
        cout << "El numero no se encuentra en el vector." << endl;
    }
    else {
        cout << "El numero esta en la posicion: "
             << resultado << endl;
    }

    return 0;
}
