// Task statement: https://www.spoj.com/problems/MPOW/
// *Author Mateusz Kowalski*
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
const int MOD=1e9+7;
struct matrix{
	int n=0;
	vector<vector<int>> M;
	matrix(int N){
		n=N;
		M=vector<vector<int>>(N,vector<int>(N));
	}
	void identity(){
		for(int i=0;i<n;++i) M[i][i]=1;
	}
	void print(){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j) cout<<M[i][j]<<" ";
			cout<<"\n";
		}
	}
	matrix operator *(matrix &A) const{
		matrix res=matrix(n);
		for(int a=0;a<n;++a){
			for(int b=0;b<n;++b){
				for(int c=0;c<n;++c){
					(res.M[a][b]+=(ll)M[a][c]*A.M[c][b]%MOD)%=MOD;
				}
			}
		}
		return res;
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	for(int tt=1;tt<=t;++tt){
		int m,n; cin>>m>>n;
		matrix x=matrix(m);
		for(int i=0;i<m;++i){
			for(int &v:x.M[i]) cin>>v;
		}
		matrix res=matrix(m);
		res.identity();
		for(int i=0;i<31;++i){
			if((1<<i)&n) res=res*x;
			x=x*x;
		}
		res.print();
	}
}
