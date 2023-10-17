//Task statement: szkopul.edu.pl/problemset/problem/l_GoAC3y67fth8byuOouzIsu/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int s[1000000];
vector<int> nodes;
vector<int> graph[1000000];
vector<int> post_order;
bool killed[1000000];
int colors[1000000];
int max_kills=0,min_kills=0,n;
void DFS(int dst){
    for(int i=0;i<graph[dst].size();i++){
        DFS(graph[dst][i]);
    } post_order.push_back(dst);
}
void shoot(){
    for(int i=0;i<post_order.size();i++){
        if(!killed[post_order[i]]) killed[s[post_order[i]]]=true;
    }
}
void walk_through_cycle(int node){
    int x=node;
    do
    {
        colors[x]=0;
        x=s[x];
    } while (x!=node);
    post_order.clear();
    x=node;
    do
    {
        for(int i=0;i<graph[x].size();i++){
            if(colors[graph[x][i]]==-1){
                DFS(graph[x][i]);
            }
        }
        x=s[x];
    } while (x!=node);
    shoot();
    int y=node;
    x=node;
    do
    {
        if(killed[x]){
            y=x;
            break;
        }
        x=s[x];
    } while (x!=node);
    x=y;
    post_order.clear();
    do
    {
        post_order.push_back(x);
        x=s[x];
    } while (x!=y);
    shoot();
}
bool is_cycle(int start_point){
    int x=start_point;
    do
    {
        if(graph[x].size()>1) return false;
        x=s[x];
    } while (x!=start_point);
    return true;
}
void set_colors(){
    int x=0;
    for(int i=0;i<n;i++){
        if(colors[i]==-1){
            int y=i;
            while(colors[y]==-1){
                colors[y]=x;
                y=s[y];
            }
            if(colors[y]==x){
                nodes.push_back(y);
            }
            x++;
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    memset(colors,-1,sizeof(colors));
    cin>>n;
    min_kills=n; max_kills=n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s[i]=x-1;
        graph[s[i]].push_back(i);
    }
    set_colors();
    for(int i=0;i<n;i++){
        if(graph[i].empty()) max_kills--;
    }
    for(int i=0;i<n;i++){
        killed[i]=false;
        colors[i]=-1;
    }
    for(int i=0;i<nodes.size();i++){
        if(is_cycle(nodes[i])&&nodes[i]!=s[nodes[i]]){
            max_kills--;
        }
        walk_through_cycle(nodes[i]);
    }
    for(int i=0;i<n;i++){
        if(!killed[i]){
            min_kills--;
        }
    }
    cout<<min_kills<<" "<<max_kills<<"\n";
}
