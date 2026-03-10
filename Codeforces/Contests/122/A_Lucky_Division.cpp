#include <bits/stdc++.h>
using namespace std ;
bool lucky (int n){
    int r =4;
    while (n!=0&& (r==4||r==7)){
       r=n%10; n/=10;
    }
    if (r==4||r==7)return 1;return 0;
}
int main ()
{
    int n,i=4; cin >> n;
    while (i<=n){
        if (lucky ( i) && n%i==0 || lucky ( n))
        {
        cout << "YES" ;
        //cout << endl << i<<endl << lucky (4);
        return 0;}
        i++;
    }
    cout << "NO";
}