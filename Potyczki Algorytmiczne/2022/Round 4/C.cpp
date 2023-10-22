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
const int MAXN=507,LOG=20;
int arr[MAXN][MAXN];
vector<int> tmp[MAXN];
int n,m;
void turnG(){
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j) if(arr[j][i]) tmp[i].pb(arr[j][i]);
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) arr[i][j]=0;
	for(int i=1;i<=m;++i){
		for(int j=0;j<(int)tmp[i].size();++j) arr[j+1][i]=tmp[i][j];
		tmp[i].clear();
	}
}
void turnD(){
	for(int i=1;i<=m;++i){
		for(int j=n;j>=1;--j) if(arr[j][i]) tmp[i].pb(arr[j][i]);
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) arr[i][j]=0;
	for(int i=1;i<=m;++i){
		for(int j=0;j<(int)tmp[i].size();++j) arr[n-j][i]=tmp[i][j];
		tmp[i].clear();
	}
}
void turnL(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) if(arr[i][j]) tmp[i].pb(arr[i][j]);
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) arr[i][j]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<(int)tmp[i].size();++j) arr[i][j+1]=tmp[i][j];
		tmp[i].clear();
	}
}
void turnP(){
	for(int i=1;i<=n;++i){
		for(int j=m;j>=1;--j) if(arr[i][j]) tmp[i].pb(arr[i][j]);
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) arr[i][j]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<(int)tmp[i].size();++j) arr[i][m-j]=tmp[i][j];
		tmp[i].clear();
	}
}
void print_board(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!arr[i][j]) cout<<".";
			else if(arr[i][j]==1) cout<<"B";
			else cout<<"C";
		}
		cout<<"\n";
	}
}
int org[MAXN][MAXN];
pii exp_shift[MAXN][MAXN][4][4];
int cols[MAXN],rows[MAXN];
void calc(){
	for(int i=1;i<MAXN;++i) cols[i]=rows[i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(arr[i][j]) ++rows[i];
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			if(arr[j][i]) ++cols[i];
		}
	}
}
pii jp[MAXN][MAXN][LOG];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		string s; cin>>s;
		for(int j=0;j<(int)s.size();++j){
			if(s[j]=='.') arr[i][j+1]=0;
			else if(s[j]=='B') arr[i][j+1]=1;
			else arr[i][j+1]=2;
		}
	}
	int k; cin>>k;
	string s; cin>>s;
	string yas="";
	bool lp=0,gd=0;
	char lst='.';
	pair<char,char> starting_moves;
	int start_idx=0;
	for(int i=0;i<k;++i){
		if(s[i]=='G'||s[i]=='D') gd=1;
		if(s[i]=='L'||s[i]=='P') lp=1;
		if(lp&&gd){
			starting_moves={lst,s[i]};
			break;
		}
		++start_idx;
		lst=s[i];
	}
	if(start_idx==k){
		if(lst=='G') turnG();
		if(lst=='D') turnD();
		if(lst=='L') turnL();
		if(lst=='P') turnP();
		print_board();
		return 0;
	}
	yas+=starting_moves.first;
	yas+=starting_moves.second;
	if(starting_moves.first>starting_moves.second) swap(starting_moves.first,starting_moves.second);
	pair<char,char> lst_pos=starting_moves;
	vector<pair<char,char>> poss={lst_pos};
	vector<char> moves;
	for(int i=start_idx+1;i<k;++i){
		if(s[i]=='G'){
			if(lst_pos.first=='G') continue;
			if(!moves.empty()&&moves.back()=='D'){
				moves.pop_back();
				poss.pop_back();
				lst_pos=poss.back();
			}else{
				moves.pb('G');
				lst_pos.first='G';
				poss.pb(lst_pos);
			}
		}
		if(s[i]=='D'){
			if(lst_pos.first=='D') continue;
			if(!moves.empty()&&moves.back()=='G'){
				moves.pop_back();
				poss.pop_back();
				lst_pos=poss.back();
			}else{
				moves.pb('D');
				lst_pos.first='D';
				poss.pb(lst_pos);
			}
		}
		if(s[i]=='P'){
			if(lst_pos.second=='P') continue;
			if(!moves.empty()&&moves.back()=='L'){
				moves.pop_back();
				poss.pop_back();
				lst_pos=poss.back();
			}else{
				moves.pb('P');
				lst_pos.second='P';
				poss.pb(lst_pos);
			}
		}
		if(s[i]=='L'){
			if(lst_pos.second=='L') continue;
			if(!moves.empty()&&moves.back()=='P'){
				moves.pop_back();
				poss.pop_back();
				lst_pos=poss.back();
			}else{
				moves.pb('L');
				lst_pos.second='L';
				poss.pb(lst_pos);
			}
		}
	}
	for(char &c:moves) yas+=c;
	if((int)yas.size()<10){
		for(char &c:yas){
			if(c=='G') turnG();
			if(c=='D') turnD();
			if(c=='L') turnL();
			if(c=='P') turnP();
		}
		print_board();
		return 0;
	}
	if(yas[0]=='G') turnG();
	if(yas[0]=='D') turnD();
	if(yas[0]=='L') turnL();
	if(yas[0]=='P') turnP();
	if(yas[1]=='G') turnG();
	if(yas[1]=='D') turnD();
	if(yas[1]=='L') turnL();
	if(yas[1]=='P') turnP();
	int ext=0;
	if(yas[0]==yas[1]){
		ext=1;
		if(yas[2]=='G') turnG();
		if(yas[2]=='D') turnD();
		if(yas[2]=='L') turnL();
		if(yas[2]=='P') turnP();
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) org[i][j]=arr[i][j];
	pair<char,char> last_moves={yas[ext],yas[ext+1]};
	if(last_moves.first>last_moves.second) swap(last_moves.first,last_moves.second);
	int start_corner=0;
	if(last_moves==make_pair('G','L')) start_corner=0;
	if(last_moves==make_pair('G','P')) start_corner=1;
	if(last_moves==make_pair('D','P')) start_corner=2;
	if(last_moves==make_pair('D','L')) start_corner=3;
	if(last_moves==make_pair('G','P')) turnL();
	if(last_moves==make_pair('D','L')) turnG();
	if(last_moves==make_pair('D','P')){turnL(); turnG();}
	vector<int> order={'P','L','G','D'};
	calc();
	//GL
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!arr[i][j]) continue;
			//P
			exp_shift[i][j][0][0]={0,m-rows[i]};
			//D
			exp_shift[i][j][0][3]={n-cols[j],0};
		}
	}
	turnP();
	calc();
	//GP
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!arr[i][j]) continue;
			//L
			exp_shift[i][j][1][1]={0,rows[i]-m};
			//D
			exp_shift[i][j][1][3]={n-cols[j],0};
		}
	}
	turnD();
	calc();
	//DP
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!arr[i][j]) continue;
			//L
			exp_shift[i][j][2][1]={0,rows[i]-m};
			//G
			exp_shift[i][j][2][2]={cols[j]-n,0};
		}		
	}
	turnL();
	calc();
	//DL
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!arr[i][j]) continue;
			//P
			exp_shift[i][j][3][0]={0,m-rows[i]};
			//G
			exp_shift[i][j][3][2]={cols[j]-n,0};
		}
	}
	vector<int> V;
	for(int i=ext+2;i<ext+6;++i){
		if(yas[i]=='P') V.pb(0);
		if(yas[i]=='L') V.pb(1);
		if(yas[i]=='G') V.pb(2);
		if(yas[i]=='D') V.pb(3);
	}
	int side=0;
	if(start_corner==0){
		if(V[0]==0) side=1;
		else side=-1;
	}
	if(start_corner==1){
		if(V[0]==3) side=1;
		else side=-1;
	}
	if(start_corner==2){
		if(V[0]==1) side=1;
		else side=-1;
	}
	if(start_corner==3){
		if(V[0]==2) side=1;
		else side=-1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			pii curr={i,j};
			int corner=start_corner;
			for(int l=0;l<4;++l){
				curr={curr.first+exp_shift[curr.first][curr.second][corner][V[l]].first,
					curr.second+exp_shift[curr.first][curr.second][corner][V[l]].second};
				corner+=side;
				if(corner==4) corner=0;
				if(corner==-1) corner=3;
			}
			jp[i][j][0]={curr.first,curr.second};
		}
	}
	int cnt=(int)yas.size()-2-ext;
	cnt=(cnt/4)*4;
	int M=cnt/4;
	for(int i=1;i<LOG;++i){
		for(int a=1;a<=n;++a){
			for(int b=1;b<=m;++b){
				jp[a][b][i]=jp[jp[a][b][i-1].first][jp[a][b][i-1].second][i-1];
			}
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) arr[i][j]=org[i][j];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!arr[i][j]) continue;
			pii curr={i,j};
			int dist=0;
			for(int l=LOG-1;l>=0;--l){
				if(dist+(1<<l)<=M){
					dist+=(1<<l);
					curr={jp[curr.first][curr.second][l].first,jp[curr.first][curr.second][l].second};
				}
			}
			org[curr.first][curr.second]=arr[i][j];
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) arr[i][j]=org[i][j];
	for(int i=ext+2+cnt;i<(int)yas.size();++i){
		if(yas[i]=='P') turnP();
		if(yas[i]=='L') turnL();
		if(yas[i]=='G') turnG();
		if(yas[i]=='D') turnD();
	}
	print_board();
}
