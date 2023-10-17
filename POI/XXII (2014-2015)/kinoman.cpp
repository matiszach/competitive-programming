//Task statement: szkopul.edu.pl/problemset/problem/k-RYEjhwNTo_XdaCidXQUGMU/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+5,nTree=1048576;
typedef long long ll;
pair<ll,ll> T[nTree*2];
void update(int pos,ll val){
	pos+=nTree;
	T[pos]={val,val};
	pos/=2;
	while(pos>0){
		T[pos].first=T[pos*2].first+T[pos*2+1].first;
		T[pos].second=max(T[pos*2].first,T[pos*2].second);
		T[pos].second=max(T[pos].second,T[pos*2+1].second+T[pos*2].first);
		T[pos].second=max(T[pos].first,T[pos].second);
		pos/=2;
	}
}
int n,m;
int order[SIZE];
int types[SIZE];
int indices[SIZE];
vector<int> occur[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>order[i];
		occur[order[i]].push_back(i);
	}
	for(int i=1;i<=m;++i){
		cin>>types[i];
		occur[i].push_back(nTree+5);
		occur[i].push_back(nTree+5);
		occur[i].push_back(nTree+5);
		if(occur[i][0]<nTree) update(occur[i][0],types[i]);
		if(occur[i][1]<nTree) update(occur[i][1],-types[i]);
	}
	int x=0,inx=0;
	ll best=T[1].second;
	for(int i=1;i<n;++i){
		x=order[i];
		inx=indices[x];
		update(i,0);
		if(occur[x][inx+1]<nTree) update(occur[x][inx+1],types[x]);
		if(occur[x][inx+2]<nTree) update(occur[x][inx+2],-types[x]);
		++indices[x];
		best=max(best,T[1].second);
	}
	cout<<best<<"\n";
}
