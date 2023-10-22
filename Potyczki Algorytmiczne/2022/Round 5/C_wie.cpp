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
const int MAXN=9;
char arr[MAXN][MAXN];
char fin[MAXN][MAXN];
bool tmp[MAXN][MAXN];
ll precalc[MAXN][MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	precalc[8][8][8]=110162338048LL;
	precalc[8][8][8]=110162338048LL;
	precalc[8][8][7]=13770292256LL;
	precalc[8][8][7]=13770292256LL;
	precalc[8][8][6]=1449504448LL;
	precalc[8][8][6]=1449504448LL;
	precalc[8][8][5]=124957280LL;
	precalc[8][8][5]=124957280LL;
	precalc[8][8][4]=8471680LL;
	precalc[8][8][4]=8471680LL;
	precalc[8][8][3]=423584LL;
	precalc[8][8][3]=423584LL;
	precalc[7][8][8]=34357508640LL;
	precalc[8][7][8]=34357508640LL;
	precalc[7][8][7]=5010470010LL;
	precalc[8][7][7]=5010470010LL;
	precalc[7][8][6]=613526940LL;
	precalc[8][7][6]=613526940LL;
	precalc[7][8][5]=61352694LL;
	precalc[8][7][5]=61352694LL;
	precalc[7][8][4]=4811976LL;
	precalc[8][7][4]=4811976LL;
	precalc[7][8][3]=277614LL;
	precalc[8][7][3]=277614LL;
	precalc[6][8][8]=8778047520LL;
	precalc[8][6][8]=8778047520LL;
	precalc[6][8][7]=1536158316LL;
	precalc[8][6][7]=1536158316LL;
	precalc[6][8][6]=224803656LL;
	precalc[8][6][6]=224803656LL;
	precalc[6][8][5]=26762340LL;
	precalc[8][6][5]=26762340LL;
	precalc[6][8][4]=2489520LL;
	precalc[8][6][4]=2489520LL;
	precalc[5][8][8]=1691114304LL;
	precalc[8][5][8]=1691114304LL;
	precalc[5][8][7]=369931254LL;
	precalc[8][5][7]=369931254LL;
	precalc[5][8][6]=67260228LL;
	precalc[8][5][6]=67260228LL;
	precalc[5][8][5]=9891210LL;
	precalc[8][5][5]=9891210LL;
	precalc[5][8][4]=1130424LL;
	precalc[8][5][4]=1130424LL;
	precalc[4][8][8]=211723200LL;
	precalc[8][4][8]=211723200LL;
	precalc[4][8][7]=61752600LL;
	precalc[8][4][7]=61752600LL;
	precalc[4][8][6]=14820624LL;
	precalc[8][4][6]=14820624LL;
	precalc[4][8][5]=2850120LL;
	precalc[8][4][5]=2850120LL;
	precalc[3][8][8]=12620256LL;
	precalc[8][3][8]=12620256LL;
	precalc[3][8][7]=5521362LL;
	precalc[8][3][7]=5521362LL;
	precalc[3][8][6]=1948716LL;
	precalc[8][3][6]=1948716LL;
	precalc[7][7][8]=10565771832LL;
	precalc[7][7][8]=10565771832LL;
	precalc[7][7][7]=1803912264LL;
	precalc[7][7][7]=1803912264LL;
	precalc[7][7][6]=257701752LL;
	precalc[7][7][6]=257701752LL;
	precalc[7][7][5]=29965320LL;
	precalc[7][7][5]=29965320LL;
	precalc[7][7][4]=2724120LL;
	precalc[7][7][4]=2724120LL;
	precalc[6][7][8]=2647385520LL;
	precalc[7][6][8]=2647385520LL;
	precalc[6][7][7]=545049960LL;
	precalc[7][6][7]=545049960LL;
	precalc[6][7][6]=93437136LL;
	precalc[7][6][6]=93437136LL;
	precalc[6][7][5]=12977380LL;
	precalc[7][6][5]=12977380LL;
	precalc[6][7][4]=1402960LL;
	precalc[7][6][4]=1402960LL;
	precalc[5][7][8]=495557568LL;
	precalc[7][5][8]=495557568LL;
	precalc[5][7][7]=128477888LL;
	precalc[7][5][7]=128477888LL;
	precalc[5][7][6]=27530976LL;
	precalc[7][5][6]=27530976LL;
	precalc[5][7][5]=4746720LL;
	precalc[7][5][5]=4746720LL;
	precalc[4][7][8]=59202000LL;
	precalc[7][4][8]=59202000LL;
	precalc[4][7][7]=20720700LL;
	precalc[7][4][7]=20720700LL;
	precalc[4][7][6]=5920200LL;
	precalc[7][4][6]=5920200LL;
	precalc[6][6][8]=645553920LL;
	precalc[6][6][8]=645553920LL;
	precalc[6][6][7]=161388480LL;
	precalc[6][6][7]=161388480LL;
	precalc[6][6][5]=5565120LL;
	precalc[6][6][5]=5565120LL;
	precalc[6][6][4]=718080LL;
	precalc[6][6][4]=718080LL;
	precalc[5][6][8]=116035920LL;
	precalc[6][5][8]=116035920LL;
	precalc[5][6][7]=36920520LL;
	precalc[6][5][7]=36920520LL;
	precalc[5][6][5]=2006550LL;
	precalc[6][5][5]=2006550LL;
	precalc[4][6][8]=12961344LL;
	precalc[6][4][8]=12961344LL;
	precalc[4][6][7]=5670588LL;
	precalc[6][4][7]=5670588LL;
	precalc[5][5][8]=19612560LL;
	precalc[5][5][8]=19612560LL;
	precalc[5][5][7]=8075760LL;
	precalc[5][5][7]=8075760LL;
	precalc[5][5][6]=2691920LL;
	precalc[5][5][6]=2691920LL;
	precalc[4][5][8]=1973088LL;
	precalc[5][4][8]=1973088LL;
	precalc[3][5][8]=75504LL;
	precalc[5][3][8]=75504LL;
	precalc[4][4][8]=164736LL;
	precalc[4][4][8]=164736LL;
	int n,m; cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) cin>>arr[i][j];
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) cin>>fin[i][j];
	}
	int N=0;
	bool x=0,y=0,finx=0,finy=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(arr[i][j]=='O'){
				x^=(i%2);
				y^=(j%2);
				++N;
			}
			if(fin[i][j]=='O'){
				finx^=(i%2);
				finy^=(j%2);
			}
		}
	}
	x^=y;
	finx^=finy;
	if(x^finx){
		cout<<"0\n";
		return 0;
	}
	vector<int> A;
	for(int i=0;i<n*m-N;++i) A.pb(0);
	for(int i=0;i<N;++i) A.pb(1);
	ll total=0;
	if(precalc[n][m][N]) total=precalc[n][m][N];
	else{
		do{
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j) tmp[i][j]=A[i*m+j];
			}
			int curr=0;
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					if(tmp[i][j]){
						if(i>0&&!tmp[i-1][j]) ++curr;
						if(i<n-1&&!tmp[i+1][j]) ++curr;
						if(j>0&&!tmp[i][j-1]) ++curr;
						if(j<m-1&&!tmp[i][j+1]) ++curr;
					}
				}
			}
			total+=curr;
		}while(next_permutation(A.begin(),A.end()));
	}
	ll curr=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(fin[i][j]=='O'){
				if(i>0&&fin[i-1][j]=='.') ++curr;
				if(i<n-1&&fin[i+1][j]=='.') ++curr;
				if(j>0&&fin[i][j-1]=='.') ++curr;
				if(j<m-1&&fin[i][j+1]=='.') ++curr;
			}
		}
	}
	curr*=2;
	long double ans=(long double)curr/(long double)total;
	cout<<fixed<<setprecision(15)<<ans<<"\n";
}
