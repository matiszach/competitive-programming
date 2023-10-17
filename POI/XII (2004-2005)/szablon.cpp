//Task statement: szkopul.edu.pl/problemset/problem/a3IarwgOdubufXQ89OsQz3v_/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
string capt;
vector<int> tmlp;
vector<int> kmp(string &s){
	int n=s.size();
	vector<int> pi(n);
	for(int i=1;i<n;++i){
		int j=pi[i-1];
		while(j>0&&s[i]!=s[j]) j=pi[j-1];
		if(s[i]==s[j]) ++j;
		pi[i]=j;
	}
	return pi;
}
bool check(int len){
	string s=capt.substr(0,len)+"$"+capt;
	vector<int> pi=kmp(s);
	int last=len;
	for(int i=len+1;i<pi.size();++i){
		if(pi[i]==len) last=i;
		if (i-last==len) return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>capt;
	int n=capt.size();
	vector<int> pi=kmp(capt);
	int a=capt.size();
	while(a>1){
		tmlp.push_back(a);
		a=pi[a-1];
	}
	reverse(tmlp.begin(),tmlp.end());
	int j=0;
	while(j<tmlp.size()&&!check(tmlp[j])){
		int temp=tmlp[j]*2;
		while(tmlp[j]<=temp) ++j;
	}
	cout<<tmlp[j]<<"\n";
}
