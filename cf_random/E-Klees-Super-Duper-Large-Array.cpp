#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;

ll ps(ll i, ll k) {
    if (i <= 0) return 0;
    return i * k + i * (i - 1) / 2;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll total_sum = ps(n, k);

    ll l = 1, r = n;
    ll res = 1;

    while (l <= r) {
        ll mid = (l+r)/2;
        ll val = 2 * ps(mid, k) - total_sum;

        if (val <= 0) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    ll min_x = abs(2 * ps(res, k) - total_sum);

    if (res + 1 <= n) {
        min_x = min(min_x, abs(2*ps(res + 1, k) - total_sum));
    }

    cout << min_x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
