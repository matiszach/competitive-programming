//Task statement: szkopul.edu.pl/problemset/problem/BM4yZ7Mo9yZtUdXxVdZAkAjs/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
const int MAXN=5e5+7,nTree=(1<<19);
int T0[nTree<<1],T1[nTree<<1];
int T0a[nTree<<1],T1a[nTree<<1];
void update0(int pos,int val){
	pos+=nTree;
	T0[pos]+=val;
	pos>>=1;
	while(pos>0){
		T0[pos]=T0[pos*2]+T0[pos*2+1];
		pos>>=1;
	}
}
int query0(int l,int r){
	if(l>r) return 0;
	l+=nTree; r+=nTree;
	int res=T0[l];
	if(l<r) res+=T0[r];
	while(l<r-1){
		if(l%2==0) res+=T0[l+1];
		if(r%2==1) res+=T0[r-1];
		l>>=1; r>>=1;
	}
	return res;
}
void update0a(int pos,int val){
	pos+=nTree;
	T0a[pos]+=val;
	pos>>=1;
	while(pos>0){
		T0a[pos]=T0a[pos*2]+T0a[pos*2+1];
		pos>>=1;
	}
}
int query0a(int l,int r){
	if(l>r) return 0;
	l+=nTree; r+=nTree;
	int res=T0a[l];
	if(l<r) res+=T0a[r];
	while(l<r-1){
		if(l%2==0) res+=T0a[l+1];
		if(r%2==1) res+=T0a[r-1];
		l>>=1; r>>=1;
	}
	return res;
}
void update1(int pos,int val){
	pos+=nTree;
	T1[pos]+=val;
	pos>>=1;
	while(pos>0){
		T1[pos]=T1[pos*2]+T1[pos*2+1];
		pos>>=1;
	}
}
int query1(int l,int r){
	if(l>r) return 0;
	l+=nTree; r+=nTree;
	int res=T1[l];
	if(l<r) res+=T1[r];
	while(l<r-1){
		if(l%2==0) res+=T1[l+1];
		if(r%2==1) res+=T1[r-1];
		l>>=1; r>>=1;
	}
	return res;
}
void update1a(int pos,int val){
	pos+=nTree;
	T1a[pos]+=val;
	pos>>=1;
	while(pos>0){
		T1a[pos]=T1a[pos*2]+T1a[pos*2+1];
		pos>>=1;
	}
}
int query1a(int l,int r){
	if(l>r) return 0;
	l+=nTree; r+=nTree;
	int res=T1a[l];
	if(l<r) res+=T1a[r];
	while(l<r-1){
		if(l%2==0) res+=T1a[l+1];
		if(r%2==1) res+=T1a[r-1];
		l>>=1; r>>=1;
	}
	return res;
}
vector<int> G[MAXN];
int amount[MAXN];
void DFS(int x,int pre){
	for(int &v:G[x]) if(v!=pre) DFS(v,x);
	amount[x]=1;
	for(int &v:G[x]) if(v!=pre) amount[x]+=amount[v];
}
int n;
int centroid1(int x,int pre){
	int vert=0;
	for(int &v:G[x]){
		if(v!=pre&&amount[v]>amount[vert]) vert=v;
	}
	if(amount[vert]<=n/2) return x;
	return centroid1(vert,x);
}
int depth[MAXN];
bool color[MAXN];
void DFS1(int x,int pre){
	color[x]=1;
	depth[x]=depth[pre]+1;
	for(int &v:G[x]) if(v!=pre) DFS1(v,x);
}
void DFS2(int x,int pre){
	depth[x]=depth[pre]+1;
	for(int &v:G[x]) if(v!=pre) DFS2(v,x);
}
bool exists[MAXN],exists_a[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	DFS(1,1);
	int a,b,q; cin>>a>>b>>q;
	vector<int> A,B;
	for(int i=1;i<=a;++i){
		int x; cin>>x;
		A.pb(x);
	}
	for(int i=1;i<=b;++i){
		int x; cin>>x;
		B.pb(x);
	}
	int cent1=centroid1(1,1);
	int cent2=cent1;
	for(int i=1;i<=n;++i) amount[i]=0;
	DFS(cent1,cent1);
	for(int &v:G[cent1]){
		int vert=0;
		for(int &w:G[v]){
			if(w!=cent1){
				if(amount[w]>amount[vert]) vert=w;
			}
		}
		if(amount[vert]<=n/2&&n-amount[v]<=n/2) cent2=v;
	}
	depth[cent2]=-1;
	DFS1(cent1,cent2);
	depth[cent1]=-1;
	DFS2(cent2,cent1);
	depth[cent1]=0;
	for(int &v:A){
		exists[v]=1;
		if(!color[v]){
			update0(depth[v],1);
		}else{
			update1(depth[v],1);
		}
	}
	for(int &v:B){
		exists_a[v]=1;
		if(!color[v]){
			update0a(depth[v],1);
		}else{
			update1a(depth[v],1);
		}
	}
	ll ans=(ll)A.size()*B.size();
	for(int &v:B){
		if(!color[v]){
			ans-=query0(depth[v]+1,n)+exists[v];
			ans-=query1(depth[v],n);
		}else{
			ans-=query0(depth[v],n);
			ans-=query1(depth[v]+1,n)+exists[v];
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=q;++i){
		char c,oper; int x; cin>>c>>oper>>x;
		if(c=='B'){
			if(oper=='+'){
				ans+=(int)A.size();
				B.pb(0);
				exists_a[x]=1;
				if(!color[x]){
					update0a(depth[x],1);
					ans-=query0(depth[x]+1,n)+exists[x];
					ans-=query1(depth[x],n);
				}else{
					update1a(depth[x],1);
					ans-=query0(depth[x],n);
					ans-=query1(depth[x]+1,n)+exists[x];
				}
			}else{
				ans-=(int)A.size();
				B.pop_back();
				exists_a[x]=0;
				if(!color[x]){
					update0a(depth[x],-1);
					ans+=query0(depth[x]+1,n)+exists[x];
					ans+=query1(depth[x],n);
				}else{
					update1a(depth[x],-1);
					ans+=query0(depth[x],n);
					ans+=query1(depth[x]+1,n)+exists[x];
				}
			}
		}
		else{
			if(oper=='+'){
				A.pb(0);
				exists[x]=1;
				if(!color[x]){
					update0(depth[x],1);
					ans+=query0a(depth[x],n)-exists_a[x];
					ans+=query1a(depth[x]+1,n);
				}else{
					update1(depth[x],1);
					ans+=query0a(depth[x]+1,n);
					ans+=query1a(depth[x],n)-exists_a[x];
				}
			}else{
				A.pop_back();
				exists[x]=0;
				if(!color[x]){
					update0(depth[x],-1);
					ans-=query0a(depth[x],n)-exists_a[x];
					ans-=query1a(depth[x]+1,n);
				}else{
					update1(depth[x],-1);
					ans-=query0a(depth[x]+1,n);
					ans-=query1a(depth[x],n)-exists_a[x];
				}
			}
		}
		cout<<ans<<"\n";
	}
}
