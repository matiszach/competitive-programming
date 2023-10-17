//Task statement: szkopul.edu.pl/problemset/problem/qcEpw4SfiiE9VBmBrUz2LgW3/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int w,n;
int arr[30001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>w>>n;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int i=0,j=n-1;
	int counter=0;
	while(i<=j){
		if(arr[i]+arr[j]<=w){
			++i;
			--j;
			++counter;
		}else{
			--j;
			++counter;
		}
	}
	cout<<counter<<"\n";
}
