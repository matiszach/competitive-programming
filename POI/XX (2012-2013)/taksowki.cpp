//Task statement: szkopul.edu.pl/problemset/problem/pxbqUTPy3IuPDul9FdT2_Sth/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=5e5+1;
ll d,m,n;
ll taxi[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>d>>m>>n;
	for(int i=0;i<n;++i){
		cin>>taxi[i];
	}
	ll curr_pos=0;
	sort(taxi,taxi+n);
	bool able=false;
	ll extra=0;
	for(int i=0;i<n;++i){
		if(taxi[i]>=d-m){
			extra=taxi[i];
			taxi[i]=-1;
			able=true;
			break;
		}
	}
	int counter=0;
	bool able2=false;
	for(int i=n-1;i>=0;--i){
		if(taxi[i]==-1) continue;
		if(taxi[i]>m-curr_pos){
			curr_pos+=taxi[i]-(m-curr_pos);
			++counter;
		}
		if(curr_pos>=(m+d-extra)/2){
			able2=true;
			break;
		}
	}
	if(curr_pos>=(m+d-extra)/2){
        able2=true;
    }
	if(curr_pos<d) ++counter;
	if((m-curr_pos>0?m-curr_pos:0)+m-curr_pos>extra&&curr_pos<d){
		cout<<"0\n";
		return 0;
	}
	if(able&&able2) cout<<max(counter,0)<<"\n";
	else cout<<"0\n";
}
