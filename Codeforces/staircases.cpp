// Task statement: https://codeforces.com/problemset/problem/1598/E
// *Author Mateusz Kowalski*
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
const int MAXN=1e3+7;
bool arr[MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	ll ans=0;
	for(int i=1;i<=n;++i){
		int x=i,y=1,len=1;
		while(1){
			if(x+1>n) break;
			++x; ++len;
			if(y+1>m) break;
			++y; ++len;
		}
		ans+=(ll)len*(len+1)/2;
	}
	for(int i=1;i<=m;++i){
		int x=1,y=i,len=1;
		while(1){
			if(y+1>m) break;
			++y; ++len;
			if(x+1>n) break;
			++x; ++len;
		}
		ans+=len*(len+1)/2;
	}
	ans-=n*m;
	int q; cin>>q;
	for(int z=1;z<=q;++z){
		int x,y; cin>>x>>y;
		int lenL=0,lenU=0,lenR=0,lenD=0;
		int curr_x=x,curr_y=y;
		while(1){
			if(curr_x-1<1||arr[curr_x-1][curr_y]) break;
			--curr_x; ++lenL;
			if(curr_y-1<1||arr[curr_x][curr_y-1]) break;
			--curr_y; ++lenL;
		}
		curr_x=x; curr_y=y;
		while(1){	
			if(curr_y-1<1||arr[curr_x][curr_y-1]) break;
			--curr_y; ++lenU;
			if(curr_x-1<1||arr[curr_x-1][curr_y]) break;
			--curr_x; ++lenU;
		}
		curr_x=x; curr_y=y;
		while(1){
			if(curr_x+1>n||arr[curr_x+1][curr_y]) break;
			++curr_x; ++lenR;
			if(curr_y+1>m||arr[curr_x][curr_y+1]) break;
			++curr_y; ++lenR;
		}
		curr_x=x; curr_y=y;
		while(1){
			if(curr_y+1>m||arr[curr_x][curr_y+1]) break;
			++curr_y; ++lenD;
			if(curr_x+1>n||arr[curr_x+1][curr_y]) break;
			++curr_x; ++lenD;
		}
		int mlp=(arr[x][y]?-1:1);
		int len1=lenL+lenD+1;
		int len2=lenR+lenU+1;
		ans+=mlp*lenL*(lenL+1)/2;
		ans+=mlp*lenU*(lenU+1)/2;
		ans+=mlp*lenR*(lenR+1)/2;
		ans+=mlp*lenD*(lenD+1)/2;
		ans-=mlp*len1*(len1+1)/2;
		ans-=mlp*len2*(len2+1)/2;
		ans+=mlp;
		cout<<ans<<"\n";
		arr[x][y]^=1;
	}
}
