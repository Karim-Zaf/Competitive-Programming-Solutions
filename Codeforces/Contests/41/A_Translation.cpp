#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string t,s; cin >> t >> s;
    bool ok= true;
    int i=0, j=(int)t.length()-1;
    while( i < (int)t.length() && ok)
    {
        if (t[i]!=s[j])
            ok=false;
        i++;
        j--;
    }
    if (ok)
        cout << "YES" ;
    else
        cout << "NO";
}