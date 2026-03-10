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
    int n;
    cin >> n ;
    vector<int> bomb(n+3), life(n+3) ,ans(n+4);
    set <pair <int,int>> s ;
    set <int> left ;

    for (int i= 1; i<= n ;i++) cin >> bomb[i] ;
    for (int i= 1 ;i<=n;i++)cin >> life[i] ;

    for (int i=0 ; i<=n+1; i++) left.insert(i);

    auto get =[&](int i){
        int one = *prev (left.lower_bound(i));
        int two = *left .upper_bound(i);
        int sum =  bomb[one]+bomb[two];
        if (sum > life[i])return 0 ;
        return 1 ;
    };


    for (int i= 1;i<=n ;i++)s.insert ({get(i),i});

    int round = 0;
    while (true){
        if(++round>n) break;
        auto it = s.begin();
        auto [mn,i]=*it;
        if (mn) break;
        set<int> upd , upd2;
        while (it !=s.end() && it->F == mn){
            int one = *prev (left.lower_bound(it->S));
            int two = *left.upper_bound(it->S);
            if (one<=n&&one>=1 && left.find(one)!=left.end())upd.insert(one);
            if (two>=1 &&two<=n&& left.find(two)!=left.end())upd.insert(two);
            upd.insert(it->S);
            upd2.insert(it->S);
            ans [round] ++;
            it++;
        }
        for (auto j : upd ) {
            s.erase({get(j),j});
        }
        for (auto j : upd2){
            bomb[j]= life[j]=0 ;
            upd.erase(j);
            left.erase(j);
        }
        for (auto j : upd) {
            s.insert({get(j) , j});
        }
    }

    for (int i= 1 ;i<=n ;i++)cout <<ans[i]<< " "; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}