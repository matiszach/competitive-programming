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
const int MAXN=8;
bool tmp[MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m,k; cin>>n>>m>>k;
	vector<int> A;
	for(int i=0;i<n*m-k;++i) A.pb(0);
	for(int i=0;i<k;++i) A.pb(1);
	ll total=0;
	do{
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j) tmp[i][j]=A[i*m+j];
		}
		int curr=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(tmp[i][j]){
					if(i>0&&!tmp[i-1][j]) ++curr;
					if(i<n-1&&!tmp[i+1][j]) ++curr;
					if(j>0&&!tmp[i][j-1]) ++curr;
					if(j<m-1&&!tmp[i][j+1]) ++curr;
				}
			}
		}
		total+=curr;
	}while(next_permutation(A.begin(),A.end()));
	cout<<total<<"\n";
}
