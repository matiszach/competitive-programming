//Task statement: szkopul.edu.pl/problemset/problem/E_UP8if3dQ6IUlFNsD1CQOdy/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e3+5,INF=1e9+7;
int n;
int val,a,b,z;
int items[SIZE];
pair<pair<int,int>,int> start_points[SIZE];
pair<int,int> end_points[SIZE];
int dp[SIZE*100];
int valid[SIZE*100];
pair<pair<int,int>,pair<int,int> > questions[SIZE*1000];
bitset<SIZE*1000> answers;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>val>>a>>b;
		items[i]=val;
		start_points[i]={{a,b},i};
		end_points[i]={b,val};
	}
	for(int i=1;i<=100000;++i) valid[i]=0;
	dp[0]=1;
	valid[0]=INF;
	sort(start_points,start_points+n);
	sort(end_points,end_points+n);
	start_points[n]={{1000000000,0},0};
	cin>>z;
	for(int q=0;q<z;++q){
		cin>>a>>val>>b;
		questions[q]={{a,q},{val,a+b}};
	}
	sort(questions,questions+z);
	int iterator=0;
	for(int i=0;i<n;++i){
		int v=start_points[i].second;
		for(int j=100000;j>=items[v];--j){
			valid[j]=max(valid[j],min(valid[j-items[v]],start_points[i].first.second));
		}
		while(iterator<z&&questions[iterator].first.first<start_points[i].first.first) ++iterator;
		while(iterator<z&&questions[iterator].first.first<start_points[i+1].first.first){
			answers[questions[iterator].first.second]=
			(valid[questions[iterator].second.first]>questions[iterator].second.second);
			++iterator;
		}
	}
	for(int q=0;q<z;++q){
		cout<<(answers[q]?"TAK":"NIE")<<"\n";
	}
}
