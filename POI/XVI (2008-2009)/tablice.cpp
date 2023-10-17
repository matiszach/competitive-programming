//Task statement: szkopul.edu.pl/problemset/problem/_i0PmDyArk7mCW0eUJJzEVOA/site/
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
const int MAXN=1e3+7;
int where[MAXN*MAXN*2];
bool exist[MAXN*MAXN*2];
int dest[MAXN];
void solve_case(){
	for(int i=0;i<MAXN*MAXN*2;++i) where[i]=0,exist[i]=0;
	int n,m; cin>>n>>m;
	vector<vector<int>> tmp=vector<vector<int>>(n,vector<int>(m));
	vector<vector<int>> tmp2=vector<vector<int>>(n,vector<int>(m));
	for(int i=0;i<n;++i){
		for(int &v:tmp[i]) cin>>v;
	}
	for(int i=0;i<n;++i){
		for(int &v:tmp2[i]) cin>>v;
	}
	for(int i=0;i<n;++i) for(int &v:tmp[i]) exist[v+MAXN*MAXN]=1;
	for(int i=0;i<n;++i){
		for(int &v:tmp2[i]){
			if(!exist[v+MAXN*MAXN]){
				cout<<"NIE\n";
				return;
			}
			exist[v+MAXN*MAXN]=0;
		}
	}
	for(int i=0;i<n;++i){
		for(int &v:tmp[i]) where[v+MAXN*MAXN]=i;
	}
	for(int i=0;i<n;++i){
		int req=where[tmp2[i][0]+MAXN*MAXN];
		dest[i]=where[tmp2[i][0]+MAXN*MAXN];
		for(int &v:tmp2[i]){
			if(where[v+MAXN*MAXN]!=req){
				cout<<"NIE\n";
				return;
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int &v:tmp[i]) where[v+MAXN*MAXN]=0;
	}
	vector<vector<int>> _tmp=vector<vector<int>>(n,vector<int>(m));
	vector<vector<int>> _tmp2=vector<vector<int>>(n,vector<int>(m));
	for(int i=0;i<n;++i) _tmp[dest[i]]=tmp[i],_tmp2[i]=tmp2[i];
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j) where[_tmp[j][i]+MAXN*MAXN]=i;
	}
	for(int i=0;i<m;++i){
		int req=where[_tmp2[0][i]+MAXN*MAXN];
		for(int j=0;j<n;++j){
			if(where[_tmp2[j][i]+MAXN*MAXN]!=req){
				cout<<"NIE\n";
				return;
			}
		}
	}
	cout<<"TAK\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i) solve_case();
}
