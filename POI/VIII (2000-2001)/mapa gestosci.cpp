//Task statement: szkopul.edu.pl/problemset/problem/0QusZwo2JAyvhPj1JIKRc8H7/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=251;
int F[SIZE][SIZE],P[SIZE][SIZE];
int n,r;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>r;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>F[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			P[i][j]=P[i-1][j]+P[i][j-1]-P[i-1][j-1]+F[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<P[max(i-r-1,0)][max(j-r-1,0)]+P[min(i+r,n)][min(j+r,n)]
			-P[min(i+r,n)][max(j-r-1,0)]-P[max(i-r-1,0)][min(j+r,n)]<<" ";
		}
		cout<<"\n";
	}
}
