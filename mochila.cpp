#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mochila(const vector<int>& p, const vector<int>& b,
            int M, vector<int>& s) {

    int n = p.size();

    vector<vector<int>> T(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= M; j++) {

            if (p[i - 1] > j) {
                T[i][j] = T[i - 1][j];
            }
            else {
                T[i][j] = max(T[i - 1][j],
                              b[i - 1] + T[i - 1][j - p[i - 1]]);
            }
        }
    }

    s.assign(n, 0);

    int i = n;
    int j = M;

    while (i > 0 && j > 0) {

        if (T[i][j] != T[i - 1][j]) {
            s[i - 1] = 1;
            j = j - p[i - 1];
        }

        i--;
    }

    return T[n][M];
}

int main() {

    vector<int> p = {9, 6, 5};
    vector<int> b = {38, 40, 24};
    int M = 15;
    vector<int> s;

    int r = mochila(p, b, M, s);

    cout << "Beneficio maximo: " << r << endl;

    for (int i = 0; i < s.size(); i++) {
        cout << "Objeto " << i << ": " << s[i] << endl;
    }

    return 0;
}
