#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

struct CentroidD {
    Long n, val_vis;
    vector<vector<Long> > adj;
    vector<Long> cparent, szt, vis;
    vector<vector<Long> > cdTree;

    CentroidD() {}
    CentroidD(Long n) : n(n) {
        val_vis = 0;
        vis.resize(n, -1);
        cparent.resize(n, -1);
        szt.resize(n, 0);
        adj.resize(n);
        cdTree.resize(n);
    }

    void addEdge(Long u, Long v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        return;
    }

    Long dfs(Long u, Long p) {
        szt[u] = 1;
        vis[u] = val_vis;
        for (Long v : adj[u]) {
            if (v != p && cparent[v] == -1 && vis[v] != val_vis) szt[u] += dfs(v, u);
        }
        return szt[u];
    }

    void decompotition(Long u, Long p, Long sz, Long pc) {
        for (Long v : adj[u]) {
            if (v != p && cparent[v] == -1 && (szt[v] << 1ll) > sz) {
                decompotition(v, u, sz, pc);
                return;
            }
        }
        cparent[u] = pc;

        if (pc != -2) {
            cdTree[u].push_back(pc);
            cdTree[pc].push_back(u);
        }
        for (Long v : adj[u]) {
            if (cparent[v] == -1) {
                dfs(v, -1);
                val_vis++;
                decompotition(v, -1, szt[v], u);
            }
        }
    }

    void build(Long u) {
        dfs(u, -1);
        for (long long i = 1; i <= n; i++) {
            cout << szt[i] << " asd " << i << endl;
        }
        val_vis++;
        decompotition(u, -1, szt[u], -2);
    }
};

const Long MX = 1e5 + 10;
const Long BT = 20;

CentroidD G;
bool visCentroid[MX];
vector<Long> aux;
Long val[MX];
Long sum;

void getVector(Long u, Long p, Long num) {
    for (Long v : G.adj[u]) {
        if (v != p && !visCentroid[v]) getVector(v, u, num ^ val[v]);
    }
    aux.push_back(num);
    return;
}

void moveToL(vector<vector<Long> > &L, vector<vector<Long> > &R, Long pos, Long num,
             vector<vector<Long> > &subtree) {
    for (Long i = 0; i < subtree[pos].size(); i++) {
        for (Long k = 0; k < BT; k++) {
            R[(subtree[pos][i] >> k) & 1][k]--;
        }
        subtree[pos][i] ^= num;
        for (Long k = 0; k < BT; k++) {
            L[(subtree[pos][i] >> k) & 1][k]++;
        }
    }
    return;
}

void updateAns(Long u) {
    vector<vector<Long> > subtree;
    for (Long v : G.adj[u]) {
        if (!visCentroid[v]) {
            aux.clear();
            getVector(v, u, val[u] ^ val[v]);
            subtree.push_back(aux);
        }
    }

    vector<vector<Long> > L(2, vector<Long>(BT, 0));
    vector<vector<Long> > R(2, vector<Long>(BT, 0));

    sum += val[u];
    for (Long i = 0; i < subtree.size(); i++) {
        for (Long j = 0; j < subtree[i].size(); j++) {
            for (Long k = 0; k < BT; k++) R[(subtree[i][j] >> k) & 1][k]++;
            sum += subtree[i][j];
        }
    }

    for (Long i = 0; i < subtree.size(); i++) {
        moveToL(L, R, i, val[u], subtree);
        for (Long k = 0; k < BT; k++)
            sum += (L[0][k] * R[1][k] + L[1][k] * R[0][k]) * (1ll << k);
        for (Long k = 0; k < BT; k++) L[0][k] = L[1][k] = 0;
    }
    return;
}

void dfs(Long u, Long p) {
    visCentroid[u] = true;
    updateAns(u);
    for (Long v : G.cdTree[u]) {
        if (v != p) dfs(v, u);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    cout << fixed;

    Long n, x, y;
    cin >> n;
    G = CentroidD(n + 1);
    for (Long i = 1; i <= n; i++) cin >> val[i];
    for (Long i = 1; i < n; i++) {
        cin >> x >> y;
        G.addEdge(x, y);
    }
    G.build(1);

    // Long centroid = -1;
    // for (Long i = 1; i <= n; i++) {
    //     if (G.cparent[i] == -2) {
    //         centroid = i;
    //         break;
    //     }
    // }

    // sum = 0;
    // dfs(centroid, -1);
    // cout << sum << "\n";
    return 0;
}
