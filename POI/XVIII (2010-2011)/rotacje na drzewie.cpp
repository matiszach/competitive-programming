//Task statement: szkopul.edu.pl/problemset/problem/OELzSaMp2K7WAgCzcYYaKI1b/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
const int SIZE=2e5+7;
typedef long long ll;
ordered_set vert[SIZE];
int n;
int nxt=0;
ll ans=0;
int get_node(){
	int x;
	cin>>x;
	if(x>0){
		vert[++nxt].insert(x);
		return nxt;
	}
	int l=get_node();
	int r=get_node();
	ll total=(ll)vert[l].size()*(ll)vert[r].size();
	if(vert[l].size()>vert[r].size()) swap(l,r);
	ll inverts=0;
	for(int v:vert[l]){
		inverts+=vert[r].order_of_key(v);
	}
	for(int v:vert[l]){
		vert[r].insert(v);
	}
	ans+=min(inverts,total-inverts);
	vert[l].clear();
	return r;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	get_node();
	cout<<ans<<"\n";
}
