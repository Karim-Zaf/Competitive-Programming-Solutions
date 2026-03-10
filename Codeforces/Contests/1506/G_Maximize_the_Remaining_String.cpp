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

const int  N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e17;

void Solve(){
    string s , res="";
    cin >> s ;
    set <char,greater<>> occ ;
    map <char , set <int>>mp ;
    for (int i= 0 ;i<s.size() ;i++) {
        occ.insert(s[i]);
        mp[s[i]].insert(i);
    }
    int n= occ.size(),curr = 0 ;

    auto possible =[&] (char c , int curr)-> bool{
        for (int i= 0 ;i<curr;i++){
            if (occ.find(s[i])==occ.end()||s[i]==c)continue;
            auto it = mp[s[i]].upper_bound(curr);
            if (it==mp[s[i]].end())return false  ;
        }return true;
    };
    for (int i= 0 ;i<n;i++){
        for (auto c : occ){
            auto it = mp[c].lower_bound(curr);
            if (it==mp[c].end()|| !possible(c,*it))continue;
            res += c ;
            curr = (*it);
            occ.erase(c);
            break;
        }
    }
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while(Test_case--)Solve();
}