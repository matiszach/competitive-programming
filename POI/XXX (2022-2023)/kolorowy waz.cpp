//Task statement: szkopul.edu.pl/problemset/problem/MAWN1VdLdXO29VvrVYuYxQyw/site/
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
const int MAXN=2e3+7;
int arr[MAXN][MAXN];
int entry[MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m,p,n; cin>>m>>p>>n;
	for(int i=0;i<=m;++i) for(int j=0;j<=m;++j) arr[i][j]=-1;
	for(int i=1;i<=p;++i){
		int a,b,c; cin>>a>>b>>c;
		arr[a][b]=c;
	}
	vector<int> colors={0};
	pii pos={1,1};
	int moment=1,len=1;
	entry[1][1]=1;
	for(int i=1;i<=n;++i){
		char c; cin>>c;
		if(c=='Z'){
			int a,b; cin>>a>>b;
			int x=entry[a][b];
			if(x==0||len-(moment-x)-1<0) cout<<"-1\n";
			else{
				cout<<colors[len-(moment-x)-1]<<"\n";
			}
		}else{
			if(c=='P') ++pos.second;
			if(c=='L') --pos.second;
			if(c=='D') ++pos.first;
			if(c=='G') --pos.first;
			entry[pos.first][pos.second]=++moment;
			if(arr[pos.first][pos.second]>=0){
				colors.pb(arr[pos.first][pos.second]);
				arr[pos.first][pos.second]=-1;
				++len;
			}
		}
	}
}
