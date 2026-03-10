#include <iostream>
using namespace std;
int main()
{
    int n , A, D; cin >>n;
    for (int i=0; i<n;i++)
    {
        char c ; cin >> c;
        if (c=='A') A++;
        else D++;
    }
    if (D>A) cout <<  "Danik";
    else if (D==A) cout << "Friendship" ;
    else cout <<  "Anton" ;
}