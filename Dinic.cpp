#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 5e3 + 2, MX2 = 5e3 + 2;

using Cap = long long;

const Cap INF = 1e18;

struct Edge {
    ll to;
    Cap flow, cap;
    ll rev; // index of the backward edge in the adj list of to
    Edge(ll to, Cap cap, ll rev) : to(to), flow(0), cap(cap), rev(rev) {}
};

struct Graph {
    vector<Edge> adj[MX];
    ll level[MX];
    ll nextEdge[MX];

    void clear(ll n) {
        for (ll i = 0; i < n; i++) adj[i].clear();
    }

    void addEdge(ll u, ll v, Cap w, bool dir) {
        adj[u].push_back(Edge(v, w, adj[v].size()));
        adj[v].push_back(Edge(u, dir ? 0 : w, adj[u].size() - 1));
    }

    Cap dfs(ll u, ll t, Cap f) {
        if (u == t) return f;
        for (ll &i = nextEdge[u]; i < adj[u].size(); i++) {
            Edge &e = adj[u][i];
            ll v = e.to;
            Edge &rev = adj[v][e.rev];
            Cap cf = e.cap - e.flow;
            if (cf == 0 || level[v] != level[u] + 1) continue;
            Cap ret = dfs(v, t, min(f, cf));
            if (ret > 0) {
                e.flow += ret;
                rev.flow -= ret;
                return ret;
            }
        }
        return 0;
    }

    bool bfs(ll s, ll t, ll n) { // O(E)
        fill(level, level + n, -1);
        queue<ll> q({s});
        level[s] = 0;
        while (!q.empty()) {
            ll u = q.front();
            nextEdge[u] = 0;
            q.pop();
            if (u == t) return true;
            for (Edge e : adj[u]) {
                ll v = e.to;
                Cap cf = e.cap - e.flow;
                if (level[v] == -1 && cf > 0) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        return false;
    }

    Cap maxFlow(ll s, ll t, ll n) {
        // General: O(E * V^2), O(E * V + V * |F|)
        // Unit Cap: O(E * min(E^(1/2) , V^(2/3)))
        // Unit Network: O(E * V^(1/2))
        // In unit network, all the edges have unit capacity
        // and for any vertex except s and t either the
        // incoming or outgoing edge is unique.
        Cap ans = 0;
        while (bfs(s, t, n)) { // O(V) iterations
            // after bfs, the graph is a DAG
            while (Cap inc = dfs(s, t, INF)) ans += inc;
        }
        return ans;
    }
} G;

int main() {
    ll n, m;
    cin >> n >> m;
    while (m--) {
        ll origen, destino, capacidad;
        cin >> origen >> destino >> capacidad;
        origen--;
        destino--;
        G.addEdge(origen, destino, capacidad, true);
    }
    cout << G.maxFlow(0, n - 1, n) << endl;
    return 0;
}