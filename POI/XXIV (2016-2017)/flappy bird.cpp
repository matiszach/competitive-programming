//Task statement: szkopul.edu.pl/problemset/problem/eLy9p2a1VStZ4y9y-LdeB-8f/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+1;
int n,x;
struct point{
	int x,y;
};
struct obs{
	int po_x,po_b,po_t;
};
obs obstacles[SIZE];
bool cmp(obs a,obs b){
	return a.po_x<b.po_x;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>x;
	int pos_x=0,pos_bot=0,pos_top=0;
	point bot_point={0,0},top_point={0,0};
	for(int i=0;i<n;++i){
		cin>>pos_x>>pos_bot>>pos_top;
		obstacles[i]={pos_x,pos_bot,pos_top};
	}
	sort(obstacles,obstacles+n,cmp);
	for(int i=0;i<n;++i){
		pos_x=obstacles[i].po_x;
		pos_bot=obstacles[i].po_b+1;
		pos_top=obstacles[i].po_t-1;
		int new_b=0,new_t=0;
		//general
		int d=pos_x-bot_point.x;
		int b_lim=bot_point.y-d,t_lim=top_point.y+d;
		//bottom one
		new_b=b_lim,new_t=t_lim;
		if(b_lim<pos_bot){
			new_b=pos_bot+(abs(b_lim)%2==abs(pos_bot)%2?0:1);
		}else if(b_lim>pos_top){
			cout<<"NIE\n";
			return 0;
		}
		if(t_lim>pos_top){
			new_t=pos_top-(abs(t_lim)%2==abs(pos_top)%2?0:1);
		}else if(t_lim<pos_bot){
			cout<<"NIE\n";
			return 0;
		}
		bot_point={pos_x,new_b};
		top_point={pos_x,new_t};
	}
	int a=bot_point.y;
	int b=bot_point.x;
	int result=(b-abs(a))/2;
	if(a>0) result+=a;
	if(result<0) result=0;
	cout<<result<<"\n";
}
