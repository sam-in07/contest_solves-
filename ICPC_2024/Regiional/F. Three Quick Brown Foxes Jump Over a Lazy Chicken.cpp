#include <bits/stdc++.h>

using namespace std;
#define ll long long



void solve(int x, int y, int z) {
    
    long long s ;
    ll p= (x + y + z) ;//2s


    
    long long area_squared = (p - 2*x) * (p - 2*y) * (p - 2*z);
 s = 4*p;  
    ll a = __gcd(s,area_squared);
    s/=a;

    area_squared/=a;
    cout << area_squared << "/" << s << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;
        solve(x, y, z);
    }
    return 0;
}
