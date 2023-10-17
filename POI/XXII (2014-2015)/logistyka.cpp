//Task statement: szkopul.edu.pl/problemset/problem/ShrCwRqlzMKLBb269GkVbWg_/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=1e6+7,nTree=(1<<21);
int n,m,a,b;
char c;
struct Q{
	char Type;
	int idx,c,s;
};
Q queries[SIZE];
bool cmp(Q q1,Q q2){
	return q1.s<q2.s;
}
bool cmp2(Q q1,Q q2){
	return q1.idx<q2.idx;
}
int last[SIZE*2],new_val[SIZE];
int T[nTree*2];
int query(int l,int r){
	l+=nTree; r+=nTree;
	int res=T[l];
	if(l!=r) res+=T[r];
	while(l<r-1){
		if(l%2==0) res+=T[l+1];
		if(r%2==1) res+=T[r-1];
		l/=2; r/=2;
	}
	return res;
}
void update(int pos,int x){
	pos+=nTree;
	while(pos>0){
		T[pos]+=x;
		pos/=2;
	}
}
ll origin[SIZE*2];
ll T2[nTree*2];
ll query2(int l,int r){
	l+=nTree; r+=nTree;
	ll res=T2[l];
	if(l!=r) res+=T2[r];
	while(l<r-1){
		if(l%2==0) res+=T2[l+1];
		if(r%2==1) res+=T2[r-1];
		l/=2; r/=2;
	}
	return res;
}
void update2(int pos,ll x){
	pos+=nTree;
	while(pos>0){
		T2[pos]+=x;
		pos/=2;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>c>>a>>b;
		queries[i]={c,i,a,b};
	}
	sort(queries+1,queries+1+m,cmp);
	int curr=1;
	for(int i=1;i<=m;++i){
		if(queries[i].s>queries[i-1].s) new_val[i]=++curr;
		else new_val[i]=curr;
		origin[curr]=queries[i].s;
	}
	for(int i=1;i<=m;++i) queries[i].s=new_val[i];
	sort(queries+1,queries+1+m,cmp2);
	for(int i=1;i<=m;++i){
		Q q=queries[i];
		if(q.Type=='U'){
			ll driver=q.c,value=q.s;
			update(value,1);
			update(last[driver],-1);
			update2(last[driver],-origin[last[driver]]);
			update2(value,origin[value]);
			last[driver]=value;
		}else{
			ll trucks=q.c,dist=q.s;
			if(trucks*origin[dist]<=(ll)query(dist+1,nTree-1)*(ll)origin[dist]+query2(1,dist)) cout<<"TAK\n";
			else cout<<"NIE\n";
		}
	}
}
