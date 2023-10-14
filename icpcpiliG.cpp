#include<bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
//attempt : kabbo 
/*solver : samin  */
/*team name : IIUC_Newbies*/
   ll t;
   cin>>t;
   while(t--)
    {
    string s;cin>>s;
    ll over = (s.size())/6;
    ll ball = s.size()-(over*6);
    ll w = 0,r = 0;
    for(ll i = 0;i<s.size();i++)
    {
        if(s[i]=='W')w++;
        else r+=s[i]-'0';
    }
   // 1.3 Overs 12 Runs 0 Wicket.
    cout<<over<<"."<<ball<<" ";
    if((s.size()>6))cout<<"Overs ";
    else cout<<"Over ";
    cout<<r<<" ";
    if(r>1)cout<<"Runs ";
    else cout<<"Run ";
    cout<<w<<" ";
    if(w>1)cout<<"Wickets.";
    else cout<<"Wicket.";
    cout<<endl;
    }
    return 0;
}
 
 























        






































