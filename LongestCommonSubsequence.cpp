#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const Long MX = 2001;
string a,b;
bool used[MX][MX];
Long dp[MX][MX];
int edit_distance(Long j,Long k){
	if((j==-1)||(k==-1)){
		return max(max(j+1,k+1),0LL);
	}
	if(used[j][k]){
		return dp[j][k];	
	}
	if(a[j]==b[k])dp[j][k]=edit_distance(j-1,k-1);
	else{
		dp[j][k]=min(min(1+edit_distance(j-1,k-1),1+edit_distance(j,k-1)),1+edit_distance(j-1,k));
	}
	used[j][k] = true;
	return dp[j][k];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    Long h;cin>>h;
	while(h--){
	cin>>a>>b;Long n=a.size()-1,m=b.size()-1;
	for(long long i=0;i<a.size();i++){
		for(long long j=0;j<b.size();j++){
			used[i][j]=false;
		}
	}
	cout<<edit_distance(n,m)<<endl;
	}
	return 0;
}