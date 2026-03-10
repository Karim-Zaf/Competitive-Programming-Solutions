#include <bits/stdc++.h>
typedef long long ll;
using namespace std ;

void solve(){
      ll n ,i=1,cnt1=0, cnt0=0,sb1=0,sb0=0,val1=0,val0=0;  cin >> n;
      char c; cin >> c ;
      if (n==1){cout << 1<<endl;return;}
      if ( c=='1') cnt1++;
      else if (c=='0')cnt0++;
      while (i<n)
      {
            
            i++;
            char c1; cin >> c1;
            if (c=='1' && c1=='1'){
                  sb1++;
            }
            else if  (c=='0' && c1=='0'){
                  sb0++;
                  //cout << "entree"<<endl<< sb0 <<endl;
            }
            else{
                  val1=max(val1,sb1+1);
                  val0=max(val0,sb0+1);
                  sb1=0;
                  sb0=0;
            }
            if (i==n){
                  val1=max(val1,sb1+1);
                  val0=max(val0,sb0+1);
                  sb1=0;
                  sb0=0;
            }
            if ( c1=='1') cnt1++;
            else if (c1=='0')cnt0++;
            c=c1;
            //cout << val0 << endl;
      }
      //cout << "val0= " <<val0 <<endl;
      ll res= max(val1*val1,val0*val0);
      
      res =max(res,cnt1*cnt0);
      cout << res << endl;
      cin.ignore();
      
}

int main ()
{
      int tt ; cin >> tt;
      while ( tt --)
            solve();
}
