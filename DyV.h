#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int busquedaBinaria(T val, const vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1;
    }

    int mitad = (ini + fin) / 2;

    if (val == v[mitad]) {
        return mitad;
    }
    else {
        if (v[mitad] > val) {
            return busquedaBinaria(val, v, ini, mitad - 1);
        }
        else {
            return busquedaBinaria(val, v, mitad + 1, fin);
        }
    }
}
