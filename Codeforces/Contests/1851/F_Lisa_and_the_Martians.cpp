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
    int n , k , comp = -1;
    cin >> n >> k ;
    map<int,int> mp [31];
    map <int , vector<int>> mp2 ;
    array <int,5> ans{0,-1,-1,-1,0} ;
    vector <int> v(n) ;
    for (auto &x: v) {
        cin >> x ;
        int suff =0 ;
        for (int i= k-1 , j= 1;i>=0 ; i--, j++){
            suff += ((1<<i) & x) ;
            mp[j][suff]++;
        }
    }
    for (auto &x: v) {
        int suff =0 ;
        for (int i= k-1 , j= 1;i>=0 ; i--, j++){
            suff += ((1<<i) & x) ;
            if (mp[j][suff]>=2 && j>ans[0]) ans[0]= j ;
        }
    }
    for (auto &x: v) {
        ++comp;
        int suff = 0;
        for (int i = k - 1, j = 1; i >= 0 && j <= ans[0]; i--, j++)
            suff += ((1 << i) & x);
        if (mp[ans[0]][suff] >= 2)mp2[suff].pb(comp);
    }

    vector <array <int,4>> final ;
    for (auto [val , vect]: mp2){
        int cnt= 0;
        for (int i=k-1 ;i>=0 ; i--)
            if ( (v[vect[0]]& (1ll<<i)) == (v[vect[1]] &(1ll<<i)))
                cnt+= (1<<i) ;
        final.pb({cnt,val,vect[0],vect[1]});
    }
    sort(rall(final));
    if (n==2) ans[2]=0, ans[3]=1 ;
    else {
        ans[1]= final[0][1];
        ans[2]=final[0][2];
        ans[3]=final[0][3];
    }
    for (int i=k-1 ;i>=0 ; i--)
        if ( ! (v[ans[2]]& (1ll<<i)) && ! (v[ans[3]] &(1ll<<i)))
            ans[4]+= (1<<i) ;


    cout << ans[2]+1 << " " << ans[3]+1 << " "<< ans[4] << endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}