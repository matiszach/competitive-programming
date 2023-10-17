//Task statement: szkopul.edu.pl/problemset/problem/ex8U04OQav3BWcaH7wCtK-_b/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e4+7,nTree=32768;
int T[nTree*2];
int n,a,b;
pair<int,int> p[SIZE];
int query(int l,int r){
	l+=nTree;
	r+=nTree;
	int ans=0;
	ans=max(T[l],T[r]);
	while(l<r-1){
		if(l%2==0) ans=max(ans,T[l+1]);
		if(r%2==1) ans=max(ans,T[r-1]);
		l/=2;
		r/=2;
	}
	return ans;
}
void update(int pos,int val){
	pos+=nTree;
	while(pos>0){
		T[pos]=max(T[pos],val);
		pos/=2;
	}
}
bool cmp(pair<int,int> p1,pair<int,int> p2){
	return p1.second<p2.second;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		p[i]={a,b};
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;++i){
		update(p[i].second,query(0,p[i].first)+(p[i].second-p[i].first));
	}
	cout<<query(0,nTree-1)<<"\n";
}
