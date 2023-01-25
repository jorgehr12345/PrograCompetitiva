#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
#define Rep0(i, n) for(int i = 0; i < (int)n; i++)
#define Rep1(i, n) for(int i = 1; i <= (int)n; i++)
const int MX=2e5 + 10,MX2=1e5+2;
typedef long long ll;
bool bo[MX];
pair<ll,ll>pa;
deque<ll>deq,deq2,deq3;
deque<pair<ll,ll>>dpa,dpa2,dpa3;
deque<pair<pair<ll,ll>,ll>>dpapa,dpapa2,dpapa3;
vector<ll>vec,vec2,vec3;
vector<ll>vec4,vec5,vec6;
vector<pair<ll,ll>>vpa,vpa2,vpa3,vpas[MX],vpas2[MX],vpas3[MX];
vector<pair<pair<ll,ll>,ll>>vpapa,vpapa2,vpapa3;
set<ll>se,se2,se3,se4,ses[MX],ses2[MX],ses3[MX];
set<pair<ll,ll>>sepa,sepa2,sepa3,sepas[MX],sepas2[MX],sepas3[MX];
set<pair<pair<ll,ll>,ll>>sepapa,sepapa2,sepapa3;
map<ll,ll> ma,ma2,ma3,ma4;
map<pair<ll,ll>,ll>mapa,mapa2,mapa3;
map<pair<ll,ll>,pair<ll,ll>>mapapa,mapapa2,mapapa3;
map<ll,pair<ll,ll>>malpa,malpa2,malpa3;
map<ll,pair<pair<ll,ll>,ll>>malpapa,malpapa2,malpapa3;

string s;
ll elem[MX][5][2];
ll dp(ll pos,ll estado,ll segundo){

    ll actual=estado;
    if(actual==4){
        return 0;
    }
    if(pos>s.size()){
        return 0;
    }
    if(s[pos]=='h'){
        if(actual==0){
            actual++;
        }
    }
    if(s[pos]=='a'){
        if(actual==1){
            actual++;
        }
    }
    if(s[pos]=='r'){
        if(actual==2){
            actual++;
        }
    }
    if(s[pos]=='d'){
        if(actual==3){
            actual++;
        }
    }

    if(elem[pos+1][actual][1]==-1){        
        elem[pos+1][actual][1]=dp(pos+1,actual,1);
    }
    if(elem[pos+1][estado][0]==-1){
        elem[pos+1][estado][0]=dp(pos+1,estado,0);
    };

    if(segundo==1){
        elem[pos][estado][1]=ma[pos]+max(elem[pos+1][estado][0],elem[pos+1][actual][1]);
    }else
    {
        elem[pos][estado][0]=max(elem[pos+1][estado][0],elem[pos+1][actual][1]);
    }
    //cout<<pos<<" "<<estado<<" "<<segundo<<" "<<elem[pos][estado][segundo]<<endl;
    return elem[pos][estado][segundo];
}




int main() {
	inic;inic2;inic3;
    memset(elem,-1,sizeof elem);
    ll n,as;cin>>n;as=n;
    cin>>s;
    ll j=1;
    ll tot=0;
    while(as--){
        ll l;cin>>l;
        ma[j]=l;
        tot+=l;
        j++;
    }
    cout<<tot-dp(0,0,0)<<endl;

	return 0;
}


