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
#define endl '\n'

const int N = 2e6 + 2, mod = 1e9 + 7, INF = 1e18 + 10;



void Solve(){
    int n, m;
    cin >> n >> m;

    int mx= n + m +2 ;

    vector<int> a(n), b(m);

    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    set ss (all(a));
     a= vector(all(ss));

    vector<int> mp(mx);
    for (auto x: a ){
        for (int j= x; j< mx ; j+= x){
            mp[j]++;
        }
    }
    vector<int> vis (mx);

    int sz = ss.size();
    int alice = 0, bob = 0, two = 0;
    for (auto x : b){
        if (mp[x] == sz) alice++;
        else if (mp[x] == 0) bob++;
        else two++;
    }

    if (two % 2 == 0){
        // alice turn
        if ( !alice ) return void ( cout << "Bob"<< endl);
        int req_alice = bob + 1;
        if (alice >= req_alice) cout << "Alice\n";
        else cout << "Bob\n";
    }
    else{
        // bob turn
        if ( !bob ) return void ( cout << "Alice"<< endl);
        kar(alice,bob);
        int req_bob = alice + 1 ;
        if (bob >= req_bob) cout << "Bob\n";
        else cout << "Alice\n";
    }
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
