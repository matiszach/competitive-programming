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
const int MAXN=1e6+7;
int pref[26][MAXN];
int arr[MAXN];
int get_diff(int l,int mid,int r){
	if(l>mid||mid>r) return 0;
	int diff=0;
	for(int i=0;i<26;++i){
		diff+=abs((pref[i][mid]-pref[i][l-1])-(pref[i][r]-pref[i][mid]));
	}
	return diff;
}
void solve_case(){
	string s; cin>>s;
	int n=s.size();
	for(int i=1;i<=n;++i) arr[i]=s[i-1]-'a';
	for(int i=0;i<26;++i){
		for(int j=1;j<=n;++j) pref[i][j]=pref[i][j-1]+(arr[j]==i?1:0);
	}
	int q; cin>>q;
	int ans=0;
	for(int i=1;i<=q;++i){
		int l,r; cin>>l>>r;
		int mid=(l+r)>>1;
		if(get_diff(l,mid,r)==1||get_diff(l,mid+1,r)==1||get_diff(l,mid-1,r)==1){
			++ans;
		}
	}
	cout<<ans<<"\n";
	for(int j=0;j<26;++j) for(int i=1;i<=n;++i) pref[j][i]=0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve_case();
	}
}
