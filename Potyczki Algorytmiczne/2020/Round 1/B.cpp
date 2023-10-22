#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+5;
long long T[SIZE*3];
int D[SIZE*3];
int r=1;
long long get_val(int id){
	id+=r;
	long long total=0;
	while(id!=0){
		total+=T[id];
		id/=2;
	}
	return total;
}
void update(int a,int b,int u,int lo,int hi,long long v){
	if(a==lo&&b==hi){
		T[u]+=v;
		return;
	}if (b<=a) return;
	int mid=(lo+hi)/2;
	update(a,min(b,mid),2*u,lo,mid,v);
	update(max(a,mid),b,2*u+1,mid,hi,v);
}
int get_amount(int id){
	id+=r;
	int total=0;
	while(id!=0){
		total+=D[id];
		id/=2;
	}
	return total;
}
void update_amount(int a,int b,int low,int high,int val,int node){
	if(a==low&&b==high){
		D[node]+=val;
		return;
	}if(b<=a) return;
	int mid=(low+high)/2;
	update_amount(a,min(mid,b),low,mid,val,node*2);
	update_amount(max(a,mid),b,mid,high,val,node*2+1);
}
long long quan,num;
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	while(r<n) r*=2;
	for(int i=0;i<m;++i){
		int a,b; long long c;
		cin>>a>>b>>c;
		if(c==3) c=2000001;
		update(a-1,b,1,0,r,c);
		update_amount(a-1,b,0,r,1,1);
	}
	int counter=0;
	for(int i=0;i<n;++i){
		num=get_val(i);
		quan=get_amount(i);
		if(num<2000001&&num!=quan*2&&num!=quan&&num>0) ++counter;
	}
	cout<<counter<<"\n";
}
