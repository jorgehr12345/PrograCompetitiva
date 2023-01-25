#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);

vector<ll>valores;
ll memo[100][100];
bool used[100][100];
ll n,total;
map<pair<ll,ll>,pair<ll,ll>>mapa;
ll knapsack(ll pos,ll suma){

    if(pos==n){
        return 0;
    }
    if(used[pos][suma]){
        return memo[pos][suma];
    }
    used[pos][suma]=true;
    ll op1=-1,op2=-1;
    if(suma - valores[pos]<0){
        mapa[make_pair(pos,suma)]=make_pair(pos+1,suma);
        memo[pos][suma]=knapsack(pos+1,suma);
    }else{
        op1=knapsack(pos+1,suma);
        op2=valores[pos] + knapsack(pos+1,suma-valores[pos]);
        if(op1>op2){
            mapa[make_pair(pos,suma)]=make_pair(pos+1,suma);
        }else{
            mapa[make_pair(pos,suma)]=make_pair(pos+1,suma - valores[pos]);
        }
        memo[pos][suma]=max(op1,op2);
    }
    return memo[pos][suma];

}


int main(){
    inic;
    inic2;
    inic3;

    cin>>n>>total;
    ll as=n;
    while(as--){
        ll l;cin>>l;valores.pb(l);
    }
    knapsack(0,total);
    // cout<<memo[0][total]<<" ------------"<<endl;;
    // cout<<memo[1][38]<<" eqwewqeqwe "<<endl;
    ll a=0,b=total;
    while(true){
        cout<<memo[a][b]<<endl;
        ll prim=mapa[make_pair(a,b)].first;
        b=mapa[make_pair(a,b)].second;
        a=prim;
        cout<<a<<" wweqweqweqw "<<b<<endl;
        if(a==0 && b==0){
            break;
        }
    }

    return 0;
}
