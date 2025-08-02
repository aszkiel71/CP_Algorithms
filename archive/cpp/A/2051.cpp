#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];

            int s = 0;
            if (i < n) s = b[i];
            dp[i] = max(dp[i], (i >= 1 ? dp[i - 1] : 0) + a[i - 1] - s);
        }

        cout << dp[n] << endl;
    }

    return 0;
}