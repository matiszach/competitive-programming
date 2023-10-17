//Task statement: szkopul.edu.pl/problemset/problem/YBrY12KT6hTbgYrqwXhH3soW/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e5+5,nTree=131072;
int T_hor[nTree*2],T_ver[nTree*2];
void update_hor(int x,int val){
	x+=nTree;
	T_hor[x]=val;
	x/=2;
	while(x>0){
		T_hor[x]=max(T_hor[x*2],T_hor[x*2+1]);
		x/=2;
	}
}
int query_hor(int x,int y){
	x+=nTree;
	y+=nTree;
	int curr_max=max(T_hor[x],T_hor[y]);
	while(x<y-1){
		if(x%2==0) curr_max=max(curr_max,T_hor[x+1]);
		if(y%2==1) curr_max=max(curr_max,T_hor[y-1]);
		x/=2;
		y/=2;
	}
	return curr_max;
}
void update_ver(int x,int val){
	x+=nTree;
	T_ver[x]=val;
	x/=2;
	while(x>0){
		T_ver[x]=max(T_ver[x*2],T_ver[x*2+1]);
		x/=2;
	}
}
int query_ver(int x,int y){
	x+=nTree;
	y+=nTree;
	int curr_max=max(T_ver[x],T_ver[y]);
	while(x<y-1){
		if(x%2==0) curr_max=max(curr_max,T_ver[x+1]);
		if(y%2==1) curr_max=max(curr_max,T_ver[y-1]);
		x/=2;
		y/=2;
	}
	return curr_max;
}
int n,m,k;
struct bus_stop{
	int x,y,p;
};
vector<bus_stop> points;
int a,b,c;
bool cmp(bus_stop x1,bus_stop x2){
	return x1.x<x2.x;
}
bool cmp2(bus_stop x1,bus_stop x2){
	return x1.y<x2.y;
}
bool cmp3(bus_stop x1,bus_stop x2){
	if(x1.x<x2.x) return true;
	else if(x1.x>x2.x) return false;
	else{
		return x1.y<x2.y;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=0;i<k;++i){
		cin>>a>>b>>c;
		points.push_back({a,b,c});
	}
	sort(points.begin(),points.end(),cmp);
	int curr_x=0,prev_x=0,iterator=0;
	for(bus_stop v:points){
		if(v.x>prev_x){
			++curr_x;
			prev_x=v.x;
		}
		points[iterator].x=curr_x;
		++iterator;
	}
	sort(points.begin(),points.end(),cmp2);
	curr_x=0,prev_x=0,iterator=0;
	for(bus_stop v:points){
		if(v.y>prev_x){
			++curr_x;
			prev_x=v.y;
		}
		points[iterator].y=curr_x;
		++iterator;
	}
	sort(points.begin(),points.end(),cmp3);
	int best=0;
	for(bus_stop v:points){
		int curr=min(query_hor(1,v.x),query_ver(1,v.y))+v.p;
		best=max(curr,best);
		update_hor(v.x,curr);
		update_ver(v.y,curr);
	}
	cout<<best<<"\n";
}
