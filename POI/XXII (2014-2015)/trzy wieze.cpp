//Task statement: szkopul.edu.pl/problemset/problem/Grfouq9u3g_TYktFXO2sNjCU/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+7,INF=1e9+7;
int n;
string s;
int pref[3][SIZE];
bool check_interval(int a,int b){
	int k1=0,k2=0,k3=0;
	k1=pref[0][b]-pref[0][a-1];
	k2=pref[1][b]-pref[1][a-1];
	k3=pref[2][b]-pref[2][a-1];
	if(k1==0) k1=INF;
	if(k2==0) k2=INF+1;
	if(k3==0) k3=INF+2;
	if(k1!=k2&&k2!=k3&&k1!=k3) return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>s;
	for(int i=1;i<=n;++i){
		int B=0,C=0,S=0;
		if(s[i-1]=='B') B=1;
		if(s[i-1]=='C') C=1;
		if(s[i-1]=='S') S=1;
		pref[0][i]=pref[0][i-1]+B;
		pref[1][i]=pref[1][i-1]+C;
		pref[2][i]=pref[2][i-1]+S;
	}
	int ans=0;
	for(int i=1;i<=n-2;++i){
		if(check_interval(i,n)) ans=max(ans,n-i+1);
		if(check_interval(i,n-1)) ans=max(ans,n-i);
		if(check_interval(i,n-2)) ans=max(ans,n-i-1);
	}
	for(int j=3;j<=n;++j){
		if(check_interval(1,j)) ans=max(ans,j);
		if(check_interval(2,j)) ans=max(ans,j-1);
		if(check_interval(3,j)) ans=max(ans,j-2);
	}
	cout<<ans<<"\n";
}
