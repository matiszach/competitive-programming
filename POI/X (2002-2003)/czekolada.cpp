//Task statement: szkopul.edu.pl/problemset/problem/8AKFvYX1GKjeakIidXGH5_h7/site/
//*Author Mateusz Kowalski*
#include <iostream>
#include <algorithm>
using namespace std;
int x[1000], y[1000];
int m,n;
int a,a1,b,b1;
int w,s;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        cin>>x[i];
        x[i]=-x[i];
    }
    for(int j=0;j<m-1;j++){
        cin>>y[j];
        y[j]=-y[j];
    }
    x[n-1]=0; y[m-1]=0;
    a1=0; b1=0;
    a=1; b=1;
    sort(x,x+n-1);
    for(int i=0;i<n-1;i++) x[i]=-x[i];
    sort(y,y+m-1);
    for(int i=0;i<m-1;i++) y[i]=-y[i];
    for(int i=0;i<n+m-2;i++){
        if(x[a1] >= y[b1]){
            s=x[a1]*b; a1++; a++; w+=s;
            continue;
        }
        if(x[a1] < y[b1]){
            s=y[b1]*a; b1++; b++; w+=s;
            continue;
        }
    }
    cout<<w<<endl;
}
