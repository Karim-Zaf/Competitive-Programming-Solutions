#include <bits/stdc++.h>
using namespace std ;
string minas ( string a)
{
   for (int i =0; i <int (a.length());i++)
      {a[i]= tolower (a[i]); }//cout << a[i] << ' '<< endl;}
   //cout << a << endl;
   return a;
}
int main ()
{
   string a , b; cin >> a >>b;
   a=minas(a);
   b=minas(b);
   //cout << a << endl << b << endl;
   if ( a < b) cout << -1;
   else if (a==b) cout << 0;
   else cout << 1;
}