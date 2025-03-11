#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(00);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = b[i] - a[i];
        }
        sort(diff.begin(), diff.end());
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += diff[i];
        }
        if (sum < 0) {
            cout << "NO\n";
            continue;
        }
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (diff[i] > 0) {
                long long needed = diff[i];
                long long available = 0;
                for (int j = 0; j < n; ++j) {
                    if (j != i) {
                        available += max(0, -diff[j]);
                    }
                }
                if (available < needed) {
                    possible = false;
                    break;
                }
            }
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}