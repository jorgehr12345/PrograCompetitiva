#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 2e5 + 2;

ll orden[MX], entrante[MX], saliente[MX], contComp = 0;
vector<ll> adj[MX], adj2[MX], adjCond[MX];
bool val[MX], val2[MX];
stack<ll> st;
void dfs1(ll ini) {
    val[ini] = true;
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (val[adj[ini][i]] == false) {
            dfs1(adj[ini][i]);
        }
    }
    cout << "METO: " << ini << endl;
    st.push(ini);
}
void dfs2(ll ini, ll ordenSCC) {
    orden[ini] = ordenSCC;
    val2[ini] = true;
    for (ll i = 0; i < adj2[ini].size(); i++) {
        if (val2[adj2[ini][i]] == false) {
            dfs2(adj2[ini][i], ordenSCC);
        }
    }
}

void kosaraju(ll nodos) {
    for (ll i = 1; i <= nodos; i++) {
        if (val[i] == false) {
            dfs1(i);
        }
    }
    while (!st.empty()) {
        ll valor = st.top();
        cout << "Estoy en el valor: " << valor << endl;
        if (val2[valor] == true) {
            st.pop();
        } else {
            contComp++;
            cout << "Entro a dfs: " << valor << " asd " << contComp << endl;
            dfs2(valor, contComp);
            st.pop();
        }
    }
    set<pair<ll, ll>> aristas;
    for (ll i = 1; i <= nodos; i++) {
        for (ll j = 0; j < adj[i].size(); j++) {
            if (orden[i] != orden[adj[i][j]]) {
                if (aristas.find({orden[i], orden[adj[i][j]]}) == aristas.end()) {
                    aristas.insert({orden[i], orden[adj[i][j]]});
                    adjCond[orden[i]].pb(orden[adj[i][j]]);
                    saliente[orden[i]]++;
                    entrante[orden[adj[i][j]]]++;
                }
            }
        }
    }
}
/*PARA USAR 2-SAT*/
// XOR = (a OR b) AND (neg(a) OR neg(b))
// neg(XOR) = (neg(a) OR b) AND (a OR neg(b))

ll neg(ll num, ll n) {
    if (num > n) {
        return num - n;
    }
    return num + n;
}

void addOr(ll a, ll b, ll n) {
    adj[neg(a, n)].pb(b);
    adj2[b].pb(neg(a, n));
    adj[neg(b, n)].pb(a);
    adj2[a].pb(neg(b, n));
}

bool valTopo[MX];
ll ordenTopo[MX];
ll ordenActual;
void dfsTopo(ll ini) {
    valTopo[ini] = true;
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (valTopo[adj[ini][i]] == false) {
            dfsTopo(adj[ini][i]);
        }
    }
    ordenTopo[ini] = ordenActual;
    ordenActual--;
}
void topoSort(ll n) {
    ordenActual = n;
    for (ll i = 1; i <= n; i++) {
        if (valTopo[i] == false) {
            dfsTopo(i);
        }
    }
}

pair<bool, string> cumple(ll n) {
    bool resp = true;
    topoSort(2 * n);
    string devolver = "";
    for (ll i = 1; i <= n; i++) {
        if (orden[i] == orden[neg(i, n)]) {
            resp = false;
        } else {
            if (ordenTopo[i] < ordenTopo[neg(i, n)]) {
                devolver += '0';
            } else {
                devolver += '1';
            }
        }
    }
    return {resp, devolver};
}

void limpiar(ll n) {
    for (ll i = 0; i <= n; i++) {
        adj[i].clear();
        adj2[i].clear();
        valTopo[i] = false;
        val[i] = false;
        val2[i] = false;
    }
}

/*FIN 2-SAT*/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    while (m--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj2[b].pb(a);
    }
    kosaraju(n); /*Si es 2-sat: kosaraju(2*n); */
    for (ll i = 1; i <= n; i++) {
        cout << orden[i] << " asasda " << endl;
    }
    limpiar(n); /*Si es 2-sat: limpiar(2*n);*/

    return 0;
}
