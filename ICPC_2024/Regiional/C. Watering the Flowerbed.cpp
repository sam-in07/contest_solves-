#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        long long K;
        cin >> N >> K;

        long long totalWaterings = 0;

        for (int i = 0; i < N; ++i) {
            long long X, Y;
            cin >> X >> Y;
           totalWaterings+= (K/X);

        }

    
        cout << "Case " << t << ": " << totalWaterings << endl;
    }
}

int main() {
    solve();
    return 0;
}
