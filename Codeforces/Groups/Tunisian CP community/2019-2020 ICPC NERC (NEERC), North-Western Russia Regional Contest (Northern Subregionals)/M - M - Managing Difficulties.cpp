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
    int n , ans = 0;
    cin >> n ;
    vector<int> v(n) , left , right ;
    for (int i=  0;i<n ;i++)cin >> v[i];
    right = v;
    sort (all(right));

    for (int j =0 ; j<n ;j++){
        int flag = 0 ;
        vector<int> nwleft, nwright ;
        for (auto x: right){
            if (x==v[j]&&!flag){
                flag = 1 ;
                continue;
            }nwright.pb(x);
        }
        right = nwright;

        int l= left.size()-1 , r = 0, cntl = 1 , cntr=1;
        while (l>=0 && r< right.size()){
            while(l-1>=0 && left[l]==left[l-1]){
                cntl ++ ; l-- ;
            }
            while( r+1 <right.size() && right[r]==right[r+1]){
                cntr++; r++;
            }
            if (v[j]-left[l]==right[r]-v[j]) {
                ans += cntr * cntl ;
                l-- ; r++ ;
                cntl=1 , cntr =1 ;
            }
            else if (v[j]-left[l]>right[r]-v[j]) r++ , cntr=1 ;
            else {
                l -- ;
                cntl=1;
            }
        }


        flag =0 ;
        for (auto x: left){
            if (!flag && x>=v[j]){
                flag = 1 ;
                nwleft.pb(v[j]);
            }
            nwleft.pb(x);
        }
        if (!flag)nwleft.pb(v[j]);
        left = nwleft;
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