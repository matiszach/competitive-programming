//Task statement: szkopul.edu.pl/problemset/problem/GaSxd7JWqK-Ukr7EDxAaJLAg/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+7,INF=1e9+7;
int n,p,q,x,y,k;
char c;
int arr[SIZE],pref[SIZE],suf[SIZE],total[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>p>>q>>x>>y;
	for(int i=1;i<=n;++i){
		cin>>c;
		if(c=='+') arr[i]=1;
		else arr[i]=-1;
	}
	pref[0]=INF; suf[n+1]=INF;
	for(int i=1;i<=n;++i){
		total[i]=total[i-1]+arr[i];
		pref[i]=min(pref[i-1],total[i]);
	}
	for(int i=n;i>=1;--i) suf[i]=min(suf[i+1],total[i]);
	if(total[n]!=q-p) k=(q-p-total[n])/2;
	int req=pref[n]+p;
	int mov=(-req+1)/2;
	int val=0,ans=INF;
	if(req<0&&k<0) val=mov*2-k;
	if(req<0&&k>=0) val=mov*2+k-(2*min(mov,k));
	if(req>=0&&k<0) val=-k;
	if(req>=0&&k>=0) val=k;
	ans=min(ans,val*x);
	int counter=0;
	for(int i=n;i>1;--i){
		++counter;
		req=min(p+suf[i]-total[i-1],p+(total[n]-total[i-1])+pref[i-1]);
		mov=(-req+1)/2;
		if(req<0&&k<0) val=mov*2-k;
		if(req<0&&k>=0) val=mov*2+k-(2*min(mov,k));
		if(req>=0&&k<0) val=-k;
		if(req>=0&&k>=0) val=k;
		ans=min(ans,val*x+counter*y);
	}
	cout<<ans<<"\n";
}
