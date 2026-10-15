#include <iostream>
#include <vector>
#include <algorithm>

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

void quickSort(vector<T>& v, int ini, int fin) {
	if(ini < fin) {
		int pivot = partition(v,ini,fin);
		quickSort(v,ini,pivot-1);
		quickSort(v,pivot+1,fin);
	}
}

int partition(vector<T>& v, int ini, int fin) {
    T x = v[fin];
    int i = ini;
    for(int j = ini; j < fin; j++) {
        if(v[j] <= x) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[fin]);
    return i;
}
