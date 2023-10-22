#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __int128 ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=1e6+7,nTree=(1<<20);
int arr[MAXN];
bitset<MAXN*40> T;
pii primes[MAXN];
const pair<long long,long long> MOD={40013455900003561,6517106827609519};
pll H[MAXN];
pll t[nTree<<1];
void update(int l,int r,pll val){
	if(l>r) return;
	l+=nTree; r+=nTree;
	(t[l].first*=val.first)%=MOD.first;
	(t[l].second*=val.second)%=MOD.second;
	if(l<r){
		(t[r].first*=val.first)%=MOD.first;
		(t[r].second*=val.second)%=MOD.second;
	}
	while(l<r-1){
		if(l%2==0){
			(t[l+1].first*=val.first)%=MOD.first;
			(t[l+1].second*=val.second)%=MOD.second;
		}
		if(r%2==1){
			(t[r-1].first*=val.first)%=MOD.first;
			(t[r-1].second*=val.second)%=MOD.second;
		}
		l>>=1; r>>=1;
	}
}
pll query(int pos){
	pos+=nTree;
	pll res={1,1};
	while(pos>0){
		(res.first*=t[pos].first)%=MOD.first;
		(res.second*=t[pos].second)%=MOD.second;
		pos>>=1;
	}
	return res;
}
pll invpair(pll x){
	ll fi=1,se=1,curr=x.first;
	for(int i=0;i<63;++i){
		if((1LL<<i)&(MOD.first-2)) (fi*=curr)%=MOD.first;
		(curr*=curr)%=MOD.first;
	}
	curr=x.second;
	for(int i=0;i<63;++i){
		if((1LL<<i)&(MOD.second-2)) (se*=curr)%=MOD.second;
		(curr*=curr)%=MOD.second;
	}
	return {fi,se};
}
ll inv(ll x,ll md){
	ll curr=x,res=1;
	for(int i=0;i<63;++i){
		if((1LL<<i)&(md-2)) (res*=curr)%=md;
		(curr*=curr)%=md;
	}
	return res%md;
}
pll get_hash(int x,int y){
	pll res=query(y);
	res.first*=inv(query(x-1).first,MOD.first);
	res.second*=inv(query(x-1).second,MOD.second);
	res.first%=MOD.first;
	res.second%=MOD.second;
	return res;
}
map<long long,set<int>> pos;
bool exists(int l,int r,pll val){
	auto it=pos[val.first].lower_bound(l);
	bool ok=0;
	if(it!=pos[val.first].end()&&(*it)<=r) ok=1;
	if(!ok) return 0;
	it=pos[val.second].lower_bound(l);
	ok=0;
	if(it!=pos[val.second].end()&&(*it)<=r) ok=1;
	if(!ok) return 0;
	return 1;
}
bool check(int l,int mid,int r){
	if(l>mid||mid>r) return 0;
	pll part1=get_hash(l,mid),part2=get_hash(mid+1,r);
	int L=mid+1,R=r;
	if((mid-l)>=(r-mid)){
		swap(part1,part2);
		L=l; R=mid;
	}
	pll req=invpair(part1);
	(req.first*=part2.first)%=MOD.first;
	(req.second*=part2.second)%=MOD.second;
	if(exists(L,R,req)) return 1;
	return 0;
}
void solve_case(){
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i){
		pos[primes[arr[i]].first].insert(i);
		pos[primes[arr[i]].second].insert(i);
	}
	for(int i=0;i<(nTree<<1);++i) t[i]={1,1};
	H[0]={1,1};
	for(int i=1;i<=n;++i){
		H[i].first=(H[i-1].first*primes[arr[i]].first)%MOD.first;
		H[i].second=(H[i-1].second*primes[arr[i]].second)%MOD.second;
	}
	for(int i=1;i<=n;++i) update(i,i,H[i]);
	int ans=0;
	int q; cin>>q;
	for(int i=1;i<=q;++i){
		int type; cin>>type;
		if(type==1){
			int x,y; cin>>x>>y;
			update(x,n,invpair(primes[arr[x]]));
			update(x,n,primes[y]);
			pos[primes[arr[x]].first].erase(x);
			pos[primes[arr[x]].second].erase(x);
			arr[x]=y;
			pos[primes[arr[x]].first].insert(x);
			pos[primes[arr[x]].second].insert(x);
		}else{
			int l,r; cin>>l>>r;
			if(l==r){
				++ans;
				continue;
			}
			int mid=(l+r)>>1;
			if(check(l,mid,r)||check(l,mid-1,r)){
				++ans;
			}
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i) H[i]={1,1};
	pos.clear();
}
void solve_ez(){
	string s; cin>>s;
	int n=s.size();
	for(int i=1;i<=n;++i) arr[i]=s[i-1]-'a'+1;
	for(int i=1;i<=n;++i){
		pos[primes[arr[i]].first].insert(i);
		pos[primes[arr[i]].second].insert(i);
	}
	for(int i=0;i<(nTree<<1);++i) t[i]={1,1};
	H[0]={1,1};
	for(int i=1;i<=n;++i){
		H[i].first=(H[i-1].first*primes[arr[i]].first)%MOD.first;
		H[i].second=(H[i-1].second*primes[arr[i]].second)%MOD.second;
	}
	for(int i=1;i<=n;++i) update(i,i,H[i]);
	int ans=0;
	int q; cin>>q;
	for(int i=1;i<=q;++i){
		int l,r; cin>>l>>r;
		if(l==r){
			++ans;
			continue;
		}
		int mid=(l+r)>>1;
		if(check(l,mid,r)||check(l,mid-1,r)){
			++ans;
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i) H[i]={1,1};
	pos.clear();
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for(int i=2;i*i<MAXN*40;++i){
		for(int j=i*i;j<MAXN*40;j+=i) T[j]=1;
	}
	int idx=1,cnt=0;
	while(cnt<MAXN){
		++idx;
		if(!T[idx]) primes[cnt++].first=idx;
	}
	cnt=0;
	while(cnt<MAXN){
		++idx;
		if(!T[idx]) primes[cnt++].second=idx;
	}
	int tt; cin>>tt;
	for(int i=1;i<=tt;++i){
		cout<<"Case #"<<i<<": ";
		solve_case();
	}
}
