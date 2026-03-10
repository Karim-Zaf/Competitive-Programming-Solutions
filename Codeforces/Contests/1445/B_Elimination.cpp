#include <bits/stdc++.h>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(nb) push_back(n)
 
using namespace std;
 
void solve(){
    int a , b, c, d; cin >> a >> b >> c >> d;
    cout << max(a+b,c+d)<<endl;
}
 
int main(){
    FAST
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}