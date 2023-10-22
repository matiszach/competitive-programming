// Task statement: https://www.spoj.com/problems/NUMTSN/
// *Author Mateusz Kowalski*
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<iostream>
#include<vector>
using namespace std;
const int INF=1e9+7;
#define pb push_back
const int N=53,M=17,M2=34,MOD=1e9+7;
int dp[2][2][M2][M2][N];
int count(string &x){
	vector<int> digits={0};
	for(char &c:x) digits.pb(c-'0');
	for(int a=0;a<N;++a){
		for(int b=0;b<M2;++b){
			for(int c=0;c<M2;++c){
				dp[0][0][b][c][a]=0;
				dp[0][1][b][c][a]=0;
				dp[1][0][b][c][a]=0;
				dp[1][1][b][c][a]=0;
			}	
		}
	}
	int n=(int)x.size();
	dp[0][0][M][M][0]=1;
	vector<int> good={3,6,9},bad={0,1,2,4,5,7,8};
	for(int i=1;i<=n;++i){
		int max_diff=min(i,n-i+1);
		int mini=max(0,M-max_diff),maxi=min(M2,M+max_diff+1);
		for(int _36=mini;_36<maxi;++_36){
			for(int _69=mini;_69<maxi;++_69){
				for(int b=0;b<2;++b){
					for(int e=0;e<2;++e){
						for(int digit:good){
							if(digit>digits[i]&&!b) break;
							int new36=_36+(digit==3)-(digit==6);
							int new69=_69+(digit==6)-(digit==9);
							if(new36<0||new36>=M2) continue;
							if(new69<0||new69>=M2) continue;
							bool newb=(b||(digit<digits[i]));
							dp[newb][1][new36][new69][i]+=dp[b][e][_36][_69][i-1];
							if(dp[newb][1][new36][new69][i]>=MOD) dp[newb][1][new36][new69][i]-=MOD;
						}
						for(int digit:bad){
							if(digit>digits[i]&&!b) break;
							bool newb=(b||(digit<digits[i]));
							dp[newb][e][_36][_69][i]+=dp[b][e][_36][_69][i-1];
							if(dp[newb][e][_36][_69][i]>=MOD) dp[newb][e][_36][_69][i]-=MOD;
						}
					}
				}
			}
		}
	}
	int ans=(dp[0][1][M][M][n]+dp[1][1][M][M][n])%MOD;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		string a,b; cin>>a>>b;
		int ans=(count(b)-count(a)+MOD)%MOD;
		int cnt3=0,cnt6=0,cnt9=0;
		for(char &c:a){
			if(c=='3') ++cnt3;
			if(c=='6') ++cnt6;
			if(c=='9') ++cnt9;
		}
		if(cnt3>0&&cnt3==cnt6&&cnt6==cnt9) ++ans;
		cout<<ans%MOD<<"\n";
	}
}
