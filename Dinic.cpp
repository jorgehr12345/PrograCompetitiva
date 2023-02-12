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
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e4 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

struct edge {
    ll valor = 0, flujo = 0, capacidad = 0, posAncestro = 0;
    edge(ll valor, ll capacidad, ll posAncestro)
        : valor(valor), flujo(0), capacidad(capacidad), posAncestro(posAncestro) {}
};

ll nivel[MX], nextEdge[MX];
vector<edge> adj[MX];

struct dinic {
    ll dfs(ll ini, ll sumidero, ll flujoTotal) {
        if (ini == sumidero) {
            return flujoTotal;
        }
        for (ll i = nextEdge[ini]; i < adj[ini].size(); i++) {
            ll disponible = adj[ini][i].capacidad - adj[ini][i].flujo;
            if (disponible == 0 || nivel[adj[ini][i].valor] != nivel[ini] + 1) {
                nextEdge[ini]++;
                continue;
            }
            ll flujoMin = dfs(adj[ini][i].valor, sumidero, min(flujoTotal, disponible));
            // cout << "Valor nodo: " << ini << " Valor destino: " << adj[ini][i].valor << " ";
            // cout << "Flujo minimo: " << flujoMin << endl;
            if (flujoMin > 0) {
                adj[ini][i].flujo += flujoMin;
                // cout << "Resto flujo: " << adj[ini][i].valor << " asdasd "
                //      << adj[adj[ini][i].valor][adj[ini][i].posAncestro].valor << endl;
                adj[adj[ini][i].valor][adj[ini][i].posAncestro].flujo -= flujoMin;
                return flujoMin;
            }
            nextEdge[ini]++;
        }
        return 0;
    }

    bool bfs(ll s, ll t, ll n) {
        fill(nivel, nivel + n + 1, -1);
        queue<ll> q({s});
        nivel[s] = 0;
        while (!q.empty()) {
            ll u = q.front();
            nextEdge[u] = 0;
            q.pop();
            if (u == t) {
                return true;
            }
            for (edge e : adj[u]) {
                int v = e.valor;
                ll disponible = e.capacidad - e.flujo;
                if (nivel[v] == -1 && disponible > 0) {
                    nivel[v] = nivel[u] + 1;
                    q.push(v);
                }
            }
        }
        return false;
    }

    ll maxFlow(ll s, ll t, ll n) {
        ll ans = 0;
        while (bfs(s, t, n)) {
            // for (ll i = 1; i <= n; i++) {
            //     cout << "Nivel i: " << nivel[i] << endl;
            // }
            while (ll inc = dfs(s, t, INF)) {
                ans += inc;
            }
        }
        return ans;
    }
};

void addEdge(ll origen, ll destino, ll capacidad, bool unidireccional = false) {
    adj[origen].pb({destino, capacidad, adj[destino].size()});
    adj[destino].pb({origen, capacidad * !bool(unidireccional), adj[origen].size() - 1});
}

void clear(int n) {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    Rep1(i, m) {
        ll a, b, w;
        cin >> a >> b >> w;
        addEdge(a, b, w);
    }
    dinic nuevo;
    cout << nuevo.maxFlow(1, n, n) << endl;
    return 0;
}