#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;
#define ll long long
#define pb push_back

const ll MX=1e5+2;

void merges(vector<ll> vecIzq,vector<ll> vecDer,vector<ll> &ordenado){
    ll indIzquierda=0;
    ll indDerecha=0;
    for(ll i=0;i<ordenado.size();i++){
        if(indIzquierda==vecIzq.size()){
            ordenado[i]=vecDer[indDerecha];
            indDerecha++;
        }else{
            if(indDerecha==vecDer.size()){
                ordenado[i]=vecIzq[indIzquierda];
                indIzquierda++;
            }else{
                if(vecIzq[indIzquierda]>vecDer[indDerecha]){
                    ordenado[i]=vecDer[indDerecha];
                    indDerecha++;
                }else{
                    ordenado[i]=vecIzq[indIzquierda];
                    indIzquierda++;
                }
            }
        }
    }
}

void merge_sort(vector<ll>&s){

    if(s.size()==1){
        return;
    }
    ll longitud=s.size();
    ll mitad=longitud/2;
    vector<ll>izquierda,derecha;
    for(ll i=0;i<mitad;i++){
        izquierda.pb(s[i]);
    }
    for(ll i=mitad;i<longitud;i++){
        derecha.pb(s[i]);
    }

    merge_sort(izquierda);
    merge_sort(derecha);
    merges(izquierda,derecha,s);
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<ll>vec;
    ll n;cin>>n;
    while(n--){
        ll l;cin>>l;
        vec.pb(l);
    }

    for(ll i:vec){
        cout<<i<<" ";
    }cout<<endl;
    merge_sort(vec);
    for(ll i:vec){
        cout<<i<<" ";
    }cout<<endl;
    


    return 0;
}