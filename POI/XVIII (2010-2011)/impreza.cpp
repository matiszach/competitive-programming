//Task statement: szkopul.edu.pl/problemset/problem/PCtteC6gKwc2ZikW8nUZzfyh/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=3e3+7;
int n,m,a,b;
bool exists[SIZE];
bool conns[SIZE][SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		conns[a][b]=1;
		conns[b][a]=1;
	}
	for(int i=1;i<=n;++i) exists[i]=1;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(!exists[i]||!exists[j]) continue;
			if(!conns[i][j]){
				exists[i]=0;
				exists[j]=0;
			}
		}
	}
	int picked=0;
	for(int i=1;i<=n;++i){
		if(picked>=n/3) break;
		if(exists[i]){
			++picked;
			cout<<i<<" ";
		}
	}
}
