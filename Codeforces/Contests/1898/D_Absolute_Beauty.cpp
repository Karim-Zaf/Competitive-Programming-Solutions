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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve() {
    int n  ,sum = 0 , ans =0, mna=INF , mnb=INF ;
    cin >> n ;
    vector <int> a(n+4) , b(n+4) ;

    for (int i= 1;i<=n ;i++)cin >> a[i];
    for (int i= 1;i<=n ;i++){
        cin >> b[i];
        if (a[i]>=b[i])mna = min (a[i], mna);
        if (b[i]>=a[i])mnb = min (b[i], mnb);
        sum += abs(a[i]-b[i]);
    }
    ans = sum ;

    for (int i= 1; i<= n ; i++){
        if (a[i]<= b[i] && mna <= a[i])
            ans = max (ans , sum -2*mna + 2*a[i]);
        if (a[i]>=b[i] && mnb <= b[i])
            ans = max (ans , sum -2*mnb + 2*b[i]);
        if (a[i]<= b[i] && mnb <=a[i])
            ans = max (ans , sum -2*mnb + 2*a[i]);
        if (b[i]<= a[i] && mna <=b[i])
            ans = max (ans , sum -2*mna + 2*b[i]);
    }

    cout << ans << endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}