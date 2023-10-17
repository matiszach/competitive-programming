//Task statement: szkopul.edu.pl/problemset/problem/h_QPStxSmfEHuL2h_I5Qpa29/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e5+7;
int n,m;
int arr[SIZE],conts[SIZE];
bool check(int k){
	priority_queue<int> Q;
	for(int i=n;i>=max(n-k,1);--i) Q.push(conts[i]);
	int val=0;
	for(int i=k;i>=1;--i){
		val=Q.top();
		Q.pop();
		if(val-arr[i]>=0) Q.push(val-arr[i]);
		else return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>conts[i];
	for(int i=1;i<=m;++i) cin>>arr[i];
	sort(arr+1,arr+1+m);
	int l=0,r=m,mid=(l+r)/2;
	while(l<=r){
		if(check(mid)) l=mid+1;
		else r=mid-1;
		mid=(l+r)/2;
	}
	cout<<l-1<<"\n";
}
