//Task statement: szkopul.edu.pl/problemset/problem/RKzLhsYuZBU0mnGt_kXeixFR/site/
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
const int MAXN=1e3+7;
int arr[MAXN][MAXN];
int rep[MAXN*MAXN],S[MAXN*MAXN];
int Find(int x){
	if(x==rep[x]) return x;
	return rep[x]=Find(rep[x]);
}
void Union(int a,int b){
	a=Find(a); b=Find(b);
	if(S[a]<S[b]) swap(a,b);
	S[a]+=S[b];
	rep[b]=a;
}
int lowest[MAXN*MAXN],highest[MAXN*MAXN];
bool used[MAXN*MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) cin>>arr[i][j];
	}
	for(int i=1;i<MAXN*MAXN;++i){
		rep[i]=i;
		S[i]=1;
	}
	vector<pii> shifts={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(pii &p:shifts){
				int x=i+p.first,y=j+p.second;
				if(x<1||x>n||y<1||y>n) continue;
				if(arr[x][y]==arr[i][j]&&Find(x*MAXN+y)!=Find(i*MAXN+j)) Union(x*MAXN+y,i*MAXN+j);
			}
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) lowest[i*MAXN+j]=INF;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(pii &p:shifts){
				int x=i+p.first,y=j+p.second;
				if(x<1||x>n||y<1||y>n||Find(x*MAXN+y)==Find(i*MAXN+j)) continue;
				int val=Find(i*MAXN+j);
				lowest[val]=min(lowest[val],arr[x][y]);
				highest[val]=max(highest[val],arr[x][y]);
			}
		}
	}
	int res1=0,res2=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int val=Find(i*MAXN+j);
			if(!used[val]){
				used[val]=1;
				if(arr[i][j]>highest[val]) ++res1;
				if(arr[i][j]<lowest[val]) ++res2;
			}
		}
	}
	cout<<res1<<" "<<res2<<"\n";
}
