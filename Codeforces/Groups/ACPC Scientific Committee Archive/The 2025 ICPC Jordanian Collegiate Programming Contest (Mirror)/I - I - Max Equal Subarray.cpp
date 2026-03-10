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
 
const int N = 100010;
int a[N];
int nxs[N];
int nxg[N];
int prs[N];
int prg[N];
int n;
 
void prep() {
    stack<int> st;
    for (int i = 1; i <= n; i++) nxs[i] = n + 1;
    for (int i = 1; i <= n; i++){
        if (a[i] == 0) continue;
        while (!st.empty() && a[st.top()] > a[i]) {
            nxs[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
 
    while (!st.empty()) st.pop();
 
    for (int i = 1; i <= n; i++) nxg[i] = n + 1;
    for (int i = 1; i <= n; i++){
        if (a[i] == 0) continue;
        while (!st.empty() && a[st.top()] < a[i]) {
            nxg[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
 
    while (!st.empty()) st.pop();
 
    for (int i = 1; i <= n; i++) prs[i] = 0;
    for (int i = n; i >= 1; i--){
        if (a[i] == 0) continue;
        while (!st.empty() && a[st.top()] > a[i]) {
            prs[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
 
    while (!st.empty()) st.pop();
 
    for (int i = 1; i <= n; i++) prg[i] = 0;
    for (int i = n; i >= 1; i--){
        if (a[i] == 0) continue;
        while (!st.empty() && a[st.top()] < a[i]) {
            prg[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}
 
void solve() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    prep();
 
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] == 0){
            int j = i;
            while (j <= n && a[j] == 0) j++;
            ans = max(ans, j - i);
            i = j - 1;
        }else {
            int l = max(prs[i], prg[i]);
            int r = min(nxs[i], nxg[i]);
            ans = max(ans, r - l - 1);
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
    cin >> t;
    while(t--)
        solve();
    return 0;
}