//Task statement: szkopul.edu.pl/problemset/problem/d5ZNN_brr5VUd_EG9OuvsTan/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+1;
int n;
string s;
int P[SIZE],suf[SIZE];
void KMP(int len){
	P[0]=P[1]=0;
	for(int i=2;i<=len;++i){
		int pref=P[i-1];
		while(pref>0&&s[pref+1]!=s[i]) pref=P[pref];
		if(s[pref+1]==s[i]) ++pref;
		P[i]=pref;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>s;
	s="#"+s;
	long long counter=0;
	KMP(n);
	for(int i=1;i<=n;++i){
		suf[i]=0;
		if(P[i]==0) continue;
		if(P[P[i]]==0) suf[i]=P[i];
		else suf[i]=suf[P[i]];
		counter+=i-suf[i];
	}
	cout<<counter<<"\n";
}
