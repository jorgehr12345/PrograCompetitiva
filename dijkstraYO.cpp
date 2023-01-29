#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;

const ll MX = 1e5 + 2;
const ll INF = 1e9 + 2;

vector<pair<ll, ll>> adj[MX];
// map<pair<ll, ll>, ll> mapa;
set<pair<ll, ll>> sepa;
ll valores[MX];
void dijkstra(ll root) {
    sepa.insert(make_pair(0, root));
    valores[root] = 0;
    set<pair<ll, ll>>::iterator it;

    while (!sepa.empty()) {
        it = sepa.begin();
        ll valorActual = (*it).second;
        sepa.erase(it);
        for (ll i = 0; i < adj[valorActual].size(); i++) {
            if (valores[adj[valorActual][i].first] >
                valores[valorActual] + adj[valorActual][i].second) {
                sepa.erase(
                    make_pair(valores[adj[valorActual][i].first], adj[valorActual][i].first));
                valores[adj[valorActual][i].first] =
                    valores[valorActual] + adj[valorActual][i].second;
                sepa.insert(
                    make_pair(valores[adj[valorActual][i].first], adj[valorActual][i].first));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;
    fill(valores, valores + n + 1, INF);
    while (m--) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
        // mapa[make_pair(a, b)] = w;
        // mapa[make_pair(b, a)] = w;
    }
    dijkstra(1);
    for (ll i = 1; i <= n; i++) {
        cout << valores[i] << endl;
    }

    return 0;
}