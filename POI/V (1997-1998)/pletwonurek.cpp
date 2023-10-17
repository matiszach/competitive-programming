//Task statement: szkopul.edu.pl/problemset/problem/sJ1qx1ofWZlg2bZR40XJB_0O/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e3+7,INF=1e9+7;
int t,a,n;
int o[SIZE],h[SIZE],w[SIZE];
int dp[22][80];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t>>a>>n;
	for(int i=1;i<=n;++i){
		cin>>o[i]>>h[i]>>w[i];
	}
	for(int i=0;i<=t;++i){
		for(int j=0;j<=a;++j){
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=t;j>=0;--j){
			for(int k=a;k>=0;--k){
				int x=min(t,j+o[i]),y=min(a,k+h[i]);
				dp[x][y]=min(dp[x][y],dp[j][k]+w[i]);
			}
		}
	}
	cout<<dp[t][a]<<"\n";
}
