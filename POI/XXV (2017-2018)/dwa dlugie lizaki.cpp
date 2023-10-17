//Task statement: szkopul.edu.pl/problemset/problem/Kmofhbw9cTx06gSZg-C5MiBU/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=1e3+7,nTree=(1<<22);
int T[2][nTree<<1];
void update(int l,int r,int val,int idx){
	l+=nTree; r+=nTree;
	if(l>r) return;
	T[idx][l]+=val;
	if(l<r) T[idx][r]+=val;
	while(l<r-1){
		if(l%2==0) T[idx][l+1]+=val;
		if(r%2==1) T[idx][r-1]+=val;
		l>>=1; r>>=1;
	}
}
int query(int pos,int idx){
	pos+=nTree;
	int res=0;
	while(pos>0){
		res+=T[idx][pos];
		pos>>=1;
	}
	return res;
}
pii seg1[MAXN],seg2[MAXN];
struct pnt{
	pii A,B;
	int type;
	int up,down;
} point[MAXN*MAXN*2];
bool cmp(pnt &A,pnt &B){
	if(A.A.first<B.A.first) return 1;
	if(A.A.first>B.A.first) return 0;
	if(A.type<=2&&B.type>2) return 1;
	if(A.type>2&&B.type<=2) return 0;
	return A.B.second<B.B.second;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m; cin>>n;
	for(int i=1;i<=n;++i){
		char x; cin>>x;
		if(x=='W') cin>>seg1[i].first;
		else cin>>seg1[i].second;
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		char x; cin>>x;
		if(x=='W') cin>>seg2[i].first;
		else cin>>seg2[i].second;
	}
	int idx=0;
	vector<pair<int,int*>> V;
	for(int i=1;i<=n;++i){
		int curr_x=0,curr_y=0;
		int j=i-1;
		int off_x=seg1[i-1].first+seg1[j+1].first;
		int off_y=seg1[i-1].second+seg1[j+1].second;
		point[++idx]={{curr_x,curr_y},{curr_x,curr_y+off_y},1};
		V.pb({curr_y,&point[idx].down});
		V.pb({curr_y+off_y,&point[idx].up});
		point[++idx]={{curr_x+off_x,curr_y},{curr_x+off_x,curr_y+off_y},3};
		V.pb({curr_y,&point[idx].down});
		V.pb({curr_y+off_y,&point[idx].up});
		for(j=i;j<=n;++j){
			curr_x+=seg1[j].first;
			curr_y+=seg1[j].second;
			off_x=seg1[i-1].first+seg1[j+1].first;
			off_y=seg1[i-1].second+seg1[j+1].second;
			point[++idx]={{curr_x,curr_y},{curr_x,curr_y+off_y},1};
			V.pb({curr_y,&point[idx].down});
			V.pb({curr_y+off_y,&point[idx].up});
			point[++idx]={{curr_x+off_x,curr_y},{curr_x+off_x,curr_y+off_y},3};
			V.pb({curr_y,&point[idx].down});
			V.pb({curr_y+off_y,&point[idx].up});
		}
	}
	for(int i=1;i<=m;++i){
		int curr_x=0,curr_y=0;
		int j=i-1;
		int off_x=seg2[i-1].first+seg2[j+1].first;
		int off_y=seg2[i-1].second+seg2[j+1].second;
		point[++idx]={{curr_x,curr_y},{curr_x,curr_y+off_y},2};
		V.pb({curr_y,&point[idx].down});
		V.pb({curr_y+off_y,&point[idx].up});
		point[++idx]={{curr_x+off_x,curr_y},{curr_x+off_x,curr_y+off_y},4};
		V.pb({curr_y,&point[idx].down});
		V.pb({curr_y+off_y,&point[idx].up});
		for(j=i;j<=m;++j){
			curr_x+=seg2[j].first;
			curr_y+=seg2[j].second;
			off_x=seg2[i-1].first+seg2[j+1].first;
			off_y=seg2[i-1].second+seg2[j+1].second;
			point[++idx]={{curr_x,curr_y},{curr_x,curr_y+off_y},2};
			V.pb({curr_y,&point[idx].down});
			V.pb({curr_y+off_y,&point[idx].up});
			point[++idx]={{curr_x+off_x,curr_y},{curr_x+off_x,curr_y+off_y},4};
			V.pb({curr_y,&point[idx].down});
			V.pb({curr_y+off_y,&point[idx].up});
		}
	}
	V.pb({-1,&point[0].down});
	sort(V.begin(),V.end());
	int curr=0;
	for(int i=1;i<(int)V.size();++i){
		if(V[i].first!=V[i-1].first) ++curr;
		*V[i].second=curr;
	}
	sort(point+1,point+idx+1,cmp);
	int ans=0;
	multiset<int> s1,s2;
	vector<pair<int,bool>> to_procces;
	for(int i=1;i<=idx;++i){
		if(point[i].A.first>point[i-1].A.first){
			for(pii v:to_procces){
				if(!v.second){
					multiset<int>::iterator it=s1.lower_bound(point[v.first].B.second);
					s1.erase(it);
				}else{
					multiset<int>::iterator it=s2.lower_bound(point[v.first].B.second);
					s2.erase(it);
				}
				update(point[v.first].down,point[v.first].up,-1,v.second);
			}
			to_procces.clear();
		}
		if(point[i].type==1){
			s1.insert(point[i].B.second);
			update(point[i].down,point[i].up,1,0);
		}
		if(point[i].type==2){
			s2.insert(point[i].B.second);
			update(point[i].down,point[i].up,1,1);
		}
		if(point[i].type==3){
			multiset<int>::iterator it=s2.upper_bound(point[i].B.second);
			if(it!=s2.begin()&&!s2.empty()){
				--it;
				if(it!=s2.end()&&*it>=point[i].A.second){
					ans=max(ans,point[i].A.first+(*it));
				}
			}
			if(query(point[i].up,1)>0) ans=max(ans,point[i].A.first+point[i].B.second);
			to_procces.pb({i,0});
		}
		if(point[i].type==4){
			multiset<int>::iterator it=s1.upper_bound(point[i].B.second);
			if(it!=s1.begin()&&!s1.empty()){
				--it;
				if(it!=s1.end()&&*it>=point[i].A.second){
					ans=max(ans,point[i].A.first+(*it));
				}
			}
			if(query(point[i].up,0)>0) ans=max(ans,point[i].A.first+point[i].B.second);
			to_procces.pb({i,1});
		}
	}
	cout<<ans<<"\n";
}
