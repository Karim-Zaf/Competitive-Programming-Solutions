/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

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

void Solve(){
    int n, m, k;
    string s, t;
    cin >> n >> m >> k >> s >> t;

    vector v{'A', 'T', 'G', 'C'};

    map<int, vector<int>> mp, res;
    for (auto c : v){
        mp[c].resize(n);
        for (int i = 0; i < n; i++){
            if (s[i] == c){
                int lef = i - k;
                int righ = i + k;
                righ = min(righ, n - 1);
                lef = max(lef, 0ll);
                mp[c][lef]++;
                if (righ + 1 < n) mp[c][righ + 1]--;
            }
        }
        for (int j = 1; j < n; j++) mp[c][j] += mp[c][j - 1];
        for (int j = 0; j < n; j++) mp[c][j] = min(mp[c][j], 1ll);

        vector<int> two(m + 3);
        for (int i = 0; i < m; i++){ if (t[i] == c)two[-i + m] = 1; }

        res[c] = multiply(mp[c], two);
    }

    map<char,int> freq;
    for (auto c : v){ freq[c] = count(all(t), c); }

    int ans = 0;
    for (int i = 0; i <= n - m; i++){
        int cnt = 1;
        for (auto c : v){ if (res[c][i + m] != freq[c])cnt = 0; }

        ans += cnt;
    }
    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}

