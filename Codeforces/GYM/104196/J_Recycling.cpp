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
#define int ll
 
const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
void solve() {
    int n;
    cin >> n;
    vector <int> v(n), left(n) , right(n) ;
    array <int,3> a ={-INF , -INF , -INF};
    for (auto & x : v) cin >> x ;
 
    stack <int> st ;
    for (int i= 0 ; i<n ;i++){
        while(!st.empty() && v[st.top()]>= v[i])
            st.pop() ;
        if (st.empty())
            left[i]=-1 ;
        else left[i]= st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop() ;
    for (int i= n-1 ; i>=0 ;i--){
        while(!st.empty() && v[st.top()]>= v[i])
            st.pop() ;
        if (st.empty())
            right[i]=n;
        else right[i]= st.top();
        st.push(i);
    }
    int mx = -INF ;
    for (int i= 0 ; i<n;i++)
        mx = max (mx , v[i]* ((--right[i])- (++left[i])+1));
    int l = INF , r = INF ;
    for (int i= 0 ; i<n;i++)
       if  (mx == v[i]* ((right[i])- (left[i])+1) && left[i] <l)
           l = left[i], r = right[i] ;
    cout << l +1<< " " << r+1 << " " << mx << endl;
 
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}