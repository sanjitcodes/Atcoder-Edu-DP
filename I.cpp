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

const int N = 3005;

int mpow(int base, int exp, int m);
int gcd(int a, int b);

double dp[N][N];

double helper(vector<double>& p, int n, int x){
	if(x == 0){
		return 1;
	}
	if(n == 0){
		return 0;
	}
	if(dp[n][x] > -0.9){
		return dp[n][x];
    }
	dp[n][x] = p[n]*helper(p, n-1,x-1) + (1-p[n])*helper(p, n-1,x);

	return dp[n][x];
}

void solve() {
    int i, j, n, k;
    cin >> n;
    vector<double> p(n+1);
    for(int i=1; i<=n; i++){
    	cin >> p[i];
    }
    memset(dp, -1, sizeof(dp));
    
    double ans = helper(p, n, (n+1)/2);
    cout << fixed << setprecision(10) << ans << "\n";
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