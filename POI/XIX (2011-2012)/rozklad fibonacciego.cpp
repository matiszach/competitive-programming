//Task statement: szkopul.edu.pl/problemset/problem/w1QbhPufazp-sH6X-u4pTnNu/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
ll fib[87];
int p;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>p;
	fib[0]=fib[1]=1;
	for(int i=2;i<87;++i) fib[i]=fib[i-1]+fib[i-2];
	while(p--){
		cin>>k;
		int ans=0;
		while(k>0){
			ll tmp=k;
			for(int i=0;i<87;++i){
				tmp=min(tmp,abs(k-fib[i]));
			}
			k=tmp;
			++ans;
		}
		cout<<ans<<"\n";
	}
}
