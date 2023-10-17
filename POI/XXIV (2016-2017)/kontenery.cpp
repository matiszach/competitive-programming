//Task statement: szkopul.edu.pl/problemset/problem/oNnWY6ZuzzhvG-jCmijiXkIk/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=2e5+5;
int n,k;
int a,l,d;
int arr[SIZE],intervals[SIZE];
vector<pair<int,int> > queries[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	int g=sqrt(n);
	for(int i=0;i<k;++i){
		cin>>a>>l>>d;
		if(d>=g){
			for(int j=0;j<l;++j) ++arr[a+j*d];
		}else queries[d].push_back({a,l});
	}
	for(int i=1;i<g;++i){
		for(int j=1;j<=n;++j) intervals[j]=0;
		for(pair<int,int> p:queries[i]){
			++intervals[p.first];
			--intervals[p.first+p.second*i];
		}
		int counter=0;
		for(int j=1;j<=i;++j){
			counter=0;
			for(int k=j;k<=n;k+=i){
				counter+=intervals[k];
				arr[k]+=counter;
			}
		}
	}
	for(int i=1;i<=n;++i) cout<<arr[i]<<" ";
}
