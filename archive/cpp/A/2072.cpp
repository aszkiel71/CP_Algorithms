#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;

        if (abs(k) > n * p) {
            cout << -1 << endl;
        } else {
            cout << (abs(k) + p - 1) / p << endl;
        }
    }
    return 0;
}