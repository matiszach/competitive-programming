//Task statement: szkopul.edu.pl/problemset/problem/w5PRX1QCpJeRUHpwNUpcbF6S/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __int128 ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
typedef long double ld;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=1e5+7;
struct truck{
	int idx;
	ll x,d,va,vb;
};
bool cmp(pair<pll,pii> A,pair<pll,pii> B){
	ll f1=A.first.first*B.first.second,f2=A.first.second*B.first.first;
	if(f1<f2) return 1;
	if(f1>f2) return 0;
	if(A.second.first<B.second.first) return 1;
	if(A.second.first>B.second.first) return 0;
	return A.second.second<B.second.second;
}
truck T[MAXN];
pair<pll,int> nxt[MAXN];
string f(__int128 x){
	if(x==0) return "0";
	vector<int> digits;
	while(x>0){
		digits.pb(x%10);
		x/=10;
	}
	reverse(digits.begin(),digits.end());
	string s;
	if(x<0) s="-";
	for(int v:digits) s+=char(v+'0');
	return s;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n,D,W,M; cin>>n>>D>>W>>M;
	for(int i=1;i<=n;++i){
		int x,d,a,b; cin>>x>>d>>a>>b;
		T[i]={i,x,d,a,b};
	}
	set<pair<pll,pii>,decltype(&cmp)> s(&cmp);
	for(int i=1;i<n;++i){
		if(T[i].va*T[i+1].vb>T[i].vb*T[i+1].va){
			ll num=(T[i+1].x-T[i+1].d-T[i].x)*(T[i].vb*T[i+1].vb);
			ll den=T[i].va*T[i+1].vb-T[i].vb*T[i+1].va;
			s.insert({{num,den},{i,i+1}});
			nxt[i]={{num,den},i+1};
		}else nxt[i]={{-1,1},i+1};
	}
	set<int> idxs;
	for(int i=1;i<=n;++i) idxs.insert(i);
	int ans=0;
	while((int)idxs.size()>0){
		while(1){
			set<int>::iterator it=idxs.begin();
			if(*idxs.begin()==n){
				++ans;
				idxs.clear();
				break;
			}
			int idx=*it,idx2=*(++it); --it;
			ll num=(T[idx].x+D)*(M*T[idx].vb);
			ll den=W*T[idx].vb-M*T[idx].va;
			set<pair<pll,pii>,decltype(&cmp)>::iterator it2=s.begin();
			bool ok=1;
			if(it2!=s.end()){
				pair<pll,pii> p=*it2;
				if(num*p.first.second>den*p.first.first) ok=0;
			}
			if(ok){
				ll car_n=W*num,car_d=M*den;
				ll truck_n=T[idx2].va*num+(T[idx2].x-T[idx2].d)*T[idx2].vb*den;
				ll truck_d=T[idx2].vb*den;
				idxs.erase(idx);
				if(car_n*truck_d<=car_d*truck_n) ++ans;
				break;
			}
			//merge consecutive trucks
			pair<pll,pii> p=*it2;
			T[p.second.second].d+=T[p.second.first].d;
			nxt[p.second.first]={{-1,1},-1};
			s.erase(it2);
			idx=p.second.second;
			it=idxs.lower_bound(p.second.first);
			if(it!=idxs.begin()&&it!=idxs.end()){
				set<int>::iterator it_pre=--it;
				int pre=*it_pre;
				if(nxt[pre].second==p.second.first&&T[pre].va*T[idx].vb>T[pre].vb*T[idx].va){
					if(nxt[pre].first.first!=-1) s.erase({nxt[pre].first,{pre,nxt[pre].second}});
					nxt[pre].second=idx;
					ll new_num=(T[idx].x-T[idx].d-T[pre].x)*(T[pre].vb*T[idx].vb);
					ll new_den=T[pre].va*T[idx].vb-T[pre].vb*T[idx].va;
					s.insert({{new_num,new_den},{pre,idx}});
					nxt[pre].first={new_num,new_den};
					nxt[p.second.first].first={-1,1};
				}
				nxt[pre].second=idx;
			}
			idxs.erase(p.second.first);
		}
	}
	cout<<ans<<"\n";
}
