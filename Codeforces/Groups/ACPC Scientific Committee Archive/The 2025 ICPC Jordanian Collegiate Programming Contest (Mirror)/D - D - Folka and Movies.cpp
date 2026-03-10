#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int mod = 1e9 + 7;
const ll inf = 1e18 + 500;
const long double EPS = 1e-10;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
 
 
void solve() {
    int n;
    cin >> n;
 
    map<string, vector<pair<ll, string>>> f;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        string s1 = "", s2 = "";
        int idx = -1;
        for (int j = 0; j < s.size(); j++)
            if (s[j] == '-') {
                idx = j;
                break;
            }
        for (int j = 0; j < idx; j++)
            s1 += s[j];
        for (int j = idx + 1; j < s.size(); j++)
            s2 += s[j];
        f[s2].push_back({stoll(s1), s1});
    }
 
    for (auto [s, v] : f) {
        sort(v.begin(), v.end());
        for (auto [x, g] : v) {
            cout << g << "-" << s << endl;
        }
    }
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