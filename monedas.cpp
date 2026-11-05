#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int inf_val = numeric_limits<int>::max();

int minCambio(const vector<int>& v, int M, vector<int>& s) {

    int n = v.size();

    vector<vector<int>> T(n, vector<int>(M + 1, inf_val));

    T[0][0] = 0;

    for (int j = 1; j <= M; j++) {
        if (j >= v[0] && T[0][j - v[0]] != inf_val) {
            T[0][j] = 1 + T[0][j - v[0]];
        }
    }

    for (int i = 1; i < n; i++) {
        T[i][0] = 0;

        for (int j = 1; j <= M; j++) {

            if (j < v[i] || T[i][j - v[i]] == inf_val) {
                T[i][j] = T[i - 1][j];
            }
            else if (T[i - 1][j] != inf_val) {
                T[i][j] = min(T[i - 1][j],
                              1 + T[i][j - v[i]]);
            }
            else {
                T[i][j] = 1 + T[i][j - v[i]];
            }
        }
    }

    s.assign(n, 0);

    if (T[n - 1][M] == inf_val) {
        return -1;
    }

    int i = n - 1;
    int j = M;

    while (j > 0) {

        if (i == 0 || T[i][j] != T[i - 1][j]) {
            s[i]++;
            j -= v[i];
        }
        else {
            i--;
        }
    }

    return T[n - 1][M];
}

int main() {

    vector<int> v = {1, 4, 6};
    int M = 8;
    vector<int> s;

    int r = minCambio(v, M, s);

    cout << "Minimo de monedas: " << r << endl;

    for (int i = 0; i < s.size(); i++) {
        cout << "Monedas de " << v[i] << ": " << s[i] << endl;
    }

    return 0;
}
