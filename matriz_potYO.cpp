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

vector<vector<ll>> vec;

ll rest_mod(ll a, ll b, ll c) {
    return ((a % c) - (b % c) + c) % c;
}
ll sum_mod(ll a, ll b, ll c) {
    return (a % c + b % c) % c;
}
ll pot_mod(ll a, ll b, ll c) {
    if (b == 0) {
        return 1 % c;
    }
    int temp = pot_mod(a, b / 2, c);
    temp = (temp * temp) % c;
    if (b % 2 == 0) return temp;
    return (temp * (a % c)) % c;
}
ll mult_mod(ll a, ll b, ll c) {
    return (((a % c) * (b % c)) % c);
}
ll fastPow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1 == 1) ans = mult_mod(ans, a, c);
        a = mult_mod(a, a, c);
        b >>= 1;
    }
    return ans;
}
ll modInverse(ll a, ll c) {
    return fastPow(a, c - 2, c);
}
ll divide(ll a, ll b, ll c) {
    return mult_mod(a, modInverse(b, c), c);
}

vector<vector<ll>> operacion(vector<vector<ll>> izq, vector<vector<ll>> der, ll c) {
    vector<vector<ll>> devolver;
    ll filas = izq.size(), columnas = der[0].size();
    for (ll i = 0; i < filas; i++) {
        vector<ll> temporal;
        for (ll j = 0; j < columnas; j++) {
            ll resultado = 0;
            for (ll k = 0; k < der.size(); k++) {
                // resultado += (izq[i][k] * der[k][j]);
                resultado = sum_mod(resultado, mult_mod(izq[i][k], der[k][j], c), c);
            }
            temporal.pb(resultado);
        }
        devolver.pb(temporal);
    }
    return devolver;
}

vector<vector<ll>> matriz_pot(vector<vector<ll>> &r, ll potencia, ll c) {
    vector<vector<ll>> par;
    if (potencia == 0) {
        for (ll i = 0; i < r.size(); i++) {
            vector<ll> qwweqwqwr;
            for (ll j = 0; j < r.size(); j++) {
                if (i == j) {
                    qwweqwqwr.pb(1);
                } else {
                    qwweqwqwr.pb(0);
                }
            }
            par.pb(qwweqwqwr);
        }
        return par;
    }
    if (potencia == 1) {
        return r;
    }
    vector<vector<ll>> temp = matriz_pot(r, potencia / 2, c);

    if (potencia % 2 == 0) {
        return operacion(temp, temp, c);
    }
    return operacion(operacion(temp, temp, c), r, c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> s;
    s.pb(0);
    s.pb(1);
    vec.pb(s);
    s.clear();
    s.pb(1);
    s.pb(1);
    vec.pb(s);

    vector<vector<ll>> rpta = matriz_pot(vec, n - 1, 1e9 + 7);
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
