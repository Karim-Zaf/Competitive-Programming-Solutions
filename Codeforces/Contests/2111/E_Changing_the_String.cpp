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
    int n, q;
    string s;
    cin >> n >> q >> s;

    map<string, set<int>> mp;
    vector<string> v(q);

    for (int i = 0; i < q; i++){
        char a, b;
        cin >> a >> b;
        v[i] = "";
        v[i] += a;
        v[i] += b;
        mp[v[i]].insert(i);
    }


    for (int i= 0 ; i<n ;i++){
        kar(i) ;
        auto &c = s[i];
        if (c == 'a') continue;
        if (c == 'c'){
            if (!mp["ca"].empty()){
                kar("one");
                kar(*mp["ca"].begin(), v[*mp["ca"].begin()])
                mp["ca"].erase(*mp["ca"].begin());
                c = 'a';
                continue;
            }
            if (!mp["cb"].empty()&& mp["ba"].empty()) {
                mp["cb"].erase(*prev(mp["cb"].end()));
                c= 'b' ;
                continue;
            }
            if (mp["cb"].empty() || mp["ba"].empty()) continue;
            int r = *prev(mp["ba"].end());
            auto it = mp["cb"].lower_bound(r);
            if (it == mp["cb"].begin()){
                kar("one");
                kar(*prev(mp["cb"].end()), v[*prev(mp["cb"].end())])
                mp["cb"].erase(*prev(mp["cb"].end()));
                c = 'b';
                continue;
            }
            it--;
            mp["cb"].erase(*it);
            mp["ba"].erase(r);

            c = 'a';

            kar("two");
            kar(*it, v[*it]);
            kar(*it, v[r]);
            continue;
        }
        else if (c == 'b'){
            if (!mp["ba"].empty()){
                mp["ba"].erase(*mp["ba"].begin());
                c = 'a';
                kar("one");
                kar(*mp["ba"].begin(), v[*mp["ba"].begin()])
                continue;
            }

            if (mp["bc"].empty() || mp["ca"].empty()) continue;
            int r = *prev(mp["ca"].end());
            auto it = mp["bc"].lower_bound(r);
            if (it == mp["bc"].begin())continue;
            it--;
            mp["bc"].erase(*it);
            mp["ca"].erase(r);
            kar("two");
            kar(*it, v[*it]);
            kar(*it, v[r]);
            c = 'a';
        }

    }
    cout << s << endl;
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
