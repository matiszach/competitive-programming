// Task statement: https://codeforces.com/problemset/problem/617/E
// *Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INF=1e18+7;
#define pb push_back
const int SIZE=1e5+7,N=(1<<21);
int n,m,k,a,b;
pair<int,pii> queries[SIZE];
int arr[SIZE];
int sqr;
bool cmp(pair<int,pii> A,pair<int,pii> B){
	if(A.second.first/sqr<B.second.first/sqr) return 1;
	if(A.second.first/sqr>B.second.first/sqr) return 0;
	return A.second.second<B.second.second;
}
int pref[SIZE];
int cnt[N];
ll ans;
void add(int x){
	ans+=cnt[x^k];
	++cnt[x];
}
void rem(int x){
	--cnt[x];
	ans-=cnt[x^k];
}
ll res[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		queries[i]={i,{a-1,b}};
	}	
	sqr=sqrt(n);
	sort(queries+1,queries+m+1,cmp);
	for(int i=1;i<=n;++i) pref[i]=pref[i-1]^arr[i];
	int L=0,R=-1;
	for(int i=1;i<=m;++i){
		int l=queries[i].second.first,r=queries[i].second.second;
		while(L>l) add(pref[--L]);
		while(R<r) add(pref[++R]);
		while(L<l) rem(pref[L++]);
		while(R>r) rem(pref[R--]);
		res[queries[i].first]=ans;
	}
	for(int i=1;i<=m;++i) cout<<res[i]<<"\n";
}
