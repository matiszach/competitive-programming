//Task statement: szkopul.edu.pl/problemset/problem/B8uHcsCWL_20NSJij1AL1b4C/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool prime(int x){
	if(x==2||x==3||x==5||x==7||x==11||x==13) return 1;
	if(x<2) return 0;
	if(x%2==0||x%3==0||x%5==0||x%7==0||x%11==0||x%13==0) return 0;
	for(int i=2;i*i<=x;++i){
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i){
		int x; cin>>x;
		if(prime(x)) cout<<"1\n"<<x<<"\n";
		else{
			if(x==12){
				cout<<"2\n5 7\n";
				break;
			}
			if(x==11){
				cout<<"1\n11\n";
				break;
			}
			if(x==10){
				cout<<"2\n3 7\n";
				break;
			}
			vector<int> res;
			int avoid=0;
			if(x%2==1){
				if(!prime(x-6)){
					res.pb(3);
					x-=3;
					avoid=3;
				}else{
					res.pb(5);
					x-=5;
					avoid=5;
				}
			}
			for(int j=3;j<=x;++j){
				if(j==avoid) continue;
				if(prime(j)&&prime(x-j)){
					res.pb(j);
					res.pb(x-j);
					break;
				}
			}
			cout<<(int)res.size()<<"\n";
			sort(res.begin(),res.end());
			for(int v:res) cout<<v<<" ";
			cout<<"\n";
		}
	}
}
