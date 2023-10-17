//Task statement: szkopul.edu.pl/problemset/problem/ElDZtvfzCl9Sj2lC1sAKG0dU/site/
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
const int MAXN=1e6+7,A=26;
int arr[MAXN];
vector<int> pos[A];
int tmp[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	string s; cin>>s;
	for(int i=0;i<n;++i) arr[i]=s[i]-'a';
	for(int i=0;i<n;++i) pos[arr[i]].pb(i);
	int ans=0;
	for(int a=0;a<A;++a){
		for(int b=0;b<A;++b){
			if(a==b) continue;
			int i=0,j=0,as=(int)pos[a].size(),bs=(int)pos[b].size(),idx=0;
			while(i<as||j<bs){
				if(i<as&&j<bs){
					if(pos[a][i]<pos[b][j]) tmp[idx++]=a,++i;
					else tmp[idx++]=b,++j;
				}else if(i<as) tmp[idx++]=a,++i;
				else tmp[idx++]=b,++j;
			}
			int val=0,pre=0,mini=INF;
			for(int k=0;k<as+bs;++k){
				if(tmp[k]==a) ++val;
				if(tmp[k]==b){
					--val;
					mini=min(mini,pre);
					pre=val;
				}
				ans=max(ans,val-mini);
			}
		}
	}
	cout<<ans<<"\n";
}
