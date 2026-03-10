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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 7e18 ;

void Solve(){
    int n;
    cin >> n;

    set<array<int, 3>> s{{0, INF, 0}};

    auto ins = [&](int l, int r, int len){
        if (l > r) return;

        auto it = s.upper_bound({r, INF, INF});
        if (it != s.end()){
            auto [lef2,righ2,len2] = *it;

            if (lef2 == r + 1 && len == len2){
                s.erase(*it);
                r = righ2;
            }
        }
        auto it2 = s.upper_bound({l, INF, INF});
        if (it2 != s.begin()){
            it2--;
            auto [lef2,righ2,len2] = *it2;

            if (righ2 == l - 1 && len == len2){
                s.erase(*it2);
                l = lef2;
            }
        }
        s.insert({l, r, len});
    };

    while (n--){
        char c;
        int l, p;

        cin >> c >> l >> p;

        if (c == '|'){
            auto it = s.upper_bound({p, INF, INF});
            if (it == s.begin())ins(p, p, l);
            else{
                it--;
                auto [lef,righ,len] = *it;

                if (lef <= p && p <= righ){
                    s.erase(*it);

                    ins(lef, p - 1, len);
                    ins(p + 1, righ, len);
                    ins(p, p, len + l);
                }
                else ins(p, p, l);
            }

            cout << "S";
        }
        else{
            int lef1 = p, righ1 = p + l - 1, ok = 0;

            auto it = s.lower_bound({lef1, INF, INF});

            if (it != s.begin()){
                it--;
                auto [lef2,righ2,len2] = *it;
                if (lef2 <= lef1 && righ1 <= righ2){
                    ok = 1;
                    s.erase(*it);
                    ins(lef2, lef1 - 1, len2);
                    ins(righ1 + 1, righ2, len2);
                    ins(lef1, righ1, len2 + 1);
                }
            }

            cout << (ok ? "S" : "U");
        }
    }
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
