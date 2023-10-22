#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+5;
int n;
string a,b;
int aa[SIZE],bb[SIZE];
int a_even[26],b_even[26];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	cin>>a>>b;
	for(int i=0;i<n;++i){
		++aa[int(a[i]-97)];
		++bb[int(b[i]-97)];
		if(i%2==1){
			++a_even[int(a[i]-97)];
			++b_even[int(b[i]-97)];
		}
	}
	bool correct=true;
	for(int i=0;i<26;++i){
		if(aa[i]!=bb[i]||a_even[i]!=b_even[i]) correct=0;
	}
	if(correct) cout<<"TAK\n";
	else cout<<"NIE\n";
}
