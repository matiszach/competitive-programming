//Task statement: szkopul.edu.pl/problemset/problem/VZifqMhw2OhTWnQqv7mC5Cge/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2002;
int G[SIZE];
bool sqr;
int curr_best=0;
int n;
void compute_row(){
	stack<pair<int,int> > S;
	int k=0,g=0,start=0;
	S.push(make_pair(k,g));
	for(int i=1;i<=n+1;i++){
		start=i;
		while(!S.empty()&&G[i]<S.top().first){
			k=S.top().first;
			g=S.top().second;
			S.pop();
			curr_best=max(k*(i-g),curr_best);
			start=g;
		}
		if(!S.empty()&&S.top().first<G[i]){
			g=start;
			k=G[i];
			S.push({k,g});
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	memset(G,0,sizeof(G));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>sqr;
			if(!sqr) G[j]++;
			else G[j]=0;
		}
		compute_row();
	}
	cout<<curr_best<<"\n";
}
