#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 998244353;
const int N_Max = 2e5 + 5;
const int Nax = 15;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
 
const int N = 1010;
int a[N][N];
int mx[N][N];
int pref_row[N][N];
int pref_col[N][N];
int n, m, q;

void solve() {  
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];    
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            pref_row[i][j] = pref_row[i][j - 1] + a[i][j];

    
    for(int i = 1 ; i <= m; i++)
        for(int j = 1; j <= n; j++)
            pref_col[j][i] = pref_col[j - 1][i] + a[j][i];

    
    for(int y = 1; y <= m; y++){
        int mx_en = 0; 
        for(int x = 1; x <= n; x++){
            if(a[x][y] == 0) continue;
            int lo = 1, ro = y, cur = 1;
            while(lo <= ro) {
                int md = (lo + ro)/2;
                if(pref_row[x][y] - pref_row[x][y - md] == md) {
                    cur = md;
                    lo = md + 1;
                }else 
                    ro = md - 1;
            }
            
            int mn = min(mx_en, cur);
            mx[x][y] = max(mx[x][y], mn);
            mx_en = max(mx_en, cur);
        }
    }
    for(int x = 1; x <= n; x++){
        int mx_en = 0;
        for(int y = 1; y <= m; y++) {
            if(a[x][y] == 0) continue;
            int lo = 1, ro = x, cur = 1;
            while(lo <= ro) {
                int md = (lo + ro)/2;
                if(pref_col[x][y] - pref_col[x - md][y] == md) {
                    cur = md;
                    lo = md + 1;
                }else 
                    ro = md - 1;
            }
            
            int mn = min(mx_en, cur);
            mx[x][y] = max(mx[x][y], mn);
            mx_en = max(mx_en, cur);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mx[i][j] = max(mx[i][j], mx[i - 1][j]);
            mx[i][j] = max(mx[i][j], mx[i][j - 1]);
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
       
        cout << 2 * mx[x][y] << endl;
    }
} 
 
int main(){
    FAST
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}