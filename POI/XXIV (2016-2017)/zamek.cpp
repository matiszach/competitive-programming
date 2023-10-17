//Task statement: szkopul.edu.pl/problemset/problem/7Lmwi_qxvuplTPlhRuci1UBt/site/
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
const int MAXN=1e6+7;
pair<pii,pii> arr[MAXN];
pii bad[MAXN];
bool block[MAXN];
bool cmp(pair<pii,pair<bool,int>> &A,pair<pii,pair<bool,int>> &B){
	if(A.first.first<B.first.first) return 1;
	if(A.first.first>B.first.first) return 0;
	if(!A.second.first&&B.second.first) return 1;
	if(A.second.first&&!B.second.first) return 0;
	return A.first.second<B.first.second;
}
vector<int> G[MAXN];
int dist[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int w,h,n,m; cin>>w>>h>>n>>m;
	pii st,nd; cin>>st.first>>st.second>>nd.first>>nd.second;
	vector<pair<pii,pair<bool,int>>> V;
	for(int i=1;i<=n;++i) cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second.first>>arr[i].second.second;
	for(int i=1;i<=m;++i) cin>>bad[i].first>>bad[i].second;
	for(int i=1;i<=n;++i){
		pii bl={min(arr[i].first.first,arr[i].second.first),min(arr[i].first.second,arr[i].second.second)};
		pii tr={max(arr[i].first.first,arr[i].second.first),max(arr[i].first.second,arr[i].second.second)};
		arr[i].first=bl;
		arr[i].second=tr;
	}
	for(int i=1;i<=n;++i){
		V.pb({arr[i].first,{1,i}});
		V.pb({arr[i].second,{0,i}});
	}
	for(int i=1;i<=m;++i){
		V.pb({bad[i],{0,i+n}});
	}
	sort(V.begin(),V.end(),cmp);
	set<pii> active;
	set<pii> recently_closed;
	int last_x=0;
	vector<pii> edges;
	for(auto &v:V){
		if(v.second.second>n){
			set<pii>::iterator it=active.upper_bound({v.first.second,0});
			block[it->second]=1;
		}else{
			if(v.first.first>last_x){
				recently_closed.clear();
				last_x=v.first.first;
			}
			if(v.second.first){
				set<pii>::iterator it=recently_closed.lower_bound({v.first.second+1,0});
				while(it!=recently_closed.end()){
					if(arr[it->second].first.second<arr[v.second.second].second.second){
						edges.pb({v.second.second,it->second});
					}else break;
					++it;
				}
				active.insert({arr[v.second.second].second.second,v.second.second});
			}else{
				recently_closed.insert({arr[v.second.second].second.second,v.second.second});
				active.erase({arr[v.second.second].second.second,v.second.second});
			}
		}
	}
	active.clear();
	recently_closed.clear();
	last_x=0;
	for(int i=1;i<=n;++i){
		swap(arr[i].first.first,arr[i].first.second);
		swap(arr[i].second.first,arr[i].second.second);
	}
	V.clear();
	for(int i=1;i<=n;++i){
		V.pb({arr[i].first,{1,i}});
		V.pb({arr[i].second,{0,i}});
	}
	sort(V.begin(),V.end(),cmp);
	for(auto &v:V){
		if(v.first.first>last_x){
			recently_closed.clear();
			last_x=v.first.first;
		}
		if(v.second.first){
			set<pii>::iterator it=recently_closed.lower_bound({v.first.second+1,0});
			while(it!=recently_closed.end()){
				if(arr[it->second].first.second<arr[v.second.second].second.second){
					edges.pb({v.second.second,it->second});
				}else break;
				++it;
			}
			active.insert({v.first.second,v.second.second});
		}else{
			recently_closed.insert({arr[v.second.second].second.second,v.second.second});
			active.erase({arr[v.second.second].first.second,v.second.second});
		}
	}
	for(auto &v:edges){
		if(!block[v.first]&&!block[v.second]){
			G[v.first].pb(v.second);
			G[v.second].pb(v.first);
		}
	}
	int start_point=0,end_point=0;
	for(int i=1;i<=n;++i){
		swap(arr[i].first.first,arr[i].first.second);
		swap(arr[i].second.first,arr[i].second.second);
	}
	for(int i=1;i<=n;++i){
		if(arr[i].first.first<=st.first&&arr[i].second.first>=st.first&&
		arr[i].first.second<=st.second&&arr[i].second.second>=st.second){
			start_point=i;
			break;
		}
	}
	for(int i=1;i<=n;++i){
		if(arr[i].first.first<=nd.first&&arr[i].second.first>=nd.first&&
		arr[i].first.second<=nd.second&&arr[i].second.second>=nd.second){
			end_point=i;
			break;
		}
	}
	for(int i=1;i<=n;++i) dist[i]=INF;
	dist[start_point]=0;
	queue<int> Q;
	Q.push(start_point);
	while(!Q.empty()){
		int vert=Q.front(); Q.pop();
		for(int &v:G[vert]){
			if(dist[v]>dist[vert]+1){
				dist[v]=dist[vert]+1;
				Q.push(v);
			}
		}
	}
	cout<<dist[end_point]+1<<"\n";
}
