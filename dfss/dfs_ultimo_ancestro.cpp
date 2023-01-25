#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std; 
typedef long long ll;
const ll MX=3e5;
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

ll ance[MX];
vector<ll>adj4[MX];
struct qwe3{
    bool val[MX];
    void dfs(ll ini,ll ancestro){
        val[ini]=true;
        if(ini!=1){
            ance[ini]=ancestro;
        }
        for(ll i=0;i<adj4[ini].size();i++){
            if(val[adj4[ini][i]]==false){
                dfs(adj4[ini][i],ini);
            }
        }
    }
};
int main(){
    ll n,as;cin>>n;as=n-1;
    while(as--){
        ll a,b;cin>>a>>b;
        adj4[a].pb(b);
        adj4[b].pb(a);
    }
    qwe3 asd;
    asd.dfs(1,1);
    cout<<" asdasd "<<endl;
    for(ll i=2;i<=n;i++){
        cout<<ance[i]<<" "<<i<<endl;
    }
    return 0;
}