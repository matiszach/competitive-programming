//Task statement: szkopul.edu.pl/problemset/problem/AB6xXa9zVukjNRe7nvPqxbVQ/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
int n;
long long powers[20][31];
int main(){
	cin>>n;
	int t[]={2,3,5,7,11,13,17,19};
	for(int i:t){
		long long beg=1;
		for(int j=0;j<31;++j){
			powers[i][j]=beg;
			beg*=i;
		}
	}
	long long biggest=1;
	int divs=1;
	vector<pair<long long,int> > v;
	for(int i=0;i<25;++i){
		for(int j=0;j<15;++j){
			for(int k=0;k<10;++k){
				for(int l=0;l<7;++l){
					for(int m=0;m<5;++m){
						for(int o=0;o<4;++o){
							for(int p=0;p<2;++p){
								for(int q=0;q<2;++q){
									int curr_divs=(i+1)*(j+1)*(k+1)*(l+1)*(m+1)*(o+1)*(p+1)*(q+1);
									long long num=1;
									int nums[]={i,j,k,l,m,o,p,q};
									bool nein=false;
									for(int g=0;g<8;++g){
										num*=powers[t[g]][nums[g]];
										if(num>n){
											nein=true;
											break;
										}
									}
									if(nein) continue;
									v.push_back({powers[2][i]*powers[3][j]*powers[5][k]*powers[7][l]*powers[11][m]*powers[13][o]*powers[17][p]*powers[19][q],curr_divs});
								}
							}
						}
					}
				}
			}
		}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();++i){
		if(v[i].first>n) break;
		if(v[i].second>divs){
			biggest=max(biggest,v[i].first);
			divs=v[i].second;
		}
	}
	cout<<biggest<<"\n";
}
