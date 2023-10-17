//Task statement: szkopul.edu.pl/problemset/problem/Ak4wWPkNtHpF-OiulN1gixfW/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+7;
int n,q,x,len;
vector<int> ind[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x;
		ind[x].push_back(i);
	}
	cin>>q;
	while(q--){
		cin>>len;
		bool ok=1;
		int curr_idx=1;
		for(int i=1;i<=len;++i){
			cin>>x;
			vector<int>::iterator it=lower_bound(ind[x].begin(),ind[x].end(),curr_idx);
			if(it!=ind[x].end()) curr_idx=*it+1;
			else ok=0;
		}
		cout<<(ok?"TAK\n":"NIE\n");
	}
}
