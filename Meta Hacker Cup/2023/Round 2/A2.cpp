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
const int MAXN=3e3+7;
char arr[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pii> curr;
int X[4]={-1,1,0,0};
int Y[4]={0,0,-1,1};
void DFS(int x,int y){
	curr.pb({x,y});
	visited[x][y]=1;
	for(int i=0;i<4;++i){
		if(!visited[x+X[i]][y+Y[i]]&&arr[x+X[i]][y+Y[i]]=='W') DFS(x+X[i],y+Y[i]);
	}
}
int n,m;
int res[MAXN][MAXN];
int check(){
	vector<vector<pii>> clusters;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!visited[i][j]&&arr[i][j]=='W'){
				DFS(i,j);
				clusters.pb(curr);
				curr.clear();
			}
		}
	}
	for(int i=0;i<(int)clusters.size();++i){
		pii pos={-1,-1};
		bool is_ok=1;
		for(pii &v:clusters[i]){
			for(int j=0;j<4;++j){
				int x=v.first+X[j],y=v.second+Y[j];
				if(arr[x][y]=='.'){
					if(pos.first!=-1&&(pos.first!=x||pos.second!=y)){
						is_ok=0;
						break;
					}else{
						pos={x,y};
					}
				}
			}
			if(!is_ok) break;
		}
		if(pos.first!=-1&&is_ok) res[pos.first][pos.second]+=clusters[i].size();
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) ans=max(ans,res[i][j]);
	}
	clusters.clear();
	return ans;
}
void solve_case(int nr){
	for(int i=0;i<MAXN;++i){
		for(int j=0;j<MAXN;++j){
			arr[i][j]='.';
			visited[i][j]=0;
			res[i][j]=0;
		}
	}
	cin>>n>>m;
	for(int i=0;i<=m+1;++i) arr[0][i]=arr[n+1][i]='B';
	for(int i=0;i<=n+1;++i) arr[i][0]=arr[i][m+1]='B';
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) cin>>arr[i][j];
	}
	cout<<check()<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve_case(i);
	}
}
