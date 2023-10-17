//Task statement: szkopul.edu.pl/problemset/problem/u14-MJgItr5hoHh2c0EBzDmS/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int nTree=524288,SIZE=5e5+7;
int n,m,a,b;
int T[nTree*2],A[nTree*2];
vector<int> v[SIZE];
pair<int,int> combine(pair<int,int> A,pair<int,int> B){
	if(A.first==B.first) return {A.first,A.second+B.second};
	if(A.second<B.second) return {B.first,B.second-A.second};
	return {A.first,A.second-B.second};
}
int query(int l,int r){
	pair<int,int> val={0,0};
	l+=nTree;
	r+=nTree;
	if(l==r) return T[l];
	val=combine({T[l],A[l]},{T[r],A[r]});
	while(l<r-1){
		if(l%2==0) val=combine(val,{T[l+1],A[l+1]});
		if(r%2==1) val=combine(val,{T[r-1],A[r-1]});
		l/=2;
		r/=2;
	}
	return val.first;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>T[i+nTree];
		v[T[i+nTree]].push_back(i);
	}
	for(int i=1;i<nTree;++i) A[i+nTree]=1;
	for(int i=nTree;i>=1;--i){
		T[i]=combine({T[i*2],A[i*2]},{T[i*2+1],A[i*2+1]}).first;
		A[i]=combine({T[i*2],A[i*2]},{T[i*2+1],A[i*2+1]}).second;
	}
	while(m--){
		cin>>a>>b;
		int cand=query(a,b);
		int occurs=upper_bound(v[cand].begin(),v[cand].end(),b)-lower_bound(v[cand].begin(),v[cand].end(),a);
		if(occurs>(b-a+1)/2) cout<<cand<<"\n";
		else cout<<"0\n";
	}
}
