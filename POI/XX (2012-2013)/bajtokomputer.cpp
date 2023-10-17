//Task statement: szkopul.edu.pl/problemset/problem/3GXkVUEnWNZRn2C2VpX2uKmq/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+5,INF=1e9+7;
int n;
int arr[SIZE];
int dp[3][SIZE];
#define neg 0
#define neut 1
#define pos 2
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	dp[neg][0]=dp[neut][0]=dp[pos][0]=INF;
	dp[arr[0]+1][0]=0;
	for(int i=1;i<n;++i){
		if(arr[i]==-1){
			dp[neg][i]=dp[neg][i-1];
			dp[neut][i]=INF;
			dp[pos][i]=dp[pos][i-1]+2;
		}else if(arr[i]==0){
			dp[neg][i]=dp[neg][i-1]+1;
			dp[neut][i]=min(dp[neg][i-1],dp[neut][i-1]);
			dp[pos][i]=dp[pos][i-1]+1;
		}else if(arr[i]==1){
			dp[neg][i]=dp[neg][i-1]+2;
			dp[neut][i]=dp[neg][i-1]+1;
			dp[pos][i]=min(dp[neg][i-1],min(dp[neut][i-1],dp[pos][i-1]));
		}
	}
	int solution=min(dp[neg][n-1],min(dp[neut][n-1],dp[pos][n-1]));
	if(solution==INF) cout<<"BRAK\n";
	else cout<<solution<<"\n";
}
