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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve(){
    int na, nb;
    cin >> na >> nb;
    deque<int> a(na), b(nb), ans;
    vector<pair<int,int>> nahhia, nahhib;
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    sort(all(a));
    sort(all(b));

    int cnta = 0, cntb = 0;

    int curr = 0;

    auto worka = [&](){
        cntb++;
        nahhia.pb({a.front(), a.back()});
        curr += a.back() - a.front();
        a.pop_front();
        a.pop_back();
    };
    auto workb = [&](){
        cnta++;
        curr += b.back() - b.front();
        nahhib.pb({b.front(), b.back()});
        b.pop_front();
        b.pop_back();
    };
    while (true){
        int bekia = a.size() - cnta;
        int bekib = b.size() - cntb;

        if (bekia <= 1 && bekib <= 1) break;

        if (bekia == 0 && !nahhia.empty()&& bekib>=3){
            cntb--;
            auto [one,two] = nahhia.back();
            nahhia.pop_back();
            curr -= two - one;
            a.push_front(one);
            a.push_back(two);
            workb();
            workb();
            ans.pb(curr);
            continue;
        }
        if (bekia == 0)break;

        if (bekib == 0 && !nahhib.empty()&&bekia>=3){
            cnta--;
            auto [one,two] = nahhib.back();
            nahhib.pop_back();
            curr -= two - one;
            b.push_front(one);
            b.push_back(two);
            worka();
            worka();
            ans.pb(curr);
            continue;
        }
        if (bekib == 0)break;

        int diffa = a.back() - a.front();
        int diffb = b.back() - b.front();
        if (bekia >= 2 && bekib >= 2 && diffa > diffb || bekib == 1){ worka(); }
        else{ workb(); }
        ans.pb(curr);
    }

    cout << ans.size() << endl;
    for (auto& x : ans) cout << x << " ";
    cout << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
