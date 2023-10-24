// Task statement: https://codeforces.com/problemset/problem/1605/D
// *Author Mateusz Kowalski*
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
const int NAX=2e5+7;
int t;
vector<int> G[NAX];
int A,B;
vector<int> colorA,colorB;
void DFS(int x,int pre,bool precol){
	if(!precol){
		++A;
		colorA.pb(x);
	}else{
		++B;
		colorB.pb(x);
	}
	for(int v:G[x]){
		if(v!=pre) DFS(v,x,!precol);
	}
}
pair<int,vector<int>> arr[NAX];
int powers[NAX];
int res[NAX];
void solve_case(){
	int n,a,b; cin>>n;
	A=0; B=0;
	colorA.clear(); colorB.clear();
	for(int i=1;i<=n;++i) res[i]=0;
	for(int i=1;i<=n;++i) G[i].clear();
	for(int i=1;i<n;++i){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	DFS(1,0,0);
	int power=0,curr=0;
	for(int i=1;i<=n;++i){
		if(i-curr>powers[power]){
			curr+=powers[power];
			++power;
		}
		++arr[power].first;
		arr[power].second.pb(i);
	}
	if(power>0){
		if(arr[power-1].first>arr[power].first) swap(arr[power],arr[power-1]);
	}
	int idxA=0,idxB=0;
	for(int i=power;i>=0;--i){
		if(A>B){
			for(int v:arr[i].second){
				--A;
				res[colorA[idxA++]]=v;
			}
		}else{
			for(int v:arr[i].second){
				--B;
				res[colorB[idxB++]]=v;
			}
		}
	}
	for(int i=0;i<=power;++i){
		arr[i].first=0;
		arr[i].second.clear();
	}
	for(int i=1;i<=n;++i) cout<<res[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	powers[0]=1;
	for(int i=1;i<=20;++i) powers[i]=powers[i-1]<<1;
	cin>>t;
	while(t--){
		solve_case();
	}
}
