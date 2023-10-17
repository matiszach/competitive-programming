//Task statement: szkopul.edu.pl/problemset/problem/PaOm0b0Z7CvBDSQxwd1ItSP8/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int MAXN=32e3+7;
int n,m,a,b;
vector<int> G[MAXN],RG[MAXN];
#define pb push_back
vector<int> postorder;
bitset<MAXN> visited;
void make_edge(int A,int B){
	G[A].pb(B);
	RG[B].pb(A);
}
void DFS(int x){
	visited[x]=1;
	for(int v:G[x]) if(!visited[v]) DFS(v);
	postorder.pb(x);
}
int colors[MAXN];
int color;
void DFS2(int x){
	colors[x]=color;
	for(int v:RG[x]) if(colors[v]==0) DFS2(v);
}
bitset<MAXN> state;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		make_edge(a*2,b*2-1);
		make_edge(b*2,a*2-1);
	}
	for(int i=1;i<=n;++i){
		a=i*2; b=i*2-1;
		make_edge(a*2-1,b*2);
		make_edge(a*2,b*2-1);
		make_edge(b*2-1,a*2);
		make_edge(b*2,a*2-1);
	}
	for(int i=1;i<=n*4;++i) if(!visited[i]) DFS(i);
	reverse(postorder.begin(),postorder.end());
	for(int v:postorder){
		if(colors[v]==0){
			++color;
			DFS2(v);
		}
	}
	for(int i=1;i<=n*2;++i){
		if(colors[i*2]==colors[i*2-1]){
			cout<<"NIE\n";
			return 0;
		}
		state[i]=colors[i*2]>colors[i*2-1];
	}
	for(int i=1;i<=n*2;++i) if(state[i]) cout<<i<<"\n";
}
