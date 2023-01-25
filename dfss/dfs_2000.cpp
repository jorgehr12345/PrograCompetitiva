#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 2e5 + 5;
bool bo[MX];
pair<ll, ll> pa;
deque<ll> deq, deq2, deq3;
deque<pair<ll, ll>> dpa, dpa2, dpa3;
deque<pair<pair<ll, ll>, ll>> dpapa, dpapa2, dpapa3;
vector<ll> vec, vec2, vec3;
vector<pair<ll, ll>> vpa, vpa2, vpa3;
vector<pair<pair<ll, ll>, ll>> vpapa, vpapa2, vpapa3;
set<ll> se, se2, se3;
set<pair<ll, ll>> sepa, sepa2, sepa3;
set<pair<pair<ll, ll>, ll>> sepapa, sepapa2, sepapa3;
map<ll, ll> ma, ma2, ma3, ma4;
map<pair<ll, ll>, ll> mapa, mapa2, mapa3;
map<pair<ll, ll>, pair<ll, ll>> mapapa, mapapa2, mapapa3;

ll n, m;
vector<ll> adj[2505];
ll convertidor(ll a, ll b) {
    return (a)*m + (b);
}
pair<ll, ll> desconvertidor(ll numero) {
    pair<ll, ll> deva;
    deva = make_pair(numero / m, numero % m);
    return deva;
}

ll el[MX], resp[MX], anc[MX];
vector<ll> adj[MX];
bool val[MX], val2[MX], val3[MX];
void dfs1(ll ini, ll p = -1) {
    if (ini != 1 && adj[ini].size() == 1) {
        se.insert(ini);
    }
    anc[ini] = p;
    val2[ini] = true;
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (val2[adj[ini][i]] == false) {
            dfs1(adj[ini][i], ini);
        }
    }
}

ll dfs2(ll ini) {
    val[ini] = true;
    ll mx = 0;
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (val[adj[ini][i]] == false) {
            mx += max(0ll, dfs2(adj[ini][i]));
        }
    }
    if (el[ini] == 0) {
        resp[ini] = -1 + mx;
        return -1 + mx;
    } else {
        resp[ini] = 1 + mx;
        return 1 + mx;
    }
}

ll dfs3(ll ini) {
    val3[ini] = true;
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (adj[ini][i] == anc[ini]) {
            if (val3[anc[ini]] == false) {
                if (resp[ini] == -1) {
                    resp[ini] = max(resp[ini], dfs3(anc[ini]) + resp[ini]);
                } else {
                    resp[ini] = max(resp[ini], dfs3(anc[ini]));
                }

            } else {
                if (resp[ini] == -1) {
                    resp[ini] = max(resp[ini], resp[anc[ini]] + resp[ini]);
                } else {
                    resp[ini] = max(resp[ini], resp[anc[ini]]);
                }
            }
        }
    }

    return resp[ini];
}

int main() {
    ll n, as, i = 1;
    cin >> n;
    as = n;
    while (as--) {
        ll t;
        cin >> t;
        el[i] = t;
        i++;
    }
    as = n - 1;
    while (as--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // dfs_ancestros(1);
    dfs1(1);
    set<ll>::iterator it;
    dfs2(1);
    for (it = se.begin(); it != se.end(); it++) {
        dfs3(*it);
    }
    for (ll i = 1; i <= n; i++) {
        cout << resp[i] << " ";
    }
    cout << endl;
    return 0;
}