#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), c1(n + 1, 0), c2(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c1[a[i]]++;
  }
  ll res = 0;
  int l = 0, r = 0;
  for (int i = 0; i <= n; i++) {
    if (c1[i] % k) {
      cout << 0 << "\n";
      return;
    } else {
      c1[i] /= k;
    }
  }

  while (l <= r && r < n) {
    c2[a[r]]++;
    while (c2[a[r]] > c1[a[r]]) {
      c2[a[l]]--;
      l++;
    }
    res += ll(r - l + 1);
    r++;
  }
  cout << res << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
