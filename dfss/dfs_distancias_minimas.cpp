#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std; 
typedef long long ll;
const ll MX=1e5 + 5;
bool bo[MX];
pair<ll,ll>pa,pa2,pa3,pa4;
deque<ll>deq,deq2,deq3,deq4;
deque<pair<ll,ll>>dpa,dpa2,dpa3,dpa4;
deque<pair<pair<ll,ll>,ll>>dpapa,dpapa2,dpapa3,dpapa4;
vector<ll>vec,vec2,vec3,vec4;
vector<pair<ll,ll>>vpa,vpa2,vpa3,vpa4;
vector<pair<pair<ll,ll>,ll>>vpapa,vpapa2,vpapa3,vpapa4;
set<ll>se,se2,se3,se4;
set<pair<ll,ll>>sepa,sepa2,sepa3,sepa4;
set<pair<pair<ll,ll>,ll>>sepapa,sepapa2,sepapa3,sepapa4;
map<ll,ll> ma,ma2,ma3,ma4;
map<pair<ll,ll>,ll>mapa,mapa2,mapa3,mapa4;
map<pair<ll,ll>,pair<ll,ll>>mapapa,mapapa2,mapapa3,mapapa4;

//empieza
vector<ll>adj3[MX];
ll dist[MX];
struct qwe2{
    bool val[MX];
    void dfs(ll ini,ll pos=0){
        dist[ini]=pos;
        val[ini]=true;
        for(ll i=0;i<adj3[ini].size();i++){
            if(val[adj3[ini][i]]==false){
                dfs(adj3[ini][i],pos+1);
            }
        }
    }
};
int main(){
    ll n,as;cin>>n;as=n-1;
    while(as--){
        ll a,b;cin>>a>>b;
        adj3[a].pb(b);
        adj3[b].pb(a);
    }
    //Acaba
    qwe2 asd;
    asd.dfs(1,0);
    for(ll i=1;i<=n;i++){
        cout<<1<<" "<<dist[i]<<" "<<i<<endl;
    }
    return 0;
}