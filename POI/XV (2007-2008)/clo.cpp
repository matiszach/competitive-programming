//Task statement: szkopul.edu.pl/task_archive/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e5+7;
int n,m,a,b;
vector<int> graph[SIZE];
bitset<SIZE> visited,on_stack;
vector<int> cycle;
int res[SIZE];
void DFS(int x,int prev){
	visited[x]=1;
	on_stack[x]=1;
	for(int v:graph[x]){
		if(!visited[v]) DFS(v,x);
		else if(on_stack[v]&&v!=prev){
			cycle.push_back(x);
			res[x]=v;
		}
	}
	on_stack[x]=0;
}
void DFS2(int x,int prev){
	res[x]=prev;
	visited[x]=1;
	for(int v:graph[x]){
		if(!visited[v]&&v!=prev) DFS2(v,x);
	}
}
void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	fastscan(n); fastscan(m);
	for(int i=1;i<=m;++i){
		fastscan(a); fastscan(b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]) DFS(i,0);
	}
	visited.reset();
	for(int v:cycle) DFS2(v,res[v]);
	for(int i=1;i<=n;++i){
		if(res[i]==0){
			cout<<"NIE\n";
			return 0;
		}
	}
	cout<<"TAK\n";
	for(int i=1;i<=n;++i) cout<<res[i]<<"\n";
}
