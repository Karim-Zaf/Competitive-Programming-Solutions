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

int binpow(int a, int k, int res = 1,int Mod = mod){
    while (k){
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a,int Mod = mod){ return binpow(a, Mod - 2); }
int mult(int a, int b,int Mod = mod){
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b,int Mod = mod){ return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }
int divide(int a, int b,int Mod = mod){
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}

template <class T>
struct Seg{ /*CHANGE THE ID YA KARIM !!*/
    const T ID = 0; /**/
    int n; /**/
    vector<T> seg; /**/
    T merge(T a, T b){ return add(a, b); } // Function
    void build(int _n){ n = _n, seg.assign(2 * n, ID); } /**/
    void pull(int p){ seg[p] = merge(seg[2 * p], seg[2 * p + 1]); } /**/
    void upd(int p, T val){
        seg[p += n] = val; /**/
        for (p /= 2; p; p /= 2)pull(p); /**/
    } /**/
    T query(int l, int r){ /**/
        T ra = ID, rb = ID; /**/
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
            if (l & 1)ra = merge(ra, seg[l++]); /**/
            if (r & 1)rb = merge(seg[--r], rb);
        } /**/
        return merge(ra, rb);
    } /**/
    void print(int i = -1){ /**/
        while (++i < n)cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " "); /**/
    }
};

void Solve(){
    string s;
    int q, ans = 0;;

    cin >> s >> q;

    int n = s.size();
    s = "#" + s;
    Seg<int> sg_pref[2], sg_suff[2];
    for (int i = 0; i < 2; i++)sg_pref[i].build(n + 4), sg_suff[i].build(n + 4);

    for (int i = 1; i <= n; i++){
        int curr = s[i] - '0';

        sg_pref[curr].upd(i, binpow(2, i - 1));
        sg_suff[curr].upd(i, binpow(2, n - i));
    }

    vector<int> nb(2), cnt_ans (2);
    for (int i = 1; i <= n; i++){
        int curr = s[i] - '0';

        int curr_cnt = 1 ;
        curr_cnt = add (curr_cnt, cnt_ans[curr]);
        curr_cnt = add (curr_cnt, add(cnt_ans[curr^1],nb[curr^1]));

        ans = add (ans , curr_cnt);

        nb[curr]= add (nb[curr],add(1,add(nb[1],nb[0])));
        cnt_ans[curr] = add(cnt_ans[curr],curr_cnt) ;
    }
/*
 * 1   1
 * 0   1
 * 1   1
 * 10  2
 * 01  2
 * 11  1
 * 101 3
 */

    while (q--){
        int indx;
        cin >> indx;

        int curr = s[indx] - '0';

        ans = add(ans, mult(-2,mult(sg_pref[curr ^ 1].query(0, indx - 1), sg_suff[curr ^ 1].query(indx + 1, n))));
        ans = add(ans, -sg_pref[curr ^ 1].query(0, indx - 1));
        ans = add(ans, -sg_suff[curr ^ 1].query(indx + 1, n));

        ans = add(ans, mult(2,mult(sg_pref[curr].query(0, indx - 1), sg_suff[curr].query(indx + 1, n))));
        ans = add(ans, sg_pref[curr].query(0, indx - 1));
        ans = add(ans, sg_suff[curr].query(indx + 1, n));

        s[indx] = char('0' + curr ^ 1);
        sg_pref[curr].upd(indx, 0);
        sg_suff[curr].upd(indx, 0);
        sg_pref[curr^1].upd(indx, binpow(2, indx - 1));
        sg_suff[curr^1].upd(indx, binpow(2, n - indx));

        cout << ans << " ";
    }
    cout << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
