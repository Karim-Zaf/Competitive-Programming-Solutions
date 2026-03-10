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
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const int N_Max = 1e5 + 7;
const ll mod = 1e9 + 7;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<int> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<int, int> p){cout << p.F << " " << p.S << endl;}
void dbgpi(vector<pair<int, int>> v){for (auto x : v) dbgg(x);}


void solve(){
    int N;
    string s;
    cin >> N >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < N; i++){
        if (s[i] == '2')
            cnt2++;
    }
    if (cnt2 == 1 || cnt2 == 2){
        no
        return;
    }
    vector<vector<char>> ans(N, vector<char>(N, '-'));
    for (int i = 0; i < N; i++)
        ans[i][i] = 'X';
    for (int i = 0; i < N; i++){
        if (s[i] == '1'){
            for (int j = 0; j < N; j++){
                if (ans[i][j] == '-'){
                    ans[i][j] = '=';
                    ans[j][i] = '=';
                }
            }
        }
    }
    for (int i = 0; i < N - 1; i++){
        if (s[i] == '1')
            continue;
        for (int j = i + 1; j < N; j++){
            if (ans[i][j] == '-'){
                ans[i][j] = '+';
                break;
            }
        }
    }
    for (int i = 0; i < N - 1; i++){
        if (s[i] == '1')
            continue;
        for (int j = i + 1; j < N; j++){
            if (ans[i][j] == '-'){
                ans[j][i] = '+';
            } 
              if (ans[i][j] == '+'){
                ans[j][i] = '-';
            }
        }
    }
    yes
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cout << ans[i][j];
        cout << endl;
    }
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
Think outside the box
int overflow
check initialization of the answer
check corner cases(small values)
stay focused ans organized
*/