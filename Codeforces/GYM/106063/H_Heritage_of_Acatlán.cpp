#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int mod = 1e9 + 7;
const long double EPS = 1e-10;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 

const int N = 100010;
const int M = 65;
int dp1[N][M];
int dp2[N][M];
int n, m;
string s, t;

int add(int u, int v) {
    u += v;
    if(u >= mod) u -= mod;
    return u;
}

int mult(int u, int v) {
    return u * 1ll * v % mod;
}

void solve() {
    cin >> n >> m;
    cin >> s >> t;
    s = "#" + s;
    t = "#" + t;
    
    dp1[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m + 1; j++)
            dp1[i][j] = dp1[i - 1][j];
        
        for(int j = 1; j <= m; j++)
            if(s[i] == t[j])
                dp1[i][j] = add(dp1[i][j], dp1[i - 1][j - 1]);
    }
    dp2[n + 1][m + 1] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = m + 1; j >= 0; j--)
            dp2[i][j] = dp2[i + 1][j];
        for(int j = m; j >= 1; j--)
            if(s[i] == t[j])
                dp2[i][j] = add(dp2[i][j], dp2[i + 1][j + 1]);
    }

    int ans = dp1[n][m];
    for(int i = 1; i <= n; i++){
        for(int pref = 0; pref <= m; pref++)
            ans = add(ans, mult(25, mult(dp1[i - 1][pref], dp2[i + 1][pref + 1])));
        for(int j = 1; j <= m; j++){
            if(s[i] == t[j]) continue;
            ans = add(ans, mult(dp1[i - 1][j - 1], dp2[i + 1][j + 1]));
        }
    }

    cout << ans << endl;
}

int main(){
    FAST

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}