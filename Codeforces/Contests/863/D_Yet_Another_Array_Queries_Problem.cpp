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

namespace implicitTreap {
    struct item{
        int value, priority, sz = 0;
        int sum = 0;
        bool reversed = false;
        item *l, *r;
        item(int value) : value(value), priority(rand()), l(NULL), r(NULL){}
        item(int value, int priority) : value(value), priority(priority), l(NULL), r(NULL){}
    };

    typedef item* pitem;

    int cnt(pitem t){ return t ? t->sz : 0; }

    void upd_cnt(pitem t){ if (t) t->sz = 1 + cnt(t->l) + cnt(t->r); }

    void push(pitem& t){ // for lazy prop
        if (!t) return;
        if (t->reversed)swap(t->l, t->r);
        if (t->l){ t->l->reversed ^= t->reversed; };
        if (t->r){ t->r->reversed ^= t->reversed; }
        t->reversed = false;
    }

    void split(pitem t, pitem& l, pitem& r, int x, int add = 0){
        if (t == NULL) return void(l = r = NULL);
        push(t);
        int curr_key = cnt(t->l) + add;
        if (x <= curr_key)
            split(t->l, l, t->l, x, add), r = t;
        else
            split(t->r, t->r, r, x, add + 1 + cnt(t->l)), l = t;
        upd_cnt(t);
    }

    void pull(pitem& t){ // for sum
        t->sum = t->value;
        if (t->l) t->sum += t->l->sum;
        if (t->r) t->sum += t->r->sum;
    }

    void mrg(pitem& t, pitem l, pitem r){
        push(l);
        push(r);
        if (!l || !r)
            t = l ? l : r;
        else if (l->priority > r->priority)
            mrg(l->r, l->r, r), t = l;
        else
            mrg(r->l, l, r->l), t = r;
        upd_cnt(t);
        // pull(t);
    }

    void reverse_range(pitem& t, int l, int r){
        if (l == r) return;
        pitem t1, t2, t3;
        split(t, t2, t3, r + 1);
        split(t2, t1, t2, l);
        t2->reversed ^= true;
        mrg(t, t1, t2);
        mrg(t, t, t3);
    }

    void shiftRange(pitem& t, int l, int r){
        if (l == r) return;
        pitem t1, t2, t3, t4;
        split(t, t3, t4, r + 1);
        split(t3, t2, t3, r);
        split(t2, t1, t2, l);
        mrg(t, t1, t3);
        mrg(t, t, t2);
        mrg(t, t, t4);
    }

    int getByIndex(pitem& t, int pos){
        pitem t1, t2, t3;
        split(t, t2, t3, pos + 1);
        split(t2, t1, t2, pos);
        int ret = t2->value;
        mrg(t, t1, t2);
        mrg(t, t, t3);
        return ret;
    }

    void ins(pitem& t,int val,int pos){
        pitem curr = new item(val);
        pitem t1, t3;
        split(t, t1, t3, pos);
        mrg(t, t1, curr);
        mrg(t, t, t3);
    };
};

void Solve(){
    int n, q, m;
    cin >> n >> q >> m;

    implicitTreap::pitem root = NULL;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    for (int i = 0; i < n; i++){ ins(root, v[i], i); }

    while (q--){
        int x, l, r;
        cin >> x >> l >> r;
        l--;
        r--;
        if (x == 2)reverse_range(root, l, r);
        else shiftRange(root, l, r);
    }
    for (int i = 1; i <= m; i++){
        int x;
        cin >> x;
        x--;
        cout << getByIndex(root, x) << " ";
    }
    cout << endl;
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
