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
const int MAXN=3e3+7;
int arr[MAXN];
int pos[MAXN];
int n;
bool check(){
	for(int i=1;i<n;++i) if(arr[i]>arr[i+1]) return 0;
	return 1;
}
bool visited[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	vector<pii> scalar;
	for(int i=1;i<=n;++i) scalar.pb({arr[i],i});
	sort(scalar.begin(),scalar.end());
	for(int i=0;i<n;++i) arr[scalar[i].second]=i+1;
	for(int i=1;i<=n;++i) pos[arr[i]]=i;
	if(check()){
		cout<<"0\n";
		return 0;
	}
	vector<int> round1,round_ba;
	for(int i=1;i<=n;++i){
		if(visited[arr[i]]) continue;
		int x=arr[i];
		vector<int> cycle;
		visited[arr[i]]=1;
		cycle.pb(arr[i]);
		while(arr[x]!=arr[i]){
			x=arr[x];
			visited[x]=1;
			cycle.pb(x);
		}
		for(int j=0;j<(int)cycle.size()/2;++j){
			round1.pb(pos[cycle[j]]);
			round_ba.pb(pos[cycle[(int)cycle.size()-j-1]]);
			swap(arr[pos[cycle[j]]],arr[pos[cycle[(int)cycle.size()-j-1]]]);
		}
	}
	reverse(round_ba.begin(),round_ba.end());
	for(int &v:round_ba) round1.pb(v);
	if(check()){
		cout<<"1\n";
		cout<<(int)round1.size()<<"\n";
		for(int &v:round1) cout<<v<<" ";
		cout<<"\n";
		return 0;
	}
	for(int i=1;i<=n;++i) pos[arr[i]]=i;
	vector<int> round2,round2_ba;
	for(int i=1;i<=n;++i){
		if(arr[i]==i) continue;
		round2.pb(i);
		round2_ba.pb(arr[i]);
		swap(arr[i],arr[arr[i]]);
	}
	reverse(round2_ba.begin(),round2_ba.end());
	for(int &v:round2_ba) round2.pb(v);
	cout<<"2\n";
	cout<<(int)round1.size()<<"\n";
	for(int &v:round1) cout<<v<<" ";
	cout<<"\n";
	cout<<(int)round2.size()<<"\n";
	for(int &v:round2) cout<<v<<" ";
	cout<<"\n";
}
