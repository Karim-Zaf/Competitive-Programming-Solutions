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


    void Solve(){
        int n  , mx1=-INF , mx2 = -INF;
        cin >> n ;
        vector <int> v(n+3) , prefodd(n+3), prefeven (n+3) ,suff(n+3);
        for (int i= 2 ; i<=n+1 ; i++)cin >> v[i]  ;
        for (int i = n+1 ; i>=2 ; i--) suff[i]= suff[i+1]+ (i%2? 0: v[i]);
        int res = suff [2];
        kar (prefeven )
        for (int i= 1 ; i<=n+1 ; i++){
            if (i%2) prefodd[i]+= v[i];
            else prefeven[i]+=v[i]  ;
            if(i)prefodd[i]+= prefodd[i-1]  ;
            if(i)prefeven[i]+= prefeven[i-1] ;
            res = max (res, suff[i+1]+ prefodd[i]+ (i%2? mx1 : mx2));
            if(i%2)mx1 = max (mx1 , prefeven[i]-prefodd[i]);
            else mx2 = max (mx2 , prefeven[i]-prefodd[i]);
        }
        cout << res << endl;


    }


    int32_t main(){
        #ifndef ONLINE_JUDGE
            freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
            freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
        #endif
        ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
        cin >> Test_case ;
        while (Test_case--) Solve();
    }