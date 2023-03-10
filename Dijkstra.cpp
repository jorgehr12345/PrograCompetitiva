#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define REP(i,n) for(Long i = 0; i < (Long)n; i++)
#define pb push_back
using namespace std;

typedef long long Long;
const Long MX = 1e5;
const Long INF = 1e18;

struct Endpoint{
	Long node, weight;
	Endpoint(){}
	
	Endpoint(Long node, Long weight) : node(node) , weight(weight) {}

	bool operator >(const Endpoint &P) const{
		if(weight == P.weight){
			return node > P.node;
		}
		return weight > P.weight;
	}
};

struct Graph{
	vector<Endpoint> adj[MX];
	bool vis[MX];
	Long d[MX];
	Long parent[MX];
	
	void clear(Long N = MX) {
		REP( i , N) {
			adj[i].clear();
		}
	}
	
	void addEdge(Long u, Long v, Long w) {
		adj[u].pb(Endpoint(v , w) );
		adj[v].pb(Endpoint(u , w));
	}
	
	void dijkstra(Long root, Long n){ //O(nlogm + mlogn)
		for(Long i = 0; i < n; i++){
			vis[i] = false;
			parent[i] = -1;
			d[i] = INF;
		}
		priority_queue<Endpoint, vector<Endpoint>, greater<Endpoint>> q;
		d[root] = 0;
	
		q.push(Endpoint(root , d[root]));
		
		while(!q.empty()){
			Endpoint p = q.top();
			q.pop();
			int u = p.node;
			if(vis[u]){
				continue;
			}
			if(p.weight != d[u]){
				continue;
			}
	
			vis[u] = true;
			for( Endpoint x : adj[u]){
				Long v = x.node;
				if(vis[v]){
					continue;
				}
				
				if(d[u] + x.weight < d[v]){
					d[v] = d[u] + x.weight;
					q.push(Endpoint(v , d[v]));
					parent[v] = u;
				}
			}
		}
	}
	
	deque<Long> retrievePath(Long v){
		if(parent[v] == -1){
			return {};
		}
		deque<Long> path;
		while(v != -1){
			path.push_front(v);
			v = parent[v];
		}
		return path;
	}
} G;

int main() {
	Long n , m;
	cin >> n >> m;
	G.clear(n);
	REP( i , m){
		Long u , v , w;
		cin >> u >> v >> w;
		G.addEdge(u , v , w);
	}
	G.dijkstra(0, n);
	REP(i , n){
		cout << G.d[i] << endl;
	}
	return 0;
}
