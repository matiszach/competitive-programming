//Task statement: szkopul.edu.pl/problemset/problem/aKKSmtjWTtDOEHDqnmQ3-eAA/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int MAXN = 1e5 + 7;
vector<int> G[MAXN], R[MAXN], SCC[MAXN];
bool visited[MAXN];
vector<int> postorder;
void DFS(int x){
	visited[x] = 1;
	for(int &v : G[x]) if(!visited[v]) DFS(v);
	postorder.pb(x);
}
int colors[MAXN];
int color;
int res[MAXN];
void rDFS(int x){
	colors[x] = color;
	++res[color];
	for(int &v : R[x]) if(!colors[v]) rDFS(v);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int a, b; cin >> a >> b;
		G[a].pb(b);
		R[b].pb(a);
	}
	for(int i = 1; i <= n; ++i){
		if(!visited[i]) DFS(i);
	}
	reverse(postorder.begin(), postorder.end());
	for(int &v : postorder){
		if(!colors[v]){
			++color;
			rDFS(v);
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int &v : G[i]){
			if(colors[i] != colors[v]) SCC[colors[i]].pb(colors[v]);
		}
	}
	for(int i = color; i >= 1; --i){
		for(int &v : SCC[i]) res[i] += res[v];
	}
	for(int i = 1; i <= n; ++i) cout << res[colors[i]] - 1 << "\n";
}

