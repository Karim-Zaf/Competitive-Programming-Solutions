/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
typedef long long ll;
using namespace __gnu_pbds;
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve(){
    string a , b ;
    int n , i=0 ,virt = 0 , res=INF, curr = 0;
    map <int,set<int> > mp ;
    indexed_set index ;
    cin >> n>> a >> b ;

    for (int k= 0; k<n; k++)mp[a[k]].insert(k);
    for (int k= 0; k<n; k++)index.insert(k);

    while (i<n&& virt<n){
        for (char c = 'a' ; c< b[virt] ; c++){
            if (mp[c].empty()) continue;
            res =min (res , curr +(int)index.order_of_key(*mp[c].begin()));
        }
        if(a[i]==b[virt]) {
            index.erase(i) ;
            mp[b[virt]].erase(*mp[b[virt]].begin());
            i= *index.begin();
            virt++;
            continue;
        }
        if (mp[b[virt]].empty()) break;
        curr += (int)index.order_of_key(*mp[b[virt]].begin() ) ;
        index.erase(*mp[b[virt]].begin());
        mp[b[virt]].erase(*mp[b[virt]].begin());
        virt++;
    }
    cout << (res == INF ? -1 : res) << endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}