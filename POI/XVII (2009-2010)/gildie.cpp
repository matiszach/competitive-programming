//Task statement: szkopul.edu.pl/problemset/problem/Oys6jiVOIap59lYCHRwDMbNT/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<int> graph[200001];
char guilds[200001];
void set_guilds(int x, int y)
{
	if(guilds[x]=='N')
	{
		if(guilds[y]=='K')
		{
			guilds[x]='S';
		}
		else{
			guilds[x]='K';
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	memset(guilds,'N',sizeof(guilds));
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		if(graph[i].size()==0)
		{
			cout<<"NIE\n";
			return 0;
		}
	}
	cout<<"TAK"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<graph[i].size();j++)
		{
			set_guilds(i,graph[i][j]);
			set_guilds(graph[i][j],i);
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<guilds[i]<<"\n";
	}
}
