#include <bits/stdc++.h>
/*

credit : Zuhaifa for corner case
*/
using namespace std;

bool isValid(vector<int> a) {

    int valid_combinations[7][3] = {
        {1, 1, 6},
        {0, 3, 6},
        {1, 2, 4},
        {1, 3, 4},
        {2, 2, 2},
        {3, 3, 3},
        {0, 4, 4}
    };

    for (int i = 0; i < 7; ++i) {
        if (a[0] == valid_combinations[i][0] && a[1] == valid_combinations[i][1] && a[2] == valid_combinations[i][2]) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {

        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());

        if (isValid(a)) {
            cout << "Case " << i << ": perfectus" << endl;
        } else {
            cout << "Case " << i << ": invalidum" << endl;
        }
    }
    return 0;
}
