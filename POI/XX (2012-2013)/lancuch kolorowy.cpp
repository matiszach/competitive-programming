//Task statement: szkopul.edu.pl/problemset/problem/MAWN1VdLdXO29VvrVYuYxQyw/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int n,m;
int needed[2000100];
int amount[2000100];
int arr[2000100];
long long balance=0;
long long len=0;
long long counter=0;
int x=0,g=0;
int main()
{
	memset(needed,0,sizeof(needed));
	memset(amount,0,sizeof(amount));
	memset(arr,0,sizeof(arr));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m>n) m=n;
	m=max(m,0);
	m=min(m,1000000);
	n=max(n,0);
	n=min(n,1000000);
	balance=m;
	for(int i=0;i<m;i++){
		cin>>amount[i];
		len+=amount[i];
	}
	for(int i=0;i<m;i++){
		cin>>x;
		x=max(0,x);
		x=min(x,1000000);
		needed[x]=amount[i];
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int curr=0;
	if(len>1000000){
		cout<<"0\n";
		return 0;
	}
	for(int i=0;i<len;i++){
		g=i;
		g=max(0,g);
		g=min(g,1000000);
		curr=arr[i];
		curr=max(0,curr);
		curr=min(curr,1000000);
		needed[curr]--;
		if(needed[curr]==0) balance--;
		else if(needed[curr]==-1) balance++;
		if(balance==0) counter++;
	}
	int next=0,prev=0,h=0;
	for(int i=len;i<n;i++){
		h=i;
		h=max(h,0);
		h=min(h,1000000);
		next=arr[h];
		g=i-len;
		g=max(0,g);
		g=min(g,1000000);
		prev=arr[g];
		prev=max(prev,0);
		prev=min(prev,1000000);
		next=max(next,0);
		next=min(next,1000000);
		needed[prev]++;
		if(needed[prev]==0) balance--;
		else if(needed[prev]==1) balance++;
		needed[next]--;
		if(needed[next]==0) balance--;
		else if(needed[next]==-1) balance++;
		if(balance==0) counter++;
	}
	cout<<counter<<"\n";
}
