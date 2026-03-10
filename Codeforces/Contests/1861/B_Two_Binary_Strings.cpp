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
#define endl '\n'
#define int long long

const long long N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;

void Solve() {
    string a , b ;
    cin>>a >> b ;
    int n = a.size() ;
    int l = 0, r =n-1 ;
    if (a.back()==b.back()&&a.back()==a[0]&& b[0]==a[0]){cout << "YES" << endl;return;}
    if (a[0]!=b[0]||a.back()!=b.back()){cout << "NO" << endl; return;}
    if (a[0]=='0') {reverse(all(a));reverse(all(b));}
    set <int> s[3];
    for (int i= 0 ; i<n ;i++){
        if (a[i]!=b[i])s[2].insert(i);
        if(a[i]==b[i])s[b[i]-'0'].insert(i);
    }
    s[2].insert(n+3);
    for (auto x: s[1]){
        auto  curr = s[0].lower_bound(x);
        if (curr == s[0].end())continue;
        int twa = *curr ;
        int comp = *s[2].lower_bound(x);
        if (comp>twa) {
            cout << "YES\n";
            return;
        }

    }
    cout << "NO"<< endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}