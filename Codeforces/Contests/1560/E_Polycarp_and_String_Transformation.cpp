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

const int  N=5e3+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve(){
    string s , order = "";
    cin >> s ;
    int n = s.size() ;
    map <char,int> mp ,pos , ans ,cnt;
    for (int i=n-1 ; i>=0 ; i--){
        if(!mp[s[i]]) {
            pos[s[i]]=order.size();
            order += s[i];
        }
        mp[s[i]]++ ;
    }
    int nb_char = order.size();
    for (auto [c,val] : mp){
        int other = order.size()-pos[c];
        if (val%other){cout << -1 << endl; return;}
        ans[c]= val/other ;
    }

    string final ="";
    for (int i= 0; i<n ; i++){
        final += s[i];
        cnt[s[i]]++;
        bool ok = true ;
        for (char c = 'a'; c<='z'; c++)
            ok = ok && (cnt[c]==ans[c]);
        if(ok) break;
    }

    auto f =[] (string s , string order ){
        string ret = s;
        for (auto c : order ){
            string nw_s ="";
            for (auto x: s )
                if (x!=c)
                    nw_s+= x;
            s = nw_s;
            ret += nw_s;
        }
        return ret ;
    };

    reverse (all(order));
    if (f(final,order)==s) cout <<final << " " << order << endl;
    else cout << -1 << endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}