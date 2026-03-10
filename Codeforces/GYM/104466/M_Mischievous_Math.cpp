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
 
const ll N = 2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 5e18 ;
 
int d ;
 
bool ok ( int a , int b , int c ){
    if (a==d || b== d || c==d) return false;
    vector <int> v(6);
    v[0]= a-b;
    v[4]= b-a;
    v[1]= a+b;
    v[2]= a/b;
    if (a%b)v[2]= -INF ;
    v[5]= b/a;
    if (b%a)v[2]= -INF ;
    v[3]= a*b;
    for (int i= 0 ;i<6 ; i++) {
        if (v[i]==d) return false;
        int curr = v[i];
        curr *= c ;
        if (curr==d) return false;
        curr = v[i];
        curr += c ;
        if (curr==d) return false;
        curr = v[i];
        curr -= c ;
        if (curr==d) return false;
        curr = v[i];
        curr= c -curr;
        if (curr==d) return false;
        curr = v[i];
        if (curr && c%curr==0) {
            curr = c/ curr ;
        }
        if (curr==d) return false;
        curr = v[i];
        if (curr%c) continue;
        curr /= c ;
        if (curr==d) return false;
    }
    return true ;
}
 
void solve(){
 
    cin >> d ;
//    for (int i= 1 ; i<=100 ;i++) {
//        d = i ;
        int k = 0;
        for (int a = 1; a <= 100; a++) {
            for (int b = 1; b <= 100; b++)
                for (int c = 1; c <= 100; c++)
                    if (k==0 && a != b && b != c && c != a &&
                        ok(a, b, c) && ok(b, a, c) && ok(c, a, b) && ok(c, b, a) &&
                        ok(a, c, b) && ok(b, c, a)) {
                        cout << a << " " << b << " " << c<< endl;
                        k= 1 ;
                        //                        return;
 
                    }
        }
//    }
 
//     assert(false) ;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}