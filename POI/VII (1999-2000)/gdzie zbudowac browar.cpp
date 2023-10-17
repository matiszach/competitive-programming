//Task statement: szkopul.edu.pl/problemset/problem/Z1C91LB8rGYMxy6wRLBmbXba/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE_CITY=1e4+1,SIZE=1e6+1;
int n;
int x,y;
int pos[SIZE_CITY],beer[SIZE_CITY],closer[SIZE_CITY];
bitset<SIZE_CITY> direction;
int occupied[SIZE];
vector<int> break_point[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	int curr_pos=0;
	for(int i=0;i<n;++i){
		cin>>x>>y;
		pos[i]=curr_pos;
		occupied[curr_pos]=x;
		beer[i]=x;
		curr_pos+=y;
	}
	int left=0,right=0;
	long long best_cost=0;
	for(int i=0;i<n;++i){
		if(pos[i]>curr_pos-pos[i]){
			//backwards
			direction[i]=0;
			break_point[(2*pos[i]-curr_pos)/2].push_back(i);
			left+=beer[i];
			closer[i]=curr_pos-pos[i];
		}else{
			//forward
			direction[i]=1;
			if(curr_pos-pos[i]!=pos[i])
			break_point[pos[i]+curr_pos/2].push_back(i);
			right+=beer[i];
			closer[i]=pos[i];
		}
		break_point[pos[i]].push_back(i);
		best_cost+=closer[i]*beer[i];
	}
	long long curr_cost=best_cost;
	for(int j:break_point[0]){
		if(!direction[j]){
			left-=beer[j];
			right+=beer[j];
			direction[j]=1;
		}else{
			left+=beer[j];
			right-=beer[j];
			direction[j]=0;
		}
	}
	int affector=0;
	for(int i=1;i<curr_pos;++i){
		int shift=0;
		shift+=left-right;
		if(curr_pos%2==1) shift+=affector;
		affector=0;
		for(int j:break_point[i]){
			if(!direction[j]){
				left-=beer[j];
				right+=beer[j];
				direction[j]=1;
				affector+=beer[j];
			}else{
				left+=beer[j];
				right-=beer[j];
				direction[j]=0;
			}
		}
		curr_cost+=shift;
		best_cost=min(best_cost,curr_cost);
	}
	cout<<best_cost<<"\n";
}
