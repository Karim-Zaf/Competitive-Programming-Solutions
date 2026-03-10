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
    int n, s, q;
    cin >> n >> s >> q;
    auto gen = [&](int x)-> array<int, 2>{
        if (x > n) return {INF, x};
        return {-n / x * x, -x};

    };


    set<array<int, 2>> seti;

    while (s--){
        int x;
        cin >> x;
        seti.insert(gen(x));
    }

    while (q--){
        int x;
        cin >> x;
        if (x == 1){
            if (seti.empty()) cout << -1 << endl;
            else{
                auto [indx , val] = *seti.begin();
                if (indx != INF) val *= -1;
                cout << val << endl;
            }
        }
        else if (x == 2){ cin>> x;seti.insert(gen(x)); }
        else{
            cin >> x;

            if (seti.find(gen(x)) == seti.end())
                cout << "Can't Delete\n";
            else{
                seti.erase(gen(x));
                cout << "Deleted Successfully\n";
            }
        }
    }

    for (auto [val , x] : seti){
        if (val != INF) x *= -1;

        cout << x << " ";
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
