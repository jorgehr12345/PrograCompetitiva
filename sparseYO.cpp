#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const ll MX=2e5+2;
const ll MOD=1e9+7;

ll valores[MX],n;
ll todosValores[MX][21],ancestros[MX][21];
void sparse(){
	for(ll i=1;i<n;i++){
		todosValores[i][0]=max(valores[i],valores[i+1]);
		ancestros[i][0]=i+1;
	}

	for(ll i=1;i<=20;i++){
		for(ll j=1;j<=n;j++){
			ancestros[j][i]=ancestros[ancestros[j][i-1]][i-1];
			todosValores[j][i]=max(todosValores[j][i-1],todosValores[ancestros[j][i-1]][i-1]);
		}
	}
}

ll query(ll inicio, ll fin){
	ll numero=fin-inicio;
	ll potencia = 31 - __builtin_clz(numero);
	ll numero1 = todosValores[inicio][potencia];
	ll numero2 = todosValores[fin - (1<<potencia)][potencia];
	return  max(numero1,numero2);
}


int main(){

	fill(valores,valores+MX,0);
	cin>>n;
	ll cont=1,as=n;
	while(as--){
		ll l;cin>>l;
		valores[cont]=l;
		cont++;
	}
	sparse();
	ll m;cin>>m;
	while(m--){
		ll a,b;cin>>a>>b;
		if(a==b){
			cout<<valores[a]<<endl;
		}else{
			cout<<query(a,b)<<" asdasdasdasd"<<endl;
		}
	}

	return 0;
}