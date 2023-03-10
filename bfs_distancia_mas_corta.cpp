#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define REP(i,n) for(Long i = 0; i < (Long)n; i++)
#define pb push_back
using namespace std;
typedef long long Long;
const Long INF = 1e18;
const Long MX = 1e5;
struct Graph{
	Long d[MX]; //distancias minimas
	vector<Long> adj[MX];
	void addEdge(Long u, Long v) {
		adj[u].pb(v);
		adj[v].pb(u);
	}
	void bfs(Long s, Long numero_de_elementos){ //O(n+m)
		for(Long u = 0; u < numero_de_elementos; u++){
			d[u] = INF;
		}
		d[s] = 0;
		deque<Long> Q;
		Q.push_back(s);
		while(!Q.empty()){
			Long u = Q.front();
			Q.pop_front();		
			for (Long v : adj[u] ) {
				if(d[v] == INF){
					d[v] = d[u] + 1;
					Q.push_back(v);
				}
			}
		}
	}
}G;
int main() {
	return 0;
}