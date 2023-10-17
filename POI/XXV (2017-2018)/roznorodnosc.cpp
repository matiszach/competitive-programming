//Task statement: szkopul.edu.pl/problemset/problem/eHGwrk9xShVF-z_2f7K4Yyb_/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=1e5+7,Ntree=4096;
ll total=0;
int best=0;
int T[Ntree*2];
map<int,int> ma[SIZE];
int n,m,k;
int arr[3007][3007];
int query(int x){
	x+=Ntree;
	int ans=0;
	while(x>1){
		ans+=T[x];
		x/=2;
	}
	return ans;
}
void update(int a,int b,int val){
	if(a>b) return;
	a+=Ntree;
	b+=Ntree;
	if(a==b){
		T[a]+=val;
		return;
	}
	T[a]+=val;
	T[b]+=val;
	while(a<b-1){
		if(a%2==0) T[a+1]+=val;
		if(b%2==1) T[b-1]+=val;
		a/=2;
		b/=2;
	}
}
void add_col(int x){
	for(int i=1;i<=n;++i){
		int val=arr[i][x];
		map<int,int>::iterator it=ma[val].find(i);
		if(it!=ma[val].end()&&it->second!=0) it->second++;
		else{
			ma[val][i]=1;
			it=ma[val].find(i);
			map<int,int>::iterator left=it,right=it;
			++right;
			--left;
			int l=i-k+1,r=i;
			if(r>(right->first)-k) r=(right->first)-k;
			if(l<(left->first)+1) l=(left->first)+1;
			update(l,r,1);
		}
	}
}
void remove_col(int x){
	for(int i=1;i<=n;++i){
		int val=arr[i][x];
		map<int,int>::iterator it=ma[val].find(i);
		if(it!=ma[val].end()&&it->second!=1) it->second--;
		else{
			map<int,int>::iterator left=it,right=it;
			++right;
			--left;
			ma[val].erase(it);
			int l=i-k+1,r=i;
			if(r>(right->first)-k) r=(right->first)-k;
			if(l<(left->first)+1) l=(left->first)+1;
			update(l,r,-1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=n;i>=1;--i){
		for(int j=1;j<=m;++j){
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<SIZE;++i){
		ma[i][0]=1;
		ma[i][SIZE+k]=1;
	}
	for(int i=1;i<=k;++i) add_col(i);
	for(int i=1;i<=n-k+1;++i){
		best=max(best,query(i));
		total+=query(i);
	}
	for(int i=k+1;i<=m;++i){
		remove_col(i-k);
		add_col(i);
		for(int j=1;j<=n-k+1;++j){
			best=max(best,query(j));
			total+=query(j);
		}
	}
	cout<<best<<" "<<total<<"\n";
}
