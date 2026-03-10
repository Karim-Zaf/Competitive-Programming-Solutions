/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

int n, m;
indexed_set s;

int convert (string s){
    int ret =0 , curr =1;
    reverse(all(s));
    for (auto c :s ){
        ret += (c-'0') * curr;
        curr *= 2 ;
    }
    return ret ;
}

string toBinary( int x){
    string ret ="";
    for (int i= m-1 ; i>=0 ; i--)
        ret += (x&(1ll<<i)? '1':'0');
    return ret;
}

int cnt (int x ){
    x -= s.order_of_key(x+1);
    return ++x ;
}

void Solve() {
    s.clear();
    cin >> n >> m ;
    for (int i= 1;i<=n ;i++){
        string ss ;
        cin >> ss ;
        s.insert(convert (ss));
    }

    int asgher = (1ll<<m) - n +1;
    asgher /= 2;

    int l = 0 , r = (1ll<<m) -1 , ans = 0 ;

    while (l<=r){
        int md= l + (r-l)/2 ;
        if (cnt(md)>=asgher){
            ans = md ;
            r= md- 1 ;
        }else l = md +1 ;
    }
    cout <<  toBinary(ans) << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}