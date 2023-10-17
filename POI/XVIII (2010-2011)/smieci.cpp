//Task statement: szkopul.edu.pl/problemset/problem/_xzIYb_M_gtd4Vz7x_nvrRE6/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+5;
list<pair<int,int> > graph[SIZE];
struct edge{
	int a,b;
	list<pair<int,int> >::iterator it1,it2;
};
int curr_idx=0;
edge edges[SIZE];
void make_edge(int a,int b){
	graph[a].push_front({b,curr_idx});
	graph[b].push_front({a,curr_idx});
	edge e;
	e.a=a; e.b=b; e.it1=graph[a].begin(); e.it2=graph[b].begin();
	edges[curr_idx]=e;
}
void del(int a,list<pair<int,int> >::iterator it){
	graph[a].erase(it);
}
vector<int> euler;
void DFS(int x){
	while(graph[x].size()){
		list<pair<int,int> >::iterator it=graph[x].begin();
		del(edges[(*it).second].a,edges[(*it).second].it1);
		del(edges[(*it).second].b,edges[(*it).second].it2);
		DFS((*it).first);
	}
	euler.push_back(x);
}
bitset<SIZE> visited,checked;
vector<int> eulers[SIZE];
vector<int> bufor;
int n,m,x,y;
bool curr,expected;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>x>>y>>curr>>expected;
		if(curr!=expected){
			make_edge(x,y);
			++curr_idx;
		}
	}
	for(int i=1;i<=n;++i){
		if(graph[i].size()%2==1){
			cout<<"NIE\n";
			return 0;
		}
	}
	int counter=0;
	for(int i=1;i<=n;++i){
		if(graph[i].size()>0){
			bufor.clear();
			euler.clear();
			DFS(i);
			for(int v:euler){
				if(visited[v]){
					eulers[counter].push_back(v);
					while(bufor.back()!=v){
						visited[bufor.back()]=0;
						eulers[counter].push_back(bufor.back());
						bufor.pop_back();
					}
					eulers[counter].push_back(v);
					++counter;
				}else{
					visited[v]=1;
					bufor.push_back(v);
				}
			}
		}
	}
	cout<<counter<<"\n";
	for(int i=0;i<counter;++i){
		if(eulers[i].size()>0){
			cout<<eulers[i].size()-1<<" ";
			for(int v:eulers[i]) cout<<v<<" ";
			cout<<"\n";
		}
	}
}
