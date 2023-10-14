
#include<bits/stdc++.h>
#define ll long long
#define     a(v)              v.begin(), v.end()
using namespace std;


int main() {
/*solver : samin  */
/*team name : IIUC_Newbies*/
   ll test;
   cin>>test;
   for(ll t=1;t<=test;t++){
  ll n;cin>>n;
  ll ar[n];
  for(ll i = 0;i<n;i++)cin>>ar[i];
  ll ans = (n*(n+1))/2;
  ans-=n;
  ll c = 1;
  for(ll i = 1;i<n;i++)
  {
   if(ar[i]==ar[i-1])c++;
   else 
   {
      ll m = (c*(c+1))/2;
      m-=c;
      //cout<<m<<endl;
      ans-=m;
      c = 1;
   }
  }
  ll m = (c*(c+1))/2;
      m-=c;
      //cout<<m<<endl;
      ans-=m;
      c = 1;
  cout<<"Case "<<t<<": ";
cout<<ans<<endl;

   }   
   retrun 0 ;

}
    




        






































