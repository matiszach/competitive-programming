//Task statement: szkopul.edu.pl/problemset/problem/Ng815bt4Fko9lj2-l7eVl3Aw/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=201;
ll dp[MAXN][MAXN][MAXN];
int powers[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int s,m,q; cin>>s>>m>>q;
	powers[0]=1;
	for(int i=1;i<MAXN;++i) powers[i]=powers[i-1]*10%m;
	dp[0][0][0]=1;
	for(int i=1;i<MAXN;++i){
		for(int j=0;j<=s;++j){
			for(int k=0;k<m;++k){
				for(int digit=0;digit<10;++digit){
					if(j+digit>s) break;
					int new_m=(k+powers[i-1]*digit)%m;
					dp[i][j+digit][new_m]+=dp[i-1][j][k];
					dp[i][j+digit][new_m]=min(dp[i][j+digit][new_m],INFLL);
				}
			}
		}
	}
	for(int z=1;z<=q;++z){
		ll k; cin>>k;
		if(dp[200][s][0]<k){
			cout<<"NIE\n";
			continue;
		}
		int st=0;
		while(dp[st][s][0]<k) ++st;
		int curr_s=s,curr_m=0;
		string res="";
		for(int i=st;i>=1;--i){
			int new_s=0,new_m=0;
			for(int digit=0;digit<10;++digit){
				new_s=curr_s-digit;
				new_m=(curr_m-powers[i-1]*digit+m*10)%m;
				if(dp[i-1][new_s][new_m]<k) k-=dp[i-1][new_s][new_m];
				else{
					res+=char(digit+'0');
					break;
				}
			}
			curr_s=new_s;
			curr_m=new_m;
		}
		cout<<res<<"\n";
	}
}
