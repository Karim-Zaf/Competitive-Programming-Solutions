#include <bits/stdc++.h>
using namespace std ;

bool lucky (long long x){
      if (x==0) return 0;
      while (x !=0){
            int dig =x%10;
            x/=10;
            //cout << dig <<endl;
            if (dig!=4 && dig!=7)
                  return 0;
                  
      }
      return 1;
}

int main (){
    long long x,s=0; cin >> x ;  //if (lucky(x)){ cout << "YES";return 0 ;}
    while (x!=0){
            int dig =x%10;
            x/=10;
            if (dig==4 || dig==7)
                  s++;
      }
    if (lucky(s)){ cout << "YES";return 0 ;}
    cout << "NO";
}

/*

int main ()
{
int t ; cin >> t;
while ( t--)
      solve();

}


*/