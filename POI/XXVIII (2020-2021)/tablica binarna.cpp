//Task statement: szkopul.edu.pl/problemset/problem/3sQlWSD2omwi4M_wdqCbycIW/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e3+7;
int arr[SIZE][SIZE];
int n,m,q;
int xx1,yy1,x2,y2;
int opers=0;
void flip(int y,int x){
	if(arr[y][x]) --opers;
	else ++opers;
	arr[y][x]^=1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	while(q--){
		cin>>yy1>>xx1>>y2>>x2;
		--yy1; --xx1; --y2; --x2;
		flip(y2,x2);
		if(xx1!=0) flip(y2,xx1-1);
		if(yy1!=0) flip(yy1-1,x2);
		if(xx1!=0&&yy1!=0) flip(yy1-1,xx1-1);
		cout<<opers<<"\n";
	}
}
