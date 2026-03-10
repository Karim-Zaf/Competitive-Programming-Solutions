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

pair<int,vector<int>> dp [N];

void Solve() {
    int n , x, y , s;
    cin >> n >> x >> y >> s ;
    int req = x%y*n ;


    if (req%y!=s%y|| req -x%y +x >s ) {cout << "NO\n";return;}

    req = s -req ;
    req/= y ;

    kar (req);
    int nwy = x/y ;

    for (int i= 1 ; i<=req;i++){
        dp[i]={-1,{}};
        for (int j =1 ; j*(j-1)/2<=i ;j++){
            int prev = i- j*(j-1)/2;
            if (dp[prev].F!=-1 && (dp[prev].F+j< dp[i].F || dp[i].F==-1)){
                dp[i].S = dp[prev].S ;
                dp[i].S.pb(j);
                dp[i].F= dp[prev].F+j;
            }
        }
    }

    array<int,3> ans={INF,0,0} ;
    for (int i = 1 , curr = nwy ; curr <= req ; i++,curr+=nwy+i-1 ){
        if (dp[req- curr].F+i <= ans[0]){
            ans[0] = dp[req-curr].F+ i ;
            ans[1]= i ;
            ans[2]= req-curr;
        }
    }

    if (ans[0]>n){cout << "NO\n";return;}

    vector<int> pr ;

    cout << "YES\n";
    for (int i= 1; i<= ans[1];i++,x+=y) pr.pb(x);
    for (auto xx: dp[ans[2]].S) {
        for (int i= 1, c= x%y; i<=xx ;i++, c+= y)
            pr.pb(c);
    }

    while (pr.size()<n) pr.pb(x%y);

    for (auto xx : pr) cout << xx << " " ; cout << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}