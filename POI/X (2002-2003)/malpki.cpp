//Task statement: szkopul.edu.pl/problemset/problem/kd-sEDS37q_Q8vr-RjxBhw4p/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=2e5+7;
int n,m,l,r;
int monke[SIZE][2],queries[SIZE*2][2];
struct{
	int anc,pos,t;
} rep[SIZE];
int Find(int a){
	int v=rep[a].anc;
	if(v!=a){
		int temp=Find(v);
		if(rep[a].t==-2) rep[a].t=rep[v].t;
		rep[a].anc=temp;
	}
	return rep[a].anc;
}
void Union(int a,int b){
	if(a==b) return;
	if(rep[a].pos>rep[b].pos) rep[b].anc=a;
	else{
		rep[a].anc=b;
		if(rep[a].pos==rep[b].pos) ++rep[b].pos;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>l>>r;
		monke[i][0]=l;
		monke[i][1]=r;
	}
	for(int i=0;i<m;++i){
		cin>>l>>r;
		queries[i][0]=monke[l][--r];
		queries[i][1]=l;
		monke[l][r]=-1;
	}
	for(int i=1;i<=n;++i){
		rep[i]={i,0,-2};
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<2;++j){
			if(monke[i][j]!=-1){
				Union(Find(i),Find(monke[i][j]));
			}
		}
	}
	rep[Find(1)].t=-1;
	for(int i=m-1;i>=0;--i){
		int v=Find(queries[i][0]),u=Find(queries[i][1]),root=Find(1);
		if(v==root&&v!=u) rep[u].t=i;
		else if(u==root&&v!=u) rep[v].t=i;
		Union(v,u);
	}
	for(int i=1;i<=n;++i){
		Find(i);
		cout<<rep[i].t<<"\n";
	}
}
