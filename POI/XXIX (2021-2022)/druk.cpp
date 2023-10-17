//Task statement: szkopul.edu.pl/problemset/problem/dezxXQ3SlwzbEWu-DGbPqPY9/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int NAX=1e3+7,CAX=27;
int n,m;
string s;
int arr[NAX][NAX];
int cnt[CAX];
const pll P={53,353};
const pll MOD={1e9+7,1e9+696969};
pll hash_hor[NAX][NAX];
pll hash_vert[NAX][NAX];
pll powers[NAX];
pll get_Hash(int row,int start,int last,bool horizontal){
	pll res={0,0};
	if(horizontal){
		res.first=(hash_hor[row][last].first-hash_hor[row][start-1].first+MOD.first)%MOD.first;
		res.second=(hash_hor[row][last].second-hash_hor[row][start-1].second+MOD.second)%MOD.second;
	}else{
		res.first=(hash_vert[row][last].first-hash_vert[row][start-1].first+MOD.first)%MOD.first;
		res.second=(hash_vert[row][last].second-hash_vert[row][start-1].second+MOD.second)%MOD.second;
	}
	return res;
}
bool compare(pll H1,pll H2,int diff){
	H1.first=H1.first*powers[diff].first%MOD.first;
	H1.second=H1.second*powers[diff].second%MOD.second;
	return H1==H2;
}
int available[NAX];
bool occupied[NAX][NAX];
bool check(int point,bool horizontal){
	pll H=get_Hash(1,1,point,horizontal);
	int total=n*m;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) occupied[i][j]=0;
	for(int i=1;i<=n;++i){
		int dist=0;
		for(int j=1;j<=m;++j) available[j]=0;
		for(int j=m;j>=1;--j){
			++dist;
			if(occupied[i][j]) dist=0;
			if(dist>=point) available[j]=1;
		}
		for(int j=1;j<=m;++j){
			if(occupied[i][j]) continue;
			//horizontal
			if(j+point-1<=m&&compare(H,get_Hash(i,j,j+point-1,1),j-1)&&available[j]){
				for(int k=j;k<=j+point-1;++k){
					occupied[i][k]=1;
					--total;
				}
			}
			//vertical
			else if(i+point-1<=n&&compare(H,get_Hash(j,i,i+point-1,0),i-1)){
				for(int k=i;k<=i+point-1;++k){
					if(occupied[k][j]) return 0;
					occupied[k][j]=1;
					--total;
				}
			}
			if(!occupied[i][j]) return 0;
		}
	}
	return total==0;
}
int colors[CAX];
bool answers[NAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s;
		for(int j=0;j<m;++j) arr[i][j+1]=s[j]-'a'+1;
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) ++cnt[arr[i][j]];
	int distinct=0;
	for(int i=1;i<CAX;++i){
		if(cnt[i]>0) ++distinct;
	}
	int ans=0;
	if(distinct==1){
		for(int i=1;i<=max(n,m);++i){
			if(n%i==0||m%i==0) ++ans;
		}
		cout<<ans<<"\n";
		for(int i=1;i<=max(n,m);++i){
			if(n%i==0||m%i==0) cout<<i<<" ";
		}
		return 0;
	}
	powers[0]={1,1};
	for(int i=1;i<=max(n,m);++i){
		powers[i].first=powers[i-1].first*P.first%MOD.first;
		powers[i].second=powers[i-1].second*P.second%MOD.second;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			hash_hor[i][j].first=(hash_hor[i][j-1].first+arr[i][j]*powers[j].first%MOD.first)%MOD.first;
			hash_hor[i][j].second=(hash_hor[i][j-1].second+arr[i][j]*powers[j].second%MOD.second)%MOD.second;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			hash_vert[i][j].first=(hash_vert[i][j-1].first+arr[j][i]*powers[j].first%MOD.first)%MOD.first;
			hash_vert[i][j].second=(hash_vert[i][j-1].second+arr[j][i]*powers[j].second%MOD.second)%MOD.second;
		}
	}
	for(int i=1;i<=m;++i){
		++colors[arr[1][i]];
		if((n*m)%i!=0) continue;
		int amount=(n*m)/i;
		bool ok=1;
		for(int j=1;j<CAX;++j){
			if(colors[j]*amount!=cnt[j]){
				ok=0;
				break;
			}
		}
		if(!ok) continue;
		if(check(i,1)){
			++ans;
			answers[i]=1;
		}
	}
	for(int i=1;i<CAX;++i) colors[i]=0;
	for(int i=1;i<=n;++i){
		++colors[arr[i][1]];
		if((n*m)%i!=0) continue;
		int amount=(n*m)/i;
		bool ok=1;
		for(int j=1;j<CAX;++j){
			if(colors[j]*amount!=cnt[j]){
				ok=0;
				break;
			}
		}
		if(!ok) continue;
		if(check(i,0)){
			if(answers[i]==0){
				++ans;
				answers[i]=1;
			}
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<NAX;++i) if(answers[i]) cout<<i<<" ";
}
