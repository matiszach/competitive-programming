//Task statement: szkopul.edu.pl/problemset/problem/dABzva_j1-BvzKMsyxkuRoue/site/
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
const int MAXN=1e6+7,MAX2=1e3+7;
struct edge{
	int a,b,c,x,y;
};
int m,n;
char x;
vector<edge> edges;
void make_edge(int a,int b,int c,int x,int y){
	edges.pb({a,b,c,x,y});
}
bool cmp(edge &A,edge &B){
	return A.c<B.c;
}
int T[MAXN],S[MAXN];
int Find(int a){
	if(a==T[a]) return a;
	return T[a]=Find(T[a]);
}
void Union(int a,int b){
	a=Find(a); b=Find(b);
	if(S[a]>S[b]) swap(a,b);
	S[b]+=S[a];
	T[a]=b;
}
bool hor[MAX2][MAX2],vert[MAX2][MAX2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>m>>n;
	for(int i=1;i<=m;++i){
		for(int j=1;j<n;++j){
			cin>>x;
			if(x=='C') make_edge((i-1)*n+j,(i-1)*n+j+1,INF,i,j);
			else make_edge((i-1)*n+j,(i-1)*n+j+1,1,i,j);
		}
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<=n;++j){
			cin>>x;
			if(x=='C') make_edge((i-1)*n+j,(i)*n+j,INF,i,j);
			else make_edge((i-1)*n+j,(i)*n+j,1,i,j);
		}
	}
	for(int i=1;i<=n*m;++i){
		T[i]=i;
		S[i]=1;
	}
	sort(edges.begin(),edges.end(),cmp);
	vector<edge> chosen;
	for(edge e:edges){
		if(Find(e.a)==Find(e.b)) chosen.pb(e);
		else Union(e.a,e.b);
	}
	int cnt=0;
	for(edge e:chosen) if(e.c==INF) ++cnt;
	cout<<chosen.size()<<" "<<cnt<<"\n";
	for(edge e:chosen){
		int a=e.a,b=e.b;
		if(a>b) swap(a,b);
		if(a+1==b){
			hor[e.x][e.y]=1;
		}else{
			vert[e.x][e.y]=1;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<n;++j) cout<<(hor[i][j]?'Z':'.');
		cout<<"\n";
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<=n;++j) cout<<(vert[i][j]?'Z':'.');
		cout<<"\n";
	}
}
