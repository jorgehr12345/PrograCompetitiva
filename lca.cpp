#include<bits/stdc++.h>
 
using namespace std;
 
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define pb push_back 
 
 
const int maxn=100005;
const int maxlogn=20;
vector<int> level(maxn, -1);
vector< vector<int> > parent(maxn, vector<int>(maxlogn, -1));
vector< vector<int> > grafo;
 
void rootTree(int toy, int vengo, int nivel){
	level[toy]=nivel;
	parent[toy][0]=vengo;
	forn(i, grafo[toy].size()){
		if(grafo[toy][i]==vengo)continue;
		rootTree(grafo[toy][i], toy, nivel+1);
	}
}
 
int LCA(int u, int v){
	if(level[u]<level[v]){
		int tmp=u;
		u=v;
		v=tmp;
	}
	//cout<<"nodo mas abajo "<<u<<endl;
	int log=0;
	while( (1<<log)<=level[u])log++;
	log--;
	//cout<<"LOG = "<<log<<endl;
	for(int i=log; i>=0; i--){
		if(level[u]-(1<<i) >=level[v]){
			//cout<<"subo de "<<u<<" a ";
			u=parent[u][i];
			//cout<<u<<endl;
		}
	}
	//cout<<"mismo nivel "<<u<<" y "<<v<<endl;
	for(int i=log; i>=0; i--){
		if(parent[u][i]!=-1 && parent[u][i]!=parent[v][i]){
			//cout<<"subo de "<<u;
			u=parent[u][i];
			//cout<<" a "<<u<<" y de "<<v<<" a ";
			v=parent[v][i];
			//cout<<v<<endl;
		}
	}
	int p;
	if(v!=u){
		p=parent[v][0];
	}else{
		p=v;
	}
	return p;
}
 
int main(){
	int N;
	cin>>N;
	forn(i, N){
		vector<int> v;
		if(2*i+1<N)v.pb(2*i+1);
		if(2*i+2<N)v.pb(2*i+2);
		if(i>0)v.pb((i-1)/2);
		grafo.pb(v);
	}
	rootTree(0, -1, 0);
	for(int j=1; (1<<j)<N; j++){
		forn(i, grafo.size()){
			if(parent[i][j-1]!=-1){
				parent[i][j]=parent[parent[i][j-1]][j-1];
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int u, v;
		cin>>u>>v;
		cout<<LCA(u, v)<<endl;
	}
}