//Task statement: szkopul.edu.pl/problemset/problem/plwJuavOqAD9XxBqllCwJRK3/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int n,s,x,nec,curr;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>s;
	x=(n*(n-1))/2;
	if((s+x)%2==1||s>x||s<-x){
		cout<<"NIE\n";
		return 0;
	}
	nec=(s+x)/2;
	curr=0;
	cout<<"0 ";
	for(int i=n-1;i>=1;--i){
		if(nec>=i){
			nec-=i;
			++curr;
		}else{
			--curr;
		}
		cout<<curr<<" ";
	}
}
