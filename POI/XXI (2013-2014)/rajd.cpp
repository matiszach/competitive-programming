//Task statement: szkopul.edu.pl/problemset/problem/orur2kPvWQR0LzMXXoP6pCat/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=5e5+7,nTree=524288;
int T[nTree*2];
int n,m,a,b;
vector<int> graph[SIZE];
pair<int,int> edges[SIZE*2];
bitset<SIZE> visited;
vector<int> order,postorder;
int pos[SIZE];
int start[SIZE],endg[SIZE],pref[SIZE],suf[SIZE];
void DFS(int x){
	visited[x]=1;
	for(int v:graph[x]){
		if(!visited[v]) DFS(v);
	}
	postorder.push_back(x);
}
void update(int l,int r,int val){
	if(l>r) return;
	l+=nTree;
	r+=nTree;
	T[l]=max(T[l],val);
	T[r]=max(T[r],val);
	while(l<r-1){
		if(l%2==0) T[l+1]=max(T[l+1],val);
		if(r%2==1) T[r-1]=max(T[r-1],val);
		l/=2;
		r/=2;
	}
}
int query(int x){
	x+=nTree;
	int val=T[x];
	while(x>0){
		val=max(T[x],val);
		x/=2;
	}
	return val;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		graph[a].push_back(b);
		edges[i]={a,b};
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]) DFS(i);
	}
	order.push_back(-1);
	for(int i=postorder.size()-1;i>=0;--i){
		order.push_back(postorder[i]);
		pos[postorder[i]]=order.size()-1;
	}
	for(int i=1;i<order.size();++i){
		for(int j:graph[order[i]]){
			endg[j]=max(endg[j],endg[order[i]]+1);
		}
	}
	for(int i=order.size()-1;i>=1;--i){
		for(int j:graph[order[i]]){
			start[order[i]]=max(start[order[i]],start[j]+1);
		}
	}
	for(int i=1;i<order.size();++i){
		pref[i]=max(pref[i-1],endg[order[i]]);
	}
	for(int i=order.size()-1;i>=1;--i){
		suf[i]=max(suf[i+1],start[order[i]]);
	}
	for(int i=1;i<=m;++i){
		update(pos[edges[i].first]+1,pos[edges[i].second]-1,endg[edges[i].first]+start[edges[i].second]+1);
	}
	int ans=m,vert=1;
	for(int i=1;i<=n;++i){
		int res=max(pref[pos[i]-1],max(suf[pos[i]+1],query(pos[i])));
		if(res<ans){
			ans=res;
			vert=i;
		}
	}
	cout<<vert<<" "<<ans<<"\n";
}
