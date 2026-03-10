#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    string x; cin >> x; 
    for (int i=0; i <int (x.length());i++){
        switch(x[i])
        case 'H':case'Q' : case'9' : {cout << "YES";
        return 0;}
    }
    cout << "NO";
}