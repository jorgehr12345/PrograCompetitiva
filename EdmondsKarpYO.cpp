#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 1e3 + 2, MX2 = 1e3 + 2, MOD = 1e9 + 7, INF = 1e18;

vector<pair<ll, ll>> adj[MX];
ll valores[MX][MX];

struct EdmondsKarp {
    ll nodos2;

    bool val[MX];
    ll parents[MX];
    bool bfs(ll ini, ll target) {
        bool encontrado = false;
        val[ini] = true;
        queue<ll> qq;
        qq.push(ini);
        while (!encontrado && !qq.empty()) {
            ll valorActual = qq.front();
            // cout << valorActual << " sadasdasd " << endl;
            qq.pop();
            for (ll i = 0; i < adj[valorActual].size(); i++) {
                if (val[adj[valorActual][i].first] == false) {
                    if (valores[valorActual][adj[valorActual][i].first] > 0) {
                        // cout << valorActual << " dfgdfgdfgd " << adj[valorActual][i].first
                        //      << endl;
                        parents[adj[valorActual][i].first] = valorActual;
                        qq.push(adj[valorActual][i].first);
                        val[adj[valorActual][i].first] = true;
                        if (adj[valorActual][i].first == target) {
                            // cout << " ------- " << endl;
                            encontrado = true;
                            break;
                        }
                    }
                }
            }
        }
        return encontrado;
    }
    void limpiar() {
        for (ll i = 1; i <= nodos2; i++) {
            parents[i] = i;
            val[i] = false;
        }
    }

    ll edmond(ll ini, ll target) {
        bool asd = true;
        ll tot = 0;
        while (asd) {
            asd = bfs(ini, target);
            // cout << "pppppppppppp" << endl;
            if (asd == true) {
                // cout << " llllll " << endl;
                ll temp = target, resp = INF;
                while (temp != ini) {
                    resp = min(valores[parents[temp]][temp], resp);
                    temp = parents[temp];
                }
                temp = target;
                while (temp != ini) {
                    valores[parents[temp]][temp] -= resp;
                    valores[temp][parents[temp]] += resp;
                    temp = parents[temp];
                }
                tot += resp;
                limpiar();
                // cout << "El valor de tot es: " << tot << endl;
            } else {
                break;
            }
        }
        return tot;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        // a++;
        // b++;
        adj[a].pb(make_pair(b, w));
        adj[b].pb(make_pair(a, 0));
        valores[a][b] += w;
        valores[b][a] = 0;
    }
    EdmondsKarp nuevo;
    nuevo.nodos2 = n;
    nuevo.limpiar();
    cout << nuevo.edmond(1, n) << endl;
    return 0;
}
