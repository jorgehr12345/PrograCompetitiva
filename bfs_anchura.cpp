#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define REP(i,n) for(Long i = 0; i < (Long)n; i++)
#define pb push_back
using namespace std;
typedef long long Long;
const Long MX = 1e5;
struct Graph {
	vector <Long> adj[MX];
	bool vis[MX];
	void addEdge(Long u, Long v) {
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	bool bfs(Long ini , Long objetivo){
		deque<Long> q;
		q.push_back(ini);
		vis[ini] = true;
		while(!q.empty()){
			Long u = q.front();
			q.pop_front();
			if(u == objetivo){
				//llegue al nodo
				return true;
			}
			for(Long v : adj[u]){
				if(!vis[v]){
					vis[v] = true;
					q.push_back(v);
				}
			}	
		}
		return false;
	}
} g;
int main() {
	return 0;
}