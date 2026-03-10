/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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
 
const ll N = 1e12+ 7 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding 
to the k-th lowest element in the set (0-indexed).*/
#define int ll 

void solve (){
    int n , m , q ; 
    cin >> n>> m >> q ;
    vector <int > v(n)  ,Qry(q), occ(m+1), id(q), ans(q); 
    indexed_set  s ;
    vector<pair<int,int>> ms ; 
    for (auto &x : v) {
        cin >> x ; 
        occ [x]++;
    }
    for (int i =1 ; i<= m ;i++ )
        ms.pb(make_pair(occ[i],i));
    sort(all(ms));
    for (int i= 0 ;i<q ;i++){
        cin >> Qry[i];
        id[i]= i ;
    }
    sort (all(id), [&] (int a, int b){
        return Qry[a]<Qry[b];
    });

    int i= 0 ,  compt = 1 , next = n+1 ;
    while(i<q && Qry[id[i]]<=n){
        ans[id[i]]= v[Qry[id[i]]-1];
        i++; 
    }
    s.insert(ms[0].S);
    while (i<q && compt <m){
        int curr = id[i];
        int zyeda = (ms[compt].F-ms[compt-1].F)*(s.size()) ;

        int l = next ;
        next  += zyeda ;
        int r = next ;

        while (Qry[curr]< next && i < q){
            int pos = Qry[curr]-l ;
            pos%= (int)(s.size());
            ans[curr]= *s.find_by_order(pos);  
            i++;
            curr = id[i];
        }

        s.insert(ms[compt].S);
        compt ++ ;
    }
    int curr = id[i];
    while (i<q){
        int pos = Qry[curr]-next ;
        pos%= (int)(s.size());
        ans[curr]= *s.find_by_order(pos);  
        i++;
        if (i<q)curr = id[i]; 
    }
    for (auto x : ans ) cout << x << endl ;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}