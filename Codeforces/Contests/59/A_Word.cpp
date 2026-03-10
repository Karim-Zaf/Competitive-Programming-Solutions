#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    string x; cin >> x; int u=0,l=0;
    for (int i=0; i <int (x.length());i++){
        if ( x[i]>='a' && x[i]<='z') l++;
        else if ( x[i]>='A' && x[i]<='Z') u++;
    }
    if ( l>=u)
    for (int i=0; i <int (x.length());i++)x[i]= tolower(x[i]);
    else for (int i=0; i <int (x.length());i++)x[i]= toupper(x[i]); cout << x;
}