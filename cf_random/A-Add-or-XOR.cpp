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

void solve() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  if (b == a) {
    cout << 0 << "\n";
    return;
  }

  if (a > b) {
    if (a % 2 == 1 && a - 1 == b) {
      cout << y << "\n";
    } else {
      cout << -1 << "\n";
    }
    return;
  }

  int d = b - a;
  if (x <= y) {
    cout << d * x << "\n";
    return;
  }

  int res = 0;
  if (a % 2 == 0) {
    res = ((d + 1) / 2) * y + (d / 2) * x;
  } else {
    res = (d / 2) * y + ((d + 1) / 2) * x;
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
