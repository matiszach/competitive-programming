//Task statement: szkopul.edu.pl/problemset/problem/vObl4Sutc8ViCjq0_eNse2uy/site/
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
int n;
short arr[5];
short trg[5];
short dp[50][50][50][50];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) cin>>trg[i];
	dp[arr[1]][arr[2]][arr[3]][arr[4]]=1;
	queue<vector<short>> Q;
	Q.push({arr[1],arr[2],arr[3],arr[4]});
	while(!Q.empty()){
		vector<short> p=Q.front(); Q.pop();
		int curr=dp[p[0]][p[1]][p[2]][p[3]];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				short new_p[4];
				for(int k=0;k<4;++k) new_p[k]=p[k];
				if(i==j){
					new_p[i-1]=0;
				}else{
					if(arr[j]-p[j-1]>=p[i-1]){
						new_p[i-1]=0;
						new_p[j-1]+=p[i-1];
					}else{
						new_p[i-1]-=(arr[j]-p[j-1]);
						new_p[j-1]=arr[j];
					}
				}
				if(dp[new_p[0]][new_p[1]][new_p[2]][new_p[3]]>curr+1||dp[new_p[0]][new_p[1]][new_p[2]][new_p[3]]==0){
					dp[new_p[0]][new_p[1]][new_p[2]][new_p[3]]=curr+1;
					vector<short> v(4);
					for(int k=0;k<4;++k) v[k]=new_p[k];
					Q.push(v);
				}
			}
		}
	}
	short ans=dp[trg[1]][trg[2]][trg[3]][trg[4]]-1;
	if(ans==-1) cout<<"NIE\n";
	else cout<<ans<<"\n";
}

