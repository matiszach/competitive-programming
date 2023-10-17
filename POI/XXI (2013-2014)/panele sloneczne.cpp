//Task statement: szkopul.edu.pl/problemset/problem/hzKdkq0maus68ExIKeHyERTJ/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int n;
int a,b,c,d;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a>>b>>c>>d;
		int sqr=sqrt(max(b,d));
		int ans=1;
		for(int k=2;k<=sqr;++k){
			if(a/k+(a%k==0?0:1)<=b/k&&c/k+(c%k==0?0:1)<=d/k) ans=k;
		}
		for(int k=1;k<=sqr;++k){
			int val=b/k;
			if(a/val+(a%val==0?0:1)<=b/val&&c/val+(c%val==0?0:1)<=d/val) ans=max(ans,val);
			val=d/k;
			if(a/val+(a%val==0?0:1)<=b/val&&c/val+(c%val==0?0:1)<=d/val) ans=max(ans,val);
		}
		cout<<ans<<"\n";
	}
}
