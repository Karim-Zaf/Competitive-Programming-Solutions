#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

struct Matrix {
    long long a[2][2] ={{0,0},{0,0}};
    Matrix operator * ( Matrix  other) {
        Matrix product ;
        for (int i= 0 ;i<2 ; i++)
            for (int j = 0 ; j<2 ; j++)
                for (int k = 0 ; k<2 ; k++){
                    product.a[i][j]+= (a[i][k] * other.a[k][j])%mod ;
                    product.a[i][j]%=mod ;
                }
        return   product ;
    }
};

void print(Matrix s ){
    for (int i= 0 ;i<2 ; i++){
        for (int j = 0 ; j<2 ; j++)
            cout << s.a[i][j] << " ";
        cout <<endl;
    }
    cout <<endl;
}

Matrix expo_power(Matrix a, long long k){
    Matrix res ;
    for (int i=0 ; i<2 ; i++)
        res.a[i][i] = 1 ;
    while (k){
        if (k % 2)
            res = res * a;
        a = a*a ;
        k/=2 ;
    }
    return res ;
}

void solve(){
	ll N, M;
	cin >> N >> M;
	Matrix mt;
	mt.a[0][0] = 0;
	mt.a[0][1] = 1;
	mt.a[1][0] = 1;
	mt.a[1][1] = 1;
	vector<ll> vec(M + 1);
	for (int i = 1; i <= M; i++) cin >> vec[i];
	sort(vec.begin() + 1, vec.end());
	for (int i = 2; i <= M; i++){
		if (vec[i] - vec[i - 1] == 1){
			cout << 0 << endl;
			return;
		}
	}

    if (M==0){
        cout << expo_power(mt, N).a[1][1] <<endl;
        return ;
    }
    
	ll ans = expo_power(mt, vec[1] - 1).a[1][1];
	for (int i = 2; i <= M; i++){
		ll len = vec[i] - vec[i - 1] - 2;
		ans = ans * expo_power(mt, len).a[1][1] % mod;
	}
	ans = ans * expo_power(mt, N - vec[M] - 1).a[1][1] % mod;
	cout << ans << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}