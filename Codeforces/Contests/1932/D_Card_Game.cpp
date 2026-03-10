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

void Solve() {
    int n ;
    char c ;
    cin >> n >> c ;
    vector<string> v(2*n) ;
    vector<pair<string,string>> ans;
    map<char ,set<int>> mp ;
    for (int i= 0 ; i<2*n; i++){
        cin >> v[i] ;
        mp[v[i][1]].insert(v[i][0]-'0');
    }
    for (auto [key,vect] : mp){
        if (key==c)continue;
        auto it = vect.begin();
        it++;
        while(true){
            if (it==vect.end())break;
            ans.pb({key+to_string(*prev(it)),key+to_string(*(it))});
            mp[key].erase(*it);
            mp[key].erase(*prev(it));
            it++;
            if (it==vect.end())break;
            it++;
        }
        if (mp[key].empty())continue;

        if (mp[c].empty()) {
            cout << "IMPOSSIBLE\n";return;
        }
        it= mp[c].begin();
        ans.pb({key+to_string(*mp[key].begin()),c+to_string(*it)});
        mp[c].erase(*it);
    }
    for (auto [key,vect] : mp){
        if (key!=c||vect.empty())continue;
        auto it = vect.begin();
        it++;
        while(true){
            if (it==vect.end())break;
            ans.pb({key+to_string(*prev(it)),key+to_string(*(it))});
            mp[key].erase(*it);
            mp[key].erase(*prev(it));
            it++;
            if (it==vect.end())break;
            it++;
        }
        if (!mp[key].empty()) {
            cout << "IMPOSSIBLE\n";return;
        }
    }
    for (auto[one,two] : ans) {
        reverse(all(one));
        reverse(all(two));
        cout << one << " " << two << endl;
    }

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}