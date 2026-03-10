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
#define int ll
 
const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
void solve() {
    int q , n ;
    cin >> n >> q;
    map <int,set<array<int,3>>> mp ;
    map <pair <int,int>,int> t ;
    set <int> s ;
 
    auto verif = [&]()-> void{
        if (s.size()<=1) {cout <<"YES\n";return;}
        if (s.size()>2) {cout << "NO\n"; return ;}
        set <int> s2  ;
        for (auto curr : s){
            auto [indice,x,y] = *mp[curr].begin();
            auto [indice2,x2,y2] = *prev(mp[curr].end());
            if (indice != indice2) {cout << "NO\n"; return ;}
            s2.insert(indice) ;
        }
        if (s2.size()==1) {cout << "NO\n"; return ;}
        cout <<"YES\n";
    };
 
    while (q--){
        int  x , y, v ;
        cin >> x >> y >> v ;
        if (v==0 && t[{x,y}]){
            mp[t[{x,y}]].erase({{(x+y)%2,x,y}});
            if (mp[t[{x,y}]].empty()) s.erase(t[{x,y}]);
            t[{x,y}] = 0 ;
            verif();
            continue;
        }else if (v==0){verif(); continue;}
        mp[v].insert({(x+y)%2,x,y});
        s.insert(v) ;
        t[{x,y}]= v ;
        verif();
    }
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}