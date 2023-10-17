//Task statement: szkopul.edu.pl/problemset/problem/w3anjkOGa2eMEBt_-GYEosat/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e5+5;
int n,z;
int inner[SIZE],outer[SIZE],debt[SIZE*3];
string s1,s2;
set<int> zeros,nines;
int zeros_dict[SIZE],nines_dict[SIZE];
char c;
int R=0;
int opers=0;
void single_insert(int pos,int val){
	debt[pos+R]+=val;
}
void update(int a,int b,int u,int lo,int hi,int v){
	if(a==lo&&b==hi){
		debt[u]+=v;
		return;
	}if (b<=a) return;
	int mid=(lo+hi)/2;
	update(a,min(b,mid),2*u,lo,mid,v);
	update(max(a,mid),b,2*u+1,mid,hi,v);
}
int get_val(int pos){
	if(pos<0||pos>n) return -1;
	int total=0;
	int curr=pos+R;
	while(curr!=0){
		total+=debt[curr];
		curr/=2;
	}
	return total;
}
void countR(){
	R=1;
	while(R<n) R*=2;
}
int compute(int x,int pos){
	return x-get_val(pos);
}
void zeros_single(int pos){
	int pos1,pos2,pos3;
	pos1=get_val(pos-1);
	pos2=get_val(pos);
	pos3=get_val(pos+1);
	if(pos1==0&&pos2==0&&pos3==0){
		zeros_dict[*--zeros.lower_bound(pos)]=zeros_dict[pos+1];
		zeros.erase(pos+1);
		zeros_dict[pos+1]=-1;
	}else if(pos1==0&&pos2==0){
		zeros_dict[*--zeros.lower_bound(pos)]=pos;
	}else if(pos2==0&&pos3==0){
		zeros.insert(pos);
		zeros_dict[pos]=zeros_dict[pos+1];
		zeros_dict[pos+1]=-1;
		zeros.erase(pos+1);
	}else if(pos1==0&&pos3==0){
		if(zeros_dict[*--zeros.lower_bound(pos)]>pos){
			zeros.insert(pos+1);
			zeros_dict[pos+1]=zeros_dict[*--zeros.lower_bound(pos)];
			zeros_dict[*--zeros.lower_bound(pos)]=pos-1;
		}
	}
	if(pos1==9&&pos2!=9&&pos3==9){
		if(nines_dict[*--nines.lower_bound(pos)]>pos){
			nines.insert(pos+1);
			nines_dict[pos+1]=nines_dict[*--nines.lower_bound(pos)];
			nines_dict[*--nines.lower_bound(pos)]=pos-1;
		}
	}
	if(pos1!=0&&pos2==0&&pos3!=0){
		zeros.insert(pos);
		zeros_dict[pos]=pos;
	}
	if(pos1!=9&&pos3!=9){
		if(pos2!=9&&nines.find(pos)!=nines.end()){
			nines.erase(pos);
			nines_dict[pos]=-1;
		}else if(pos2==9){
			nines.insert(pos);
			nines_dict[pos]=pos;
		}
	}
	if(pos1==9&&pos3==9){
		set<int>::iterator it=--nines.lower_bound(pos);
		if(nines_dict[*it]>pos){
			nines_dict[*it]=pos-1;
			nines.insert(pos+1);
			nines_dict[pos+1]=nines_dict[*it];
		}
	}else if(pos1==9){
		set<int>::iterator it=--nines.lower_bound(pos);
		if(nines_dict[*it]==pos){
			nines_dict[*it]=pos-1;
		}
	}else if(pos3==9){
		if(nines.find(pos)!=nines.end()){
			nines.insert(pos+1);
			nines_dict[pos+1]=nines_dict[pos];
			nines.erase(pos);
			nines_dict[pos]=-1;
		}
	}
}
void zeros_multi(int pos1,int pos2){
	if(get_val(pos1)==0&&get_val(pos1-1)==0){
		if(pos1>0)
		++zeros_dict[*--zeros.lower_bound(pos1)];
	}else if(get_val(pos1-1)==9){
		if(pos1>0){
			set<int>::iterator it=--nines.lower_bound(pos1);
			if(nines_dict[*it]>=pos1){
				--nines_dict[*it];
			}
		}
	}else if(get_val(pos1)==0){
		zeros.insert(pos1);
		zeros_dict[pos1]=pos1;
	}
	if(nines.find(pos1)!=nines.end()){
		nines.erase(pos1);
		nines_dict[pos1]=-1;
	}
	if(get_val(pos2)==9&&get_val(pos2-1)==9){
		++nines_dict[*--nines.lower_bound(pos2)];
		if(get_val(pos2+1)==9){
			nines_dict[*--nines.lower_bound(pos2)]=nines_dict[pos2+1];
			nines.erase(pos2+1);
			nines_dict[pos2+1]=-1;
		}
	}
	else if(get_val(pos2)==9&&get_val(pos2+1)==9){
		nines.insert(pos2);
		nines_dict[pos2]=nines_dict[pos2+1];
		nines.erase(pos2+1);
		nines_dict[pos2+1]=-1;
	}
	else if(get_val(pos2)==9){
		nines.insert(pos2);
		nines_dict[pos2]=pos2;
	}
	if(zeros.find(pos2)!=zeros.end()){
		if(get_val(pos2+1)==0){
			zeros.insert(pos2+1);
			zeros_dict[pos2+1]=zeros_dict[pos2];
		}
		zeros.erase(pos2);
		zeros_dict[pos2]=-1;
	}
	if(pos1>0){
		if(get_val(pos1)==0&&get_val(pos1-1)!=0){
			zeros.insert(pos1);
			zeros_dict[pos1]=pos1;
		}
	}else{
		if(get_val(pos1)==0){
			zeros.insert(pos1);
			zeros_dict[pos1]=pos1;
		}
	}
}
void nines_single(int pos){
	int pos1,pos2,pos3;
	pos1=get_val(pos-1);
	pos2=get_val(pos);
	pos3=get_val(pos+1);
	if(pos1==9&&pos2==9&&pos3==9){
		nines_dict[*--nines.lower_bound(pos)]=nines_dict[pos+1];
		nines.erase(pos+1);
		nines_dict[pos+1]=-1;
	}else if(pos1==9&&pos2==9){
		nines_dict[*--nines.lower_bound(pos)]=pos;
	}else if(pos2==9&&pos3==9){
		nines.insert(pos);
		nines_dict[pos]=nines_dict[pos+1];
		nines_dict[pos+1]=-1;
		nines.erase(pos+1);
	}else if(pos1==9&&pos3==9){
		if(nines_dict[*--nines.lower_bound(pos)]>pos)
		{
			nines.insert(pos+1);
			nines_dict[pos+1]=nines_dict[*--nines.lower_bound(pos)];
			nines_dict[*--nines.lower_bound(pos)]=pos-1;
		}
	}
	if(pos1==0&&pos2!=0&&pos3==0){
		if(zeros_dict[*--zeros.lower_bound(pos)]>pos){
			zeros.insert(pos+1);
			zeros_dict[pos+1]=zeros_dict[*--zeros.lower_bound(pos)];
			zeros_dict[*--zeros.lower_bound(pos)]=pos-1;
		}
	}
	if(pos1!=9&&pos2==9&&pos3!=9){
		nines.insert(pos);
		nines_dict[pos]=pos;
	}
	if(pos1!=0&&pos3!=0){
		if(pos2!=0&&zeros.find(pos)!=zeros.end()){
			zeros.erase(pos);
			zeros_dict[pos]=-1;
		}else if(pos2==0){
			zeros.insert(pos);
			zeros_dict[pos]=pos;
		}
	}
	if(pos1==0&&pos3==0){
		set<int>::iterator it=--zeros.lower_bound(pos);
		if(zeros_dict[*it]>pos){
			zeros_dict[*it]=pos-1;
			zeros.insert(pos+1);
			zeros_dict[pos+1]=zeros_dict[*it];
		}
	}else if(pos1==0){
		set<int>::iterator it=--zeros.lower_bound(pos);
		if(zeros_dict[*it]==pos){
			zeros_dict[*it]=pos-1;
		}
	}else if(pos3==0){
		if(zeros.find(pos)!=zeros.end()){
			zeros.insert(pos+1);
			zeros_dict[pos+1]=zeros_dict[pos];
			zeros.erase(pos);
			zeros_dict[pos]=-1;
		}
	}
}
void nines_multi(int pos1,int pos2){
	if(get_val(pos1)==9&&get_val(pos1-1)==9){
		if(pos1>0)
		++nines_dict[*--nines.lower_bound(pos1)];
	}else if(get_val(pos1-1)==0){
		if(pos1>0){
			set<int>::iterator it=--zeros.lower_bound(pos1);
			if(zeros_dict[*it]>=pos1){
				--zeros_dict[*it];
			}
		}
	}else if(get_val(pos1)==9){
		nines.insert(pos1);
		nines_dict[pos1]=pos1;
	}
	if(zeros.find(pos1)!=nines.end()){
		zeros.erase(pos1);
		zeros_dict[pos1]=-1;
	}
	if(get_val(pos2)==0&&get_val(pos2-1)==0){
		++zeros_dict[*--zeros.lower_bound(pos2)];
		if(get_val(pos2+1)==0){
			zeros_dict[*--zeros.lower_bound(pos2)]=zeros_dict[pos2+1];
			zeros.erase(pos2+1);
			zeros_dict[pos2+1]=-1;
		}
	}
	else if(get_val(pos2)==0&&get_val(pos2+1)==0){
		zeros.insert(pos2);
		zeros_dict[pos2]=zeros_dict[pos2+1];
		zeros.erase(pos2+1);
		zeros_dict[pos2+1]=-1;
	}
	else if(get_val(pos2)==0){
		zeros.insert(pos2);
		zeros_dict[pos2]=pos2;
	}
	if(nines.find(pos2)!=nines.end()){
		if(get_val(pos2+1)==9){
			nines.insert(pos2+1);
			nines_dict[pos2+1]=nines_dict[pos2];
		}
		nines.erase(pos2);
		nines_dict[pos2]=-1;
	}
	if(pos1>0){
		if(get_val(pos1)==9&&get_val(pos1-1)!=9){
			nines.insert(pos1);
			nines_dict[pos1]=pos1;
		}
	}else{
		if(get_val(pos1)==9){
			nines.insert(pos1);
			nines_dict[pos1]=pos1;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>z;
	countR();
	--n;
	cin>>s1>>s2;
	for(int i=1;i<=n;++i){
		inner[i]=int(s1[i-1]-48);
		outer[i]=int(s2[i-1]-48);
	}
	int rest=0,val=0;
	for(int i=n;i>0;--i){
		val=(inner[i]+outer[i]+rest);
		debt[i+R]=val%10;
		rest=val/10;
	}
	debt[R]=rest;
	int start=-1,end=-1;
	if(debt[R]==0) start=0;
	if(start==0&&debt[R+1]!=0){
		zeros.insert(0);
		zeros_dict[start]=0;
		start=-1;
	}
	for(int i=1;i<=n;++i){
		if(debt[i+R]==0&&start==-1){
			start=i;
			end=i;
		}else if(debt[i+R]==0){
			end=i;
		}else if(debt[i-1+R]==0&&debt[i+R]!=0){
			zeros.insert(start);
			zeros_dict[start]=end;
			start=-1;
			end=-1;
		}
	}
	if(start!=-1){
		zeros.insert(start);
		zeros_dict[start]=end;
	}
	start=-1;
	end=-1;
	if(debt[R]==9) start=0;
	if(start==9&&debt[R+1]!=9){
		nines.insert(0);
		nines_dict[start]=0;
		start=-1;
	}
	for(int i=1;i<=n;++i){
		if(debt[i+R]==9&&start==-1){
			start=i;
			end=i;
		}else if(debt[i+R]==9){
			end=i;
		}else if(debt[i-1+R]==9&&debt[i+R]!=9){
			nines.insert(start);
			nines_dict[start]=end;
			start=-1;
			end=-1;
		}
	}
	if(start!=-1){
		nines.insert(start);
		nines_dict[start]=end;
	}
	debt[n+1+R]=-1;
	int counter=0;
	for(int q=0;q<z;++q){
		cin>>c;
		if(c=='S'){
			++counter;
			int x;
			cin>>x;
			x=n-x+1;
			cout<<get_val(x)<<"\n";
		}else if(c=='W'){
			//inner
			int pos,val,prev;
			cin>>pos>>val;
			pos=n-pos+1;
			prev=inner[pos];
			inner[pos]=val;
			if(prev<val){
				int diff=val-prev;
				int num=get_val(pos);
				if(diff+num<=9){
					single_insert(pos,compute((diff+num)%10,pos));
					nines_single(pos);
				}else{
					if(get_val(pos-1)<9){
						single_insert(pos-1,1);
						single_insert(pos,compute((diff+num)%10,pos));
						nines_multi(pos-1,pos);
					}else{
						set<int>::iterator it=--nines.lower_bound(pos);
						int start=*it;
						int end=nines_dict[start];
						if(end<=pos){
							if(start!=0||end!=0)
							update(start,pos,1,0,R,-9);
							single_insert(start-1,1);
							single_insert(pos,compute((diff+num)%10,pos));
							zeros.insert(start);
							zeros_dict[start]=pos-1;
							nines.erase(start);
							nines_dict[start]=-1;
							nines_multi(start-1,pos);
						}else{
							if(start!=0||end!=0)
							update(start,pos,1,0,R,-9);
							single_insert(start-1,1);
							single_insert(pos,compute((diff+num)%10,pos));
							zeros.insert(start);
							zeros_dict[start]=pos-1;
							nines.erase(start);
							nines.insert(pos+1);
							nines_dict[pos+1]=nines_dict[start];
							nines_dict[start]=-1;
							nines_multi(start-1,pos);
						}
					}
				}
			}else if(prev>val){
				int diff=prev-val;
				int num=get_val(pos);
				if(num-diff>=0){
					single_insert(pos,compute((num-diff+10)%10,pos));
					zeros_single(pos);
				}else{
					if(get_val(pos-1)>0){
						single_insert(pos-1,-1);
						single_insert(pos,compute((num-diff+10)%10,pos));
						zeros_multi(pos-1,pos);
					}else{
						set<int>::iterator it=--zeros.lower_bound(pos);
						int start=*it;
						int end=zeros_dict[start];
						if(end<=pos){
							if(start!=0||end!=0)
							update(start,pos,1,0,R,9);
							single_insert(start-1,-1);
							single_insert(pos,compute((num-diff+10)%10,pos));
							nines.insert(start);
							nines_dict[start]=pos-1;
							zeros.erase(start);
							zeros_dict[start]=-1;
							zeros_multi(start-1,pos);
						}else{
							if(start!=0||end!=0)
							update(start,pos,1,0,R,9);
							single_insert(start-1,-1);
							single_insert(pos,compute((num-diff+10)%10,pos));
							nines.insert(start);
							nines_dict[start]=pos-1;
							zeros.erase(start);
							zeros.insert(pos+1);
							zeros_dict[pos+1]=zeros_dict[start];
							zeros_dict[start]=-1;
							zeros_multi(start-1,pos);
						}
					}
				}
			}
		}else if(c=='Z'){
			int pos,val,prev;
			cin>>pos>>val;
			pos=n-pos+1;
			prev=outer[pos];
			outer[pos]=val;
			if(prev<val){
				int diff=val-prev;
				int num=get_val(pos);
				if(diff+num<=9){
					single_insert(pos,compute((diff+num)%10,pos));
					nines_single(pos);
				}else{
					if(get_val(pos-1)<9){
						single_insert(pos-1,1);
						single_insert(pos,compute((diff+num)%10,pos));
						nines_multi(pos-1,pos);
					}else{
						set<int>::iterator it=--nines.lower_bound(pos);
						int start=*it;
						int end=nines_dict[start];
						if(end<=pos){
							if(start!=0||end!=0)
							update(start,pos,1,0,R,-9);
							single_insert(start-1,1);
							single_insert(pos,compute((diff+num)%10,pos));
							zeros.insert(start);
							zeros_dict[start]=pos-1;
							nines.erase(start);
							nines_dict[start]=-1;
							nines_multi(start-1,pos);
						}else{
							if(start!=0||end!=0)
							update(start,pos,1,0,R,-9);
							single_insert(start-1,1);
							single_insert(pos,compute((diff+num)%10,pos));
							zeros.insert(start);
							zeros_dict[start]=pos-1;
							nines.erase(start);
							nines.insert(pos+1);
							nines_dict[pos+1]=nines_dict[start];
							nines_dict[start]=-1;
							nines_multi(start-1,pos);
						}
					}
				}
			}else if(prev>val){
				int diff=prev-val;
				int num=get_val(pos);
				if(num-diff>=0){
					single_insert(pos,compute((num-diff+10)%10,pos));
					zeros_single(pos);
				}else{
					if(get_val(pos-1)>0){
						single_insert(pos-1,-1);
						single_insert(pos,compute((num-diff+10)%10,pos));
						zeros_multi(pos-1,pos);
					}else{
						set<int>::iterator it=--zeros.lower_bound(pos);
						int start=*it;
						int end=zeros_dict[start];
						if(end<=pos){
							if(start!=0||end!=0)
							update(start,pos,1,0,R,9);
							single_insert(start-1,-1);
							single_insert(pos,compute((num-diff+10)%10,pos));
							nines.insert(start);
							nines_dict[start]=pos-1;
							zeros.erase(start);
							zeros_dict[start]=-1;
							zeros_multi(start-1,pos);
						}else{
							if(start!=0||end!=0)
							update(start,pos,1,0,R,9);
							single_insert(start-1,-1);
							single_insert(pos,compute((num-diff+10)%10,pos));
							nines.insert(start);
							nines_dict[start]=pos-1;
							zeros.erase(start);
							zeros.insert(pos+1);
							zeros_dict[pos+1]=zeros_dict[start];
							zeros_dict[start]=-1;
							zeros_multi(start-1,pos);
						}
					}
				}
			}
		}
	}
}
