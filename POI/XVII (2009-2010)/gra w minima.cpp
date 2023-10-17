//Task statement: szkopul.edu.pl/problemset/problem/zGq2aLbEYfP96wuSl8SSYSGs/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+7;
typedef long long ll;
int n;
int arr[SIZE],value[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	value[1]=arr[1];
	for(int i=2;i<=n;++i){
		value[i]=max(value[i-1],arr[i]-value[i-1]);
	}
	cout<<value[n]<<"\n";
}
