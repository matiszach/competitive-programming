//Task statement: szkopul.edu.pl/problemset/problem/KkN5UonnNGIG3AuMqoI6xr62/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+5;
int n,k;
pair<int,int> lawyers[SIZE];
pair<int,int> origin[SIZE];
bool comp(pair<int,int> a,pair<int,int> b){
	if(a.first<b.first) return true;
	else if(a.first>b.first) return false;
	else{
		return a.second<b.second;
	}
}
vector<pair<int,int> > available;
priority_queue<int> pq;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	int a,b;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		lawyers[i]={a,b};
		origin[i]={a,b};
	}
	sort(lawyers+1,lawyers+n+1,comp);
	int curr=0;
	for(int i=1;i<=n;++i){
		while(!pq.empty()&&lawyers[i].first>=-pq.top()){
			--curr;
			pq.pop();
		}
		while(curr>=k){
			--curr;
			pq.pop();
		}
		++curr;
		pq.push(-lawyers[i].second);
		if(curr>=k){
			available.push_back({lawyers[i].first,-pq.top()});
		}
	}
	int best=0;
	pair<int,int> best_set;
	for(int i=0;i<available.size();++i){
		if(available[i].second-available[i].first>best){
			best=available[i].second-available[i].first;
			best_set={available[i].first,available[i].second};
		}
	}
	cout<<best<<"\n";
	int amount=0;
	for(int i=1;i<=n;++i){
		if(origin[i].first<=best_set.first&&origin[i].second>=best_set.second){
			cout<<i<<" ";
			++amount;
		}
		if(amount==k) return 0;
	}
}
