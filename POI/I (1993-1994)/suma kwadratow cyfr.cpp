//Task statement: szkopul.edu.pl/problemset/problem/VwKJTv4dd23eLGYIeUCOZRcj/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int t;
string n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		cout<<n;
		if(n=="4"||n=="1"){
			cout<<"\n";
			continue;
		}
		cout<<" ";
		int val=0;
		for(int i=0;i<n.size();++i){
			val+=(n[i]-48)*(n[i]-48);
		}
		while(val!=1&&val!=4){
			cout<<val<<" ";
			int temp=val;
			val=0;
			while(temp>0){
				val+=(temp%10)*(temp%10);
				temp/=10;
			}
		}
		cout<<val<<"\n";
	}
}
