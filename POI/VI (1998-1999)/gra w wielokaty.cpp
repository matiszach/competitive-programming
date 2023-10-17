//Task statement: szkopul.edu.pl/problemset/problem/3rPNlMtwf0PuDgOG18X_NPhf/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[3];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	if(n%2==0){
		cout<<"TAK\n";
		return 0;
	}
	int x,y,z;
	for(int i=0;i<3;++i){
		cin>>arr[i];
	}
	sort(arr,arr+3);
	if((arr[0]+1==arr[1]&&arr[1]+1==arr[2])||
		arr[2]==n-1&&arr[0]==0&&(arr[1]==1||arr[1]==n-2)){
		cout<<"TAK\n";
	}else cout<<"NIE\n";
}
