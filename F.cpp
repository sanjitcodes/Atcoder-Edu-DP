// Jai Mata Di..
// 
// @ author : Sanjit Anand (sanjit_15)
// 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag , tree_order_statistics_node_update>; 
template<typename T>
using order_multiset = tree<T,null_type,less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int             long long
#define PI              3.1415926535897932384626
#define gc              getchar_unlocked
#define fo(i,n)         for(i=0;i<n;i++)
#define rep(i,k,n)      for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb              push_back
#define pf              pop_front
#define ppb             pop_back
#define ppf             pop_front
#define F               first
#define S               second
#define trav(it, a)     for(auto it = a.begin(); it != a.end(); it++)
#define ppc             __builtin_popcount
#define ppcll           __builtin_popcountll
#define ctzll           __builtin_ctzll
#define clzll           __builtin_clzll
#define all(x)          x.begin(),x.end()

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
typedef set<int>        si;
typedef list<int>       li;
typedef tuple<int>      tpi;

const long long INF = 1e18;
const long long MOD = 1000000007;
const long long MM = 998244353;

const int N = 2000010;

int mpow(int base, int exp, int m);
int gcd(int a, int b);

int dp[3005][3005];

string get_LCS(string& a, string& b, int l){
	int i=0, j=0;
	string LCS = "";
	while(l){
		if(a[i]==b[j]){
			LCS += a[i];
			i++;
			j++;
			l--;
		}
		else{
			if(dp[i][j+1] > dp[i+1][j]){
				j++;
			}
			else{
				i++;
			}
		}
	}
	return LCS;
}

int len_lcs(string& a, string& b, int i, int j){
	if(i>=a.length() || j>=b.length()){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(a[i] == b[j]){
		dp[i][j] = 1+len_lcs(a, b, i+1, j+1);
	}
	else{
		dp[i][j] = max(len_lcs(a, b, i+1, j),len_lcs(a, b, i, j+1));
	}
	return dp[i][j];

}

void solve() {
    int i, j, n, k;
    string a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    int len = len_lcs(a, b, 0, 0);
    cout << get_LCS(a, b, len) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    #ifdef NCR
        pmain();
    #endif
    #ifdef SIEVE
        sieve();
    #endif

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int gcd(int a, int b){
    return b==0 ? a : gcd(b,a%b);
}

int mpow(int base, int exp, int m=MOD) {
  base %= m;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % m;
    base = ((long long)base * base) % m;
    exp >>= 1;
  }
  return result;
}