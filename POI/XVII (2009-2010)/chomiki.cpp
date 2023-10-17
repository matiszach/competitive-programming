//Task statement: szkopul.edu.pl/problemset/problem/mLv0a_y18C5vj5J6jFK2gbwr/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=(ll)1e17;
const int SIZE=2e2+7;
int n,m;
string hams[SIZE];
ll KMP(string &s){
	int N=s.size();
	vector<ll> pi(N);
	for(int i=1;i<N;++i){
		int j=pi[i-1];
		while(j>0&&s[i]!=s[j]) j=pi[j-1];
		if(s[i]==s[j]) ++j;
		pi[i]=j;
	}
	return pi.back();
}
struct MAT{
	ll A[SIZE][SIZE];
	void operator=(const MAT &b){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				A[i][j]=b.A[i][j];
			}
		}
	}
	void operator*=(const MAT &b){
		ll a[SIZE][SIZE];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				ll best=INF;
				for(int k=1;k<=n;++k)
					best=min(best,A[i][k]+b.A[k][j]);
				a[i][j]=best;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				A[i][j]=a[i][j];
			}
		}
	}
	void init(){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				A[i][j]=INF;
			}
		}
	}
};
MAT x,y;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>hams[i];
	m--;
	x.init();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			ll weg=0;
			if(hams[i]==hams[j]) weg=(ll)hams[i].size()-KMP(hams[i]);
			else{
				string temp=hams[j]+'$'+hams[i];
				weg=(ll)hams[j].size()-KMP(temp);
			}
			x.A[i][j]=weg;
		}
	}
	y.init();
	y=x;
	ll ans=INF;
	if(m==0){
		for(int i=1;i<=n;++i) ans=min(ans,(ll)hams[i].size());
		cout<<ans<<"\n";
		return 0;
	}
	m--;
	for(int i=0;i<31;++i){
		if((1<<i)&m) x*=y;
		y*=y;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			ans=min(ans,x.A[i][j]+(ll)hams[i].size());
		}
	}
	cout<<ans<<"\n";
}
