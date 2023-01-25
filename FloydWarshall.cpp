#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;

#define Rep0(i, n) for (int i = 0; i < (int)n; i++)
#define Rep1(i, n) for (int i = 1; i <= (int)n; i++)
typedef long long ll;
const ll MX = 2e5 + 10, MX2 = 2e5 + 2, MX3 = 500;
const ll INF = 1e18;
// bool bo[MX];
// pair<ll, ll> pa;
// deque<ll> deq, deq2, deq3;
// deque<pair<ll, ll>> dpa, dpa2, dpa3;
// deque<pair<pair<ll, ll>, ll>> dpapa, dpapa2, dpapa3;
// vector<ll> vec, vec2, vec3;
// vector<ll> vec4, vec5, vec6;
// vector<pair<ll, ll>> vpa, vpa2, vpa3, vpas[MX], vpas2[MX], vpas3[MX];
// vector<pair<pair<ll, ll>, ll>> vpapa, vpapa2, vpapa3;
// set<ll> se, se2, se3, se4, ses[MX], ses2[MX], ses3[MX];
// set<pair<ll, ll>> sepa, sepa2, sepa3, sepas[MX], sepas2[MX], sepas3[MX];
// set<pair<pair<ll, ll>, ll>> sepapa, sepapa2, sepapa3;
// map<ll, ll> ma, ma2, ma3, ma4;
// map<pair<ll, ll>, ll> mapa, mapa2, mapa3;
// map<pair<ll, ll>, pair<ll, ll>> mapapa, mapapa2, mapapa3;
// map<ll, pair<ll, ll>> malpa, malpa2, malpa3;
// map<ll, pair<pair<ll, ll>, ll>> malpapa, malpapa2, malpapa3;

struct Graph {
    ll d[MX3][MX3];
    ll p[MX3][MX3];
    vector<ll> path;

    void clear(ll N) {
        Rep0(i, N) {
            Rep0(j, N) {
                d[i][j] = INF;
                p[i][j] = -1;
            }
        }
    }

    Graph() {
        clear(MX3);
    }

    void addEdge(ll u, ll v, ll cost) {
        d[u][v] = min(d[u][v], cost);
        d[v][u] = d[u][v];
    }

    void retrievePath(ll i, ll j, bool clean = true) { // O(n)
        if (clean) {
            path.clear();
            clean = false;
            path.pb(i);
            if (i == j) return;
        }

        if (p[i][j] == -1) {
            path.pb(j);
            return;
        }

        retrievePath(i, p[i][j], clean);
        retrievePath(p[i][j], j, clean);
    }

    void floydWarshall(ll n) { // O(n)
        Rep0(i, n) {
            d[i][i] = 0;
        }

        Rep0(k, n) {
            Rep0(i, n) {
                Rep0(j, n) {
                    if (d[i][k] < INF && d[k][j] < INF) {
                        // if (d[i][k] + d[k][j] < d[i][j] - EPS)  //real weights
                        if (d[i][j] > d[i][k] + d[k][j]) {
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                            p[i][j] = k;
                        }
                    }
                }
            }
        }

        // negative cycle
        Rep0(i, n) {
            Rep0(j, n) {
                Rep0(k, n) {
                    if (d[i][k] < INF && d[k][j] < INF && d[k][k] < 0) {
                        d[i][j] = -INF;
                    }
                }
            }
        }
    }
} G;

int main() {
    inic;
    inic2;
    inic3;
    cout << " asdadsadasd " << endl;
    cout << INF << endl;
    cout << " ----------- " << endl;
    return 0;
}
