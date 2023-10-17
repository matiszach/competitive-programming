//Task statement: szkopul.edu.pl/problemset/problem/V1PYHlhJQGTY6KR5ODoTTYU4/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int A=31,SIZE=1e6+7;
string s1,s2;
int n;
int iter[A];
vector<int> idx[A];
int arr[SIZE];
typedef long long ll;
ll ans;
vector<int> merge_sort(int start,int end){
	if(start==end) return {arr[start]};
	int mid=(start+end)/2;
	vector<int> S=merge_sort(start,mid),E=merge_sort(mid+1,end),res;
	int it1=0,it2=0;
	while(it1<(int)S.size()||it2<(int)E.size()){
		if(it1==(int)S.size()){
			res.push_back(E[it2++]);
		}
		else if(it2==(int)E.size()){
			ans+=(ll)it2;
			res.push_back(S[it1++]);
		}
		else if(S[it1]<E[it2]){
			ans+=(ll)it2;
			res.push_back(S[it1++]);
		}
		else{
			res.push_back(E[it2++]);
		}
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	cin>>s1>>s2;
	for(int i=0;i<n;++i) idx[s2[i]-'A'].push_back(i);
	for(int i=0;i<n;++i) arr[i]=idx[s1[i]-'A'][iter[s1[i]-'A']++];
	merge_sort(0,n-1);
	cout<<ans<<"\n";
}
