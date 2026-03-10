#include <iostream>
#include <string>
using namespace std;
int main ()
{
   int n,x=0 ; cin >>n;
   for (int i=0; i<n; i++)
   {
       string ch; cin >> ch;
       if (ch[1] =='+') x++;
       else x--;} cout <<x;
}