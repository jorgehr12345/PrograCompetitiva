#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define REP(i,n) for(Long i = 0; i < (Long)n; i++)
#define pb push_back
using namespace std;
typedef long long Long;
const Long MX = 1e5;
//DFS
vector<Long> adj[MX];
bool vis[MX];
void addEdge(Long u , Long v){
	adj[u].push_back(v);
	adj[v].push_back(u); //si es no dirigido
}	
bool dfs(Long u , Long target){
	if(u == target){
		return true;
	}
	vis[u] = true;
	for(Long v : adj[u]){
		if(!vis[v]){
			bool encontrado = dfs(v , target);
			if(encontrado){
				return true;
			}
		}
	}
	return false;
}
//TERMINA DFS
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Long n,u,v;cin>>n;
	while(n--){
		cin >> u >> v;
		addEdge(u , v);
	}
	return 0;
}