//Task statement: szkopul.edu.pl/problemset/problem/kvwWom2nxVBqipEfeiMtidn5/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e5+7,N=18;
int n,m,x;
int arr[SIZE];
map<int,int> ma[N];
int ans=0;
int convert(int a,int b){
    int val=0;
    for(int i=a+b-1,c=0;i>=a;--i,++c){
        if(arr[i]==1) val+=(1<<c);
    }
    return val;
}
void remove_len(int a,int b){
    if(b>n) return;
    int i=max(1,a-b+1);
    int j=convert(i,b);
    for(;i<=min(a,n-b+1);++i){
        if(--ma[b][j]==0){
            map<int,int>::iterator it=ma[b].find(j);
            ma[b].erase(it);
        }
        j<<=1;
        j+=arr[i+b];
        if(j&(1<<b)) j-=(1<<b);
    }
}
void add_len(int a,int b){
    if(b>n) return;
    int i=max(1,a-b+1);
    int j=convert(i,b);
    for(;i<=min(a,n-b+1);++i){
        ++ma[b][j];
        j<<=1;
        j+=arr[i+b];
        if(j&(1<<b)) j-=(1<<b);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        char c;
        cin>>c;
        if(c=='1') arr[i]=1;
    }
    for(int i=1;i<=min(N-1,n);++i){
        for(int j=1;j<=n-i+1;++j){
            ++ma[i][convert(j,i)];
        }
    }
    for(int i=1;i<N;++i){
        if(ma[i].size()<(1<<i)){
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";
    while(m--){
        cin>>x;
        for(int i=1;i<N;++i) remove_len(x,i);
        if(arr[x]==1) arr[x]=0;
        else arr[x]=1;
        for(int i=1;i<N;++i) add_len(x,i);
        for(int i=1;i<N;++i){
            if(ma[i].size()<(1<<i)){
                ans=i;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}
