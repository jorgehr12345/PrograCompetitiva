#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std; 
typedef long long ll;
#define Rep0(i, n) for(ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for(ll i = 1; i <= (ll)n; i++)
const ll MX=2e5 + 10,MX2=1e7+2;
bool bo[MX];
pair<ll,ll>pa;
deque<ll>deq,deq2,deq3;
deque<pair<ll,ll>>dpa,dpa2,dpa3;
deque<pair<pair<ll,ll>,ll>>dpapa,dpapa2,dpapa3;
vector<ll>vec,vec2,vec3;
vector<ll>vec4,vec5,vec6;
vector<pair<ll,ll>>vpa,vpa2,vpa3,vpas[MX];
vector<pair<pair<ll,ll>,ll>>vpapa,vpapa2,vpapa3;
set<ll>se,se2,se3,se4;
set<pair<ll,ll>>sepa,sepa2,sepa3;
set<pair<pair<ll,ll>,ll>>sepapa,sepapa2,sepapa3;
map<ll,ll> ma,ma2,ma3,ma4;
map<pair<ll,ll>,ll>mapa,mapa2,mapa3;
map<pair<ll,ll>,pair<ll,ll>>mapapa,mapapa2,mapapa3;
map<ll,pair<ll,ll>>malpa,malpa2,malpa3;
map<ll,pair<pair<ll,ll>,ll>>malpapa,malpapa2,malpapa3;


ll acum=0;
struct SegmentTree{
	ll t[4 * MX2];
	
	ll maxN;
	
	void clear(ll n) {
		for(ll i = 0; i < 4 * n; i++) {
			t[i] = 0;
		}
		maxN = n;
	}
	
	// void build(vector<ll> &a, ll id , ll tl , ll tr) { //O(n)
	// 	if (tl == tr){
	// 		t[id] = a[tl];
	// 	} else{
	// 		ll tm = (tl + tr) / 2;
	// 		ll left = 2 * id;
	// 		ll right = 2 * id + 1;
	// 		build(a, left, tl, tm);
	// 		build(a, right, tm + 1, tr);
	// 		t[id] = 0 /*combine(t[left] , t[right])*/;
	// 	}
	// }
	
	// void build(vector<ll> &a ) {
	// 	maxN = a.size();
	// 	build(a , 1 , 0 , maxN - 1);
	// }

	void query(ll pos ,ll id , ll tl , ll tr ) { //O(logn)
		/*if (l <= tl && tr <= r) {
			return t[id];
		}
		ll tm = (tl + tr) / 2;
		ll left = 2 * id;
		ll right = 2 * id + 1;
		if(r < tm + 1){
			//only left child
			return query(l , r , left , tl , tm);
		}else if(tm < l){
			//only right child
			return query(l , r, right , tm + 1 , tr);  
		} else{
			//both children
			return combine(query(l, r, left, tl, tm) , query(l, r, right, tm + 1, tr));
		}*/



        if (tl == tr) {
			//t[id]= val;
            acum+=t[id];
		}else{
            
			ll tm = (tl + tr) / 2;
			ll left = 2 * id;
			ll right = 2 * id + 1;


            acum+=t[id];
			if (pos <= tm) {
                query(pos, left, tl, tm);
                
			}else {

				query(pos,right, tm + 1, tr);
			}
            //t[id];
        }
	}
	/*
	void query(ll l , ll r) {
		assert(maxN > 0);
		return query(l , r , 1 , 0 , maxN - 1);
	}*/
	
	void update(ll val, ll id, ll tl , ll tr,ll iz,ll de) { //O(logn)

        if (iz <= tl && tr <= de) {
			t[id]+=val;
            return;
		}
		ll tm = (tl + tr) / 2;
		ll left = 2 * id;
		ll right = 2 * id + 1;
		if(de < tm + 1){
			//only left child
			update(val,left,tl,tm,iz,de);
		}else if(tm < iz){
			//only right child
			update(val,right,tm+1,tr,iz,de);
		} else{
			//both children
			//return combine(query(l, r, left, tl, tm) , query(l, r, right, tm + 1, tr));
            update(val,left,tl,tm,iz,de);
            update(val,right,tm+1,tr,iz,de);
		}


        /*
		if (tl == tr) {
			t[id]= val;
		}else{
            
			ll tm = (tl + tr) / 2;
			ll left = 2 * id;
			ll right = 2 * id + 1;



			if (pos <= tm) {
				update(val, left, tl, tm,);

			}else {
				update(pos, val, right, tm + 1, tr);
			}
            t[id];
		}*/
	}
	


	void update(ll iz,ll de, ll val) {
		//assert(maxN > 0);
		update(val,1,0,MX2,iz,de);
	}
} st;



int main() {
	inic;inic2;inic3;
    ll t;cin>>t;
	ll maximo=-1,resp=0;
    while(t--){

		ll n;cin>>n;
		while(n--){
			ll l,r;cin>>l>>r;
			st.update(l,r,1);
			maximo=max(maximo,r);
		}
		for(ll i=1;i<=maximo;i++){
			st.query(i,1,1,MX2);
			//cout<<acum<<endl;
			if(acum==1){
				resp++;
			}
			acum=0;
		}
		cout<<resp<<'\n';
		st.clear(maximo);
        // string s;cin>>s;
        // for(ll i=0;i<s.size();i++){
        //     vec.pb(s[i]-'0');
        // }
        // st.build(vec);
        // ll as;cin>>as;
        // while(as--){
        //     ll iz,de,val;cin>>iz>>de>>val;
        //     st.update(iz,de,val);
        // }
        // ll que;cin>>que;
        // as=que;
        // while(as--){
        //     ll l;cin>>l;
        //     acum=0;
        //     st.query(l,1,0,vec.size()-1);
        //     cout<<acum<<endl;
        // }

        // st.clear(n);
    }
    return 0;
}