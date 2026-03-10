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

const ll N = 4e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

void solve(){
    int n , m , s , d ;
    cin >> n >> m>> s >> d ;
    vector <pair <string,int>> res;
    vector <int> v(n);
    for (int i= 0;i<n;i++)
        cin >> v[i];
    sort (all(v));
    if (v[0]-1<s) {cout << "IMPOSSIBLE" << endl; return;}
    res .pb({"RUN",v[0]-1});
    res .pb({"JUMP",v[0]-1});
    for (int i= 1;i<n;i++){
        if (v[i]-v[i-1]-2>=s) {
            pair<string, int> p = res.back();
            res[res.size() - 1].S = v[i - 1] +1 - p.S ;
            if (res[res.size() - 1].S>d){cout << "IMPOSSIBLE" << endl; return;}
            res.pb({"RUN", v[i] - v[i - 1] - 2});
            res.pb({"JUMP", v[i] - 1});
        }
    }
    pair<string, int> p = res.back();
    res[res.size() - 1].S = v.back() -p.S+1 ;
    if (res[res.size() - 1].S>d){cout << "IMPOSSIBLE" << endl; return;}
    if (m-v.back()-1) res.pb({"RUN",m -v.back()-1});
    for (int i= 0;i<res.size();i++)
        cout << res[i].F << " " << res[i].S << endl;

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