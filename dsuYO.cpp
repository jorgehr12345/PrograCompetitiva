#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const ll MX = 2e5 + 2;

map<ll, ll> ma;
map<pair<ll, ll>, ll> mapa;
set<ll> se;

ll tamanio[MX], lider[MX], minimo[MX];
ll find_lider(ll nodo) {
    if (lider[nodo] == nodo) {
        return nodo;
    }
    lider[nodo] = find_lider(lider[nodo]);
    return lider[nodo];
}
void join(ll nodo_a, ll nodo_b) {
    nodo_a = find_lider(nodo_a);
    nodo_b = find_lider(nodo_b);
    if (nodo_a != nodo_b) {
        if (tamanio[nodo_a] >= tamanio[nodo_b]) {
            tamanio[nodo_a] += tamanio[nodo_b];
            lider[nodo_b] = nodo_a;
            minimo[nodo_a] = min(minimo[nodo_b], minimo[nodo_a]);
        } else {
            tamanio[nodo_b] += tamanio[nodo_a];
            lider[nodo_a] = nodo_b;
            minimo[nodo_b] = min(minimo[nodo_b], minimo[nodo_a]);
        }
    }
}

ll valores[MX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    fill(tamanio, tamanio + n + 1, 1);
    iota(lider, lider + n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> valores[i];
        minimo[i] = valores[i];
    }
    ll m;
    cin >> m;
    for (ll i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        join(a, b);
    }

    ll a, b;
    cin >> a >> b;
    while (lider[a] != a) {
        a = lider[a];
    }
    while (lider[b] != b) {
        b = lider[b];
    }
    if (a == b) {
        cout << "Estan en el mismo grupo";
    }
    // ll q;
    // cin >> q;
    // while (q--) {
    //     ll a, b;
    //     cin >> a >> b;
    //     if (find_lider(a) != find_lider(b)) {
    //         cout << "No estan en el mismo grupo" << endl;
    //     }
    // }
    return 0;
}
