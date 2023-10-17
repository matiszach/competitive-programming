//Task statement: szkopul.edu.pl/problemset/problem/UglLG7z6s5FUkEY21SCW3swi/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e5+5;
int n,x,z;
int y,a;
int value[SIZE];
vector<pair<int,int> > arr;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x>>z;
	int counter=0;
	for(int i=0;i<n;++i){
		cin>>y;
		counter+=y;
		for(int j=0;j<y;++j){
			cin>>a;
			arr.push_back({a,i});
		}
	}
	sort(arr.begin(),arr.end());
	for(int i=arr.size()-1;i>=0;--i){
		int platform=arr[i].second;
		if(platform<n-1){
			if(value[platform+1]>value[platform]+1) value[platform+1]=value[platform]+1;
			if(value[platform+1]<value[platform]+1) value[platform]=value[platform+1];
			else ++value[platform];
		}else ++value[platform];
	}
	for(int i=0;i<z;++i){
		cin>>a;
		cout<<value[a-1]<<"\n";
	}
}
