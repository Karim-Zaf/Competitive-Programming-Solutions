/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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
#define endl '\n'
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define nop cout<<"-1"<<endl;
#define int ll

const ll N = 1e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  (a+b); }
    void build(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }return comb(ra,rb);
    }
};

void solve(){
    int n ,m , q , time = 0;
    string ch ;
    cin >> n>> m >> q >> ch ;
    vector <int> id(n), conv(n);
    set <int> s ;
    Seg <int> sg ;
    sg.build(n);
    for (int i= 0 ; i< n ;i++)s.insert(i);
    for (int i= 0;i<m  ;i++){
        int l , r ;
        cin >> l >> r ;
        l-- ; r--;
        auto it = s.lower_bound(l);
        set <int> erase ;
        while (it!=s.end() && (*(it))<= r){
            id[time++]=*it;
            erase.insert(*it);
            it++;
        }

        for (auto x : erase)
            s.erase(x);
    } int t =time;
    for (auto x :s )
        id[time++]= x;
    for (int i= 0 ;i<n ;i++)
        conv[id[i]]=i;
    for (int i= 0 ;i<n ;i++) {
        sg.upd(conv[i], ch[i] == '1' );
    }
    for (int i= 0 ;i<q; i++){
        int x;
        cin >> x ; x--;
        if (ch[x]=='0')ch[x]='1';
        else ch[x]='0';
        sg.upd(conv[x],ch[x]=='1');

        int uns = sg.query(0,n-1);
        uns = min (uns , t);
        cout << uns - sg.query(0,uns-1) << endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}

// Failure gives you two choices: You stay down or You get up ;)