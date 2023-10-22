// Task statement: https://www.spoj.com/problems/MAXMATCH/
// *Author Mateusz Kowalski*
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
// fft implementation is from cp-algorithms
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + (int)b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
int main()
{
	ios_base::sync_with_stdio(0);
	string s; cin>>s;
	int n=s.size();
	vector<int> cnt(3*n,0);
	//a
	vector<int> A(n,0),B(n,0);
	for(int i=0;i<n;++i){
		A[i]=B[i]=(s[i]=='a');
	}
	reverse(B.begin(),B.end());
	vector<int> C=multiply(A,B);
	for(int i=0;i<(int)C.size();++i) cnt[i]+=C[i];
	A.assign(n,0); B.assign(n,0);
	//b
	for(int i=0;i<n;++i){
		A[i]=B[i]=(s[i]=='b');
	}
	reverse(B.begin(),B.end());
	C=multiply(A,B);
	for(int i=0;i<(int)C.size();++i) cnt[i]+=C[i];
	A.assign(n,0); B.assign(n,0);
	//c
	for(int i=0;i<n;++i){
		A[i]=B[i]=(s[i]=='c');
	}
	reverse(B.begin(),B.end());
	C=multiply(A,B);
	for(int i=0;i<(int)C.size();++i) cnt[i]+=C[i];
	int maxi=0;
	for(int i=0;i<n-1;++i) maxi=max(maxi,cnt[i]);
	vector<int> res;
	for(int i=0;i<n-1;++i) if(cnt[i]==maxi) res.pb(n-1-i);
	reverse(res.begin(),res.end());
	cout<<maxi<<"\n";
	for(int v:res) cout<<v<<" ";
	cout<<"\n";
}
