#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std; 
typedef long long ll;
#define Rep0(i, n) for(ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for(ll i = 1; i <= (ll)n; i++)
const ll MX=2e5 + 5;
bool bo[MX];
pair<ll,ll>pa;
deque<ll>deq,deq2,deq3;
deque<pair<ll,ll>>dpa,dpa2,dpa3;
deque<pair<pair<ll,ll>,ll>>dpapa,dpapa2,dpapa3;
vector<ll>vec,vec2,vec3;
vector<pair<ll,ll>>vpa,vpa2,vpa3;
vector<pair<pair<ll,ll>,ll>>vpapa,vpapa2,vpapa3;
set<ll>se,se2,se3;
set<pair<ll,ll>>sepa,sepa2,sepa3;
set<pair<pair<ll,ll>,ll>>sepapa,sepapa2,sepapa3;
map<ll,ll> ma,ma2,ma3,ma4;
map<pair<ll,ll>,ll>mapa,mapa2,mapa3;
map<pair<ll,ll>,pair<ll,ll>>mapapa,mapapa2,mapapa3;
const ll EXTRA = 6;
struct BIT{
	ll tree[MX+EXTRA];
	
	void clear(ll n){ //O(n)
		for(ll i = 0; i <= n + EXTRA; i++){
			tree[i] = 0;
		}
	}
	
	ll query(ll x){ //O(log n)
		x += EXTRA;
		ll sum = 0;
		while(x > 0){
			sum += tree[x];
			x -= (x & -x);
		}
		return sum;
	}
	
	void update(ll x , ll add){ //O(log n)
		x += EXTRA;
		while(x < MX + EXTRA){
			tree[x] += add;
			x += (x & -x);
		}
	}	
} ft,ft2;
int main(){
    ll n,m;
    while(cin>>n>>m){
        string resp="";
        ft.clear(MX);ft2.clear(n);se.clear();se2.clear();
        ll i=1;
        while(n--){
            ll t;cin>>t;
            if(t<0){
                ft.update(i,1);se.insert(i);//cout<<"pos "<<i<<endl;
                //cout<<ft.query(i)<<" query "<<endl;
            }if(t==0){
                ft2.update(i,1);se2.insert(i);
            }
            i++;
        }
        while(m--){
            char a;ll b,c;
            cin>>a>>b>>c;
            if(a=='C'){
                if(se.find(b)!=se.end()){
                    se.erase(se.find(b));ft.update(b,-1);
                    //cout<<" elim "<<b<<endl;
                }
                if(c<0){
                    se.insert(b);ft.update(b,1);
                }

                if(se2.find(b)!=se2.end()){
                    se2.erase(se2.find(b));ft2.update(b,-1);
                    //cout<<" elim "<<b<<endl;
                }
                if(c==0){
                    se2.insert(b);ft2.update(b,1);
                }
            }else
            {
                if(a=='P'){
                    if((ft2.query(c) - ft2.query(b-1)) ==0){
                        if((ft.query(c)-ft.query(b-1))%2==0){
                            resp+="+";
                            
                        }else
                        {
                            resp+="-";
                        }
                        
                    }else
                    {
                        resp+="0";
                    }
                }
                
            } 
            
        }
        cout<<resp<<endl;
    }
    return 0;
}