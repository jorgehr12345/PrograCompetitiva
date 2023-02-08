#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define POT(x) ((x) * (x))
const ll MX = 3e4 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

ll obtenerBit(ll num, ll pos) {
    return ((num >> pos) & 1);
}

bool verificarPrendido(ll num, ll pos) {
    if (((num >> pos) & 1) == 1) {
        return true;
    }
    return false;
}

int main() {
    inic;
    inic2;
    ll n;
    cin >> n;
    for (ll i = 0; i <= 20; i++) {
        if (verificarPrendido(n, i)) {
            cout << pow(2, i) << " asd " << endl;
        }
    }
    // for (ll i = 0; i < (1 << 5); i++) {
    //     for (ll j = 0; j < 5; j++) {
    //         if (verificarPrendido(i, j) == true) {
    //             cout << i << " qwe " << j << endl;
    //         }
    //     }
    // }
    return 0;
}