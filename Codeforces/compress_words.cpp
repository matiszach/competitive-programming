// Task statement: https://codeforces.com/problemset/problem/1200/E
// *Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
#define pb push_back
const int SIZE=1e6+7;
int n;
string word[SIZE];
pll Hash[SIZE],Hash2[SIZE];
pll powers[SIZE];
const ll MOD1=1e9+7,MOD2=1e9+696969;
const ll P1=307,P2=257;
pll get_Hash(int start,int end){
	pll val;
	val.first=(Hash[end].first-Hash[start-1].first+MOD1)%MOD1;
	val.second=(Hash[end].second-Hash[start-1].second+MOD2)%MOD2;
	return val;
}
pll get_Hash2(int start,int end,int shift){
	pll val;
	val.first=(Hash2[end].first-Hash2[start-1].first+MOD1)%MOD1;
	val.second=(Hash2[end].second-Hash2[start-1].second+MOD2)%MOD2;
	val.first=(val.first*powers[shift].first)%MOD1;
	val.second=(val.second*powers[shift].second)%MOD2;
	return val;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>word[i];
	powers[0]={1,1};
	for(int i=1;i<SIZE;++i){
		powers[i].first=powers[i-1].first*P1%MOD1;
		powers[i].second=powers[i-1].second*P2%MOD2;
	}
	Hash[1]={word[1][0]*P1,word[1][0]*P2};
	for(int i=1;i<(int)word[1].size();++i){
		Hash[i+1].first=(Hash[i].first+word[1][i]*powers[i+1].first%MOD1)%MOD1;
		Hash[i+1].second=(Hash[i].second+word[1][i]*powers[i+1].second%MOD2)%MOD2;
	}
	string res=word[1];
	for(int i=2;i<=n;++i){
		//Hash it!
		Hash2[1]={word[i][0]*P1,word[i][0]*P2};
		for(int j=1;j<(int)word[i].size();++j){
			Hash2[j+1].first=(Hash2[j].first+word[i][j]*powers[j+1].first%MOD1)%MOD1;
			Hash2[j+1].second=(Hash2[j].second+word[i][j]*powers[j+1].second%MOD2)%MOD2;
		}
		//(just)search it!
		int val=0;
		for(int j=min((int)res.size(),(int)word[i].size());j>=1;--j){
			pll x=get_Hash((int)res.size()-j+1,(int)res.size());
			pll y=get_Hash2(1,j,(int)res.size()-j);
			if(x==y){
				val=j;
				break;
			}
		}
		int curr=(int)res.size()+1;
		for(int j=max(val,0);j<(int)word[i].size();++j){
			Hash[curr].first=(Hash[curr-1].first+word[i][j]*powers[curr].first%MOD1)%MOD1;
			Hash[curr].second=(Hash[curr-1].second+word[i][j]*powers[curr].second%MOD2)%MOD2;
			res+=word[i][j];
			++curr;
		}
	}
	cout<<res<<"\n";
}
