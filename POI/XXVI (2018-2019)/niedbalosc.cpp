//Task statement: szkopul.edu.pl/problemset/problem/PIWHXi6DUtOUJJ0Z2KFUCuYI/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+7,INF=1e9+7;
string s1,s2;
int rA[2][SIZE],rC[2][SIZE],rG[2][SIZE],rT[2][SIZE];
int lA[2][SIZE],lC[2][SIZE],lG[2][SIZE],lT[2][SIZE];
struct letter{
	int l1,r1,l2,r2;
	char c;
};
list<letter> arr;
letter l(int l1,int r1,int l2,int r2,char c){
	letter temp;
	temp.l1=l1;
	temp.r1=r1;
	temp.l2=l2;
	temp.r2=r2;
	temp.c=c;
	return temp;
}
int get_available(int l1,int r1,int l2,int r2){
	if(l1>s1.size()||l2>s2.size()) return 0;
	if(rA[0][l1]<=r1&&rA[1][l2]<=r2) return 1;
	if(rC[0][l1]<=r1&&rC[1][l2]<=r2) return 2;
	if(rG[0][l1]<=r1&&rG[1][l2]<=r2) return 3;
	if(rT[0][l1]<=r1&&rT[1][l2]<=r2) return 4;
	return 0;
}
void change(list<letter>::iterator it,int l1,int l2){
	char c=(*it).c;
	if(c=='A'){
		(*it).l1=rA[0][l1];
		(*it).l2=rA[1][l2];
	}else if(c=='C'){
		(*it).l1=rC[0][l1];
		(*it).l2=rC[1][l2];
	}else if(c=='G'){
		(*it).l1=rG[0][l1];
		(*it).l2=rG[1][l2];
	}else if(c=='T'){
		(*it).l1=rT[0][l1];
		(*it).l2=rT[1][l2];
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>s1>>s2;
	int prevA=0,prevC=0,prevG=0,prevT=0;
	for(int i=0;i<s1.size();++i){
		if(s1[i]=='A') prevA=i+1;
		if(s1[i]=='C') prevC=i+1;
		if(s1[i]=='G') prevG=i+1;
		if(s1[i]=='T') prevT=i+1;
		lA[0][i+1]=prevA;
		lC[0][i+1]=prevC;
		lG[0][i+1]=prevG;
		lT[0][i+1]=prevT;
	}
	prevA=0,prevC=0,prevG=0,prevT=0;
	for(int i=0;i<s2.size();++i){
		if(s2[i]=='A') prevA=i+1;
		if(s2[i]=='C') prevC=i+1;
		if(s2[i]=='G') prevG=i+1;
		if(s2[i]=='T') prevT=i+1;
		lA[1][i+1]=prevA;
		lC[1][i+1]=prevC;
		lG[1][i+1]=prevG;
		lT[1][i+1]=prevT;
	}
	prevA=INF,prevC=INF,prevG=INF,prevT=INF;
	for(int i=s1.size()-1;i>=0;--i){
		if(s1[i]=='A') prevA=i+1;
		if(s1[i]=='C') prevC=i+1;
		if(s1[i]=='G') prevG=i+1;
		if(s1[i]=='T') prevT=i+1;
		rA[0][i+1]=prevA;
		rC[0][i+1]=prevC;
		rG[0][i+1]=prevG;
		rT[0][i+1]=prevT;
	}
	prevA=INF,prevC=INF,prevG=INF,prevT=INF;
	for(int i=s2.size()-1;i>=0;--i){
		if(s2[i]=='A') prevA=i+1;
		if(s2[i]=='C') prevC=i+1;
		if(s2[i]=='G') prevG=i+1;
		if(s2[i]=='T') prevT=i+1;
		rA[1][i+1]=prevA;
		rC[1][i+1]=prevC;
		rG[1][i+1]=prevG;
		rT[1][i+1]=prevT;
	}
	arr.push_back(l(0,0,0,0,'$'));
	arr.push_back(l(INF,s1.size()+1,INF,s2.size()+1,'$'));
	for(list<letter>::iterator it=arr.begin();it!=--arr.end();){
		if(it!=arr.begin()&&(*it).c=='$') break;
		list<letter>::iterator it2=it; ++it2;
		int l1=(*it).l1,l2=(*it).l2;
		int r1=(*it2).r1,r2=(*it2).r2;
		int let=get_available(l1+1,r1-1,l2+1,r2-1);
		switch(let){
			case 0:
				++it;
				change(it2,l1+1,l2+1);
				break;
			case 1:
				l1=rA[0][l1+1];
				l2=rA[1][l2+1];
				r1=lA[0][r1-1];
				r2=lA[1][r2-1];
				arr.insert(it2,l(l1,r1,l2,r2,'A'));
				change(it2,l1+1,l2+1);
				break;
			case 2:
				l1=rC[0][l1+1];
				l2=rC[1][l2+1];
				r1=lC[0][r1-1];
				r2=lC[1][r2-1];
				arr.insert(it2,l(l1,r1,l2,r2,'C'));
				change(it2,l1+1,l2+1);
				break;
			case 3:
				l1=rG[0][l1+1];
				l2=rG[1][l2+1];
				r1=lG[0][r1-1];
				r2=lG[1][r2-1];
				arr.insert(it2,l(l1,r1,l2,r2,'G'));
				change(it2,l1+1,l2+1);
				break;
			case 4:
				l1=rT[0][l1+1];
				l2=rT[1][l2+1];
				r1=lT[0][r1-1];
				r2=lT[1][r2-1];
				arr.insert(it2,l(l1,r1,l2,r2,'T'));
				change(it2,l1+1,l2+1);
				break;
		}
	}
	for(list<letter>::iterator it=++arr.begin();it!=--arr.end();it++){
		cout<<(*it).c;
	}
}
