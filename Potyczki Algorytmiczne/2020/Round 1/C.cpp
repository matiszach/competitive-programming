#include <bits/stdc++.h>
using namespace std;
int arr[3][5];
int n;
string s;
int main(){
	cin>>n;
	getline(cin>>ws,s);
	for(int i=0;i<(int)s.size();i+=3){
		int x=int(s[i]-49);
		int y=int(s[i+1]-65);
		++arr[y][x];
	}
	bool valid=true;
	for(int i=0;i<3;++i){
		for(int j=0;j<4;++j){
			if(arr[i][j]<1) valid=false;
		}
	}
	for(int i=0;i<3;++i) if(arr[i][4]<2) valid=false;
	if(valid) cout<<"TAK\n";
	else cout<<"NIE\n";
}
