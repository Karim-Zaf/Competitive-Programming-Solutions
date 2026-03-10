#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n, sq=0, sa=0; cin >>n; char c ;
        while (n--)
        {
            cin >> c;
            if (c=='Q')
                sq++; 
            else if (c=='A'&&sq>sa)sa++;
        }
        //cout << "sa= "<< sa << "sq= "<< sq<<endl;
        if (sq<=sa&&c=='A')cout << "Yes"<<endl;else cout << "No"<<endl;
    }
}