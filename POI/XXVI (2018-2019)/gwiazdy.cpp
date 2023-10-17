//Task statement: szkopul.edu.pl/problemset/problem/vE94xK5yr-lSfcAMD3IKFd7F/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+5;
int n,s;
int tp[2][SIZE],efc[SIZE];
vector<pair<int,int> > oper_blocks;
vector<int> order;
long long ans=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>s;
	for(int i=1;i<n;++i){
		cin>>tp[0][i]>>tp[1][i];
		efc[i]=(tp[0][i]<tp[1][i]?0:1);
		ans+=min(tp[0][i],tp[1][i]);
	}
	efc[n]=2;
	int amount=1;
	for(int i=2;i<=n;++i){
		if(efc[i]==efc[i-1]){
			++amount;
		}else{
			oper_blocks.push_back({efc[i-1],amount});
			amount=1;
		}
	}
	int left=0,right=n+1,val=0,best=99999999,idx=0,ext=0;
	if(oper_blocks[0].first==1&&s>=right-oper_blocks[0].second){
		for(int i=1;i<=right-s;++i){
			if(abs(tp[0][i]-tp[1][i])<best){
				best=abs(tp[0][i]-tp[1][i]);
				idx=i-1;
			}
		}
		ans+=best;
		for(int i=right-idx;i<=right-1;++i) order.push_back(i);
		for(int i=right-oper_blocks[0].second-1;i<right-idx;++i){
			if(s!=i) order.push_back(i);
		}
		ext=1;
		right-=oper_blocks[0].second+1;
	}else if(oper_blocks[0].first==0&&s<=left+oper_blocks[0].second){
		for(int i=1;i<=s;++i){
			if(abs(tp[0][i]-tp[1][i])<best){
				best=abs(tp[0][i]-tp[1][i]);
				idx=i-1;
			}
		}
		ans+=best;
		for(int i=idx;i>=1;--i) order.push_back(i);
		for(int i=oper_blocks[0].second+1;i>idx;--i){
			if(s!=i) order.push_back(i);
		}
		ext=1;
		left+=oper_blocks[0].second+1;
	}
	for(int i=0+ext;i<oper_blocks.size();++i){
		if(oper_blocks[i].first==1){
			val=oper_blocks[i].second;
			if(s>=right-val&&s<=right-1) ++val;
			for(int j=right-val;j<=right-1;++j){
				if(j!=s) order.push_back(j);
			}
			right-=val;
		}else{
			val=oper_blocks[i].second;
			if(s<=left+val&&s>=left+1) ++val;
			for(int j=left+val;j>=left+1;--j){
				if(j!=s) order.push_back(j);
			}
			left+=val;
		}
	}
	cout<<ans<<"\n";
	cout<<s<<" ";
	for(int v:order) cout<<v<<" ";
}
