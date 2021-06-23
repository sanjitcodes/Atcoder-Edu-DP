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
#define sz(x)           x.size()

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

int mpow(int base, int exp, int m);
int gcd(int a, int b);

const int N = 2000010;

int helper(vector<int> &v, int n, int k){

	int dp[n+2][k+2];

	for(int j=0; j<=k; j++){
		dp[1][j] = (j > v[1]) ? 0 : 1;
	}

	for(int i=2; i<=n; i++){
		for(int j=0; j<=k; j++){
			if(j==0){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = (MOD + dp[i][j-1] + dp[i-1][j] - ((j-v[i] >= 1) ? (dp[i-1][j-v[i]-1]) : 0)) % MOD;
			}
		}
	}
	return dp[n][k];
}

void solve() {
    int i, j, n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
    	cin >> v[i];
    } 
    cout << helper(v, n, k) << "\n";
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