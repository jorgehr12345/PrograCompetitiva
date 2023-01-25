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
//Esto solo sirve cuando el update es al final pues por cada update se deben hacer n operaciones al construir el arreglo de diferencias. 
/*struct partialsum{
    ll respuestas[MX],diferencias[MX];
    //CUARTO
    ll query(ll pos){   // las queries O(1)
        return respuestas[pos];
    }
    //SEGUNDO
    void actualizar(ll ini,ll fin,ll aumento){ //se construyen las diferencias (los updates) en O(1)
        diferencias[ini]+=aumento;
        diferencias[fin+1]-=aumento;
    }
    //TERCERO
    void respuesta(vector<ll>&v){ // las respuestas en base a las diferencias O(n)
        respuestas[0]=diferencias[0];
        for(ll i=1;i<v.size();i++){
            respuestas[i]=respuestas[i-1] + diferencias[i];
        }
    }
    //PRIMERO
    void construccion(vector<ll> &v){//construyo los acummulados O(n) 
        for(ll i=0;i<vec.size();i++){
            diferencias[i]+=vec[i];
            diferencias[i+1]-=vec[i];
        }
    }
}asd;
*/
ll n,elementos[MX],tree[MX]={0},acumulado[MX]={0};
//actualizar trees
void update(ll pos,ll agre){
    while(pos<=n){
        tree[pos]+=agre;
        pos+=(pos&-pos);
    }
}
int main(){
    cin>>n;
    ll as=n,t,i=1;
    //Insertar elementos
    while(as--){
        cin>>t;elementos[i]=t;
        i++;
    }
    //Hallar los trees
    for(ll j=1;j<=n;j++){
        tree[j]+=elementos[j];
        ll s=j;
        s+=(s&-s);
        tree[s]+=tree[j];
    }
    //Hallar el acumulado
    for(ll j=1;j<=n;j++){
        ll p=j,resp=0;
        while(p>0){
            resp+=tree[p];
            p-=(p&-p);
        }
        acumulado[j]=resp;
    }
    
    return 0;
}
/*
16
1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2
*/