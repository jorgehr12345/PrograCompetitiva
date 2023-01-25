#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define debug(x) cout << #x << " = " << x << endl
using namespace std; 
typedef long long ll;
#define Rep0(i, n) for(ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for(ll i = 1; i <= (ll)n; i++)
const ll MX=2e5 + 10,MX2=1e9+2;
bool bo[MX];
pair<ll,ll>pa;
deque<ll>deq,deq2,deq3;
deque<pair<ll,ll>>dpa,dpa2,dpa3;
deque<pair<pair<ll,ll>,ll>>dpapa,dpapa2,dpapa3;
vector<ll>vec,vec2,vec3;
vector<ll>vec4,vec5,vec6;
vector<pair<ll,ll>>vpa,vpa2,vpa3,vpas[MX];
vector<pair<pair<ll,ll>,ll>>vpapa,vpapa2,vpapa3;
set<ll>se,se2,se3,se4,sear[MX],sear2[MX],sear3[MX];
set<pair<ll,ll>>sepa,sepa2,sepa3;
set<pair<pair<ll,ll>,ll>>sepapa,sepapa2,sepapa3;
map<ll,ll> ma,ma2,ma3,ma4;
map<pair<ll,ll>,ll>mapa,mapa2,mapa3;
map<pair<ll,ll>,pair<ll,ll>>mapapa,mapapa2,mapapa3;
map<ll,pair<ll,ll>>malpa,malpa2,malpa3;
map<ll,pair<pair<ll,ll>,ll>>malpapa,malpapa2,malpapa3;


ll combine(ll x, ll y){
	return max(x , y);
}

struct SegmentTree {

	ll maxN;
	
	void clear(ll n) {
		for(ll i = 0; i < 4 * n; i++) {
			t[i] = 0;
			lazy[i] = 0;
		}
		maxN = n;
	}
	
	ll t[4 * MX];
	ll lazy[4 * MX];
	
	void build(vector<ll> &a, ll id , ll tl , ll tr ) { //O(n)
		lazy[id] = 0;
		if (tl == tr) {
			t[id] = a[tl];
		}else{
			ll tm = (tl + tr) / 2;
			ll left = 2 * id;
			ll right = 2 * id + 1;
			build(a, left, tl, tm);
			build(a, right, tm + 1, tr);
			t[id] = combine(t[left], t[right]);
		}
	}
	
	void build(vector<ll> &a ) {
		maxN = a.size();
		build(a , 1 , 0 , maxN - 1);
	}
	
	void push(ll id) { //O(1)
		ll left = 2 * id;
		ll right = 2 * id + 1;
		
		//Apply the lazy value of the node to the children
		t[left] += lazy[id]; 
		t[right] += lazy[id]; 
		
		//aggregate the lazy value of the node to the lazy value of the children
		lazy[left] += lazy[id];
		lazy[right] += lazy[id];
		
		//restart lazy node of the node
		lazy[id] = 0;
	}


	ll query(ll l, ll r, ll id , ll tl, ll tr ) { //O(logn)
		if (l <= tl && tr <= r) {
			return t[id];
		}
		ll tm = (tl + tr) / 2;
		ll left = 2 * id;
		ll right = 2 * id + 1;
		push(id);
		if(r < tm + 1){
			return query(l , r , left , tl , tm);
		}else if(tm < l){
			return query(l , r, right , tm + 1 , tr);  
		} else{
			return combine(query(l, r, left, tl, tm) , query(l, r, right, tm + 1, tr));
		}
	}
	
	ll query(ll l , ll r) {
		//assert(maxN > 0);
		return query(l , r , 1 , 0 , maxN - 1);
	}

	void update(ll l, ll r, ll add, ll id , ll tl , ll tr) { //O(logn)
		if(tr < l || tl > r){
			return;
		}
		if (l <= tl && tr <= r) {
			//apply the update to the node
			t[id] += add;
			
			//agregate the lazy value
			lazy[id] += add;
		}else{
			ll tm = (tl + tr) / 2;
			ll left = 2 * id;
			ll right = 2 * id + 1 ;
			push(id);
			update(l, r, add , left, tl, tm);
			update(l, r, add , right, tm + 1, tr);
			t[id] = combine(t[left], t[right]);
		}
	}
	
	void update(ll l , ll r, ll add) {
		//assert(maxN > 0);
		update(l, r , add , 1 , 0 , maxN - 1);
	}
	
	void print( ll id , ll tl , ll tr ){
		cout << "a[ " << tl << " ... " << tr << " ],  t = " << t[id] <<  " lazy = " << lazy[id] << endl;
		if (tl == tr) {
			return;
		}
		ll tm = (tl + tr) / 2;
		ll left = 2 * id;
		ll right = 2 * id + 1 ;
		print(left, tl, tm);
		print(right, tm + 1, tr);
	}
	
	void print(){
		print(1 , 0 , maxN - 1);
	}
} st;


int main(){
	inic;inic2;inic3;
	
	return 0;
}