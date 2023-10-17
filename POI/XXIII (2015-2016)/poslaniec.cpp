//Task statement: szkopul.edu.pl/problemset/problem/Mk-9GNDtSal6h_8T4n9Ezq9M/site/
//*Author Mateusz Kowalski*
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
const int MAXN=107,D=51;
int arr[MAXN][MAXN];
ll z;
int n;
struct matrix{
	ll M[MAXN][MAXN];
	matrix operator *(const matrix &B) const{
		matrix res;
		for(int a=1;a<=n;++a) for(int b=1;b<=n;++b) res.M[a][b]=0;
		for(int a=1;a<=n;++a){
			for(int b=1;b<=n;++b){
				for(int c=1;c<=n;++c){
					(res.M[a][b]+=M[a][c]*B.M[c][b])%=z;
				}
			}
		}
		return res;
	}
	void init(int T[][MAXN]){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) M[i][j]=T[i][j];
		}
	}
};
ll total[MAXN][MAXN][D];
ll bad[MAXN][MAXN][D];
ll good[MAXN][MAXN][D];
int main()
{
	ios_base::sync_with_stdio(0);
	int m; cin>>n>>m>>z;
	for(int i=1;i<=m;++i){
		int a,b; cin>>a>>b;
		arr[a][b]=1;
	}
	int q; cin>>q;
	matrix org;
	org.init(arr);
	matrix curr;
	curr.init(arr);
	for(int i=1;i<D;++i){
		for(int a=1;a<=n;++a) for(int b=1;b<=n;++b) total[a][b][i]=curr.M[a][b];
		curr=curr*org;
	}
	for(int a=1;a<=n;++a) for(int b=1;b<=n;++b) good[a][b][1]=total[a][b][1];
	for(int a=1;a<=n;++a){
		for(int b=1;b<=n;++b){
			if(a==b) continue;
			for(int k=1;k<D;++k){
				ll val=0,val2=0;
				for(int j=1;j<k;++j){
					(val+=(total[a][b][j]*good[b][b][k-j]+total[a][a][j]*good[a][b][k-j]))%=z;
					(val2+=(total[b][b][j]*good[b][b][k-j]+total[b][a][j]*good[a][b][k-j]))%=z;
				}
				bad[a][b][k]=val;
				bad[b][b][k]=val2;
				good[a][b][k]=(total[a][b][k]+z-bad[a][b][k])%z;
				good[b][b][k]=(total[b][b][k]+z-bad[b][b][k])%z;
			}
		}
	}
	for(int i=1;i<=q;++i){
		int a,b,d; cin>>a>>b>>d;
		cout<<good[a][b][d]<<"\n";
	}
}
