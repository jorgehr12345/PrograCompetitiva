#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 2e3 + 2;

vector<vector<double>> vec;

vector<vector<double>> operacion(vector<vector<double>> izq, vector<vector<double>> der) {
    vector<vector<double>> devolver;
    ll filas = izq.size(), columnas = der[0].size();
    for (ll i = 0; i < filas; i++) {
        vector<double> temporal;
        for (ll j = 0; j < columnas; j++) {
            double resultado = 0;
            for (ll k = 0; k < der.size(); k++) {
                resultado += (izq[i][k] * der[k][j]);
            }
            temporal.pb(resultado);
        }
        devolver.pb(temporal);
    }
    return devolver;
}

vector<vector<double>> matriz_pot(vector<vector<double>> r, ll potencia) {
    if (potencia == 1) {
        return r;
    }
    vector<vector<double>> temp = matriz_pot(r, potencia / 2);

    if (potencia % 2 == 0) {
        return operacion(temp, temp);
    }
    return operacion(operacion(temp, temp), r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<double> s;
    s.pb(0);
    s.pb(1);
    vec.pb(s);
    s.clear();
    s.pb(1);
    s.pb(1);
    vec.pb(s);

    vector<vector<double>> rpta = matriz_pot(vec, n - 1);
    cout << rpta[1][1] << '\n';
    // ll dimension1, dimension2, dimension3, dimension4;
    // cin >> dimension1 >> dimension2 >> dimension3 >> dimension4;
    // vector<vector<double>> izquierda, derecha, rpta;
    // while (dimension1--) {
    //     vector<double> p;
    //     ll as = dimension2;
    //     while (as--) {
    //         double l;
    //         cin >> l;
    //         p.pb(l);
    //     }
    //     izquierda.pb(p);
    // }
    // while (dimension3--) {
    //     vector<double> p;
    //     ll as = dimension4;
    //     while (as--) {
    //         double l;
    //         cin >> l;
    //         p.pb(l);
    //     }
    //     derecha.pb(p);
    // }
    // rpta = operacion(izquierda, derecha);
    // for (ll i = 0; i < rpta.size(); i++) {
    //     for (ll j = 0; j < rpta[i].size(); j++) {
    //         cout << rpta[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
