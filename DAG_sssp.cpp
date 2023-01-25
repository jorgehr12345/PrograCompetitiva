#include <bits/stdc++.h>
#define pb push_back
#define ll long long
const ll MX=1e5+2;

using namespace std;

const ll INF=1e9+2;

map<pair<ll,ll>,ll>mapa;
map<pair<ll,ll>,bool>mapb;
vector<ll>adj[MX],adj2[MX];
vector<ll>hojas;
bool val[MX];
void dfsInicial(ll ini,ll padre,ll root){
    if(ini!=root){
        adj2[ini].pb(padre);
        if(adj[ini].size()==0){
            hojas.pb(ini);
        }
    }  
    // val[ini]=true;
    
    for(ll i=0;i<adj[ini].size();i++){
        if(mapb[make_pair(ini,adj[ini][i])]==false){
            mapb[make_pair(ini,adj[ini][i])]=true;
            mapb[make_pair(adj[ini][i],ini)]=true;
            dfsInicial(adj[ini][i],ini,root);
        }
    }

    
    
}
ll optimos[MX];
bool val2[MX];
ll dfsVolteado(ll ini){
    
    
    val2[ini]=true;

    for(ll i=0;i<adj2[ini].size();i++){
        
        if(optimos[adj2[ini][i]]!=INF){
            optimos[ini]=min(mapa[make_pair(ini,adj2[ini][i])] + optimos[adj2[ini][i]],optimos[ini]);
        }else{
            optimos[adj2[ini][i]]=dfsVolteado(adj2[ini][i]);
            optimos[ini]=min(mapa[make_pair(ini,adj2[ini][i])] + optimos[adj2[ini][i]],optimos[ini]);

        }
        // if(optimos[adj[ini][i]]==INF){
        //     optimos[adj[ini][i]]=dfsVolteado(adj[ini][i]);
        // }
    }
    if(optimos[ini]==INF){
        return 0;
    }
    return optimos[ini];
}

int main(){

    ll n;cin>>n;
    fill(optimos,optimos+MX,INF);
    ll m;cin>>m;
    while(m--){
        ll a,b,w;cin>>a>>b>>w;
        adj[a].pb(b);
        mapa[make_pair(a,b)]=w;
        mapa[make_pair(b,a)]=w;        
    }
    dfsInicial(1,1,1);
    for(ll i=0;i<hojas.size();i++){
        cout<<hojas[i]<<" qqqqqqqqqqqqqqqq "<<endl;
        dfsVolteado(hojas[i]);
    }
    for(ll i=1;i<=n;i++){
        cout<<optimos[i]<<" asdasddasd "<<endl;
    }
    return 0;
}