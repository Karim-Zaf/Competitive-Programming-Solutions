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
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 1e5 + 1 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

void solve(){
    int  t , q ,diff = 0 ;
    string s1 , s2 ; 
    cin >> s1 >> s2 >> t >> q ;
    queue <tuple<int,char,int>> block ;
    for (int i= 0 ; i< s1.size() ;i++)
        diff += s1[i]!=s2[i];
    for (int i= 0 ; i<q ; i++){
        int x;
        cin >> x ;
        if (!block.empty() && get<0>(block.front())==i){
            auto [index,charac,pos] = block.front();
            diff += s1[pos]!=s2[pos];
            block.pop();
        }
        if (x== 1){
            int pos ;
            cin >> pos ; 
            diff-= s1[--pos]!=s2[pos];
            block.push( make_tuple(i+t,s1[pos],pos));
        }
        else if (x == 2) {
            int one , two , pos1 , pos2; 
            cin >>one >> pos1 >> two >>  pos2 ;
            pos1 -- ; pos2 --; 
            diff-= s1[pos1]!=s2[pos1];
            diff-= s1[pos2]!=s2[pos2];
            if (one ==1 && two ==2) swap(s1[pos1],s2[pos2]);
            if (one ==1 && two ==1) swap(s1[pos1],s1[pos2]);
            if (one ==2 && two ==1) swap(s2[pos1],s1[pos2]);
            if (one ==2 && two ==2) swap(s2[pos1],s2[pos2]);
            diff+= s1[pos1]!=s2[pos1];
            diff+= s1[pos2]!=s2[pos2];
        }
        else if ( diff == 0 ){ yes }
        else { no }
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}