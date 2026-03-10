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

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+6;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 1e6;    ll n; vector<T> seg;
    T comb(T a, T b) { return  min(a,b); }
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
    }void print(){
        for(int i=0;i<n;i++)cout<<query(i,i)<<" ";cout<<'\n';}
};

void Solve(){
    int n , m , k, zeros =0 ;
    cin >> n >> m >> k ;
    vector <int> prefo(n+5) , pref(n+5),preft(n+5) ;
    vector< vector <pair<int,int>>> vp (n+2);
    vector <pair<int,int>> days (m+4) ;
    for (int i= 1 ;i<= m ; i++){
        cin >> days[i].F >> days[i].S ;
        pref[days[i].F]++ ;
        pref[days[i].S +1]-- ;
    }
    set <int> s[3] ;

    for (int i= 1; i<= n;i++){
        pref[i]+= pref[i-1] ;
        zeros += (pref[i]==0) ;
        prefo[i] = prefo[i-1]+ (pref[i]==1) ;
        preft[i] = preft[i-1]+ (pref[i]==2) ;
        if (pref[i]<=2 ) s[pref[i]].insert(i);
    }
    for (int i=1 ; i<= m ; i++){
        for (int j= 1 ; j<=2 ; j++){
            auto it = s[j].lower_bound(days[i].F) ;
            set <int> er ;
            while (it !=s[j].end() && (*it)<=days[i].S){
                vp[(*it)].pb(days[i]);
                if (vp[(*it)].size()==j)er.insert((*it));
                it++;
            }for (auto x : er) s[j].erase(x);
        }
    }
    int res = 0 ;
    for (int i=1 ;i<= n;i++){
        if (vp[i].size()>2||vp[i].empty()) continue;
        int l = vp[i][0].F , r= vp[i][0].S ;
        res = max (res , prefo[r] -prefo[l-1]);
        if (vp[i].size()!=2)continue;
        l = max (vp[i][0].F,vp[i][1].F),r = min (vp[i][0].S,vp[i][1].S);
        int curr = preft[r] -preft[l-1] ;
        l = min (vp[i][0].F,vp[i][1].F),r = max (vp[i][0].S,vp[i][1].S);
        curr += prefo[r] -prefo[l-1] ;
        res = max (res , curr);

    }
    sort (days.begin()+1 , days.begin()+m+1);

    Seg <int> sg ;
    sg.build(n+4);
    set <pair<int,int>> sp ;
    int mx = 0 ;

    for (int i= 1 ;i<=m ; i++){
        auto it = sp.begin();
        set <pair <int,int>> er ;
        while ( it!=sp.end() && (*it).F<days[i].F){
            er.insert(*it);
            it++;
        }for (auto [r,l]: er){
            mx = max (mx , prefo[r] -prefo[l-1]);
            sp.erase({r,l});
        }
        int r = days[i].S , l = days[i].F ;
        res = max (res , prefo[r] -prefo[l-1]+ mx);

        if (sg.query(l,n+3)<=n+2){
            res = max (res , prefo[r] -prefo[sg.query(l,n+3)-1]);
        }
        sp.insert({days[i].S,days[i].F});
        sg.upd(r, min (sg.query(r,r),l));
    }
    cout << res +zeros << endl;





}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}