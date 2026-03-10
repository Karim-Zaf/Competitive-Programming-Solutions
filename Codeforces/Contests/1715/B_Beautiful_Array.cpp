#include <bits/stdc++.h>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(nb) push_back(n)

using namespace std;


void solve(){
    ll N, K, B, S;
    cin >> N >> K >> B >> S;
    vector<ll> beautiful(N, 0);
    beautiful[N - 1] = B * K;
    if (beautiful[N - 1] > S){
        cout << -1 << endl;
        return;
    }
    S -= beautiful[N - 1];
    for (int i = N - 2; i > -1; i--){
         if (S < K - 1)
            break;
        beautiful[i] = K - 1;
        S -= K - 1;
    }
    beautiful[N - 1] += S;
    if (beautiful[N - 1] / K != B){
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < N; i++)
        cout << beautiful[i] << " ";
    cout << endl;
}

int main(){
    FAST
    
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
