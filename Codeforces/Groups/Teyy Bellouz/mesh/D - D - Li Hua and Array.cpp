/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma gcc optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifndef ONLINE_JUDGE

#include "debug.cpp"

#else
#define kar(...)
#endif
#define endl '\n'

typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


const int N = 1e5 + 1, A_max = 5e6 + 1;

int phi[A_max], cnt[A_max], a[N];
set<int> s, er;


template<class T> struct Seg {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = {1e8,1e8}; /**/ int n;/**/ vector<T> seg;/**/
    T comb(T a, T b){ if (a.first < b.first ) return a; return b ; } // Function
    void build(int _n){n=_n,seg.assign(2*n,ID);} /**/
    void pull(int p){seg[p]=comb(seg[2*p],seg[2*p+1]);}/**/
    void upd(int p, T val){seg[p+=n]=val;/**/for(p/=2;p;p/=2)pull(p);/**/}/**/
    T query(int l, int r) {/**/T ra=ID,rb=ID;/**/for(l+=n,r+=n+1;l<r;l/=2,r/=2){
            if(l&1)ra=comb(ra,seg[l++]);/**/if(r&1)rb=comb(seg[--r],rb);
        }/**/return comb(ra,rb);
    }/**/void print(int i=-1){/**/while(++i<n)cout<<(i==0?"sg : ":"")<<query(i,i)<<(i==n-1?"\n":" ");/**/}
};

void phi_from_1_to_n(int n = A_max) {
    for (int i = 0; i < n; i++)phi[i] = i;

    for (int i = 2; i < n; i++) {
        if (phi[i] == i) {
            for (int j = i; j < n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    cnt[1] = 1;
    for (int i = 2; i < n; i++) cnt[i] += 1 + cnt[phi[i]];
}


void Solve() {
    int n, q;
    phi_from_1_to_n();
    cin >> n >> q;

    indexed_set sp, ranges;

    Seg<pair<int,int>> sg ;
    sg.build(n+1) ;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sp.insert({i, a[i]});
        ranges.insert({a[i], i});
        sg.upd(i,{cnt[i],a[i]});
        int curr = a[i], b = 0;
        while (curr != 1) {
            curr = phi[curr];
            sp.insert({i, curr});
            ranges.insert({curr, i});
            assert (++b <= 30);
        }
        s.insert(i);
    }

    while (q--) {
        int x, l, r;
        cin >> x >> l >> r;

        if (x == 1) {
            auto it = s.lower_bound(l);

            er.clear();
            while (it != s.end() && (*it) <= r) {
                er.insert(*it);
                it++;
            }
            for (auto &x: er) {
                if (a[x] != 1) {
                    sp.erase({x, a[x]});
                    ranges.erase({a[x], x});
                }
                a[x] = phi[a[x]];
            sg.upd(x,{cnt[x],a[x]});
                if (a[x] == 1) s.erase(x);
            }
            continue;
        }

        int curr = sg.query(l,r).second, b = 0;

        while (true) {
            int calc = ranges.order_of_key({curr, r + 1}) - ranges.order_of_key({curr, l});

            if (calc == r - l + 1) {
                int res = sp.order_of_key({r, 1e8}) - sp.order_of_key({l, -1e8});
                cout << res - (r - l + 1) * cnt[curr] << endl;
                break;
            }
            assert (curr != 1);
            assert (++b <= 30);
            curr = phi[curr];
        }
    }


}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    Solve();
}
