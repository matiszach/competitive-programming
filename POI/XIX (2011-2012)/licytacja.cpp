//Task statement: szkopul.edu.pl/problemset/problem/deIZtcberd8cAXH64zlIq0wC/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
#include "cliclib.h"
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
const int MAXN=3e4+7;
int arr[82]={1,2,3,4,6,8,9,12,16,18,24,27,32,36,48,54,64,72,81,96,108,128,144,162,192,216,243,256,288,324,384,432,486,512,576,648,729,768,864,972,1024,1152,1296,1458,1536,1728,1944,2048,2187,2304,2592,2916,3072,3456,3888,4096,4374,4608,5184,5832,6144,6561,6912,7776,8192,8748,9216,10368,11664,12288,13122,13824,15552,16384,17496,18432,19683,20736,23328,24576,26244,27648};
int dict[MAXN];
bool dp[MAXN][82];
bool calc[MAXN][82];
int n;
bool get_state(int stones,int bid){
	if(stones+bid>=n) return 0;
	if(calc[stones][dict[bid]]) return dp[stones][dict[bid]];
	calc[stones][dict[bid]]=1;
	bool b1=get_state(stones+bid,1);
	bool b2=get_state(stones,bid*2);
	bool b3=get_state(stones,bid*3);
	if(!b1||!b2||!b3) return dp[stones][dict[bid]]=1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	n=inicjuj();
	int bid=1,stones=0;
	for(int i=0;i<82;++i) dict[arr[i]]=i;
	get_state(0,1);
	while(stones<n){
		if(!dp[stones+bid][dict[1]]){
			alojzy(1);
			stones+=bid;
			bid=1;
		}else if(!dp[stones][dict[bid*2]]){
			alojzy(2);
			bid*=2;
		}else{
			alojzy(3);
			bid*=3;
		}
		int move=bajtazar();
		if(move==1){
			stones+=bid;
			bid=1;
		}else if(move==2){
			bid*=2;
		}else bid*=3;
	}
}
