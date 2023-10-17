//Task statement: szkopul.edu.pl/problemset/problem/gIvRmapl7sX6di87092Rmjdw/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=5e5+7,LOG=20;
int n,k,a,b;
int graph[SIZE],cc[SIZE],cycle[SIZE];
int state[SIZE],pos[SIZE],branch[SIZE];
int depth[SIZE],root[SIZE],amount[SIZE]
int scc[SIZE];
int lca[LOG][SIZE];
int preorder[SIZE],postorder[SIZE];
vector<int> G[SIZE],r_graph[SIZE];
bitset<SIZE> visited;
int idx=0;
void DFS(int x){
	visited[x]=1;
	cc[x]=idx;
	for(int v:G[x]){
		if(!visited[v]) DFS(v);
	}
}
vector<int> path;
bool found=0;
int element=0;
void DFS2(int x){
	path.push_back(x);
	visited[x]=1;
	cycle[x]=1;
	if(cycle[graph[x]]==1){
		cycle[graph[x]]=2;
		found=1;
		element=graph[x];
		return;
	}else if(!visited[graph[x]]) DFS2(graph[x]);
	cycle[x]=0;
}
int counter=0;
void DFS3(int x,int dep){
	visited[x]=1;
	pos[x]=dep;
	scc[x]=idx;
	++counter;
	if(!visited[graph[x]]) DFS3(graph[x],dep+1);
}
int curr=1;
void DFS4(int x,int prev,int dep){
	preorder[x]=++idx;
	lca[0][x]=prev;
	branch[x]=curr;
	depth[x]=dep;
	for(int v:r_graph[x]){
		if(!visited[v]&&state[v]==0) DFS4(v,x,dep+1);
	}
	postorder[x]=++idx;
}
bool anc(int v,int u){
	if(v==u) return 1;
	return (preorder[v]<preorder[u]&&postorder[v]>postorder[u]);
}
int LCA(int v,int u){
	if(anc(v,u)) return v;
	if(anc(u,v)) return u;
	for(int i=LOG-1;i>=0;--i){
		if(!anc(lca[i][v],u)){
			v=lca[i][v];
		}
	}
	return lca[0][v];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>graph[i];
	for(int i=1;i<=n;++i){
		G[i].push_back(graph[i]);
		G[graph[i]].push_back(i);
		r_graph[graph[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			DFS(i);
			++idx;
		}
	}
	visited.reset();
	idx=1;
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			while(!path.empty()){
				cycle[path.back()]=0;
				path.pop_back();
			}
			element=0;
			found=0;
			DFS2(i);
			if(!found) continue;
			int prev=0;
			while(!path.empty()&&prev!=element){
				state[path.back()]=idx;
				cycle[prev]=0;
				prev=path.back();
				path.pop_back();
			}
			++idx;
		}
	}
	visited.reset();
	for(int i=1;i<=n;++i){
		if(!visited[i]&&state[i]>0){
			DFS3(i,0);
			amount[idx]=counter;
			counter=0;
			++idx;
		}
	}
	visited.reset();
	idx=0;
	for(int i=1;i<=n;++i){
		if(!visited[i]&&state[i]>0){
			DFS4(i,i,0);
			root[curr]=i;
			++curr;
		}
	}
	for(int i=1;i<LOG;++i){
		for(int j=1;j<=n;++j){
			lca[i][j]=lca[i-1][lca[i-1][j]];
		}
	}
	while(k--){
		cin>>a>>b;
		if(a==b) cout<<"0 0\n";
		else if(cc[a]!=cc[b]){
			cout<<"-1 -1\n";
		}else if(branch[a]==branch[b]){
			int y=LCA(a,b);
			cout<<depth[a]-depth[y]<<" "<<depth[b]-depth[y]<<"\n";
		}else{
			int vert_a=root[branch[a]],vert_b=root[branch[b]];
			int a1=depth[a],a2=depth[a],b1=depth[b],b2=depth[b];
			if(pos[vert_a]<pos[vert_b]){
				a1+=pos[vert_b]-pos[vert_a];
				b2+=amount[scc[vert_a]]-(pos[vert_b]-pos[vert_a]);
			}else{
				b1+=pos[vert_a]-pos[vert_b];
				a2+=amount[scc[vert_a]]-(pos[vert_a]-pos[vert_b]);
			}
			if(max(a1,b1)==max(a2,b2)){
				if(min(a1,b1)==min(a2,b2)){
					if(a1>a2) cout<<a1<<" "<<b1<<"\n";
					else cout<<a2<<" "<<b2<<"\n";
				}else if(min(a1,b1)<min(a2,b2)){
					cout<<a1<<" "<<b1<<"\n";
				}else cout<<a2<<" "<<b2<<"\n";
			}else if(max(a1,b1)<max(a2,b2)){
				cout<<a1<<" "<<b1<<"\n";
			}else cout<<a2<<" "<<b2<<"\n";
		}
	}
}
