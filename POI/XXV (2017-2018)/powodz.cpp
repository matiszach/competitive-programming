//Task statement: szkopul.edu.pl/problemset/problem/xCiDtZ0ZX70fyac1Sav8d37J/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll val=1,MOD=1e9+7,H;
int n,m,brd;
struct tile{
	ll ans,h;
	pair<int,int> p;
	int deg;
};
vector<vector<tile> > tiles;
struct edge{
	int x1,y1,x2,y2,h;
};
vector<edge> edges;
bool cmp(edge e1,edge e2){
	return e1.h<e2.h;
}
pair<int,int> Find(pair<int,int> x){
	if(x==tiles[x.first][x.second].p) return x;
	return tiles[x.first][x.second].p=Find(tiles[x.first][x.second].p);
}
void Union(pair<int,int> x,pair<int,int> y,int h){
	pair<int,int> a=Find(x),b=Find(y);
	if(a!=b){
		if(tiles[a.first][a.second].deg<tiles[b.first][b.second].deg) swap(a,b);
		tiles[b.first][b.second].p=a;
		tiles[a.first][a.second].ans=(tiles[a.first][a.second].ans+h-tiles[a.first][a.second].h)*
		                             (tiles[b.first][b.second].ans+h-tiles[b.first][b.second].h)%MOD;
		tiles[a.first][a.second].h=h;
		if(tiles[a.first][a.second].deg==tiles[b.first][b.second].deg) ++tiles[a.first][a.second].deg;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>H;
	if(m>1)
	for(int i=1;i<=n;++i){
		for(int j=1;j<m;++j){
			cin>>brd;
			edges.push_back({j,i,j+1,i,brd});
		}
	}
	if(n>1)
	for(int j=1;j<n;++j){
		for(int i=1;i<=m;++i){
			cin>>brd;
			edges.push_back({i,j,i,j+1,brd});
		}
	}
	sort(edges.begin(),edges.end(),cmp);
	tiles.resize(n+1);
	for(int i=1;i<=n;++i) tiles[i].resize(m+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			tiles[i][j].ans=1;
			tiles[i][j].h=0;
			tiles[i][j].p={i,j};
		}
	}
	for(edge e:edges){
		Union({e.y1,e.x1},{e.y2,e.x2},e.h);
	}
	pair<int,int> v=Find({1,1});
	val=(tiles[v.first][v.second].ans+H-tiles[v.first][v.second].h)%MOD;
	cout<<val<<"\n";
}
