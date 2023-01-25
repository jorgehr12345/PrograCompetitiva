#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
typedef long long ll;
#define Rep0(i, n) for(ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for(ll i = 1; i <= (ll)n; i++)
using namespace std; 
const ll MX=3e5;
bool bo[MX];
pair<ll,ll>pa;
deque<ll>deq,deq2,deq3;
deque<pair<ll,ll>>dpa,dpa2,dpa3;
deque<pair<pair<ll,ll>,ll>>dpapa,dpapa2,dpapa3;
vector<ll>vec,vec2,vec3;
vector<pair<ll,ll>>vpa,vpa2,vpa3;
vector<pair<pair<ll,ll>,ll>>vpapa,vpapa2,vpapa3;
set<ll>se,se2,se3;
set<pair<ll,ll>>sepa,sepa2,sepa3;
set<pair<pair<ll,ll>,ll>>sepapa,sepapa2,sepapa3;
map<ll,ll> ma,ma2,ma3,ma4;
map<pair<ll,ll>,ll>mapa,mapa2,mapa3;
map<pair<ll,ll>,pair<ll,ll>>mapapa,mapapa2,mapapa3;

vector<ll>adj[MX];
set<ll>nod_rec;
bool val[MX];
ll dist[MX],nod[MX],anc[MX],hijos[MX];
void dfs1(ll ini,ll pos=0,ll ance=-1){
    //distancia al nodo 1
    dist[ini]=pos;
    pos++;
    //numero de elementos recorridos
    nod[ini]=nod_rec.size();
    nod_rec.insert(ini);
    //ancestro
    anc[ini]=ance;
    val[ini]=true;
    for(ll i=0;i<adj[ini].size();i++){
        if(val[adj[ini][i]]==false){
            dfs1(adj[ini][i],pos,ini);
        }
    }
}
bool val2[MX];
ll dfs2(ll ini){
    //numero de hijos
    ll resp=1;
    val2[ini]=true;
    for(auto x:adj[ini]){
        if(val2[x]==false){
            resp+=dfs2(x);
        }
    }
    hijos[ini]=resp;
    return resp;
}

int main(){
    inic;inic2;inic3;
    ll n,m,as;cin>>n>>m;as=n-1;
    while(as--){
        ll a,b;cin>>a>>b;adj[a].pb(b);adj[b].pb(a);
    }
    dfs1(1);
    dfs2(1);
    as=m;
    /*Rep1(i,n){
        cout<<i<<" "<<hijos[i]<<endl;
    }*/
    while(as--){
        ll t;cin>>t;
        ll mayor=0,elem=-1;
        vec.clear();
        while(t--){
            ll q;cin>>q;vec.pb(q);
            if(mayor<dist[q]){
                mayor=dist[q];
                elem=q;
            }
        }
        bool ok=true;
        for(ll i=0;i<vec.size();i++){
            //cout<<elem<<" "<<vec[i]<<" "<<anc[vec[i]]<<endl;
            if(vec[i]!=elem && (vec[i]!=1 && anc[vec[i]]!=1)){
                if(!(nod[vec[i]]<nod[elem] && nod[elem]<=nod[vec[i]] + hijos[vec[i]])){
                    if(!(nod[anc[vec[i]]]<nod[elem] && nod[elem]<=nod[anc[vec[i]]] + hijos[anc[vec[i]]])){
                        ok=false;break;
                    }
                }
            }
        }
        if(ok==true){
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }
        
    }
	return 0;
}