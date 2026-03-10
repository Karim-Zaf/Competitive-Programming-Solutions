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

template <int MOD_ = mod>
struct modnum{
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:
    using ll = long long;

    int v;

    static int minv(int a, int m){
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:
    modnum() : v(0){}
    modnum(ll v_) : v(int(v_ % MOD)){ if (v < 0) v += MOD; }
    explicit operator int() const{ return v; }
    friend std::ostream& operator <<(std::ostream& out, const modnum& n){ return out << int(n); }

    friend std::istream& operator >>(std::istream& in, modnum& n){
        ll v_;
        in >> v_;
        n = modnum(v_);
        return in;
    }

    friend bool operator ==(const modnum& a, const modnum& b){ return a.v == b.v; }
    friend bool operator !=(const modnum& a, const modnum& b){ return a.v != b.v; }

    modnum inv() const{
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }

    friend modnum inv(const modnum& m){ return m.inv(); }

    modnum neg() const{
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }

    friend modnum neg(const modnum& m){ return m.neg(); }

    modnum operator-() const{ return neg(); }
    modnum operator+() const{ return modnum(*this); }

    modnum& operator ++(){
        v++;
        if (v == MOD) v = 0;
        return *this;
    }

    modnum& operator --(){
        if (v == 0) v = MOD;
        v--;
        return *this;
    }

    modnum& operator +=(const modnum& o){
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }

    modnum& operator -=(const modnum& o){
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }

    modnum& operator *=(const modnum& o){
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }

    modnum& operator /=(const modnum& o){ return *this *= o.inv(); }

    friend modnum operator ++(modnum& a, int32_t){
        modnum r = a;
        ++a;
        return r;
    }

    friend modnum operator --(modnum& a, int32_t){
        modnum r = a;
        --a;
        return r;
    }

    friend modnum operator +(const modnum& a, const modnum& b){ return modnum(a) += b; }
    friend modnum operator -(const modnum& a, const modnum& b){ return modnum(a) -= b; }
    friend modnum operator *(const modnum& a, const modnum& b){ return modnum(a) *= b; }
    friend modnum operator /(const modnum& a, const modnum& b){ return modnum(a) /= b; }
};

template <typename T>
T pow(T a, long long b){
    assert(b >= 0);
    T r = 1;
    while (b){
        if (b & 1) r *= a;
        b >>= 1;
        a *= a;
    }
    return r;
}

using modint = modnum<>;

vector<int> v;
const int M = 305;
modint dp[M][M][M];
int n;

modint work(int i,int mx, int mn_seq){
    if (i > n) return 1;

    modint& ret = dp[i][mx][mn_seq];
    if (ret != -1) return ret;

    ret = 0;
    //take
    if (v[i] >= mn_seq)
        ret += work(i + 1, max(mx, v[i]), (v[i] < mx ? max(mn_seq, v[i]) : mn_seq));

    //leave
    ret += work(i + 1, mx, mn_seq);

    return ret;
}

void Solve(){
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 0; i <= n + 3; i++)
        for (int j = 0; j <= n + 3; j++)
            for (int k = 0; k <= n + 3; k++)
                dp[k][i][j] = -1;

    cout << work(1, 0, 0) << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
