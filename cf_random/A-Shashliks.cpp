#include <bits/stdc++.h>

#include <cassert>
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
  int k, a, b, x, y;
  cin >> k >> a >> b >> x >> y;

  if (x > y) {
    swap(x, y);
    swap(a, b);
  }
  int cnt = 0;

  if (a > b) {
    if (k >= a) {
      int n1 = (k - a) / x + 1;
      cnt += n1;
      k -= n1 * x;
    }
    if (k >= b) {
      int n2 = (k - b) / y + 1;
      cnt += n2;
      k -= n2 * y;
    }
  } else {
    if (k >= a) {
      cnt = (k - a) / x + 1;
    } else {
      cnt = 0;
    }
  }

  cout << cnt << "\n";
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
