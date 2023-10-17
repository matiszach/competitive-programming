//Task statement: szkopul.edu.pl/problemset/problem/UU2Uj-barjiONnRxd9aEVoDj/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+7;
int edges[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;++i) edges[i]=0;
	for(int i=1;i<=m;++i){
		int a,b; cin>>a>>b;
		++edges[a];
		++edges[b];
	}
	int total=n*(n-1)*(n-2)/6;
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=edges[i]*(n-edges[i]-1);
	}
	cout<<total-ans/2<<"\n";
}
