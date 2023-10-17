//Task statement: szkopul.edu.pl/problemset/problem/oFbVh8iOGlqNYUUueTt5V9N4/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
int arr[MAXN];
void fastscan(int &x){
    char a=getchar_unlocked();
    int val=0;
    for(;a>='0'&&a<='9';a=getchar_unlocked()) val=val*10+a-48;
    x=val;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int idx=0;
    while(1){
        int x; fastscan(x);
        if(!x) break;
        arr[++idx]=x;
    }
    sort(arr+1,arr+idx+1);
    for(int i=1;i<=idx-2;++i){
        if(arr[i]+arr[i+1]>arr[i+2]){
            cout<<arr[i]<<" "<<arr[i+1]<<" "<<arr[i+2]<<"\n";
            return 0;
        }
    }
    cout<<"NIE\n";
}
