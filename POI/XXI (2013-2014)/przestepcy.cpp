//Task statement: szkopul.edu.pl/problemset/problem/bobLSP2Wo3SQjakifBIQhXlq/site/
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
const int MAXN=1e6+7,nTree=(1<<20);
int n,k,l,r;
int arr[MAXN];
int burg1[MAXN],burg2[MAXN];
vector<int> pos[MAXN];
int dp[MAXN];
int closest_left[MAXN],closest_right[MAXN];
int T[nTree<<1];
void update(int beg,int en){
	if(beg>en) return;
	beg+=nTree; en+=nTree;
	++T[beg];
	if(beg<en) ++T[en];
	while(beg<en-1){
		if(beg%2==0) ++T[beg+1];
		if(en%2==1) ++T[en-1];
		beg>>=1; en>>=1;
	}
}
int query(int plc){
	plc+=nTree;
	int val=T[plc];
	while(plc>>=1) val+=T[plc];
	return val;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) pos[arr[i]].pb(i);
	cin>>l>>r;
	for(int i=1;i<=l;++i) cin>>burg1[i];
	for(int i=1;i<=r;++i) cin>>burg2[i];
	vector<pii> seg1,seg2;
	int last=0;
	for(int v:pos[burg1[1]]){
		int start=v,curr=v;
		bool nein=0;
		for(int i=2;i<=l-1;++i){
			vector<int>::iterator it=upper_bound(pos[burg1[i]].begin(),pos[burg1[i]].end(),curr);
			if(it==pos[burg1[i]].end()){
				nein=1;
				break;
			}
			curr=*it;
			if(dp[curr]==i) break;
			dp[curr]=i;
			last=max(last,curr);
		}
		if(nein) break;
		last=max(last,curr);
		seg1.pb({start,last});
	}
	for(int i=1;i<=n;++i) dp[i]=0;
	last=n;
	reverse(pos[burg2[1]].begin(),pos[burg2[1]].end());
	for(int v:pos[burg2[1]]){
		int start=v,curr=v;
		bool nein=0;
		for(int i=2;i<=r-1;++i){
			vector<int>::iterator it=lower_bound(pos[burg2[i]].begin(),pos[burg2[i]].end(),curr);
			if(it==pos[burg2[i]].begin()||pos[burg2[i]].size()==0){
				nein=1;
				break;
			}
			--it;
			curr=*it;
			if(dp[curr]==i) break;
			dp[curr]=i;
			last=min(last,curr);
		}
		if(nein) break;
		last=min(last,curr);
		seg2.pb({start,last});
	}
	reverse(pos[burg2[1]].begin(),pos[burg2[1]].end());
	reverse(seg2.begin(),seg2.end());
	for(int i=1;i<=k;++i){
		if(pos[i].size()>0){
			int x=pos[i][0];
			pii p={x,INF};
			vector<pii>::iterator it=upper_bound(seg1.begin(),seg1.end(),p);
			if(it==seg1.end()) closest_left[i]=-1;
			else closest_left[i]=it->second;
			x=pos[i].back();
			p={x,-INF};
			it=lower_bound(seg2.begin(),seg2.end(),p);
			if(it==seg2.begin()) closest_right[i]=-1;
			else{
				--it;
				closest_right[i]=it->second;
			}
		}else closest_left[i]=closest_right[i]=-1;
	}
	seg1.clear(); seg2.clear();
	seg1.shrink_to_fit();
	seg2.shrink_to_fit();
	for(int i=1;i<=k;++i){
		if(closest_left[i]!=-1&&closest_right[i]!=-1) update(closest_left[i],closest_right[i]);
	}
	int ans=0;
	for(int i=1;i<=n;++i) if(arr[i]==burg1[l]&&query(i)>0) ++ans;
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i) if(arr[i]==burg1[l]&&query(i)>0) cout<<i<<" ";
}
