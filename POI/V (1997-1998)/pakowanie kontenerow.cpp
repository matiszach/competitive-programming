//Task statement: szkopul.edu.pl/problemset/problem/1Y7_N7Eac6sRfgp_hJ9Oc7Lz/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int n,q;
struct comp{
	bool operator()(pair<int,int> a,pair<int,int> b){
		if(a.first!=b.first){
		if(a.first>b.first) return true;
		else return false;
	}else if(a.second>b.second) return true;
	else return false;
	}
};
struct comp2{
	bool operator()(int a,int b){
		return a>b;
	}
};
priority_queue<pair<int,int>,vector<pair<int,int> >,comp> pq;
priority_queue<int,vector<int>,comp2> con;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int a,b;
		cin>>a>>b;
		pq.push({a,b});
	}
	cin>>q;
	for(int i=0;i<q;++i){
		int a,b;
		cin>>a>>b;
		for(int j=0;j<b;++j){
			con.push(a);
		}
	}
	pair<int,int> bufor;
	int counter=0;
	while(!pq.empty()&&!con.empty()){
		if(pq.top().first<con.top()){
			bufor=pq.top();
			pq.pop();
			if(!pq.empty())
			{
				if(bufor.first==pq.top().first){
					pair<int,int> new_elem={bufor.first+1,bufor.second+pq.top().second};
					pq.pop();
					pq.push(new_elem);
				}
			}else{
				cout<<"NIE\n";
				return 0;
			}
		}
		else if(pq.top().first==con.top()){
			counter+=pq.top().second;
			con.pop();
			pq.pop();
		}else{
			cout<<"NIE\n";
			return 0;
		}
	}
	cout<<counter<<"\n";
}
