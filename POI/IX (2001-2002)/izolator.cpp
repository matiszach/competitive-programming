//Task statement: szkopul.edu.pl/problemset/problem/C-avIJ9h36gThNQUOeaYwAD9/site/
//*Author Mateusz Kowalski*
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int tab[100000];
int x=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tab[i];
		x+=tab[i];
	}
	sort(tab,tab+n);
	for(int i=0;i<n/2;i++)
	{
		x+=tab[n-i-1]-tab[i];
	}
	cout<<x<<endl;
}
