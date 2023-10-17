//Task statement: szkopul.edu.pl/problemset/problem/bS_effBgQtuS7NXJA_dn7Ogm/site/
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
const int MAXN=257;
int n,m;
vector<int> pos;
bool arr[MAXN][MAXN];
bitset<MAXN> hor[32][MAXN],vert[32][MAXN];
void mul(int idx){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			bool res=0;
			if((hor[idx-1][i]&vert[idx-1][j]).count()>0) res=1;
			hor[idx][i][j]=res;
			vert[idx][j][i]=res;
		}
	}
}
bitset<MAXN> res[MAXN],C[MAXN];
void mul2(int idx){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			bool rs=0;
			if((res[i]&vert[idx][j]).count()>0) rs=1;
			C[i][j]=rs;
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) res[i][j]=C[i][j];
}
int k;
bool check(int x){
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) res[i][j]=0;
	for(int i=1;i<=n;++i) res[i][i]=1;
	for(int i=0;i<31;++i){
		if((1<<i)&x) mul2(i);
	}
	vector<int> cnt(MAXN);
	for(int v:pos){
		for(int j=1;j<=n;++j){
			if(res[v][j]) ++cnt[j];
		}
	}
	for(int i=1;i<=n;++i) if(cnt[i]==k) return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=k;++i){
		int x; cin>>x;
		pos.pb(x);
	}
	for(int i=1;i<=m;++i){
		int a,b; cin>>a>>b;
		arr[a][b]=1;
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) hor[0][i][j]=arr[i][j];
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) vert[0][j][i]=arr[i][j];
	for(int i=1;i<=31;++i) mul(i);
	int l=0,r=n*n,mid=0;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(!check(l)) cout<<"NIE\n";
	else cout<<"TAK\n"<<l<<"\n";
}
