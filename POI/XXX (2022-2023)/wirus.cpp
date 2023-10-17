//Task statement: szkopul.edu.pl/problemset/problem/oghgoWt-Ai8xS6iTN8vHyoL3/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int MAXN=707;
typedef long long ll;
bool curr[MAXN][MAXN],res[MAXN][MAXN],tmp[MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; ll d; cin>>n>>d;
	string s; cin>>s;
	if(d<=2'000'000){
		deque<bool> Q;
		for(int i=1;i<=n;++i) Q.push_back(s[i-1]-'0');
		for(int i=1;i<=d;++i){
			int x=Q.front();
			Q.pop_front();
			x^=Q.front();
			Q.push_back(x);
		}
		for(int v:Q) cout<<v;
		cout<<"\n";
		return 0;
	}
	for(int i=0;i<n-1;++i) curr[i][i+1]=1;
	curr[n-1][0]=curr[n-1][1]=1;
	for(int i=0;i<n;++i) res[i][i]=1;
	for(int i=0;i<50;++i){
		if((1LL<<i)&d){
			for(int a=0;a<n;++a){
				for(int b=0;b<n;++b){
					for(int c=0;c<n;++c) tmp[a][b]^=(res[a][c]&curr[c][b]);
				}
			}
			for(int a=0;a<n;++a) for(int b=0;b<n;++b) res[a][b]=tmp[a][b];
			for(int a=0;a<n;++a) for(int b=0;b<n;++b) tmp[a][b]=0;
		}
		for(int a=0;a<n;++a){
			for(int b=0;b<n;++b){
				for(int c=0;c<n;++c) tmp[a][b]^=(curr[a][c]&curr[c][b]);
			}
		}
		for(int a=0;a<n;++a) for(int b=0;b<n;++b) curr[a][b]=tmp[a][b];
		for(int a=0;a<n;++a) for(int b=0;b<n;++b) tmp[a][b]=0;
	}
	vector<bool> A(n),ans(n);
	for(int i=0;i<n;++i) A[i]=s[i]-'0';
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			ans[i]=ans[i]^((res[i][j])&&A[j]);
		}
	}
	for(bool v:ans) cout<<v;
	cout<<"\n";
}
