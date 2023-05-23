#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 std::cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 1e5 + 2;
vector<ll> adj[MX];

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
int main() {
    inic;
    inic2;
    inic3;
    ll n, m;
    cin >> n >> m;
    ordenActual = n;
    while (m--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    topoSort(n);
    for (ll i = 1; i <= n; i++) {
        cout << i << " orden: " << ordenTopo[i] << endl;
    }
    return 0;
}