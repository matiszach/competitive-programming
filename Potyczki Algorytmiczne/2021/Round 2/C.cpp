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
int n;
string s;
char letters[8];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>s;
	letters[3]='a';
	letters[4]='c';
	letters[5]='g';
	letters[6]='o';
	int counter=0;
	for(int i=0;i<n*8;++i){
		if(s[i]=='1') ++counter;
	}
	if(counter<3*n||counter>6*n){
		cout<<"NIE\n";
		return 0;
	}
	int num=counter/n;
	int rest=counter%n;
	for(int i=1;i<=n-rest;++i) cout<<letters[num];
	for(int i=1;i<=rest;++i) cout<<letters[num+1];
}
