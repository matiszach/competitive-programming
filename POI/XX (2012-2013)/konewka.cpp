//Task statement: szkopul.edu.pl/problemset/problem/_QmEe3QujrdvoUaXdnKGIc2I/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=3e5+7,nTree=524288,INF=1e9+1e7;
int T[nTree*2],lazy[nTree*2],TT[nTree*2];
int arr[SIZE];
int N,K;
void update_simple(int pos){
	pos+=nTree;
	TT[pos]+=1;
	pos/=2;
	while(pos>0){
		TT[pos]=TT[pos*2]+TT[pos*2+1];
		pos/=2;
	}
}
int query_simple(int l,int r){
	l+=nTree;
	r+=nTree;
	if(l==r) return TT[l];
	int ans=TT[l]+TT[r];
	while(l<r-1){
		if(l%2==0) ans+=TT[l+1];
		if(r%2==1) ans+=TT[r-1];
		l/=2;
		r/=2;
	}
	return ans;
}
void prop(int v,int start,int end){
	if(lazy[v]!=0){
		T[v]+=lazy[v];
		if(start!=end){
			lazy[v*2]+=lazy[v];
			lazy[v*2+1]+=lazy[v];
		}
		lazy[v]=0;
	}
}
void update(int v,int start,int end,int l,int r,int val){
	prop(v,start,end);
	if(start>r||end<l||start>end) return;
	if(start>=l&&end<=r){
		T[v]+=val;
		if(start!=end){
			lazy[v*2]+=val;
			lazy[v*2+1]+=val;
		}
		return;
	}
	int mid=(start+end)/2;
	update(v*2,start,mid,l,r,val);
	update(v*2+1,mid+1,end,l,r,val);
	T[v]=max(T[v*2],T[v*2+1]);
}
int query(){
	int pos=1;
	int start=0,end=nTree-1;
	while(pos<nTree){
		prop(pos,start,end);
		if(T[pos*2]>T[pos*2+1]){
			end=(start+end)/2;
			pos=pos*2;
		}else{
			start=(start+end)/2+1;
			pos=pos*2+1;
		}
	}
	return pos-nTree;
}
void inicjuj(int n, int k, int *D)
{
    N=n,K=k;
    for(int i=0;i<n;++i){
        if(D[i]>=K){
			update(1,0,nTree-1,i,i,-INF);
			update_simple(i);
		}
        else update(1,0,nTree-1,i,i,D[i]);
	}
}

void podlej(int a, int b)
{
    update(1,0,nTree-1,a,b,1);
    while(T[1]>=K){
		int pos=query();
		update_simple(pos);
		update(1,0,nTree-1,pos,pos,-INF);
	}
}

int dojrzale(int a, int b)
{
    return query_simple(a,b);
}
/*int main()
{
	N=4,K=6;
	int D[N]={5,4,3,7};
	for(int i=1;i<=N;++i){
		arr[i]=D[i];
        update(1,0,nTree-1,i,i,arr[i]);
        if(arr[i]>=K) update_simple(i);
	}
	cout<<dojrzale(2,3)<<"\n";
	podlej(0,2);
	cout<<dojrzale(1,2)<<"\n";
	podlej(2,3);
	podlej(0,1);
	cout<<dojrzale(0,3)<<"\n";
}*/
