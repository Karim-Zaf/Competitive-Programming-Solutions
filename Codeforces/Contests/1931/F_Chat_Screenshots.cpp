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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int n, k ;

bool eq (vector<int> &one , vector<int> &two) {
    if (one.size()!=two.size()) return false ;
    for (int i= 0 ; i<one.size() ; i++)
        if (one[i]!=two[i]) return false;
    return true ;
}

vector<int> work(vector<int> a, vector<int> b){
    int aa =a.front(), bb = b.front();
    vector<int> one , two ;
    for (auto x: a ) if(x!=aa&&x!=bb) one .pb(x) ;
    for (auto x: b ) if(x!=aa&&x!=bb) two .pb(x) ;

    if (!eq(one,two)) return {} ;

    vector<int> ans  ;

    int x =1, y= 1 ,flag = 0;

    while (x<a.size()&&y<b.size()){
        if (a[x]==bb)ans.pb(bb),x++;
        if (x>=a.size()||y>=b.size())break;
        if (a[x]!=b[y]&& !flag)flag = 1,ans.pb(aa) ;
        ans.pb(a[x]);
        x++;
        y++;
    }
    if (!flag) ans.pb(aa);
    return ans ;
}

vector<int> res ;


bool verif (vector<int> &v ) {
    int rass = v.front() ;
    vector<int> one , two ;
    for (auto x: res) if (x!=rass)one.pb(x);
    for (auto x: v) if (x!=rass)two.pb(x);

    if (!eq(one,two)) return false ;

    return true;
}

void Solve() {
    cin >> n >> k ;
    vector<vector<int>> v ;

    for (int i= 1;  i<=k ;i++){
        vector<int> nw ;
        for (int j = 1, x; j<=n ;j++) {
            cin >> x;
            nw.pb(x);
        }
        v.pb(nw);
    }

    if (k==1) {cout << "YES\n";return;}

    res = work(v[0],v[1]) ;

    if (res.empty()){cout << "NO\n";return;}

    if (k>=3){
        vector<int> a =work(v[0],v[1]);
        vector<int> b =work(v[0],v[2]);
        vector<int> c =work(v[2],v[1]);

        if (eq(b,c)) res = b ;
        else res =a ;
    }

    for (auto vect : v)
        if (!verif(vect)){cout << "NO\n";return;}

    cout << "YES\n";
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}