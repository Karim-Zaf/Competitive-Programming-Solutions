#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int mod = 1e9 + 7;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
bool ask(int idx) {
    cout << idx << endl;
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> p, imp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(i % 2 == 0)
            imp.push_back({x, i});
        else 
            p.push_back({x, i});
    }
    sort(imp.begin(), imp.end());
    sort(p.begin(), p.end());
    int rp = p.size();
    while(k > 0){
        int x;
        cin >> x;
        if(x == 2){
            assert(!p.empty());
            assert(ask(p.back()[1] + 1));
            p.pop_back();
        }else {
            if(imp.empty()) {
                assert(!p.empty());
                assert(ask(p.back()[1] + 1));
                p.pop_back();
            }else{
                array<int, 2> arr = {imp.back()[0], -(int)2e9};
                int g = p.size() - (lower_bound(p.begin(), p.end(), arr) - p.begin());
                if(g >= k){
                    assert(ask(p.back()[1] + 1));
                    p.pop_back();
                }else {
                    assert(ask(imp.back()[1] + 1));
                    imp.pop_back();
                }
            }
        }
        k--;
    }
}

int main()
{
    FAST
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
