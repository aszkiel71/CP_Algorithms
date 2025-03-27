#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long x, y, a;
        cin >> x >> y >> a;
        a = a * 2 + 1;

        if (x * 2 >= a) {
            cout << "NO\n";
            continue;
        }

        if ((x + y) * 2 >= a) {
            cout << "YES\n";
            continue;
        }

        int tmp = (a - 1) / (x + y);
        int rem = a - tmp * (x + y);


        if (rem <= x * 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}