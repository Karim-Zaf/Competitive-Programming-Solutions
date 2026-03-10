/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;




int main (){
    ios::sync_with_stdio(0);cin.tie(0);
    int n , m ,p ;
    cin >> n >> m >> p ;
    int a [n] , b[m] ;
    for (int i= 0 ;i<n ;i++)cin >> a[i] ;
    for (int i= 0 ;i<m ;i++)cin >> b[i] ;
    int p1 = 0, p2 = 0;
    while (a[p1] % p == 0) p1 += 1;
    while (b[p2] % p == 0) p2 += 1;
    cout << p1 + p2 << endl;
}
