#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 std::cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 2e5 + 2;

vector<pair<ll, ll>> puentes;
bool val[MX];
vector<ll> adj[MX];
ll parent[MX], discover[MX], low[MX];
ll aumentador = 1;
void bridges(ll ini, ll padre) {
    val[ini] = true;
    discover[ini] = aumentador;
    low[ini] = aumentador;
    aumentador++;
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (val[adj[ini][i]] == false) {
            bridges(adj[ini][i], ini);
        }
        if (adj[ini][i] != padre) {
            low[ini] = min(low[ini], low[adj[ini][i]]);
        }
    }
    if (low[ini] > discover[padre]) {
        puentes.pb(make_pair(ini, padre));
    }
}

int main() {
    inic;
    inic2;
    inic3;
    ll n, m;
    cin >> n >> m;
    while (m--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bridges(1, 1);
    for (ll i = 0; i < puentes.size(); i++) {
        cout << puentes[i].first << " asdad " << puentes[i].second << endl;
    }
    return 0;
}
