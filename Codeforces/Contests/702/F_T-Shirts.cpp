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

namespace treap {
    struct item{
        int key, priority, sz = 0;
        int index;
        int upd = 0;
        int val_push = 0;
        int tot_push = 0;
        int tot = 0;
        item *l, *r;
        item(int key,int index) : key(key), index(index), priority(rand()), l(NULL), r(NULL){}
        item(int key,int index, int priority) : key(key), index(index), priority(priority), l(NULL), r(NULL){}
    };

    typedef item* pitem;

    int cnt(pitem t){ return t ? t->sz : 0; }

    void upd_cnt(pitem t){ if (t) t->sz = 1 + cnt(t->l) + cnt(t->r); }

    void push(pitem& t){
        if (!t || !t->upd)return;

        if (t->l)t->l->val_push += t->val_push, t->l->upd = 1, t->l->tot_push += t->tot_push;
        if (t->r)t->r->val_push += t->val_push, t->r->upd = 1, t->r->tot_push += t->tot_push;
        t->key += t->val_push;
        t->tot += t->tot_push;
        t->val_push = t->upd = t->tot_push = 0;
    }

    void split(pitem t, int x, pitem& l, pitem& r){
        push(t);
        push(l);
        push(r);
        if (t == NULL) l = r = NULL;
        else if (t->key <= x){
            split(t->r, x, t->r, r);
            l = t;
        }
        else split(t->l, x, l, t->l), r = t;
        upd_cnt(t);
        push(t);
    }

    void mrg(pitem& t, pitem l, pitem r){
        push(t);
        push(l);
        push(r);
        if (!l || !r)
            t = l ? l : r;
        else if (l->priority > r->priority)
            mrg(l->r, l->r, r), t = l;
        else
            mrg(r->l, l, r->l), t = r;
        upd_cnt(t);
        push(t);
    }

    pitem unite(pitem l, pitem r){
        push(l);
        push(r);
        if (!l || !r) return l ? l : r;
        if (l->priority < r->priority) swap(l, r);
        pitem lt = NULL, rt = NULL;
        split(r, l->key, lt, rt);
        upd_cnt(l);
        upd_cnt(r);
        l->l = unite(l->l, lt);
        l->r = unite(l->r, rt);
        upd_cnt(l);
        upd_cnt(r);
        return l;
    }

    void ins(pitem& t, pitem t2){
         push(t2);
        pitem t1 = NULL, t3 = NULL;
        t2-> l = t2 -> r = NULL;
        split(t, t2->key, t1, t3);
        mrg(t, t1, t2);
        mrg(t, t, t3);
        upd_cnt(t);
    }

    void ins(pitem& t, int x,int index, int val=0){
        pitem t1 = NULL, t3 = NULL;
        pitem t2 = new item(x, index);
        t2 -> tot = val;
        split(t, x, t1, t3);
        mrg(t, t1, t2);
        mrg(t, t, t3);
        upd_cnt(t);
    }

    pair<int,int> getByIndex(pitem& t, int x){
        push(t);
        if (t == nullptr) return {-1, -1};
        upd_cnt(t);
        if (cnt(t->l) == x){ return {t->index, t->tot}; }
        return cnt(t->l) > x ? getByIndex(t->l, x)
                   : getByIndex(t->r, x - cnt(t->l) - 1);
    }

    pitem getMax(pitem& p){
        push(p);
        upd_cnt(p);
        return (p && p->r ? getMax(p->r) : p);
    }

    pitem getMin(pitem& p){
        push(p);
        upd_cnt(p);
        return (p && p->l ? getMin(p->l) : p);
    }
};

void Solve(){
    int n, k;
    cin >> n;

    vector<pair<int,int>> vp(n);
    for (auto& [c,q] : vp) cin >> c >> q;

    sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int,int> b){
        if (a.S > b.S) return true;
        if (a.S == b.S && a.F < b.F) return true;
        return false;
    });

    cin >> k;
    vector<int> b(k);
    for (auto& x : b) cin >> x;

    treap::pitem root = NULL;

    for (int i = 0; i < k; i++){ ins(root, b[i], i); }
    for (auto& [c,q] : vp){
        treap::pitem l = NULL, r = NULL, mx = NULL, mn = NULL;
        split(root, c - 1, l, r);

        if (r){
            r->upd = 1;
            r->tot_push++;
            r->val_push = -c;
            push(r);
        }

        mx = getMax(l);
        mn = getMin(r);
        while (mx && mn && mx->key > mn->key){
            treap::pitem md = NULL;
            split(r, mn->key, md, r);

            queue<treap::pitem> bfs;
            bfs.push(md);
            while (!bfs.empty()){
                treap::pitem curr = bfs.front();
                bfs.pop();
                if (curr ) push( curr) ;
                if (curr) ins(l, curr->key , curr->index, curr->tot);
                if (curr && curr->l) bfs.push(curr->l);
                if (curr && curr->r) bfs.push(curr->r);
            }

            mx = getMax(l);
            mn = getMin(r);
        }
        mrg(root, l, r);
    }
    vector<int> ans(k);
    for (int i = 0; i < k; i++){
        auto [pos,val] = getByIndex(root, i);
        ans[pos] = val;
    }
    for (auto& x : ans) cout << x << " ";
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
