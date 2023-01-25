#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;
const ll MX=1e5+2;

vector<ll>adj[MX];
bool val[MX];
void bfs(ll ini){
  queue<ll>dd;
  val[ini]=true;
  dd.push(ini);
  while(!dd.empty()){
    ll valor=dd.front();
    cout<<valor<<" aasd "<<endl;
    dd.pop();
    for(ll i=0;i<adj[valor].size();i++){
      if(val[adj[valor][i]]==false){
        val[adj[valor][i]]=true;
        dd.push(adj[valor][i]);
      }
    }

  }

}

int main(){

  ll n;cin>>n;
  ll as = n;
  while(as--){
    ll a,b;cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }  
  bfs(1);

  return 0;
}