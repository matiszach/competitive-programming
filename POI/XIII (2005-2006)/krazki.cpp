//Task statement: szkopul.edu.pl/problemset/problem/lR_LabSUC2n7EMmDHpw-wk_b/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int n,m;
int k[300001],t[300001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>t[i];
	}
	for(int i=0;i<m;++i){
		cin>>k[i];
	}
	for(int i=1;i<n;i++){
		if(t[i-1]<t[i]) t[i]=t[i-1];
	}
	for(int i=1;i<m;i++){
		if(k[i-1]>k[i]) k[i]=k[i-1];
	}
	int curr_point=n-1;
	for(int i=0;i<m;i++){
		if(curr_point==0&&t[0]<k[i]){
			cout<<"0\n";
			return 0;
		}
		for(int j=curr_point;j>=0;j--){
			if(t[j]>=k[i]){
				curr_point=j-1;
				break;
			}if(j==0){
				cout<<"0\n";
				return 0;
			}
		}
	}
	if(curr_point<0){
		cout<<"0\n";
		return 0;
	}
	cout<<curr_point+2<<"\n";
}
