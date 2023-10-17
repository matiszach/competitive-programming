//Task statement: szkopul.edu.pl/problemset/problem/1asri4nHTSmINAOKJ-iUZf6f/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=2e5+5,nTree=1048576;
const ll INF=2e18+5;
pair<ll,int> inters[SIZE];
struct block{
	ll start,end;
	int quan;
};
vector<block> arr;
struct parameters{
	ll big,small,diff;
};
vector<parameters> pars;
ll T[nTree*2],A[nTree*2];
void update(int x,int oper){
	int pos=x+nTree;
	while(pos>0){
		T[pos]+=x*oper;
		A[pos]+=oper;
		pos/=2;
	}
}
ll query(int v,ll k){
	if(A[v]==0) return 0;
	if(A[v]==k) return T[v];
	if(v>nTree) return T[v]/A[v]*k;
	if(A[v*2+1]>k) return query(v*2+1,k);
	else return query(v*2,k-A[v*2+1])+query(v*2+1,A[v*2+1]);
}
int n,h;
ll n1,h1,n2,h2;
ll x;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x>>h;
		inters[i]={x,h};
	}
	cin>>n1>>h1>>n2>>h2;
	if(h1<h2){
		swap(h1,h2);
		swap(n1,n2);
	}
	inters[n+1]={INF,0};
	int amount=1;
	ll start=inters[1].first,end=start+inters[1].second;
	for(int i=2;i<=n+1;++i){
		if(inters[i].first<=end){
			end=max(inters[i].first+inters[i].second,end);
			++amount;
		}else{
			arr.push_back({start,end,amount});
			start=inters[i].first;
			end=max(inters[i].first+inters[i].second,end);
			amount=1;
		}
	}
	for(int i=1;i<arr.size();++i){
		ll diff=arr[i].start-arr[i-1].end;
		pars.push_back({diff/h1,(diff%h1)/h2+(diff%h2==0?0:1),diff%h1});
	}
	int best=arr[0].quan,curr=arr[0].quan,j=0,b=0,s=0;
	for(int i=0;i<pars.size();++i){
		curr+=arr[i+1].quan;
		update(pars[i].small,1);
		b+=pars[i].big;
		s+=pars[i].small;
		bool cond=0;
		if(b<=n1&&s<=n2) cond=1;
		if(b<=n1&&s>n2){
			int bdiff=n1-b,sdiff=s-n2;
			if(query(1,bdiff)>=sdiff) cond=1;
		}
		if(b>n1&&s<=n2){
			int bdiff=b-n1,sdiff=n2-s;
			if(bdiff*(h1/h2)<=sdiff) cond=1;
		}
		while(!cond){
			b-=pars[j].big;
			s-=pars[j].small;
			update(pars[j].small,-1);
			curr-=arr[j].quan;
			++j;
			if(b<=n1&&s<=n2) cond=1;
			if(b<=n1&&s>n2){
				int bdiff=n1-b,sdiff=s-n2;
				if(query(1,bdiff)>=sdiff) cond=1;
			}
			if(b>n1&&s<=n2){
				int bdiff=b-n1,sdiff=n2-s;
				if(bdiff*(h1/h2)<=sdiff) cond=1;
			}
		}
		best=max(best,curr);
	}
	arr.clear();
	pars.clear();
	for(int i=1;i<nTree*2;++i){
		T[i]=0;
		A[i]=0;
	}
	inters[0]={-INF,0};
	amount=1;
	start=inters[n].first,end=start-inters[n].second;
	for(int i=n-1;i>=0;--i){
		if(inters[i].first>=end){
			end=min(inters[i].first-inters[i].second,end);
			++amount;
		}else{
			arr.push_back({start,end,amount});
			start=inters[i].first;
			end=min(inters[i].first-inters[i].second,end);
			amount=1;
		}
	}
	for(int i=1;i<arr.size();++i){
		ll diff=arr[i-1].end-arr[i].start;
		pars.push_back({diff/h1,(diff%h1)/h2+(diff%h2==0?0:1),diff%h1});
	}
	curr=arr[0].quan,j=0,b=0,s=0;
	for(int i=0;i<pars.size();++i){
		curr+=arr[i+1].quan;
		update(pars[i].small,1);
		b+=pars[i].big;
		s+=pars[i].small;
		bool cond=0;
		if(b<=n1&&s<=n2) cond=1;
		if(b<=n1&&s>n2){
			int bdiff=n1-b,sdiff=s-n2;
			if(query(1,bdiff)>=sdiff) cond=1;
		}
		if(b>n1&&s<=n2){
			int bdiff=b-n1,sdiff=n2-s;
			if(bdiff*(h1/h2)<=sdiff) cond=1;
		}
		while(!cond){
			b-=pars[j].big;
			s-=pars[j].small;
			update(pars[j].small,-1);
			curr-=arr[j].quan;
			++j;
			if(b<=n1&&s<=n2) cond=1;
			if(b<=n1&&s>n2){
				int bdiff=n1-b,sdiff=s-n2;
				if(query(1,bdiff)>=sdiff) cond=1;
			}
			if(b>n1&&s<=n2){
				int bdiff=b-n1,sdiff=n2-s;
				if(bdiff*(h1/h2)<=sdiff) cond=1;
			}
		}
		best=max(best,curr);
	}
	cout<<best+n1+n2<<"\n";
}
