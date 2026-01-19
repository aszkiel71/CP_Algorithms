#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#define int long long

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n; cin >> n;
    int tmp;
    vector<int> a(n), b(n), p;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    tmp = a[0];
    for (int i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            p.push_back(i);
            while (tmp % i == 0) tmp /= i;
        }
    }
    if (tmp != 1) p.push_back(tmp);

    tmp = b[0];
    for (int i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            p.push_back(i);
            while (tmp % i == 0) tmp /= i;
        }
    }
    if (tmp != 1) p.push_back(tmp);

    bool g;
    for (int val : p) {
        g = true;
        for (int i = 0; i < n && g; i++) {
            if (a[i] % val != 0 && b[i] % val != 0) {
                g = false;
            }
        }
        if (g) {
            cout << val << "\n";
            return;
        }
    }

    cout << "-1\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
