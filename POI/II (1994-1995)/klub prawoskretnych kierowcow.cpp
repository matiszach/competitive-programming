//Task statement: szkopul.edu.pl/problemset/problem/BsP4m48sclpwBWnsX1XKhL-4/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=107,INF=1e9+7;
int n,m;
bool arr[SIZE][SIZE],visited[SIZE][SIZE][4];
int dist[SIZE][SIZE][4];
int next_v[SIZE][SIZE][4];
int cx1,cx2,cy1,cy2;
queue<pair<pair<int,int>,int> > Q;
int Y[]{-1,0,1,0},X[]{0,1,0,-1};
vector<pair<int,int> > path;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			char c;
			cin>>c;
			if(c=='1') arr[i][j]=1;
			for(int k=0;k<4;++k) dist[i][j][k]=INF;
		}
	}
	cin>>cx1>>cy1>>cx2>>cy2;
	pair<int,int> A={cx1,cy1},B={cx2,cy2};
	for(int i=0;i<=n;++i){
		arr[i][0]=1; arr[i][m+1]=1;
	}
	for(int i=0;i<=m;++i){
		arr[0][i]=1; arr[n+1][i]=1;
	}
	if(arr[A.first][A.second]||arr[B.first][B.second]){
		cout<<"NIE\n";
		return 0;
	}
	for(int i=0;i<4;++i){
		visited[A.first][A.second][i]=1;
		dist[A.first][A.second][i]=1;
		Q.push({A,i});
	}
	int counter=0;
	while(!Q.empty()){
		pair<pair<int,int>,int> v=Q.front();
		++counter;
		Q.pop();
		int forward=v.second,right=(forward+1)%4;
		pair<int,int> vert=v.first;
		pair<int,int> f={vert.first+Y[forward],vert.second+X[forward]};
		pair<int,int> r={vert.first+Y[right],vert.second+X[right]};
		if(!arr[f.first][f.second]&&!visited[f.first][f.second][forward]){
			visited[f.first][f.second][forward]=1;
			dist[f.first][f.second][forward]=dist[vert.first][vert.second][forward]+1;
			next_v[vert.first][vert.second][(forward+2)%4]=(forward+2)%4;
			Q.push({f,forward});
		}
		if(!arr[r.first][r.second]&&!visited[r.first][r.second][right]){
			visited[r.first][r.second][right]=1;
			dist[r.first][r.second][right]=dist[vert.first][vert.second][forward]+1;
			next_v[vert.first][vert.second][(right+2)%4]=(forward+2)%4;
			Q.push({r,right});
		}
	}
	int ans=INF;
	for(int i=0;i<4;++i) ans=min(ans,dist[B.first][B.second][i]);
	if(ans==INF){
		cout<<"NIE\n";
		return 0;
	}
	cout<<ans<<"\n";
	int curr_dir=0;
	for(int i=0;i<4;++i){
		if(ans==dist[B.first][B.second][i]) curr_dir=(i+2)%4;
	}
	while(B!=A){
		path.push_back(B);
		B.first+=Y[curr_dir]; B.second+=X[curr_dir];
		curr_dir=next_v[B.first][B.second][curr_dir];
	}
	path.push_back(A);
	for(int i=path.size()-1;i>=0;--i) cout<<path[i].first<<" "<<path[i].second<<"\n";
}
