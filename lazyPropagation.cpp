#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NUint);
#define inic3 cout.tie(NUint);
using namespace std; 

#define Rep0(i, n) for(int i = 0; i < (int)n; i++)
#define Rep1(i, n) for(int i = 1; i <= (int)n; i++)
const int MX=2e5 + 10,MX2=2e5+2;
typedef long long ll;
set<int>se,se2;


struct SegmentTree{
	int lazy[4 * MX2];
	//bool marked[4 * MX];
	//int maxN=2e5+2;
	
	void clear(int n) {
		for(int i = 0; i < 4 * n; i++) {
			lazy[i] = 0;
			//marked[i] = false;
		}
	}
	
	void push(int id){ //O(1)
		//if(marked[id]){
			int left = 2 * id;
			int right = 2 * id + 1 ;
            if(lazy[id]!=0){
    			lazy[left] = lazy[id];
    			lazy[right] = lazy[id];
                lazy[id]=0;
            }
			//aggregate the lazy value of the node to the lazy value of the children
			//marked[left] = true;
			//marked[right] = true;
			
			//restart lazy node of the node
			//marked[id] = false;
		//}
	}
	
	void update(int l, int r, int val, int id, int tl, int tr ){ //O(logn)
		if(tr < l || tl > r){
			return;
		}
		if (l <= tl && tr <= r) {
			//aggregate update
			lazy[id] = val;
            //cout<<lazy[id]<<" cuyo id es "<<id<<endl;
			//marked[id] = true;
		}else {
			int tm = (tl + tr) / 2;
			int left = 2 * id;
			int right = 2 * id + 1 ;
			push(id);
			update(l, r, val , left, tl, tm);
			update(l, r, val , right, tm + 1, tr);
            // for(int i=1;i<=32;i++){
            // cout<<lazy[i]<<" ";}cout<<endl;
		}
	}
	
	void update(int l , int r, int val) {
		//assert(maxN > 0);
		update(l , r , val, 1 , 0 , 2e5/*maxN - 1*/);
	}
} st;

bool resp[4*MX2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
    int asd=1;
    while(t--){

		memset(resp,false,sizeof resp);
		//memset(st.lazy,0,sizeof st.lazy);
        se.clear();
        se2.clear();
        int n;cin>>n;
        int i=1;
        int ximo=-1;
        while(n--){
            int izq,der;cin>>izq>>der;
            st.update(izq,der,i);
			ximo=max(ximo,der);
            i++;
            //ximo=max(ximo,der);
        }
		//cout<<sizeof st.lazy<<endl;
		//cout<<st.lazy[6400063]<<endl;
        //cout<<st.lazy[4*MX2]<<endl;
		for(int i=1;i<4*MX2;i++){
            //cout<<st.lazy[i]<<" ";
            if(st.lazy[i]!=0 && resp[i]==false){
                //cout<<i<<" "<<st.lazy[i]<<endl;
                se.insert(st.lazy[i]);
				if(2*i<4*MX2){
					resp[2*i]=true;
				}
				if(2*i+1<4*MX2){
					resp[2*i+1]=true;
				}
            }
			if(resp[i]==true){
				if(2*i<4*MX2){
					resp[2*i]=true;
				}
				if(2*i+1<4*MX2){
					resp[2*i+1]=true;
				}
			}
        }
        //cout<<"sdadad "<<se2.end()<<endl;
        st.clear(ximo);
        cout<<"Case "<<asd<<": ";
        cout<<se.size()<<'\n';
        // set<int>::iterator it;
        // for(it=se.begin();it!=se.end();it++){
        //     cout<<*it<<" ";
        // }
        asd++;
    }
    
	return 0;
}