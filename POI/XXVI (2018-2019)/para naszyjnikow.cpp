//Task statement: szkopul.edu.pl/problemset/problem/OtqvpeGnW8TDwTXsatPekUcF/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e5+7;
int q,n,m;
int arr[SIZE],arr2[SIZE],l0[SIZE][2],l1[SIZE][2],r0[SIZE][2],r1[SIZE][2],pref[SIZE][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>q;
	while(q--){
		cin>>n>>m;
		if(n<m){
			for(int i=1;i<=n;++i){
				cin>>arr2[i];
				arr2[i]%=2;
			}
			for(int i=1;i<=m;++i){
				cin>>arr[i];
				arr[i]%=2;
			}
			swap(n,m);
		}else{
			for(int i=1;i<=n;++i){
				cin>>arr[i];
				arr[i]%=2;
			}
			for(int i=1;i<=m;++i){
				cin>>arr2[i];
				arr2[i]%=2;
			}
		}
		int buf0=0,buf1=0;
		for(int i=1;i<=n;++i){
			if(arr[i]==0) buf0=i;
			if(arr[i]==1) buf1=i;
			l1[i][0]=buf1;
			l0[i][0]=buf0;
		}
		buf0=SIZE; buf1=SIZE;
		for(int i=n;i>=1;--i){
			if(arr[i]==0) buf0=i;
			if(arr[i]==1) buf1=i;
			r1[i][0]=buf1;
			r0[i][0]=buf0;
		}
		buf0=0; buf1=0;
		for(int i=1;i<=m;++i){
			if(arr2[i]==0) buf0=i;
			if(arr2[i]==1) buf1=i;
			l1[i][1]=buf1;
			l0[i][1]=buf0;
		}
		buf0=SIZE; buf1=SIZE;
		for(int i=m;i>=1;--i){
			if(arr2[i]==0) buf0=i;
			if(arr2[i]==1) buf1=i;
			r1[i][1]=buf1;
			r0[i][1]=buf0;
		}
		for(int i=1;i<=n;++i) pref[i][0]=pref[i-1][0]+arr[i];
		for(int i=1;i<=m;++i) pref[i][1]=pref[i-1][1]+arr2[i];
		int ans=0;
		int p1=pref[m][1]%2;
		int p2=pref[m-1][1]%2;
		if(r1[1][1]!=SIZE&&l0[m][1]!=0) ans=max(0,l0[m][1]-r1[1][1]);
		if(r0[1][1]!=SIZE&&l1[m][1]!=0) ans=max(max(ans,0),l1[m][1]-r0[1][1]);
		buf0=0; buf1=0;
		for(int i=1;i<=n-m+1;++i){
			int val=0;
			if(r0[i][0]<=i+m-1&&l1[i+m-1][0]>=i) val=max(val,l1[i+m-1][0]-r0[i][0]);
			if(r1[i][0]<=i+m-1&&l0[i+m-1][0]>=i) val=max(val,l0[i+m-1][0]-r1[i][0]);
			ans=max(val,ans);
			buf0=(pref[i+m-1][0]-pref[i-1][0])%2;
			if(m>1) buf1=(pref[i+m-2][0]-pref[i-1][0])%2;
			if(buf0==p1) ans=max(ans,m);
			if(m>1&&buf1==p2) ans=max(ans,m-1);
		}
		cout<<ans<<"\n";
	}
}
