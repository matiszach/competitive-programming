//Task statement: szkopul.edu.pl/problemset/problem/hJBP1ksBBCO__0pT_WbuobQS/site/
//*Author Mateusz Kowalski*
#include "skolib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define pb push_back
const int INF=1e9+7;
const ll INFLL=1e18+7;
const int MAXN=1e3+7;
int dist[MAXN][MAXN];
bool pot[MAXN][MAXN];
int n;
int X[8]={1,1,-1,-1,2,2,-2,-2};
int Y[8]={2,-2,2,-2,1,-1,1,-1};
bool visited[MAXN][MAXN];
void BFS(int posx,int posy){
	queue<pii> Q;
	Q.push({posx,posy});
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) dist[i][j]=INF,visited[i][j]=0;
	}
	visited[posx][posy]=1;
	dist[posx][posy]=0;
	while(!Q.empty()){
		pii vert=Q.front(); Q.pop();
		for(int i=0;i<8;++i){
			int new_x=vert.first+X[i],new_y=vert.second+Y[i];
			if(new_x<1||new_x>n||new_y<1||new_y>n) continue;
			if(visited[new_x][new_y]) continue;
			if(dist[new_x][new_y]<=dist[vert.first][vert.second]) continue;
			visited[new_x][new_y]=1;
			dist[new_x][new_y]=dist[vert.first][vert.second]+1;
			Q.push({new_x,new_y});
		}
	}
}
pii ask(int posx,int posy){
	int dst=pytanie(posx,posy);
	BFS(posx,posy);
	for(int a=1;a<=n;++a){
		for(int b=1;b<=n;++b){
			if(dist[a][b]!=dst) pot[a][b]=0;
		}
	}
	pii curr={-1,-1};
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(pot[i][j]){
				++cnt;
				curr={i,j};
			}
		}
	}
	if(cnt==1) return curr;
	return {-1,-1};
}
int main()
{
	ios_base::sync_with_stdio(0);
	n=daj_n();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) pot[i][j]=1;
	}
	pii nxt={n/2,n/2};
	ask(1,1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) if(pot[i][j]) nxt={i,j};
	}
	int xd=0;
	while(1){
		pii res=ask(nxt.first,nxt.second);
		++xd;
		if(res.first!=-1){
			odpowiedz(res.first,res.second);
			return 0;
		}
		vector<pii> cands;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(pot[i][j]){
					cands.pb({i,j});
					nxt={i,j};
				}
			}
		}
		int best=100;
		for(pii &p:cands){
			BFS(p.first,p.second);
			map<int,int> d;
			for(pii &w:cands) ++d[dist[w.first][w.second]];
			int maxi=0;
			for(auto v:d) maxi=max(maxi,v.second);
			if(maxi<best){
				 best=maxi;
				 nxt=p;
			}
		}
	}
}
