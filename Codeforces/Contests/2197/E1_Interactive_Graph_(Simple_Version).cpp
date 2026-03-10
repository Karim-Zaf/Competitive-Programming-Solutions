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

const int N = 32, mod = 1e9 + 7, INF = 1e18 + 10;

vector<int> ask(int x){
    cout << "? " << x << endl;
    cout.flush();
    int n;
    cin >> n;
    vector<int> ret(n);
    for (auto& x : ret) cin >> x;
    return ret;
}

void Solve(){
    int n;
    cin >> n;

    int indx = 2;

    set<vector<int>> vecs[n + 1];
    vector<int> done(n + 1);
    for (int i = 1; i <= n; i++){ vecs[i].insert({i}); }

    done[1]=1 ;
    while (true){
        vector<int> res = ask(indx);

        if (res.empty()) break;

        vecs[res.front()].insert(res);
        if (done[res.back()]){
            for (auto vect : vecs[res.back()]){
                vector<int> nw = res;
                nw.pop_back();
                for (auto x : vect) nw.push_back(x);
                indx++;
                vecs[nw.front()].insert(nw);
            }
            indx--;
        }
        indx++;
        for (auto x : res) done[x]=1 ;
        // done[res.back()] = 1;

        auto vect = res;
        int sz = vect.size();
        for (int j = sz - 1; j >= 0; j--){
            vector<int> curr;
            for (int i = j; i < sz; i++){ curr.push_back(vect[i]); }
            vecs[curr.front()].insert(curr);
        }
    }

    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++){ for (auto x : vecs[i]){ if (x.size() == 2) ans.pb(x); } }

    cout << "! ";
    cout << ans.size() << endl;

    for (auto x : ans) cout << x[0] << " " << x[1] << endl;
    cout.flush();
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
