#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const ll MX=1e5+2;

ll lider[MX],tamanios[MX];
ll find_lider(ll nodo){
    if(lider[nodo]==nodo){
        return nodo;
    }else{
        lider[nodo]=find_lider(lider[nodo]);
    }
    return lider[nodo];
}
void join(ll nodo_a,ll nodo_b){
    nodo_a=find_lider(nodo_a);
    nodo_b=find_lider(nodo_b);

    if(nodo_a!=nodo_b){
        if(tamanios[nodo_a]>tamanios[nodo_b]){
            tamanios[nodo_a]+=tamanios[nodo_b];
            lider[nodo_b]=nodo_a;
        }else{
            tamanios[nodo_b]+=tamanios[nodo_a];
            lider[nodo_a]=nodo_b;
        }
    }
}

priority_queue<pair<pair<ll,ll>,ll>,vector<pair<pair<ll,ll>,ll>>,greater<pair<pair<ll,ll>,ll>>>pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    iota(lider,lider+MX,0);
    fill(tamanios,tamanios+MX,1);

    ll n,m;cin>>n>>m;
    ll as=m;
    while(as--){
        ll a,b,w;cin>>a>>b>>w;
        pq.push(make_pair(make_pair(w,a),b));
    }
    // set<ll>se;
    ll total=0;
    while(!pq.empty()){
        ll peso=pq.top().first.first;
        ll nodo_1=pq.top().first.second;
        ll nodo_2=pq.top().second;
        pq.pop();
        ll lid1=find_lider(nodo_1);
        ll lid2=find_lider(nodo_2);
        if(lid1==lid2){
            continue;
        }
        total+=peso;
        join(nodo_1,nodo_2);
        // cout<<lider[nodo_1]<<" rrrrrrrrrrrrr "<<lider[nodo_2]<<endl;
        // cout<<nodo_1<<" asd "<<nodo_2<<" qwe "<<peso<<endl;
        // se.insert(nodo_1);
        // se.insert(nodo_2);
    }
    cout<<total<<endl;
    

    return 0;
}