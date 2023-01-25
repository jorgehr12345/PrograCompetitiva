#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

vector<ll>numeros;
ll respuesta=-1,posicion=-1;
void binary_search(ll L,ll R,ll num){
    if(L==R){
        ll med=L;
        if(num>numeros[med]){
            return;
        }
        respuesta=numeros[L];
        posicion=L;
        return;
    }
    ll izq=L;
    ll der=R;
    ll med=(L+R)/2;
    if(num>numeros[med]){
        izq=med+1;
    }else{
        der=med;
    }
    binary_search(izq,der,num);
}



int main(){

    ll n;cin>>n;
    while(n--){
        ll l;cin>>l;
        numeros.pb(l);
    }
    ll s;cin>>s;
    binary_search(0,numeros.size()-1,s);
    cout<<respuesta<<" ----- "<<posicion<<endl;
    return 0;
}