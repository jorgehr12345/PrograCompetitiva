#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std; 
typedef long long ll;
#define Rep0(i, n) for(ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for(ll i = 1; i <= (ll)n; i++)
const ll MX=1e5 + 10,MX2=1e9+2;
bool bo[MX];
pair<ll,ll>pa;
deque<ll>deq,deq2,deq3;
deque<pair<ll,ll>>dpa,dpa2,dpa3;
deque<pair<pair<ll,ll>,ll>>dpapa,dpapa2,dpapa3;
vector<ll>vec,vec2,vec3;
vector<ll>vec4,vec5,vec6;
vector<pair<ll,ll>>vpa,vpa2,vpa3,vpas[MX],vpas2[MX],vpas3[MX];
vector<pair<pair<ll,ll>,ll>>vpapa,vpapa2,vpapa3;
set<ll>se,se2,se3,se4,ses[MX],ses2[MX],ses3[MX];
set<pair<ll,ll>>sepa,sepa2,sepa3,sepas[MX],sepas2[MX],sepas3[MX];
set<pair<pair<ll,ll>,ll>>sepapa,sepapa2,sepapa3;
map<ll,ll> ma,ma2,ma3,ma4;
map<pair<ll,ll>,ll>mapa,mapa2,mapa3;
map<pair<ll,ll>,pair<ll,ll>>mapapa,mapapa2,mapapa3;
map<ll,pair<ll,ll>>malpa,malpa2,malpa3;
map<ll,pair<pair<ll,ll>,ll>>malpapa,malpapa2,malpapa3;

const ll INF=1e18;

ll d[MX];
struct Compare{
    bool operator() (ll u, ll v) const {
		if (d[u] == d[v]) return u < v; 
        return d[u] < d[v];
    }
};

struct Graph{
	vector<pair<ll,ll>> adj[MX];
	ll parent[MX];
	
	void clear(ll n) {
		for (int i = 0; i < n; i++) {
			adj[i].clear();
		}
	}
	
	void addEdge(ll u, ll v, ll w) {
		adj[u].push_back({v , w});
		//adj[v].push_back({u , w}); //Undirected
	}
	
	void dijkstra(ll s, ll n){ //O(E log V)
		for(ll i = 0; i < n; i++){
			parent[i] = -1;
			d[i] = INF;
		}
		set<ll, Compare> q;
		d[s] = 0;
		q.insert(s);
		while(!q.empty()){
			ll u = *q.begin();
			q.erase(q.begin());
			for(auto e : adj[u]){
				ll v = e.first;
				// ll w=0;
				ll w = e.second;
				// if(sepa2.find(make_pair(u,v))!=sepa2.end()){
				// 	w=-1;
				// }
				if(d[u] + w < d[v]){
					q.erase(v);
					d[v] = d[u] + w;
					parent[v] = u;
					q.insert(v);
				}
			}
		}
	}
	vector <ll> shortestpath(ll s){
		vector <ll> v;
		v.push_back(s + 1);
		while(parent[s] > 0){
			v.push_back(parent[s] + 1);
			s = parent[s];
		}
		v.push_back(parent[s] + 1);
		if(parent[s] == 0) return v;
		v.clear();
		return v;
	}
} G;

ll mini(ll a,ll b){
    return min(a,b);
}


int main(){
    inic;inic2;inic3;
    ll n,m;cin>>n>>m;
	ll as=m;
	while(as--){
		ll a,b,c;cin>>a>>b>>c;/*vpa.pb(make_pair(a,b));sepa.insert(make_pair(a,b));*/
		G.addEdge(a-1,b-1,c);
		G.addEdge(b-1,a-1,c);
		sepa.insert(make_pair(a-1,b-1));
		sepa.insert(make_pair(b-1,a-1));
	}
	G.dijkstra(0,n);
	for(ll i=0;i<n;i++){
		vpa.pb(make_pair(d[i],i));
	}
	sort(vpa.begin(),vpa.end());
	
	return 0;
}


