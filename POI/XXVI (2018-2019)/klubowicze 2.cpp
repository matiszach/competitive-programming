//Task statement: szkopul.edu.pl/problemset/problem/iNO3dMisUj2wQ_ywbKfWLlpi/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=4e6+7;
int n,m;
int arr[MAXN];
int pref[2][MAXN];
bool to_check[2][31];
int curr;
bool check(int start,int last){
	for(int i=0;i<2;++i){
		if(to_check[i][curr]){
			if(pref[i][last]-pref[i][start-1]==0) return 0;
		}
	}
	return 1;
}
int lft[MAXN],rgt[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i) cin>>arr[i];
	for(int i=1;i<=m;++i) arr[i+m]=arr[i];
	for(int i=1;i<=m;++i) rgt[i]=m*2;
	for(int i=1;i<=m;++i){
		for(int j=0;j<n;++j){
			to_check[((1<<j)&arr[i])?1:0][j]=1;
		}
	}
	for(int i=0;i<n;++i){
		curr=i;
		for(int j=1;j<=m*2;++j){
			pref[0][j]=pref[0][j-1]+(((1<<i)&arr[j])?0:1);
			pref[1][j]=pref[1][j-1]+(((1<<i)&arr[j])?1:0);
		}
		int last=0;
		for(int start=1;start<=m;++start){
			last=max(last,start);
			if(!check(start,last)){
				while(last<start+m-1&&!check(start,last+1)) ++last;
				++last;
			}
			lft[start]=max(lft[start],last);
		}
		last=m*2+1;
		for(int start=m*2-1;start>m-1;--start){
			last=min(last,start);
			if(!check(last,start)){
				while(last>start-m+1&&!check(last-1,start)) --last;
				--last;
			}
			rgt[start-m+1]=min(rgt[start-m+1],last);
		}
	}
	ll ans=0;
	for(int i=1;i<=m;++i) ans+=max(0,rgt[i]-lft[i]);
	cout<<ans/2<<"\n";
}
