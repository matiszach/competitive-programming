//Task statement: szkopul.edu.pl/problemset/problem/oFbVh8iOGlqNYUUueTt5V9N4/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int n;
long double t[10001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int a,b;
		char c;
		cin>>a>>c>>b;
		t[i]=(long double)a/(long double)b;
	}
	sort(t,t+n);
	if(t[0]+t[1]>t[n-1]) cout<<"TAK\n";
	else cout<<"NIE\n";
}
