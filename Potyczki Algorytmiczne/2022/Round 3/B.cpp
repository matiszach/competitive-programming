#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAXN=607;
string words[MAXN];
int count(string s){
	int n=(int)s.size();
	int N=(1<<n);
	vector<string> good;
	for(int mask=1;mask<N;++mask){
		int curr=0;
		string str="";
		for(int i=0;i<n;++i){
			if((1<<i)&mask){
				if(s[i]=='L') ++curr;
				else --curr;
				str+=s[i];
				if(curr<0) break;
			}
		}
		if(curr!=0) continue;
		good.pb(str);
	}
	sort(good.begin(),good.end());
	int res=(!good.empty());
	for(int i=1;i<(int)good.size();++i){
		if(good[i]!=good[i-1]) ++res;
	}
	return res;
}
int main()
{
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>words[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			string s=words[i]+words[j];
			cout<<count(s)<<" ";
		}
		cout<<"\n";
	}
} 
