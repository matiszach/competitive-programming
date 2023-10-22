#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=2e6+7;
int a[MAXN],b[MAXN];
int rel[MAXN];
int pref[MAXN];
int get(int l,int r,bool neg){
	if(!neg) return pref[r]-pref[l-1];
	return (r-l+1)-(pref[r]-pref[l-1]);
}
int tmpA[MAXN],tmpB[MAXN];
int n;
bool check(int x){
	for(int i=1;i<=x;++i){
		tmpA[n-x+i]=b[i];
		tmpB[n-x+i]=a[i];
	}
	for(int i=1;i<=n-x;++i){
		tmpA[i]=a[i+x];
		tmpB[i]=b[i+x];
	}
	for(int i=1;i<=n/2;++i){
		if(tmpA[i]>tmpB[i]) return 0;
	}
	for(int i=n;i>n-n/2;--i){
		if(tmpA[i]<tmpB[i]) return 0;
	}
	for(int i=1;i<=n;++i){
		if(tmpA[i]!=tmpB[n-i+1]) return 0;
	}
	return 1;
}
void shift(int x){
	for(int i=1;i<=x;++i){
		tmpA[n-x+i]=b[i];
		tmpB[n-x+i]=a[i];
	}
	for(int i=1;i<=n-x;++i){
		tmpA[i]=a[i+x];
		tmpB[i]=b[i+x];
	}
	for(int i=1;i<=n;++i){
		a[i]=tmpA[i];
		b[i]=tmpB[i];
	}
}
void solve_case(){
	cin>>n;
	for(int i=0;i<=n;++i){
		a[i]=0;
		b[i]=0;
		tmpA[i]=0;
		tmpB[i]=0;
		rel[i]=0;
		pref[i]=0;
	}
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) cin>>b[i];
	if(n%2){
		int pos=-1;
		for(int i=1;i<=n;++i){
			if(a[i]==b[i]){
				if(pos!=-1){
					cout<<"-1\n";
					return;
				}
				pos=i-1;
			}
		}
		if(pos==-1){
			cout<<"-1\n";
			return;
		}
		if(pos<n/2){
			if(check(pos+n/2+1)) cout<<pos+n/2+1<<"\n";
			else{
				shift(n);
				if(check(pos+n/2+1)) cout<<pos+n/2+1+n<<"\n";
				else cout<<"-1\n";
			}
			return;
		}else{
			if(check(pos-n/2)) cout<<pos-n/2<<"\n";
			else{
				shift(n);
				if(check(pos-n/2)) cout<<pos-n/2+n<<"\n";
				else cout<<"-1\n";
			}
			return;
		}
	}else{
		for(int i=1;i<=n;++i){
			if(a[i]<b[i]) rel[i]=1;
			if(a[i]>b[i]) rel[i]=0;
			if(a[i]==b[i]){
				cout<<"-1\n";
				return;
			}
		}
		for(int i=1;i<=n;++i) pref[i]=pref[i-1]+rel[i];
		for(int i=0;i<n;++i){
			if(i<=n/2){
				int l=get(i+1,i+n/2,0);
				int r=get(i+n/2+1,n,0)+get(1,i,1);
				if(l==n/2&&r==0){
					if(check(i)){
						cout<<i<<"\n";
						return;
					}
				}
			}else{
				int l=get(i+1,n,0)+get(1,n/2-(n-i),1);
				int r=get(n/2-(n-i)+1,i,1);
				if(l==n/2&&r==0){
					if(check(i)){
						cout<<i<<"\n";
						return;
					}
				}
			}
		}
		shift(n);
		for(int i=1;i<=n;++i){
			if(a[i]<b[i]) rel[i]=1;
			if(a[i]>b[i]) rel[i]=0;
		}
		for(int i=1;i<=n;++i) pref[i]=pref[i-1]+rel[i];
		for(int i=0;i<n;++i){
			if(i<=n/2){
				int l=get(i+1,i+n/2,0);
				int r=get(i+n/2+1,n,0)+get(1,i,1);
				if(l==n/2&&r==0){
					if(check(i)){
						cout<<i+n<<"\n";
						return;
					}
				}
			}else{
				int l=get(i+1,n,0)+get(1,n/2-(n-i),1);
				int r=get(n/2-(n-i)+1,i,1);
				if(l==n/2&&r==0){
					if(check(i)){
						cout<<i+n<<"\n";
						return;
					}
				}
			}
		}
	}
	cout<<"-1\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve_case();
	}
}
