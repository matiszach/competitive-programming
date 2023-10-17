//Task statement: szkopul.edu.pl/problemset/problem/VbW8KlWy9WK3aYvK55X96X7P/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e3+7;
int q,n,m,a,b;
char arr[SIZE][SIZE],temp[SIZE][SIZE],buf[SIZE][SIZE];
vector<pair<int,int> > stamp;
string s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>q;
	while(q--){
		cin>>n>>m>>a>>b;
		for(int i=1;i<=n;++i){
			cin>>s;
			for(int j=0;j<m;++j){
				arr[i][j+1]=s[j];
				temp[i][j+1]='.';
			}
		}
		pair<int,int> shift={-1,-1};
		int left=m,right=0,down=0;
		for(int i=1;i<=a;++i){
			cin>>s;
			for(int j=0;j<b;++j){
				char z=s[j];
				if(z=='x'){
					if(shift.first==-1&&shift.second==-1) shift={i,j};
					stamp.push_back({i-shift.first,j-shift.second});
					left=min(left,j-shift.second);
					right=max(right,j-shift.second);
					down=max(down,i-shift.first);
				}
			}
		}
		bool ok=1;
		for(int i=1;i<=n;++i){
			if(!ok) break;
			for(int j=1;j<=m;++j){
				if(!ok) break;
				if(arr[i][j]=='x'&&temp[i][j]!='x'&&i+down<=n&&j+left>=1&&j+right<=m){
					for(pair<int,int> p:stamp){
						if(temp[i+p.first][j+p.second]=='x'||arr[i+p.first][j+p.second]!='x'){
							ok=0;
							break;
						}else temp[i+p.first][j+p.second]='x';
					}
				}
			}
		}
		if(ok){
			for(int i=1;i<=n;++i){
				if(!ok) break;
				for(int j=1;j<=m;++j){
					if(!ok) break;
					if(temp[i][j]!=arr[i][j]){
						ok=0;
					}
				}
			}
		}
		cout<<(ok?"TAK\n":"NIE\n");
		stamp.clear();
	}
}
