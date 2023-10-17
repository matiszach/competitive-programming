//Task statement: szkopul.edu.pl/problemset/problem/AWhdD7i4V7mupdKWVtpgfGSM/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int n,m,x,counter=0;
string s;
pair<int,int> f[2000001];
void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
void faststring(string &text){
	char c=getchar();
	while(c!='\n'){
		text+=c;
		c=getchar();
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(f,-1,sizeof(f));
	fastscan(n); fastscan(m); faststring(s);
	for(int i=0;i<n;++i){
		if(s[i]=='W') ++counter;
		else counter+=2;
	}
	f[counter]={0,n-1};
	int l=0,r=n-1,temp=counter;
	while(temp>=3){
		if(s[l]=='W'&&s[r]=='W'){
			++l; --r;
		}else if(s[l]=='T'){
			++l;
		}else if(s[r]=='T'){
			--r;
		}
		temp-=2;
		f[temp]={l,r};
	}
	int dist_s=-1,dist_e=-1;
	for(int i=0;i<n;++i){
		if(s[i]=='W'){
			dist_s=i;
			break;
		}
	}
	for(int i=n-1;i>=0;--i){
		if(s[i]=='W'){
			dist_e=n-1-i;
			break;
		}
	}
	temp=counter;
	if(dist_s!=-1){
		if(dist_s<dist_e){
			l=dist_s+1; r=n-1;
			temp-=dist_s*2+1;
		}else{
			l=0; r=n-2-dist_e;
			temp-=dist_e*2+1;
		}
		f[temp]={l,r};
	}
	while(temp>=3){
		if(s[l]=='W'&&s[r]=='W'){
			++l; --r;
		}else if(s[l]=='T'){
			++l;
		}else if(s[r]=='T'){
			--r;
		}
		temp-=2;
		f[temp]={l,r};
	}
	vector<int> queries;
	for(int i=1;i<=m;++i){
		fastscan(x);
		queries.push_back(x);
	}
	for(int t:queries){
		if(f[t].first!=-1) cout<<f[t].first+1<<" "<<f[t].second+1<<"\n";
		else cout<<"NIE\n";
	}
}
