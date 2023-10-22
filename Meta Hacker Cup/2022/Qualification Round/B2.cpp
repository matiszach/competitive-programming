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
vector<int> G[MAXN*MAXN];
int in[MAXN*MAXN];
bool bad_tiles[MAXN][MAXN];
void solve_case(){
	int r,c; cin>>r>>c;
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j) cin>>arr[i][j];
	}
	for(int i=0;i<MAXN*MAXN;++i){
		bad_tiles[i/MAXN][i%MAXN]=0;
		in[i]=0;
		G[i].clear();
		G[i].shrink_to_fit();
	}
	vector<pii> shifts={{-1,0},{1,0},{0,-1},{0,1}};
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j){
			if(arr[i][j]=='#') continue;
			for(pii p:shifts){
				int new_x=i+p.first;
				int new_y=j+p.second;
				if(new_x<1||new_x>r||new_y<1||new_y>c||arr[new_x][new_y]=='#') continue;
				G[i*MAXN+j].pb(new_x*MAXN+new_y);
				++in[new_x*MAXN+new_y];
			}
		}
	}
	queue<int> Q;
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j){
			if(in[i*MAXN+j]==0){
				bad_tiles[i][j]=1;
			}
			if(in[i*MAXN+j]==0&&arr[i][j]=='^'){
				cout<<"Impossible\n";
				return;
			}
			if(in[i*MAXN+j]==1){
				Q.push(i*MAXN+j);
				in[i*MAXN+j]=0;
			}
		}
	}
	while(!Q.empty()){
		int vert=Q.front(); Q.pop();
		bad_tiles[vert/MAXN][vert%MAXN]=1;
		for(int v:G[vert]){
			--in[v];
			if(in[v]==1) Q.push(v);
		}
	}
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j){
			if(arr[i][j]=='^'){
				if(bad_tiles[i][j]){
					cout<<"Impossible\n";
					return;
				}
				int cnt=0;
				for(int v:G[i*MAXN+j]){
					if(!bad_tiles[v/MAXN][v%MAXN]) ++cnt;
				}
				if(cnt<2){
					cout<<"Impossible\n";
					return;
				}
			}
		}
	}
	cout<<"Possible\n";
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j){
			if(arr[i][j]=='#') cout<<"#";
			else if(bad_tiles[i][j]) cout<<".";
			else cout<<"^";
		}
		cout<<"\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<": \n";
		solve_case();
	}
}
