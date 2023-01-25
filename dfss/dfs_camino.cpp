#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std; 
typedef long long ll;
vector<ll>vec,vec2,vec3,vec4;
pair<ll,ll>pa;
vector<pair<ll,ll>>vpa,vpa2,vpa3;
set<ll>se,se2,se3;
set<pair<ll,ll>>sepa,sepa2,sepa3;
map<ll,ll>ma,ma2,ma3;
map<pair<ll,ll>,ll>mapa,mapa2,mapa3;
map<pair<ll,ll>,pair<ll,ll>>mapapa,mapapa2,mapapa3;
const ll MX=1e5 + 1;
//EMPIEZA (vec4 es el contenedor)
vector<ll>adj2[MX];
struct qwe1{
    bool val[MX];
    bool encontrado;
    void dfs(ll ini,ll target){
        val[ini]=true;
        vec4.pb(ini);
        if(ini==target){
            encontrado=true;
            return;
        }
        for(ll i=0;i<adj2[ini].size();i++){
            if(val[adj2[ini][i]]==false && encontrado==false){
                dfs(adj2[ini][i],target);
            }    
        }
        if(encontrado==false){
            vec4.pop_back();
        }            
        
    }
};
int main(){
    ll n,a,b,as;cin>>n;as=n;as--;
    while(as--){
        cin>>a>>b;adj2[a].pb(b);adj2[b].pb(a);
    }
    //ACABA
    qwe1 asd;asd.dfs(4,17);
    for(ll i=0;i<vec.size();i++){
        cout<<vec4[i]<<" ";
    }cout<<endl;
    vec.clear();
    qwe1 asd2;
    asd2.dfs(3,13);
    for(ll i=0;i<vec4.size();i++){
        cout<<vec4[i]<<" ";
    }cout<<endl;
    return 0;
}
/*
18
1 2
1 3
2 4
2 5
3 6
3 7
4 8
5 9
6 10
6 11
7 12
7 13
10 14
10 15
12 16
13 17
13 18*/