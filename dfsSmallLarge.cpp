#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
using Long = ll;
typedef long double ld;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

ll tam[MX];
vector<ll> adj[MX];
void dfsPesos(ll ini, ll pap) {
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (adj[ini][i] != pap) {
            dfsPesos(adj[ini][i], ini);
            tam[ini] += tam[adj[ini][i]];
        }
    }
}

ll color[MX], big[MX], cantidad[MX];
void hacerQuery(ll ini, ll pap, ll valor) {
    cantidad[color[ini]] += valor;
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (adj[ini][i] != pap && big[adj[ini][i]] == 0) {
            hacerQuery(adj[ini][i], ini, valor);
        }
    }
}

void small_to_large(ll ini, ll pap, ll mant) {
    ll mayorHijo = -1, peso = -1;
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (adj[ini][i] != pap) {
            if (peso < tam[adj[ini][i]]) {
                mayorHijo = adj[ini][i];
                peso = tam[adj[ini][i]];
            }
        }
    }
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (adj[ini][i] != pap && adj[ini][i] != mayorHijo) {
            small_to_large(adj[ini][i], ini, 0);
        }
    }
    if (mayorHijo != -1) {
        small_to_large(mayorHijo, ini, 1);
        big[mayorHijo] = 1;
    }
    hacerQuery(ini, pap, 1);
    if (mayorHijo != -1) {
        big[mayorHijo] = 0;
    }
    if (mant == 0) {
        hacerQuery(ini, pap, -1);
    }
}

int main() {
    inic;
    inic2;
    ll n;
    cin >> n;
    fill(tam, tam + n + 1, 1);
    dfsPesos(1, -1);
    return 0;
}