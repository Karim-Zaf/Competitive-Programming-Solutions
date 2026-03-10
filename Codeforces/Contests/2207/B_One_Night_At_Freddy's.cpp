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

void Solve(){
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> v(n);

    for (auto& x : v)cin >> x;

    int lef = 0, righ = l + 3, res = -1;

    // while (lef <= righ){
    //     int md = lef + (righ - lef) / 2;
    // md = 18;
    m = min( m , n+1);
    vector<int> ans(m);


    sort (rall(v));

    int prv = 0 ;
    multiset<int> s;

    for (int i= 0 ;i<m ; i++)s.insert(0);

    for (int i= 1 ;i<=l ; i++){

        int beki = v.size() ;
        while (s.size() > beki +1) s.erase(s.find(*s.begin()));


        int mn = *s.begin();
        s.erase(s.find(mn));
        s.insert(mn+1);


        if ( !v.empty() && v.back()==i){
            int mx = *prev (s.end());
            s.erase(s.find(mx));
            s.insert(0);
        v.pop_back() ;
        }
    }
    cout << *prev(s.end()) << endl;
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
