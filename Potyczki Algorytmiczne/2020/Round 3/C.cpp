#include <bits/stdc++.h>
using namespace std;
const int SIZE=2e6+5,MAX=1e6+1;
int n;
int a,w,t;
int diag[SIZE],hor[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a>>w>>t;
		if(a==1) ++diag[w-t+MAX];
		else ++hor[w-t+MAX];
	}
	int counter=0;
	for(int i=0;i<SIZE;++i){
		counter+=min(diag[i],hor[i]);
	}
	cout<<counter<<"\n";
}
