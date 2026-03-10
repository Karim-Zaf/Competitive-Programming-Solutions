/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)
#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 998244353, INF = 1e18 + 10;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert){
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++){
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1){
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len){
            cd w(1, 0);
            for (int j = 0; j < len / 2; j++){
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert){
        for (cd& x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

struct DSU{
    vector<int> sz, parent;

    void init(int n){
        for (int i = 0; i < n; i++){
            parent.pb(i);
            sz.pb(1);
        }
    }

    int get(int a){ return (parent[a] == a ? a : parent[a] = get(parent[a])); }

    bool unite(int a, int b){
        if ((a = get(a)) == (b = get(b))) return false;
        if (sz[a] > sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same_set(int a, int b){ return get(a) == get(b); }
    int size(int a){ return sz[get(a)]; }
};

vector<int> f[6][6];

void Solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int sh = m;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            vector<int> poly1(n + 2);
            vector<int> poly2(n + 2);

            for (int k = 0; k < n; k++) poly1[k] = s[k] == char(i + 'a');
            for (int k = 0; k < m; k++) poly2[sh - k] = t[k] == char(j + 'a');
            f[i][j] = multiply(poly1, poly2);
        }
    }

    for (int i = 0; i < n; i++){
        if (i + m - 1 >= n) return;
        int ans = 0;

        vector<pair<int,int>> vp;
        for (int a = 0; a < 6; a++)
            for (int b = 0; b < 6; b++){
                int curr = f[a][b][i + sh];
                // kar(a,b,curr);
                if (curr && a != b) vp.pb({a, b});
            }

        DSU dsu;
        dsu.init(7);
        for (auto [x,y] : vp){ dsu.unite(x, y); }
        set<int> par;
        for (auto [x,y] : vp){
            par.insert(dsu.get(x));
            par.insert(dsu.get(y));
        }

        for (auto x : par) ans += dsu.size(x) - 1;

        cout << ans << " ";
    }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
