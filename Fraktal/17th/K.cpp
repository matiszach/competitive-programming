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
const int MAXN=9;
int dist[MAXN][MAXN][MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int q; cin>>q;
	for(int a=0;a<8;++a) for(int b=0;b<8;++b) for(int c=0;c<8;++c) for(int d=0;d<8;++d) dist[a][b][c][d]=INF;
	vector<pii> moves={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
	for(int a=0;a<8;++a){
		for(int b=0;b<8;++b){
			queue<pii> Q;
			Q.push({a,b});
			dist[a][b][a][b]=0;
			while(!Q.empty()){
				pii vert=Q.front(); Q.pop();
				for(pii &p:moves){
					int new_x=vert.first+p.first,new_y=vert.second+p.second;
					if(new_x<0||new_x>=8||new_y<0||new_y>=8||dist[a][b][new_x][new_y]<=dist[a][b][vert.first][vert.second]) continue;
					dist[a][b][new_x][new_y]=dist[a][b][vert.first][vert.second]+1;
					Q.push({new_x,new_y});
				}
			}
		}
	}
	for(int i=1;i<=q;++i){
		char x; cin>>x;
		int y; cin>>y;
		x-='A';
		--y;
		char xx; cin>>xx;
		int yy; cin>>yy;
		xx-='A';
		--yy;
		cout<<dist[(int)x][y][(int)xx][yy]<<"\n";
	}
}
