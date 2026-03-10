#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#endif
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
const ll mod = 1e9 + 7;
const int N_Max = 1e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
char a[27][27];
 
bool is_vowel(char c){
	return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i' || c == 'y';
}
 
bool dfs(string &s, int curr){
	if (s.size() == 1) return is_vowel(s[0]);
	string l = "", r = "";
	for (int i = 0; i + 1 < (int)s.size(); i += 2)
		l += a[s[i] - 'a' + 1][s[i + 1] - 'a' + 1];
	if ((int)s.size() & 1) l += s.back();
	for (int i = (int)s.size() - 1; i - 1 >= 0; i -= 2)
		r += a[s[i] - 'a' + 1][s[i - 1] - 'a' + 1];
	if ((int)s.size() & 1) r += s[0];
	reverse(r.begin(), r.end());
	if (curr % 2 == 0) return dfs(l, curr + 1) || dfs(r, curr + 1);
	return dfs(l, curr + 1) && dfs(r, curr + 1);
}
 
void solve(){
	string s;
	for (int i = 1; i <= 26; i++)
		for (int j = 1; j <= 26; j++) cin >> a[i][j];
	cin >> s;
	int N = (int)s.size();
	int ans = dfs(s, 0);
	cout << (ans ? "Salah" : "Marzo") << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}