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
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
int get_sum11(string s){
	int ret = 0, cnt = 10;
	for (char c : s){
		if (c == '-') continue;
		int x = (c == 'X' ? 10 : c - '0');
		ret = (ret + cnt * x) % 11;
		cnt--;
	}
	return ret;
}
 
int get_sum10(string s){
	int ret = 0, cnt = 1;
	for (char c : s){
		if (c == '-') continue;
		int x = c - '0';
		ret = (ret + cnt * x) % 10;
		cnt = 4 - cnt;
	}
	return ret;
}
 
bool check(string s){
	if (s[0] == '-' || s.back() == '-' || (int)s.size() < 10 || (int)s.size() > 13) return false;
	int cnt = 0;
	for (int i = 1; i < (int)s.size(); i++){
		if (s[i] == '-') cnt++;
		if (s[i] == '-' && s[i - 1] == '-') return false;
	}
	if ((int)s.size() - cnt != 10) return false;
	if ((int)s.size() == 13 && s[11] != '-') return false;
	int x = s.find('X');
	if (x != -1 && x != (int)s.size() - 1) return false;
	return true;
}
 
void solve(){
	string s;
	cin >> s;
	if (!check(s) || get_sum11(s)){
		cout << "invalid" << endl;
		return;
	}
	s.pop_back();
	string ans = "978-" + s;
	int sz = 1;
	for (int c : ans)
		if (c != '-') sz++;
	int r = get_sum10(ans);
	if (sz & 1) ans += (char)((10 - r) % 10 + '0');
	else{
		int cnt = 0;
		for (int c = 0; c < 10; c++){
			int curr = (r + c * 3) % 10;
			if (curr == 0){
				cnt++;
				ans += (char)(c + '0');
			}
		}
		assert(cnt == 1);
	}
	assert(get_sum10(ans) == 0);
	cout << ans << endl;
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