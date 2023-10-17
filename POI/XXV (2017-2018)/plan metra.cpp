//Task statement: szkopul.edu.pl/problemset/problem/vvd6w7n7EXFVEg3nkqGxEirV/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=5e5+7;
int n;
int d[SIZE],l[SIZE];
int path[4*SIZE];
vector<pair<int,int> > conns_1,conns_n;
vector<pair<int,int> > path_conns[4*SIZE];
bitset<SIZE> used;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	if(n==1){
		cout<<"TAK\n";
		return 0;
	}
	if(n==2){
		cout<<"TAK\n1 2 1\n";
		return 0;
	}
	for(int i=2;i<=n-1;++i) cin>>d[i];
	for(int i=2;i<=n-1;++i) cin>>l[i];
	int diff=abs(d[2]-l[2]);
	bool ok=1;
	for(int i=3;i<=n-1;++i){
		if(diff!=abs(d[i]-l[i])) ok=0;
	}
	if(ok){
		if(diff>0){
			cout<<"TAK\n";
			cout<<"1 "<<n<<" "<<diff<<"\n";
			for(int i=2;i<=n-1;++i){
				if(d[i]>l[i]) cout<<n<<" "<<i<<" "<<l[i]<<"\n";
				else cout<<"1 "<<i<<" "<<d[i]<<"\n";
			}
			return 0;
		}
	}
	int path_len=d[2]+l[2];
	for(int i=3;i<=n-1;++i){
		path_len=min(path_len,d[i]+l[i]);
	}
	path[0]=1;
	path[path_len]=n;
	for(int i=2;i<=n-1;++i){
		if(d[i]+l[i]==path_len){
			if(path[d[i]]==0&&d[i]!=path_len&&l[i]!=path_len){
				path[d[i]]=i;
			}else{
				cout<<"NIE\n";
				return 0;
			}
			used[i]=1;
		}
	}
	for(int i=2;i<=n-1;++i){
		if(abs(d[i]-l[i])==path_len){
			if(d[i]>l[i]){
				conns_n.push_back({i,d[i]-path_len});
			}else conns_1.push_back({i,l[i]-path_len});
			used[i]=1;
		}
	}
	for(int i=2;i<=n-1;++i){
		if(!used[i]){
			bool found=0;
			if(d[i]>l[i]){
				int val=d[i]-l[i];
				if((path_len-val)%2==0&&path_len>val){
					int idx=(path_len-val)/2+val;
					if(idx<path_len){
						if(path[idx]!=0){
							path_conns[idx].push_back({i,d[i]-idx});
							used[i]=1;
							found=1;
						}
					}
				}
			}else{
				int val=l[i]-d[i];
				if((path_len-val)%2==0&&path_len>val){
					int idx=(path_len-val)/2;
					if(idx<path_len){
						if(path[idx]!=0){
							path_conns[idx].push_back({i,d[i]-idx});
							used[i]=1;
							found=1;
						}
					}
				}
			}
			if(!found){
				cout<<"NIE\n";
				return 0;
			}
		}
	}
	cout<<"TAK\n";
	for(pair<int,int> p:conns_1){
		cout<<"1 "<<p.first<<" "<<p.second<<"\n";
	}
	for(pair<int,int> p:conns_n){
		cout<<n<<" "<<p.first<<" "<<p.second<<"\n";
	}
	for(int i=1;i<=path_len-1;++i){
		for(pair<int,int> p:path_conns[i]){
			cout<<path[i]<<" "<<p.first<<" "<<p.second<<"\n";
		}
	}
	int len=1,prev=1;
	for(int i=1;i<=path_len+1;++i){
		if(path[i]!=0){
			cout<<prev<<" "<<path[i]<<" "<<len<<"\n";
			len=1;
			prev=path[i];
		}else ++len;
	}
}
