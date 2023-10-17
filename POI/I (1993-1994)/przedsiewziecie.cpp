//Task statement: szkopul.edu.pl/problemset/problem/_eiKtK6ANqMn5Nfl6UNJksjy/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e5+5;
int n,z,t,k,num;
vector<int> graph[SIZE],r_graph[SIZE];
#define pb push_back
long long times[SIZE];
bitset<SIZE> visited;
vector<int> postorder;
int counter;
void DFS(int x){
	visited[x]=1;
	for(int v:graph[x]){
		if(!visited[v]) DFS(v);
	}
	postorder.pb(x);
}
bool found=false;
void DFS2(int x){
	visited[x]=1;
	for(int v:r_graph[x]){
		if(!visited[v]) found=true;
	}
}
long long values[SIZE];
long long significance[SIZE];
long long biggest=0;
void DFS3(int x){
	visited[x]=1;
	for(int v:r_graph[x]){
		if(!visited[v]) DFS3(v);
	}
	for(int v:r_graph[x]){
		values[x]=max(values[x],values[v]);
	}
	values[x]+=times[x];
	biggest=max(biggest,values[x]);
}
void DFS4(int x){
	visited[x]=1;
	for(int v:graph[x]){
		if(!visited[v]) DFS4(v);
	}
	long long min_sign=99999999999999;
	significance[x]=min_sign;
	long long val=0;
	long long time_val=0;
	for(int v:graph[x]){
		significance[x]=min(significance[x],significance[v]+(values[v]-values[x]-times[v]));
		if(significance[v]<min_sign){
			min_sign=significance[v];
			val=values[v];
			time_val=times[v];
		}
	}
	if(graph[x].size()==0) significance[x]=biggest-values[x];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>t>>k;
		times[i]=t;
		for(int j=0;j<k;++j){
			cin>>num;
			graph[num].pb(i);
			r_graph[i].pb(num);
		}
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			DFS(i);
		}
	}
	visited.reset();
	for(int i=postorder.size()-1;i>=0;--i){
		if(!visited[postorder[i]]) DFS2(postorder[i]);
	}
	if(found){
		cout<<"CYKL\n";
		return 0;
	}
	visited.reset();
	for(int i=1;i<=n;++i){
		if(graph[i].size()==0){
			if(!visited[i]) DFS3(i);
		}
	}
	visited.reset();
	for(int i=1;i<=n;++i){
		if(r_graph[i].size()==0){
			if(!visited[i]) DFS4(i);
		}
	}
	cout<<biggest<<"\n";
	cin>>z;
	int node=0,change=0;
	for(int q=0;q<z;++q){
		cin>>node>>change;
		if(change>significance[node]){
			cout<<"TAK\n";
		}else cout<<"NIE\n";
	}
}
