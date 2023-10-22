#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __int128 ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
string findSum(string str1, string str2) 
{ 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) 
        str.push_back(carry+'0'); 
    reverse(str.begin(), str.end()); 
    return str; 
} 
string division(string number, ll divisor)
{ 
    string ans; 
    int idx = 0; 
    ll temp = number[idx] - '0'; 
    while (temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
    while ((int)number.size() > idx) 
    { 
        ans += (temp / divisor) + '0'; 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
    if (ans.length() == 0) 
        return "0"; 
    return ans; 
} 
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;        
        for (int j=len2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
    if (i == -1)
    return "0";
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
    return s;
}
bool isSmaller(string str1, string str2) 
{ 
    int n1 = str1.length(), n2 = str2.length(); 
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false;  
    for (int i=0; i<n1; i++) 
    if (str1[i] < str2[i]) 
        return true; 
    else if (str1[i] > str2[i]) 
        return false; 
    return false; 
} 
string findDiff(string str1, string str2) 
{ 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
    string str = "";  
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end());     
    int carry = 0; 
    for (int i=0; i<n2; i++) 
    { 
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str.push_back(sub + '0'); 
    } 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0;       
        str.push_back(sub + '0'); 
    } 
    reverse(str.begin(), str.end());  
    return str; 
} 
ll to_int(string A){
	reverse(A.begin(),A.end());
	ll curr=1;
	ll res=0;
	for(char &c:A){
		res+=(c-'0')*curr;
		curr*=10;
	}
	return res;
}
string normalize(string A){
	int N=(int)A.size();
	string res="";
	bool started=0;
	for(int i=0;i<N;++i){
		if(A[i]!='0') started=1;
		if(started||i==N-1) res+=A[i];
	}
	return res;
}
string bigDivision(string A,string B){
	string l="1",r="",mid="";
	for(int i=0;i<min((int)A.size(),(int)A.size()-(int)B.size()+2);++i) r+=A[i];
	for(int i=0;i<min((int)r.size(),(int)A.size()-(int)B.size()-2);++i) l+="0";
	while(isSmaller(l,r)){
		mid=division(findSum(findSum(l,r),"1"),2);
		string tmp=multiply(B,mid);
		if(!isSmaller(A,tmp)) l=mid;
		else r=normalize(findDiff(mid,"1"));
	}
	return l;
}
string MOD(string A,string B){
	string x=bigDivision(A,B);
	string y=multiply(x,B);
	return normalize(findDiff(A,y));
}
string GCD(string A,string B){
	if(A=="0") return B;
	if(B=="0") return A;
	string tmp="";
	while(A!="0"){
		tmp=A;
		A=MOD(B,A);
		B=tmp;
	}
	return B;
}
string to_str(ll A){
	string res="";
	while(A>0){
		res+=char(A%10+'0');
		A/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
struct frac{
	string a,b;
	frac(){
		a="0"; b="1";
	}
	frac(string A,string B){
		a=A; b=B;
	}
	frac operator+(frac A){
		string g=GCD(b,A.b);
		if(isSmaller(g,"10000000000000000000000000000000000000")){
			string tmp=division(A.b,to_int(g));
			return frac(findSum(multiply(a,tmp),multiply(A.a,division(b,to_int(g)))),multiply(b,tmp));
		}
		string tmp=bigDivision(A.b,g);
		return frac(findSum(multiply(a,tmp),multiply(A.a,bigDivision(b,g))),multiply(b,tmp));
	}
	frac operator/(string A){
		string g=GCD(a,A);
		if(isSmaller(g,"10000000000000000000000000000000000000")){
			return frac(division(a,to_int(g)),multiply(b,division(A,to_int(g))));
		}
		return frac(bigDivision(a,g),multiply(b,bigDivision(A,g)));
	}
};
const int MAXN=107;
vector<int> G[MAXN],R[MAXN];
frac f[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i){
		int x; cin>>x;
		for(int j=0;j<x;++j){
			int l; cin>>l;
			G[i].pb(l);
			R[l].pb(i);
		}
	}
	f[1]=frac("1","1");
	for(int i=1;i<=n;++i){
		for(int &v:R[i]){
			f[i]=f[i]+f[v];
		}
		if(!G[i].empty()) f[i]=f[i]/to_str((int)G[i].size());
	}
	string ans="1";
	for(int i=2;i<=n;++i){
		string g=GCD(ans,f[i].b);
		if(isSmaller(g,"10000000000000000000000000000000000000")){
			ans=division(ans,to_int(g));
		}else ans=bigDivision(ans,g);
		ans=multiply(ans,f[i].b);
	}
	cout<<ans<<"\n";
}
